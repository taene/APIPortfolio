#include "TilemapRenderer.h"
#include "tGameObject.h"
#include "Transform.h"
#include "tTexture.h"
#include "Renderer.h"

namespace t
{
	TilemapRenderer::TilemapRenderer()
		:Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mTileSize(52.0f , 52.0f)
		, mScale(Vector2::One)	//transform의 스케일설정과 spriteRenderer의 스케일설정은 따로임(알아서 설정)
		, mIndex(0,0)
	{}

	TilemapRenderer::~TilemapRenderer()
	{}

	void TilemapRenderer::Init()
	{}

	void TilemapRenderer::Update()
	{}

	void TilemapRenderer::LateUpdate()
	{}

	void TilemapRenderer::Render(HDC hdc)
	{
		if ( mTexture == nullptr )
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		float rot = tr->GetRoation();
		Vector2 scale = tr->GetScale();

		if ( renderer::mainCamera )
			pos = renderer::mainCamera->CalculatePosition(pos);

		if ( mTexture->GetTextureType()
			== graphics::Texture::eTextureType::Bmp )
		{
			if ( mTexture->IsAlpha() )
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, pos.x , pos.y
					, mTileSize.x * mScale.x * scale.x
					, mTileSize.y * mScale.y * scale.y
					, mTexture->GetHdc()
					, mIndex.x * mTileSize.x , mIndex.y * mTileSize.y
					, mTileSize.x
					, mTileSize.y
					, func);
			}
			else
			{
				//https://blog.naver.com/power2845/50147965306
				TransparentBlt(hdc
					, pos.x , pos.y
					, mTileSize.x * mScale.x * scale.x
					, mTileSize.y * mScale.y * scale.y
					, mTexture->GetHdc()
					, mIndex.x * mTileSize.x , mIndex.y * mTileSize.y
					, mTileSize.x
					, mTileSize.y
					, RGB(255 , 0 , 255));
			}
		}
		//else if (mTexture->GetTextureType()
		//	== graphics::Texture::eTextureType::Png)
		//{
		//	// 투명화 시킬 픽셀의 색 범위
		//	Gdiplus::ImageAttributes imgAtt = {};
		//	imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

		//	Gdiplus::Graphics graphcis(hdc);

		//	graphcis.TranslateTransform(pos.x, pos.y);
		//	graphcis.RotateTransform(rot);
		//	graphcis.TranslateTransform(-pos.x, -pos.y);

		//	graphcis.DrawImage(mTexture->GetImage()
		//		, Gdiplus::Rect
		//		(
		//			pos.x, pos.y
		//			, mTexture->GetWidth() * mSize.x * scale.x
		//			, mTexture->GetHeight() * mSize.y * scale.y
		//		)
		//		, 0, 0
		//		, mTexture->GetWidth(), mTexture->GetHeight()
		//		, Gdiplus::UnitPixel
		//		, nullptr/*&imgAtt*/);
		//}}

	}
}