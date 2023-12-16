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
        virtual void Start() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render(HDC hdc) override;

        void OnEnter() override;
        void OnExit() override;

    private:
        void mapTileFileSaveLoad();

    };
}