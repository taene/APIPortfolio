#pragma once
#include "tCollider.h"

namespace t
{
	class CircleCollider2D : public Collider
	{
	public:
		CircleCollider2D();
		~CircleCollider2D();

		virtual void Init();
		virtual void Start();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	private:
		float mRadius;

	};
}