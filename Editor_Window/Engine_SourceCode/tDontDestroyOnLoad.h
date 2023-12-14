#pragma once
#include "Scene.h"

namespace t
{
	class DontDestroyOnLoad :public Scene
	{
	public:
		DontDestroyOnLoad();
		~DontDestroyOnLoad();

		void Init() override;
		void Start() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		//void Destroy() override;

		void OnEnter() override;
		void OnExit()  override;
	};
}