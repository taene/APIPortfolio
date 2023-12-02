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

			i->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* i : mGameObjects)
		{
			if (i == nullptr)
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

			i->Render(hdc);
		}
	}
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}
}