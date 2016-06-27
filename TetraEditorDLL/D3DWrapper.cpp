#include "D3DRenderer.h" 
#include <vcclr.h>
#include <msclr\marshal_cppstd.h>

#include "MainSystem.h"

using namespace System;
using namespace msclr::interop;

namespace D3DMesh
{
	public ref class Vector
	{
	public:
		Vector(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		float x, y, z;
	};

	public ref class D3DWrapper
	{
	public:
		IntPtr Initialize(IntPtr hwnd)
		{
			MAIN_SYS->Init();
			return IntPtr(((Tetra::DX9RenderTarget *)(GRP_SYS->GetRenderTarget()))->GetSurface());
		}

		VOID Render(int% width, int% height)
		{
			MAIN_SYS->Loop();
			width = 800;
			height = WINDOW_HEIGHT;
		}
		VOID Cleanup()
		{
			MAIN_SYS->Release();
		}

		void AddObject(System::String ^objectName)
		{
			OBJ_SYS->AddObject(Tetra::Object::Create(marshal_as<std::string>(objectName)));
			OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->AddComponent<Tetra::Transform>();
			OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->AddComponent<Tetra::SpriteRenderer>();
			OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->GetComponent<Tetra::SpriteRenderer>()->SetSourceTexture(RES_SYS->GetResource<Tetra::Texture>("bg"));
			OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->Init();
		}

		float GetTransformX(System::String ^objectName)
		{
			return OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->GetComponent<Tetra::Transform>()->position.x;
		}
		float GetTransformY(System::String ^objectName)
		{
			return OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->GetComponent<Tetra::Transform>()->position.y;
		}
		float GetTransformZ(System::String ^objectName)
		{
			return OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->GetComponent<Tetra::Transform>()->position.z;
		}
		void SetTransform(System::String ^objectName, float x, float y, float z)
		{
			Tetra::Object *obj = OBJ_SYS->GetObject(marshal_as<std::string>(objectName));
			if(obj != nullptr)
				obj->GetComponent<Tetra::Transform>()->position = Vector3(x, y, z);
		}

		int GetObjectNum()
		{
			return OBJ_SYS->GetObjectCount();
		}

		System::String ^GetObjectName(int index)
		{
			return marshal_as<String^>(OBJ_SYS->GetObject(index)->GetName());
		}
		void SetObjectName(System::String ^objectName, System::String ^changeName)
		{
			(OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->SetName(marshal_as<std::string>(changeName)));
		}
		System::String ^GetSpriteResource(System::String ^objectName)
		{
			return marshal_as<String^>(OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->
				GetComponent<Tetra::SpriteRenderer>()->GetSourceTexture()->GetFileName());
		}
		void SetSpriteResource(System::String ^objectName, System::String ^resourceName)
		{
			OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->GetComponent<Tetra::SpriteRenderer>()
				->SetSourceTexture(RES_SYS->GetResource<Tetra::Texture>(
				marshal_as<std::string>(resourceName)));
		}

		void KeyboardMove(System::String ^objectName)
		{
			if (GetAsyncKeyState(VK_DOWN))
				OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->
					GetComponent<Tetra::Transform>()->position += Vector3(0, 2, 0);
			if (GetAsyncKeyState(VK_UP))
				OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->
					GetComponent<Tetra::Transform>()->position += Vector3(0, -2, 0);
			if (GetAsyncKeyState(VK_LEFT))
				OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->
					GetComponent<Tetra::Transform>()->position += Vector3(-2, 0, 0);
			if (GetAsyncKeyState(VK_RIGHT))
				OBJ_SYS->GetObject(marshal_as<std::string>(objectName))->
					GetComponent<Tetra::Transform>()->position += Vector3(2, 0, 0);
		}

		void AddResource(System::String ^resourceName, System::String ^resourcePath)
		{
			RES_SYS->AddResource(
				Tetra::Texture::Create(
				marshal_as<std::string>(resourceName), marshal_as<std::string>(resourcePath)));
		}
		int GetResourceNum()
		{
			return RES_SYS->GetResourceCount();
		}

		System::String ^GetResourceName(int index)
		{
			return marshal_as<String^>(RES_SYS->GetResource(index)->GetFileName());
		}
	};
}
