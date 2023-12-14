#include "tLayer.h"

namespace t
{
	Layer::Layer() 
		:mGameObjects{}, mType(eLayerType::None)
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
	void Layer::Start()
	{
		for ( GameObject* i : mGameObjects )
		{
			if ( i == nullptr )
				continue;

			if ( i->IsActive() == false )
				continue;

			i->Start();
		}
	}
	void Layer::Update()
	{
		for (GameObject* i : mGameObjects)
		{
			if (i == nullptr)
				continue;

			if ( i->IsActive() == false )
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

			if ( i->IsActive() == false )
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

			if ( i->IsActive() == false )
				continue;

			i->Render(hdc);
		}
	}
	void Layer::Destroy()
	{
		std::vector<GameObject*> deleteObjects = {};
		findDeadGameObjects(deleteObjects);
		eraseDeadGameObject();
		deleteGameObjects(deleteObjects);

		//GameObjectIter == std::vector<GameObject*>::iterator

		/*for ( GameObjectIter iter = mGameObjects.begin()
			; iter != mGameObjects.end()
			; )
		{
			GameObject::eState active = ( *iter )->GetActive();
			if ( active == GameObject::eState::Dead )
			{
				GameObject* deathObj = ( *iter );
				iter = mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				continue;
			}

			iter++;
		}*/
	}
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}
	void Layer::EraseGameObject(GameObject* eraseGameObj)
	{
		// std::erase() iter넣어줘서 해당 이터레이와 같은 객체 삭제
		std::erase_if(mGameObjects ,
			[=] (GameObject* gameObj)
			{
				return gameObj == eraseGameObj;
			});
	}
	void Layer::findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs)
	{
		for ( GameObject* gameObj : mGameObjects )
		{
			GameObject::eState active = gameObj->GetState();
			if ( active == GameObject::eState::Dead )
				gameObjs.push_back(gameObj);
		}
	}
	void Layer::deleteGameObjects(std::vector<GameObject*> deleteObjs)
	{
		for ( GameObject* obj : deleteObjs )
		{
			delete obj;
			obj = nullptr;
		}
	}
	void Layer::eraseDeadGameObject()
	{
		std::erase_if(mGameObjects ,
			   [ ] (GameObject* gameObj)
			   {
					  return ( gameObj )->IsDead();
			   });
	}
}