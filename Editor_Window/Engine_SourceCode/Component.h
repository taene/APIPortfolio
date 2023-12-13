#pragma once
#include "tEntity.h"

namespace t
{
	using namespace enums;

	class GameObject;
	class Component : public Entity
	{
	public:
		Component(eComponentType type);
		~Component();

		virtual void Init();
		virtual void Start();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { mOwner = owner; }
		GameObject* GetOwner() { return mOwner; }
		eComponentType GetType() { return mType; }

	private:
		GameObject* mOwner;
		eComponentType mType;
	};
}