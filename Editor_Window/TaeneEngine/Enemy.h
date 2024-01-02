#pragma once
#include "..\\Engine_SourceCode\\tGameObject.h"

namespace t
{
    class Enemy :public GameObject
    {
	public:
		Enemy();
		~Enemy();

		void Init() override;
		void Start() override;
		void Update() override;
		void LateUpdate()override;
		void Render(HDC hdc) override;

		
	private:

    };

}