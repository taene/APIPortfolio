#pragma once
#include "Component.h"
#include "tTexture.h"

namespace t
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(math::Vector2 size) { mSize = size; }
		
		math::Vector2 GetTextureSize() { return math::Vector2(mTexture->GetWidth(), mTexture->GetHeight()); }


	private:
		graphics::Texture* mTexture;
		math::Vector2 mSize;
	};
}