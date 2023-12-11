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
		void Start() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(GameObject* target) { mTarget = target; };

	private:
		class GameObject* mTarget;
		Vector2 mDistance;	//물체 간 거리
		Vector2 mResolution;	//화면 해상도
		Vector2 mLookPosition;	//카메라가 바라보고있는 위치
	};

}