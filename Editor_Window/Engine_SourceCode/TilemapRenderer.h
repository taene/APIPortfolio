#pragma once
#include "tEntity.h"
#include "Component.h"
#include "tTexture.h"

namespace t
{
	class TilemapRenderer : public Component
	{
	public:
		TilemapRenderer();
		~TilemapRenderer();

		void Init() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetScale(math::Vector2 scale) { mScale = scale; }

		Vector2 GetTileSize() { return mTileSize; }
		Vector2 GetScale() { return mScale; }

	private:
		graphics::Texture* mTexture;
		Vector2 mTileSize;
		Vector2 mScale;
		Vector2 mIndex;	//행열 표현이므로 정수만 사용
	};
}