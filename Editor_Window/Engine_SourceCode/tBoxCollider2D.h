#pragma once
#include "tCollider.h"

namespace t
{
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		~BoxCollider2D();

		virtual void Init();
		virtual void Start();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	private:

	};
}