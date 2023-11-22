#pragma once
#include "Component.h"
namespace t
{
	using namespace math;

	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetSize(Vector2 pos) { size.x = pos.x; size.y = pos.y; }
		Vector2 GetSize() { return size; }
		void ImageLoad(const std::wstring& path);

	private:
		Gdiplus::Image* mImgae;
		Vector2 size;
	};
}