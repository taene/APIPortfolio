#pragma once
#include "tEntity.h"
#include "pch.h"
#include "tGameObject.h"

namespace t
{
	class Layer :public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Init();
		virtual void Start();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);

		const std::vector<GameObject*> GetGameObjects() { return mGameObjects; }

	private:
		void findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs);
		void deleteGameObjects(std::vector<GameObject*> gameObjs);
		void eraseGameObject();

	private:
		enums::eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};

	typedef std::vector<GameObject*>::iterator GameObjectIter;
}