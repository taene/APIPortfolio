#include "tAnimator.h"
#include "tResources.h"
#include "tTexture.h"

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
        for (auto& it : mAnimations)
        {
            delete it.second;
            it.second = nullptr;
        }

        for (auto& it : mEvents)
        {
            delete it.second;
            it.second = nullptr;
        }
    }
    void Animator::Init()
    {
    }
    void Animator::Update()
    {
        if (mActiveAnimation)
        {
            mActiveAnimation->Update();

            Events* events = FindEvents(mActiveAnimation->GetName());

            if (mActiveAnimation->IsComplete() == true)
            {
                if (events)
                    events->completeEvent();

                if (mbLoopAnimation == true)
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

    void Animator::CreateAnimation(const std::wstring& name
        , graphics::Texture* spriteSheet
        , Vector2 leftTop
        , Vector2 size , Vector2 offset
        , UINT spriteLength , float duration)
    {
        Animation* animation = nullptr;
        animation = FindAnimation(name);

        if (animation != nullptr)
            return;

        animation = new Animation();
        animation->SetName(name);
        animation->CreateAnimation(name, spriteSheet,
            leftTop, size, offset, spriteLength, duration);

        animation->SetAnimator(this);

        Events* events = new Events();
        mEvents.insert(std::make_pair(name, events));

        mAnimations.insert(std::make_pair(name, animation));
    }
    void Animator::CreateAnimationByFolder(const std::wstring& name, const std::wstring& path, Vector2 offset, float duration)
    {
        Animation* animation = nullptr;
        animation = FindAnimation(name);
        if (animation != nullptr)
            return;
        //D:\JunJae\AR50\YamYam_Engine\Resources\Mushroom\1.bmp
        int fileCount = 0;
        std::filesystem::path fs(path);
        std::vector<graphics::Texture*> images = {};
        for (auto& p : std::filesystem::recursive_directory_iterator(fs))
        {
            std::wstring fileName = p.path().filename();
            std::wstring fullName = p.path();

            graphics::Texture* texture = Resources::Load<graphics::Texture>(fileName, fullName);
            images.push_back(texture);
            fileCount++;
        }
        UINT sheetWidth = images[0]->GetWidth() * fileCount;
        UINT sheetHeight = images[0]->GetHeight();
        graphics::Texture* spriteSheet = graphics::Texture::Create(name, sheetWidth, sheetHeight);

        UINT imageWidth = images[0]->GetWidth();
        UINT imageHeight = images[0]->GetHeight();
        for (size_t i = 0; i < images.size(); i++)
        {
            BitBlt(spriteSheet->GetHdc(), i * imageWidth, 0
                , imageWidth, imageHeight
                , images[i]->GetHdc(), 0, 0, SRCCOPY);
        }

        CreateAnimation(name, spriteSheet
            , Vector2(0.0f, 0.0f), Vector2(imageWidth, imageHeight)
            , offset, fileCount, duration);
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

        if (mActiveAnimation)
        {
			Events* currentEvents = FindEvents(mActiveAnimation->GetName());
			if (currentEvents)
				currentEvents->endEvent();
        }

        Events* nextEvents = FindEvents(animation->GetName());
        if (nextEvents)
            nextEvents->startEvent();

        mActiveAnimation = animation;
        mActiveAnimation->Reset();
        mbLoopAnimation = loop;
    }
    Animator::Events* Animator::FindEvents(const std::wstring& name)
    {
        auto it = mEvents.find(name);

        if (it == mEvents.end())
            return nullptr;

        return it->second;
    }
    std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
    {
        Events* events = FindEvents(name);
        return events->startEvent.mEvent;
    }
    std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
    {
        Events* events = FindEvents(name);
        return events->completeEvent.mEvent;
    }
    std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
    {
        Events* events = FindEvents(name);
        return events->endEvent.mEvent;
    }
}