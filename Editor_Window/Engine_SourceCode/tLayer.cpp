#include "tLayer.h"

namespace t
{
	Layer::Layer() :mGameObjects{}, mType()
	{
	}
	Layer::~Layer()
	{
		for (GameObject* obj : mGameObjects)
		{
			if (obj == nullptr)
				continue;

			delete obj;
			obj = nullptr;
		}
	}
	void Layer::Init()
	{
		for (GameObject* i : mGameObjects)
		{
			if (i == nullptr)
				continue;

			i->Init();
		}
	}
	void Layer::Update()
	{
		for (GameObject* i : mGameObjects)
		{
			if (i == nullptr)
				continue;

			GameObject::eState state = i->GetActive();
			if (state == GameObject::eState::Paused
				|| state == GameObject::eState::Dead)
				continue;

			i->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* i : mGameObjects)
		{
			if (i == nullptr)
				continue;

			GameObject::eState state = i->GetActive();
			if (state == GameObject::eState::Paused
				|| state == GameObject::eState::Dead)
				continue;

			i->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (GameObject* i : mGameObjects)
		{
			if (i == nullptr)
				continue;

			GameObject::eState state = i->GetActive();
			if (state == GameObject::eState::Paused
				|| state == GameObject::eState::Dead)
				continue;

			i->Render(hdc);
		}
	}
	void Layer::Destroy()
	{
		//GameObjectIter == std::vector<GameObject*>::iterator

		for (GameObjectIter iter = mGameObjects.begin()
			; iter != mGameObjects.end()
			; )
		{
			GameObject::eState active = (*iter)->GetActive();
			if (active == GameObject::eState::Dead)
			{
				GameObject* deathObj = (*iter);
				iter = mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				continue;
			}

			iter++;
		}
	}
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}
	void Layer::findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs)
	{}
	void Layer::deleteGameObjects(std::vector<GameObject*> gameObjs)
	{}
	void Layer::eraseGameObject()
	{}
}