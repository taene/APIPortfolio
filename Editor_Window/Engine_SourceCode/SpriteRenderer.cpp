#include "SpriteRenderer.h"
#include "tGameObject.h"
#include "Transform.h"
#include "tTexture.h"
#include "Renderer.h"

namespace t
{
	SpriteRenderer::SpriteRenderer()
		:Component(enums::eComponentType::SpriteRenderer), mTexture(nullptr), mSize(math::Vector2::Zero)
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
		float rot = tr->GetRoation();
		Vector2 scale = tr->GetScale();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

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
			//원하는 범위의 색을 지울 수 있음
			Gdiplus::ImageAttributes imgAtt = {};
			//imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphcis(hdc);

			graphcis.TranslateTransform(pos.x, pos.y);
			graphcis.RotateTransform(rot);
			graphcis.TranslateTransform(-pos.x, -pos.y);

			graphcis.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect
				(
					pos.x, pos.y, mSize.x, mSize.y
					/*, mTexture->GetWidth() * mSize.x * scale.x
					, mTexture->GetHeight() * mSize.y * scale.y*/
				)
				, 0, 0
				, mTexture->GetWidth(), mTexture->GetHeight()
				, Gdiplus::UnitPixel
				, nullptr/*&imgAtt*/);
		}
	}
}