#pragma once
#include "Component.h"

namespace t
{
	using namespace math;
	class Camera :public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; }
		
		Camera();
		~Camera();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;



	private:
		class GameObject* mTarget;
		Vector2 mDistance;	//��ü �� �Ÿ�
		Vector2 mResolution;	//ȭ�� �ػ�
		Vector2 mLookPosition;	//ī�޶� �ٶ󺸰��ִ� ��ġ
	};

}