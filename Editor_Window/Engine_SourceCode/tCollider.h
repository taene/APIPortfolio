#pragma once
#include "Component.h"

namespace t
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual void Init();
		virtual void Start();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		Vector2 GetOffset() { return mOffset; }
		void SetOffset(Vector2 offset) { mOffset = offset; }
		UINT32 GetID() { return mID; }
		Vector2 GetSize() { return mSize; }
		void SetSize(Vector2 size) { mSize = size; }

	private:
		static UINT CollisionID;

		UINT32 mID;
		Vector2 mOffset;
		Vector2 mSize;
	};
}