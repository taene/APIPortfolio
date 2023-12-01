#include "tAnimator.h"

namespace t
{
    Animator::Animator()
        :Component(enums::eComponentType::Animator), 
        mAnimations{}, 
        mActiveAnimation(nullptr),
        mbLoopAnimation(false),
        mEvents{}
    {
    }
    Animator::~Animator()
    {
    }
    void Animator::Init()
    {
    }
    void Animator::Update()
    {
        if (mActiveAnimation)
        {
            mActiveAnimation->Update();
            if (mActiveAnimation->IsComplete() == true && mbLoopAnimation == true)
            {
                mActiveAnimation->Reset();
            }
        }
    }
    void Animator::LateUpdate()
    {
    }
    void Animator::Render(HDC hdc)
    {
        if (mActiveAnimation)
            mActiveAnimation->Render(hdc);
    }
    void Animator::CreateAnimation(const std::wstring& name, 
        graphics::Texture* spriteSheet, 
        Vector2 leftTop, Vector2 size, Vector2 pivot,
        UINT spriteLength, float duration)
    {
        Animation* animation = nullptr;
        animation = FindAnimation(name);

        if (animation != nullptr)
            return;

        animation = new Animation();
        animation->CreateAnimation(name, spriteSheet,
            leftTop, size, pivot, spriteLength, duration);

        animation->SetAnimator(this);

        mAnimations.insert(std::make_pair(name, animation));
    }
    Animation* Animator::FindAnimation(const std::wstring& name)
    {
        auto it = mAnimations.find(name);

        if (it == mAnimations.end())
            return nullptr;

        return it->second;
    }
    void Animator::PlayAnimation(const std::wstring& name, bool loop)
    {
        Animation* animation = FindAnimation(name);
        
        if (animation == nullptr)
            return;

        mActiveAnimation = animation;
        mActiveAnimation->Reset();
        mbLoopAnimation = loop;
    }
}