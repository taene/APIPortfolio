#include "Scene.h"

namespace t
{
	Scene::Scene() :mLayers{}
	{
		createLayers();
	}
	Scene::~Scene()
	{
		for (Layer* lay : mLayers)
		{
			delete lay;
			lay = nullptr;
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
	}
	void Scene::AddGameObject(GameObject* gameObj, const enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
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