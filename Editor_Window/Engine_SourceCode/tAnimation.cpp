#include "tAnimation.h"
#include "tTime.h"
#include "Transform.h"
#include "tGameObject.h"
#include "tAnimator.h"
#include "Renderer.h"
#include "Camera.h"

namespace t
{
	Animation::Animation()
		:Resource(enums::eResourceType::Animation),
		mAnimator(nullptr),
		mTexture(nullptr),
		mSpriteSheet{},
		mIndex(-1),
		mTime(0.0f),
		mbComplete(false)
	{
	}
	Animation::~Animation()
	{
	}
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::Update()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();

		if (mSpriteSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;
		
			if (mIndex < mSpriteSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}
	void Animation::Render(HDC hdc)
	{
		//알파블렌드를 쓸 수 있는 조건: 해당 이미지에 알파채널이 있어야 한다.

		if (mTexture == nullptr)
			return;

		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		float rot = tr->GetRoation();
		Vector2 scale = tr->GetScale();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		Sprite sprite = mSpriteSheet[mIndex];
		
		graphics::Texture::eTextureType type = mTexture->GetTextureType();
		if (type == graphics::Texture::eTextureType::Bmp)
		{
			HDC imgHdc = mTexture->GetHdc();

			if ( mTexture->IsAlpha() )
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, sprite.pivot.x/*pos.x - (sprite.size.x / 2.0f)*/
					, sprite.pivot.y/*pos.y - (sprite.size.y / 2.0f)*/
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, func);
			}
			else
			{
				/*TransparentBlt(hdc
					, pos.x - ( sprite.size.x / 2.0f ) + sprite.pivot.x
					, pos.y - ( sprite.size.y / 2.0f ) + sprite.pivot.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, RGB(255 , 0 , 255));*/
				TransparentBlt(hdc
					, sprite.pivot.x/*pos.x - (sprite.size.x / 2.0f)*/
					, sprite.pivot.y/*pos.y - (sprite.size.y / 2.0f)*/
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, RGB(255 , 0 , 255));
			}

			//충돌체 그리기
			Rectangle(hdc , pos.x , pos.y , pos.x + 10 , pos.y + 10);
		}
		else if (type == graphics::Texture::eTextureType::Png)
		{
			//내가 원하는 픽셀을 투명화 시킴
			Gdiplus::ImageAttributes imgAtt = {};

			//투명화 시킬 픽셀의 색 범위
			//imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			//graphics.TranslateTransform(pos.x, pos.y);
			//graphics.RotateTransform(rot);
			//graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect
				(
					pos.x - (sprite.size.x / 2.0f)
					, pos.y - (sprite.size.y / 2.0f)
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
				)
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, Gdiplus::UnitPixel
				, /*&imgAtt*/nullptr
			);
		}
	}
	void Animation::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 pivot, UINT spriteLength, float duration)
	{
		mTexture = spriteSheet;
		for (int i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.pivot = pivot;
			sprite.duration = duration;

			mSpriteSheet.push_back(sprite);
		}
	}
	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}