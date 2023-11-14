#pragma once
#include "tEntity.h"
#include "tGameObject.h"

namespace t
{
	class Scene :public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		std::vector<GameObject*> mGameObjects;
	};
}