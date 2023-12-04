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
        void switchScene();

    private:
        class GameObject* button1;
        class GameObject* button2;
    };
}