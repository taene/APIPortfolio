#include "SpriteRenderer.h"
#include "tGameObject.h"
#include "Transform.h"
#include "tTexture.h"

namespace t
{
	SpriteRenderer::SpriteRenderer()
		:Component(), mTexture(nullptr), mSize(math::Vector2::One)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Init()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)	//texture 세팅 안되어있음
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		if (mTexture->GetTextureType() 
			== graphics::Texture::eTextureType::Bmp)
		{
			//https://blog.naver.com/power2845/50147965306
			TransparentBlt(hdc, pos.x, pos.y,
				mSize.x, mSize.y,
				mTexture->GetHdc(),
				0, 0, mTexture->GetWidth(), mTexture->GetHeight(),
				RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType()
			== graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphcis(hdc);
			graphcis.DrawImage(mTexture->GetImage(),
				Gdiplus::Rect(pos.x, pos.y, mSize.x, mSize.y));
		}
	}
}