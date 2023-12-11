#pragma once
#include "Script.h"

namespace t
{
	class BulletScript : public Script
	{
	public:
		BulletScript();
		~BulletScript();

		void Init() override;
		void Start() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:

	};

}