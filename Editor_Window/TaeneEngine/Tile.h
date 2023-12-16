#pragma once
#include "..\\Engine_SourceCode\\tGameObject.h"

namespace t
{
    class Tile :public GameObject
    {
	public:
		void Init() override;
		void Start() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetIndexPosition(int x , int y);

	private:
    };

}