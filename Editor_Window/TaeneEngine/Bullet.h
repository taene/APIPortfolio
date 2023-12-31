#pragma once
#include "tGameObject.h"

namespace t
{
	class Bullet : public GameObject
	{
	public:
		Bullet();
		~Bullet();

		void Init() override;
		void Start() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;



	private:

	};
}