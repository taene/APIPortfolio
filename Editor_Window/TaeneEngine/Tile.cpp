#include "Tile.h"
#include "tInput.h"
#include "Transform.h"
#include "tTime.h"
#include "TilemapRenderer.h"

namespace t
{
	void Tile::Init()
	{
		GameObject::Init();
	}
	void Tile::Start()
	{
		GameObject::Start();
	}
	void Tile::Update()
	{
		GameObject::Update();
	}
	void Tile::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Tile::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Tile::SetIndexPosition(int x, int y)
	{
		//x,y는 인덱스
		Transform* tr = GetComponent<Transform>();
		Vector2 pos;
		pos.x = x * TilemapRenderer::TileSize.x;
		pos.y = y * TilemapRenderer::TileSize.y;
		tr->SetPosition(pos);
	}
}