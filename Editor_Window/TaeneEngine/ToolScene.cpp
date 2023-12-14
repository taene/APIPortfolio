#include "ToolScene.h"
#include "tObject.h"
#include "Tile.h"
#include "TilemapRenderer.h"
#include "tResources.h"
#include "tTexture.h"
#include "Camera.h"
#include "Renderer.h"

namespace t
{
	ToolScene::ToolScene()
		:tmr(nullptr)
	{}
	ToolScene::~ToolScene()
	{}
	void ToolScene::Init()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Particle , Vector2(344.0f , 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		Tile* tile = object::Instantiate<Tile>(eLayerType::MapTile);
		tmr = tile->AddComponent<TilemapRenderer>();

		tmr->SetTexture(Resources::Find<graphics::Texture>(L"basementTile"));

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
	}
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		float tileSize = tmr->GetTileSize().x;
		float scale = tmr->GetScale().x;

		//grid
		for ( size_t i = 0; i < 50; i++ )
		{
			MoveToEx(hdc , ( tileSize * scale ) * i , 0 , NULL);
			LineTo(hdc , ( tileSize * scale ) * i , 2000);
		}

		for ( size_t i = 0; i < 50; i++ )
		{
			MoveToEx(hdc , 0 , ( tileSize * scale ) * i , NULL);
			LineTo(hdc , 2000 , ( tileSize * scale ) * i);
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
}