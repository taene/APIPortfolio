#include "SpriteRenderer.h"
#include "tGameObject.h"
#include "Transform.h"

namespace t
{
	SpriteRenderer::SpriteRenderer() : mImgae(nullptr), mWidth(0), mHeight(0)
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
		graphcis.DrawImage(mImgae, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
		////파랑 브러쉬 생성
		//HBRUSH blueBrush
		//	= CreateSolidBrush(RGB(255, 0, 255));

		//// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		//HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		//SelectObject(hdc, oldPen);

		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Rectangle(hdc, tr->GetX(), tr->GetY(), 
		//	100 + tr->GetX(), 100 + tr->GetY());

		//SelectObject(hdc, oldBrush);
		//DeleteObject(blueBrush);
		//DeleteObject(redPen);
	}
	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImgae = Gdiplus::Image::FromFile(path.c_str());
		mWidth = mImgae->GetWidth();
		mHeight = mImgae->GetHeight();
	}
}