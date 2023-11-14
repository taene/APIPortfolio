#include "Scene.h"

namespace t
{
	Scene::Scene() :mGameObjects{}
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Init()
	{
	}
	void Scene::Update()
	{
		for (GameObject* i : mGameObjects)
		{
			i->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (GameObject* i : mGameObjects)
		{
			i->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (GameObject* i : mGameObjects)
		{
			i->Render(hdc);
		}
	}
	void Scene::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}