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
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);

	private:
		enums::eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};

	typedef std::vector<GameObject*>::iterator GameObjectIter;
}