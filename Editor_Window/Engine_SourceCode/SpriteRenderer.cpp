#include "SpriteRenderer.h"
#include "tGameObject.h"
#include "Transform.h"

namespace t
{
	SpriteRenderer::SpriteRenderer() : mImgae(nullptr), size(0.0f,0.0f)
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
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphcis(hdc);

		graphcis.DrawImage(mImgae, Gdiplus::Rect(pos.x, pos.y, size.x, size.y));
	}
	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImgae = Gdiplus::Image::FromFile(path.c_str());
		size.x = mImgae->GetWidth();
		size.y = mImgae->GetHeight();
	}
}