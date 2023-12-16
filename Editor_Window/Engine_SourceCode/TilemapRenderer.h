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
		Vector2 GetScale() { return mScale; }

		Vector2 GetIndex() { return mIndex; }
		void SetIndex(Vector2 index) { mIndex = index; }

	public:
		static Vector2 TileSize;
		static Vector2 OriginTileSize;
		static Vector2 SelectedIndex;

	private:
		graphics::Texture* mTexture;
		Vector2 mOriginTileSize;
		Vector2 mScale;
		Vector2 mIndex;	//행열 표현이므로 정수만 사용
	};
}