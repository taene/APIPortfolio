#pragma once
#include "tEntity.h"
#include "Component.h"
#include "tGameObject.h"

namespace t
{
	using namespace math;

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		Vector2 GetPosition() { return mPosition; }
		float GetRoation() { return mRotation; }
		Vector2 GetScale() { return mScale; }
		void SetRotation(float rotate) { mRotation = rotate; }
		void SetScale(Vector2 scale) { mScale = scale; }

		void SetParent(Transform* tr) 
		{
			mParent = tr;
			Vector2 myPos = mPosition;
			SetPosition(mParent->GetPosition());
			mPosition += myPos;
		}

	private:
		Vector2 mPosition;
		Vector2 mScale;
		float mRotation;

		Transform* mParent;
	};
}