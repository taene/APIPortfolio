#include "tCollisionManager.h"
#include "Scene.h"
#include "SceneManager.h"
#include "tGameObject.h"
#include "tCollider.h"
#include "Transform.h"

namespace t
{

	std::bitset<( UINT ) eLayerType::Max> CollisionManager::mCollisionLayerMatrix[ ( UINT ) eLayerType::Max ] = {};
	std::unordered_map<UINT64 , bool> CollisionManager::mCollisionMap = {};

	void CollisionManager::Init()
	{}

	void CollisionManager::Start()
	{}

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for ( UINT row = 0; row < ( UINT ) eLayerType::Max; row++ )
		{
			for ( UINT col = 0; col < ( UINT ) eLayerType::Max; col++ )
			{
				if ( mCollisionLayerMatrix[ row ][ col ] == true )
				{
					LayerCollision(scene , ( eLayerType ) row , ( eLayerType ) col);
				}
			}
		}
	}

	void CollisionManager::LateUpdate()
	{}

	void CollisionManager::Render(HDC hdc)
	{}

	void CollisionManager::Clear()
	{
		mCollisionMap.clear();
		mCollisionLayerMatrix->reset();
	}

	//레이어끼리 충돌할지 말지 체크하는 함수
	void CollisionManager::CollisionLayerCheck(eLayerType left , eLayerType right , bool enable)
	{
		int row = 0;
		int col = 0;

		if ( left <= right )
		{
			row = ( UINT ) left;
			col = ( UINT ) right;
		}
		else
		{
			row = ( UINT ) right;
			col = ( UINT ) left;
		}

		mCollisionLayerMatrix[ row ][ col ] = enable;

	}

	void CollisionManager::LayerCollision(Scene* scene , eLayerType left , eLayerType right)
	{
		const std::vector<GameObject*>& lefts = SceneManager::GetGameObjects(left);
		/*scene->GetLayer(left)->GetGameObjects();*/
		const std::vector<GameObject*>& rights = SceneManager::GetGameObjects(right); 
		/*scene->GetLayer(right)->GetGameObjects();*/

		for ( GameObject* left : lefts )
		{
			if ( left->IsActive() == false )
				continue;
			Collider* leftCol = left->GetComponent<Collider>();
			if ( leftCol == nullptr )
				continue;

			for ( GameObject* right : rights )
			{
				if ( right->IsActive() == false )
					continue;
				Collider* rightCol = right->GetComponent<Collider>();
				if ( rightCol == nullptr )
					continue;
				if ( left == right )
					continue;

				ColliderCollision(leftCol , rightCol);
			}

		}
	}

	void CollisionManager::ColliderCollision(Collider* left , Collider* right)
	{
		// 두 충돌체 번호로 가져온 ID 확인하여 CollisionID 세팅
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		// 이전 충돌 정보를 검색한다.
		// 만약에 충돌정보가 없는 상태라면
		// 충돌정보를 생성해준다.

		auto iter = mCollisionMap.find(id.id);
		if ( iter == mCollisionMap.end() )
		{
			mCollisionMap.insert(std::make_pair(id.id , false));
			iter = mCollisionMap.find(id.id);
		}

		// 충돌 체크를 해준다
		if ( Intersect(left , right) )
		{
			//최초 충돌할
			if ( iter->second == false )
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else // 이미 충돌 중
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			//충돌을 하지 않은 상태
			if ( iter->second == true )
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}
	}
	bool CollisionManager::Intersect(Collider* left , Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		// size 1,1 일 기본크기 (100픽셀)
		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		eColliderType leftType = left->GetColliderType();
		eColliderType rightType = right->GetColliderType();

		//AABB 충돌
		// rect - rect
		if ( leftType == eColliderType::Rect2D
			&& rightType == eColliderType::Rect2D )
		{
			if ( fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f) )
			{
				return true;
			}
		}


		// circle - circle
		if ( leftType == eColliderType::Circle2D
			&& rightType == eColliderType::Circle2D )
		{
			// 원이 그려질때 네모의 왼쪽 위가 pivot이고 그 네모의 내접원이 그려짐-> 따라서 원의 중심은 leftPos+원의 반지름(x,y)
			Vector2 leftCirclePos = leftPos + ( leftSize / 2.0f );
			Vector2 rightCirclePos = rightPos + ( rightSize / 2.0f );
			float distance = ( leftCirclePos - rightCirclePos ).length();
			if ( distance <= ( leftSize.x / 2.0f + rightSize.x / 2.0f ) )
			{
				return true;
			}
		}

		if ( leftType == eColliderType::Circle2D && rightType == eColliderType::Rect2D )
		{
			// circle - rect

			//원의 중심좌표
			Vector2 c = leftPos + ( leftSize / 2.0f );
			//원의 반지름
			float radius = leftSize.x / 2.0f;

			//네모 꼭짓점들
			Vector2 rectLeftTop = rightPos;
			Vector2 rectRightTop = Vector2(rectLeftTop.x + leftSize.x , rectLeftTop.y);
			Vector2 rectLeftBottom = Vector2(rectLeftTop.x , rectLeftTop.y + leftSize.y);
			Vector2 rectRightBottom = rectLeftTop + leftSize;

			if ( ( rectLeftTop.x <= c.x && c.x <= rectRightTop.x )
				|| ( rectLeftTop.y <= c.y && c.y <= rectLeftBottom.y ) )
			{
				//네모를 반지름만큼 확장
				RECT rectEx = {
					rectLeftTop.x - radius,
					rectLeftTop.y - radius,
					rectRightBottom.x + radius,
					rectRightBottom.y + radius
				};

				if ( ( rectEx.left < c.x && c.x < rectEx.right )
					&& ( rectEx.top < c.y && c.y < rectEx.bottom ) )
				{
					return true;
				}
			}
			else
			{
				//네모의 꼭짓점들이 원안에 있는지
				bool check[ 4 ] = { false };
				Vector2 points[ 4 ] = { rectLeftTop ,rectRightTop ,rectLeftBottom ,rectRightBottom };
				for ( int i = 0; i < 4; i++ )
				{
					float distance = ( c - points[ i ] ).length();

					if ( distance > radius )
						check[ i ] = false;
					else
						check[ i ] = true;
				}

				for ( int i = 0; i < 4; i++ )
				{
					if ( check[ i ] )
						return true;
				}
			}

			return false;
		}
		else if ( leftType == eColliderType::Rect2D && rightType == eColliderType::Circle2D )
		{
			// rect - circle
			// 
			//원의 중심
			Vector2 c = rightPos + ( rightSize / 2.0f );
			//원의 반지름
			float radius = rightSize.x / 2.0f;

			//네모 꼭짓점들
			Vector2 rectLeftTop = leftPos;
			Vector2 rectRightTop = Vector2(rectLeftTop.x + rightSize.x , rectLeftTop.y);
			Vector2 rectLeftBottom = Vector2(rectLeftTop.x , rectLeftTop.y + rightSize.y);
			Vector2 rectRightBottom = rectLeftTop + rightSize;

			if ( ( rectLeftTop.x <= c.x && c.x <= rectRightTop.x )
				|| ( rectLeftTop.y <= c.y && c.y <= rectLeftBottom.y ) )
			{
				//네모를 반지름만큼 확장
				RECT rectEx = {
					rectLeftTop.x - radius,
					rectLeftTop.y - radius,
					rectRightBottom.x + radius,
					rectRightBottom.y + radius
				};

				if ( ( rectEx.left < c.x && c.x < rectEx.right )
					&& ( rectEx.top < c.y && c.y < rectEx.bottom ) )
				{
					return true;
				}
			}
			else
			{
				//네모의 꼭짓점들이 원안에 있는지
				bool check[ 4 ] = { false };
				Vector2 points[ 4 ] = { rectLeftTop ,rectRightTop ,rectLeftBottom ,rectRightBottom };
				for ( int i = 0; i < 4; i++ )
				{
					float distance = ( c - points[ i ] ).length();

					if ( distance > radius )
						check[ i ] = false;
					else
						check[ i ] = true;
				}

				for ( int i = 0; i < 4; i++ )
				{
					if ( check[ i ] )
						return true;
				}
			}

			return false;
		}

		return false;
	}
}