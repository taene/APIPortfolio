#pragma once
#include "..\\Engine_SourceCode\\Scene.h"

namespace t
{
    class InGameScene :public Scene
    {
    public:
        InGameScene();
        ~InGameScene();

        virtual void Init() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render(HDC hdc) override;

        void OnEnter() override;
        void OnExit() override;

    private:
        class GameObject* bg1;
        class Player* knight;

    };
}