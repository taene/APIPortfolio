#pragma once
#include "tEntity.h"

namespace t
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component(enums::eComponentType type);
		~Component();

		virtual void Init();
		virtual void Start();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { mOwner = owner; }
		GameObject* GetOwner() { return mOwner; }
		enums::eComponentType GetType() { return mType; }

	private:
		GameObject* mOwner;
		enums::eComponentType mType;
	};
}