#pragma once
#include "tEntity.h"
#include "tGameObject.h"
#include "tLayer.h"

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
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const enums::eLayerType type);
		Layer* GetLayer(enums::eLayerType type) { return mLayers[(UINT)type]; }

	private:
		void createLayers();

	private:
		std::vector<Layer*> mLayers; 
	};
}