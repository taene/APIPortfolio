#pragma once
#include "..\\Engine_SourceCode\\Scene.h"

namespace t
{
    class MainMenuScene :public Scene
    {
    public:
        MainMenuScene();
        ~MainMenuScene();

        virtual void Init() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render(HDC hdc) override;

        void OnEnter() override;
        void OnExit() override;

    private:
        class GameObject* bg;
        class GameObject* logo;
    };
}