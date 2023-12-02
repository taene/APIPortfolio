#pragma once
#include "Component.h"

namespace t
{
	using namespace math;
	class Camera :public Component
	{
	public:
		
		Camera();
		~Camera();

		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; }

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(GameObject* target) { mTarget = target; };

	private:
		class GameObject* mTarget;
		Vector2 mDistance;	//��ü �� �Ÿ�
		Vector2 mResolution;	//ȭ�� �ػ�
		Vector2 mLookPosition;	//ī�޶� �ٶ󺸰��ִ� ��ġ
	};

}