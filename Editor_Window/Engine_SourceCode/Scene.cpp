#include "Scene.h"
#include "tCollisionManager.h"

namespace t
{
	Scene::Scene() 
		:mLayers{}
	{
		createLayers();
	}
	Scene::~Scene()
	{
		for (Layer* i : mLayers)
		{
			delete i;
			i = nullptr;
		}
	}
	void Scene::Init()
	{
		for (Layer* i : mLayers)
		{
			if (i == nullptr)
				continue;

			i->Init();
		}
	}
	void Scene::Start()
	{
		for ( Layer* i : mLayers )
		{
			if ( i == nullptr )
				continue;

			i->Start();
		}
	}
	void Scene::Update()
	{
		for (Layer* i : mLayers)
		{
			if (i == nullptr)
				continue;

			i->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer* i : mLayers)
		{
			if (i == nullptr)
				continue;

			i->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer* i : mLayers)
		{
			if (i == nullptr)
				continue;

			i->Render(hdc);
		}
	}
	void Scene::Destroy()
	{
		for (Layer* i : mLayers)
		{
			if (i == nullptr)
				continue;

			i->Destroy();
		}
	}
	void Scene::OnEnter()
	{
	}
	void Scene::OnExit()
	{
		CollisionManager::Clear();
	}
	void Scene::AddGameObject(GameObject* gameObj, const enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}
	void Scene::EraseGameObject(GameObject* gameObj)
	{
		eLayerType layerType = gameObj->GetLayerType();
		mLayers[ ( UINT ) layerType ]->EraseGameObject(gameObj);
	}
	void Scene::createLayers()
	{
		mLayers.resize((UINT)enums::eLayerType::Max);

		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}
}