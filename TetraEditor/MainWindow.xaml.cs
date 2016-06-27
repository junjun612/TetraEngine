using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using System.Runtime.InteropServices;
using System.Windows.Interop;
using D3DMesh;

using Microsoft.Win32;


namespace TetraEditor
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        private readonly D3DWrapper myD3DScene = new D3DWrapper();

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            StartRendering();
        }

        private void StartRendering()
        {
            if (!d3dImage.IsFrontBufferAvailable)
                return;

            IntPtr scene = myD3DScene.Initialize(new WindowInteropHelper(this).Handle);

            Inspecter.Items.Clear();
            for (int i = 0; i < myD3DScene.GetObjectNum(); i++)
            {
                Inspecter.Items.Add(myD3DScene.GetObjectName(i));
            }

            Resource.Items.Clear();
            for (int i = 0; i < myD3DScene.GetResourceNum(); i++)
            {
                Resource.Items.Add(myD3DScene.GetResourceName(i));
            }

            d3dImage.Lock();
            {
                d3dImage.SetBackBuffer(D3DResourceType.IDirect3DSurface9, scene);

                d3dImage.Unlock();
            }
            CompositionTarget.Rendering += new EventHandler(OnRendering);
        }
        private void EndRendering()
        {
            CompositionTarget.Rendering -= OnRendering;
            myD3DScene.Cleanup();
        }

        void KeyboardMove()
        {
            if (selectedObject != "")
            {
                myD3DScene.KeyboardMove(selectedObject);
                if (Keyboard.IsKeyDown(Key.Down) || Keyboard.IsKeyDown(Key.Up) ||
                    Keyboard.IsKeyDown(Key.Left) || Keyboard.IsKeyDown(Key.Right))
                {
                    float x = myD3DScene.GetTransformX(selectedObject);
                    float y = myD3DScene.GetTransformY(selectedObject);
                    float z = myD3DScene.GetTransformZ(selectedObject);

                    PosX.Text = x.ToString();
                    PosY.Text = y.ToString();
                    PosZ.Text = z.ToString();
                }
            }
        }

        void OnRendering(object sender, EventArgs e)
        {
            if (!d3dImage.IsFrontBufferAvailable)
                return;

            d3dImage.Lock();
            {
                KeyboardMove();

                int width = 0, height = 0;
                myD3DScene.Render(ref width, ref height);
                d3dImage.AddDirtyRect(new Int32Rect(0, 0, width, height));

                d3dImage.Unlock();
            }
        }

        private void d3dImage_IsFrontBufferAvailableChanged(object sender, DependencyPropertyChangedEventArgs e )
        {
            if (d3dImage.IsFrontBufferAvailable)
            {
                StartRendering();
            }
            else
            {
                EndRendering();
            }
        }

        int tmpNum = 0;
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            myD3DScene.AddObject("Object" + tmpNum);
            tmpNum++;

            Inspecter.Items.Clear();
            for (int i = 0; i < myD3DScene.GetObjectNum() + 1; i++)
            {
                Inspecter.Items.Add(myD3DScene.GetObjectName(i));
            }
        }

        String selectedObject = "";
        private void Inspecter_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var addedItems = e.AddedItems;
            if (addedItems.Count == 1)
            {
                selectedObject = addedItems[0].ToString();
                Name.Text = selectedObject;
                
                float x = myD3DScene.GetTransformX(selectedObject);
                float y = myD3DScene.GetTransformY(selectedObject);
                float z = myD3DScene.GetTransformZ(selectedObject);

                PosX.Text = x.ToString();
                PosY.Text = y.ToString();
                PosZ.Text = z.ToString();

                ImageSource.Text = ": " + myD3DScene.GetSpriteResource(selectedObject);
            }
        }

        private void Pos_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (PosX != null && PosY != null && PosZ != null && selectedObject != "")
            {
                float x;
                if (PosX.Text == "" || PosX.Text == "-") x = 0;
                else x = System.Convert.ToSingle(PosX.Text);

                float y;
                if (PosY.Text == "" || PosY.Text == "-") y = 0;
                else y = System.Convert.ToSingle(PosY.Text);

                float z;
                if (PosZ.Text == "" || PosZ.Text == "-") z = 0;
                else z = System.Convert.ToSingle(PosZ.Text);

                myD3DScene.SetTransform(selectedObject, x, y, z);
            }
        }

        private void Name_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (Name.Text != "" && selectedObject != "")
            {
                myD3DScene.SetObjectName(selectedObject, Name.Text);
                selectedObject = Name.Text;

                Inspecter.Items.Clear();
                for (int i = 0; i < myD3DScene.GetObjectNum(); i++)
                {
                    Inspecter.Items.Add(myD3DScene.GetObjectName(i));
                }
            }
        }

        String selectedResource = "";
        private void Resource_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var addedItems = e.AddedItems;
            if (addedItems.Count == 1)
            {
                selectedResource = addedItems[0].ToString();
            }
        }

        int resourceNum = 0;
        private void ResourceButton_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFile = new OpenFileDialog();
            if(openFile.ShowDialog() == true)
            {
                myD3DScene.AddResource(openFile.SafeFileName, openFile.FileName);
                resourceNum++;

                Resource.Items.Clear();
                for (int i = 0; i < myD3DScene.GetResourceNum(); i++)
                {
                    Resource.Items.Add(myD3DScene.GetResourceName(i));
                }
            }
        }

        private void ResourceSetButton_Click(object sender, RoutedEventArgs e)
        {
            if (selectedObject != "" && selectedResource != "")
            {
                myD3DScene.SetSpriteResource(selectedObject, selectedResource);

                ImageSource.Text = ": " + myD3DScene.GetSpriteResource(selectedObject);
            }
        }
    }
}
