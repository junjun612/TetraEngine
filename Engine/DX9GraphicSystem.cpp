#include "DX9GraphicSystem.h"


#include "Texture.h"
namespace Tetra
{
	DX9GraphicSystem::DX9GraphicSystem(HWND hWnd) : GraphicSystem(hWnd)
	{
		d3d = NULL;
		device = nullptr;

		sprite = nullptr;
	}


	DX9GraphicSystem::~DX9GraphicSystem()
	{
	}

	DX9GraphicSystem *DX9GraphicSystem::Create(HWND hWnd)
	{
		// 생성, 에러 검출
		DX9GraphicSystem *returnSystem = new DX9GraphicSystem(hWnd);
		if (returnSystem == nullptr)
			Error::Throw<SystemError>("DX9 그래픽 객체 생성을 실패하였습니다.");

		// 초기화, 에러 검출
		returnSystem->Init();
		if (returnSystem->GetDevice() == NULL)
		{
			SAFE_RELEASE(returnSystem);
			Error::Throw<SystemError>("DX9 디바이스 생성을 실패하였습니다.");
		}

		return returnSystem;
	}

	//===
	// 화면 관리 함수
	void DX9GraphicSystem::ClearScreen()
	{
		device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
			D3DXCOLOR(this->clearColor.r, clearColor.g, clearColor.b, 1), 1.0f, 0);
	}

	void DX9GraphicSystem::Present()
	{
		device->Present(NULL, NULL, NULL, NULL);
	}

	//===
	// 수학
	void DX9GraphicSystem::SetTransform(Matrix &mat)
	{
		D3DXMATRIX d3d9Matrix = GetSuitableMatrix(mat);
		device->SetTransform(D3DTS_WORLD, &d3d9Matrix);
	}

	D3DXVECTOR3 DX9GraphicSystem::GetSuitableVector(Vector3 vec)
	{
		return D3DXVECTOR3(vec.x, vec.y, vec.z);
	}

	D3DXMATRIX DX9GraphicSystem::GetSuitableMatrix(Matrix mat)
	{
		D3DXMATRIX returnMatrix;
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			returnMatrix.m[i][j] = mat.m4x4[i][j];

		return returnMatrix;
	}

	//===
	// 텍스쳐 관리
	GraphicTexture *DX9GraphicSystem::CreateGraphicTexture(std::string filePath)
	{
		return GraphicTexture::Create<DX9GraphicTexture, DX9GraphicSystem>(this, filePath);
	}

	void DX9GraphicSystem::DrawGraphicTexture(GraphicTexture *graphicTexture, Matrix &matrix)
	{
		D3DXMATRIX d3d9Matrix = GetSuitableMatrix(matrix);

		sprite->Begin(D3DXSPRITE_ALPHABLEND);
		{
			sprite->SetTransform(&d3d9Matrix);

			sprite->Draw(static_cast<DX9GraphicTexture *>(graphicTexture)->GetTexture(),
				NULL, NULL, NULL, D3DXCOLOR(1, 1, 1, 1));
		}
		sprite->End();
	}

	void DX9GraphicSystem::DrawTexture(Texture *graphicTexture, Matrix &matrix)
	{
		DrawGraphicTexture(graphicTexture->GetGraphicTexture(), matrix);
	}

	//===
	// 렌더타겟 관리
	RenderTarget *DX9GraphicSystem::CreateRenderTarget(int width, int height)
	{
		return RenderTarget::Create<DX9RenderTarget, DX9GraphicSystem>(this, width, height);
	}

	void DX9GraphicSystem::SetRenderTarget(RenderTarget *rt)
	{
		device->SetRenderTarget(0, static_cast<DX9RenderTarget *>(rt)->GetSurface());
	}

	//===
	// 초기화 및 관리
	void DX9GraphicSystem::Init()
	{
		// d3d 생성
		d3d = Direct3DCreate9(D3D_SDK_VERSION);

		// device 생성
		D3DPRESENT_PARAMETERS d3dpp;
		ZeroMemory(&d3dpp, sizeof(d3dpp));
		d3dpp.Windowed = TRUE;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
		d3dpp.BackBufferWidth = 800;
		d3dpp.BackBufferHeight = 600;
		d3dpp.EnableAutoDepthStencil = TRUE;
		d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

		d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING | 
			D3DCREATE_MULTITHREADED |             // #7 WPF のレンダリングスレッドから安全に Direct3Dスレッドを呼び出せるように
			D3DCREATE_FPU_PRESERVE,
			&d3dpp, &device);

		// 2d 이미지를 띄우기 위한 sprite 생성
		D3DXCreateSprite(device, &sprite);
		
		// 렌더타겟 설정
		LPDIRECT3DSURFACE9 startedRenderTarget = nullptr;
		device->GetRenderTarget(0, &startedRenderTarget);
		RenderTarget *presentRenderTarget = DX9RenderTarget::CreateRenderTarget(this, startedRenderTarget);
		this->presentRenderTarget = presentRenderTarget;
		if (startedRenderTarget == nullptr)	Error::Throw<SystemError>("DX9 첫 렌더타겟 설정이 실패했습니다.");

		// 렌더스테이트 설정
		device->SetRenderState(D3DRS_ZENABLE, TRUE);
		device->SetRenderState(D3DRS_AMBIENT, 0xffffffff);
	}

	void DX9GraphicSystem::LoopStart()
	{
		ClearScreen();
		device->BeginScene();
	}

	void DX9GraphicSystem::LoopEnd()
	{
		device->EndScene();
		Present();
	}

	void DX9GraphicSystem::Release()
	{
		SAFE_RELEASE(device);
		SAFE_RELEASE(d3d);

		SAFE_RELEASE_DELETE(presentRenderTarget);
	}
}