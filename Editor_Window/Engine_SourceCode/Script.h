#pragma once
#include "Component.h"

namespace t
{
	class Script :public Component
	{
	public:
		Script();
		~Script();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

	private:

	};
}