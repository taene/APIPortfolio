#pragma once
#include "..\\Engine_SourceCode\\Scene.h"

namespace t
{
    class PlayScene :public Scene
    {
    public:
        PlayScene();
        ~PlayScene();

        virtual void Init() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render(HDC hdc) override;

        void OnEnter() override;
        void OnExit() override;


    private:
        class Player* bg;
    };
}
