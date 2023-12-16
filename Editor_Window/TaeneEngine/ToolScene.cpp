#include "ToolScene.h"
#include "tObject.h"
#include "Tile.h"
#include "TilemapRenderer.h"
#include "tResources.h"
#include "tTexture.h"
#include "tInput.h"

//camera
#include "Camera.h"
#include "Renderer.h"
#include "CameraMoveScript.h"

namespace t
{
	ToolScene::ToolScene()
	{}
	ToolScene::~ToolScene()
	{}
	void ToolScene::Init()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None , Vector2::Zero);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		camera->AddComponent<CameraMoveScript>();

		/*Tile* tile = object::Instantiate<Tile>(eLayerType::MapTile);
		tmr = tile->AddComponent<TilemapRenderer>();
		tmr->SetTexture(Resources::Find<graphics::Texture>(L"basementTile"));*/

		Scene::Init();
	}
	void ToolScene::Start()
	{
		Scene::Start();
	}
	void ToolScene::Update()
	{
		Scene::Update();
	}
	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();

		if ( Input::GetKeyDown(eKeyCode::LButton) )
		{
			Vector2 pos = Input::GetMousePosition();
			pos = renderer::mainCamera->CalculateTilePosition(pos);

			if ( pos.x >= 0.0f && pos.y >= 0.0f )
			{
				int idxX = pos.x / TilemapRenderer::TileSize.x;
				int idxY = pos.y / TilemapRenderer::TileSize.y;

				Tile* tile = object::Instantiate<Tile>(eLayerType::MapTile);
				TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
				tmr->SetTexture(Resources::Find<graphics::Texture>(L"basementTile"));
				tmr->SetIndex(TilemapRenderer::SelectedIndex);

				tile->SetIndexPosition(idxX , idxY);
				mTiles.push_back(tile);
			}
			else
			{
				//
			}

		}

		if ( Input::GetKeyDown(eKeyCode::S) )
		{
			Save();
		}
		if ( Input::GetKeyDown(eKeyCode::L) )
		{
			Load();
		}

		/*if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"LoadingScene");
		}*/
	}
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		//grid
		for ( size_t i = 0; i < 50; i++ )
		{
			Vector2 pos = renderer::mainCamera->CalculatePosition
			(
				Vector2(TilemapRenderer::TileSize.x * i , 0.0f)
			);

			MoveToEx(hdc , ( TilemapRenderer::TileSize.x ) * i , 0 , NULL);
			LineTo(hdc , ( TilemapRenderer::TileSize.x ) * i , 2000);
		}

		for ( size_t i = 0; i < 50; i++ )
		{
			Vector2 pos = renderer::mainCamera->CalculatePosition
			(
				Vector2(0.0f , TilemapRenderer::TileSize.y * i)
			);

			MoveToEx(hdc , 0 , ( TilemapRenderer::TileSize.y ) * i , NULL);
			LineTo(hdc , 2000 , ( TilemapRenderer::TileSize.y ) * i);
		}
	}
	void ToolScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}
	void ToolScene::Save()
	{// open a file name
		OPENFILENAME ofn = {};

		wchar_t szFilePath[ 256 ] = {};

		ZeroMemory(&ofn , sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[ 0 ] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0*.tile\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if ( false == GetSaveFileName(&ofn) )
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile , szFilePath , L"wb");

		for ( Tile* tile : mTiles )
		{
			TilemapRenderer* tmr = tile->GetComponent<TilemapRenderer>();
			Transform* tr = tile->GetComponent<Transform>();

			Vector2 sourceIndex = tmr->GetIndex();
			Vector2 position = tr->GetPosition();

			int x = sourceIndex.x;
			fwrite(&x , sizeof(int) , 1 , pFile);
			int y = sourceIndex.y;
			fwrite(&y , sizeof(int) , 1 , pFile);

			x = position.x;
			fwrite(&x , sizeof(int) , 1 , pFile);
			y = position.y;
			fwrite(&y , sizeof(int) , 1 , pFile);
		}

		fclose(pFile);
	}
	void ToolScene::Load()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[ 256 ] = {};

		ZeroMemory(&ofn , sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[ 0 ] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if ( false == GetOpenFileName(&ofn) )
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile , szFilePath , L"rb");

		while ( true )
		{
			int idxX = 0;
			int idxY = 0;

			int posX = 0;
			int posY = 0;


			if ( fread(&idxX , sizeof(int) , 1 , pFile) == NULL )
				break;
			if ( fread(&idxY , sizeof(int) , 1 , pFile) == NULL )
				break;
			if ( fread(&posX , sizeof(int) , 1 , pFile) == NULL )
				break;
			if ( fread(&posY , sizeof(int) , 1 , pFile) == NULL )
				break;

			Tile* tile = object::Instantiate<Tile>(eLayerType::MapTile , Vector2(posX , posY));
			TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"basementTile"));
			tmr->SetIndex(Vector2(idxX , idxY));

			mTiles.push_back(tile);
		}

		fclose(pFile);
	}
}

LRESULT CALLBACK WndTileProc(HWND hWnd , UINT message , WPARAM wParam , LPARAM lParam)
{
	switch ( message )
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos = { };
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd , &mousePos);

		t::math::Vector2 mousePosition;
		mousePosition.x = mousePos.x;
		mousePosition.y = mousePos.y;

		int idxX = mousePosition.x / t::TilemapRenderer::OriginTileSize.x;
		int idxY = mousePosition.y / t::TilemapRenderer::OriginTileSize.y;

		t::TilemapRenderer::SelectedIndex = Vector2(idxX , idxY);
	}

	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd , &ps);

		//Rectangle(hdc, 100, 100, 200, 200);
		t::graphics::Texture* texture
			= t::Resources::Find<t::graphics::Texture>(L"basementTile");

		TransparentBlt(hdc
			, 0 , 0
			, texture->GetWidth()
			, texture->GetHeight()
			, texture->GetHdc()
			, 0 , 0
			, texture->GetWidth()
			, texture->GetHeight()
			, RGB(255 , 0 , 255));

		EndPaint(hWnd , &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd , message , wParam , lParam);
	}
	return 0;
}