#include "tUIManager.h"
#include "tUIHUD.h"
//#include "tUIButton.h"

namespace t
{
	std::unordered_map<eUIType , UIBase*> UIManager::mUIs = {};
	std::stack<UIBase*> UIManager::mUIBases = {};
	std::queue<eUIType> UIManager::mRequestUIQueue = {};
	UIBase* UIManager::mActiveUI = nullptr;

	void UIManager::Init()
	{
		// UI 객체 생성해주기
		UIHUD* hud = new UIHUD();
		mUIs.insert(std::make_pair(eUIType::HpBar , hud));

		/*UIButton* button = new UIButton();
		mUIs.insert(std::make_pair(eUIType::Button , button));*/
	}
	void UIManager::OnLoad(eUIType type)
	{
		std::unordered_map<eUIType , UIBase*>::iterator iter = mUIs.find(type);

		if ( iter == mUIs.end() )
		{
			OnFail();
			return;
		}

		OnComplete(iter->second);
	}
	void UIManager::Update()
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while ( !uiBases.empty() )
		{
			UIBase* uiBase = uiBases.top();
			if ( uiBase )
			{
				uiBase->Update();
				uiBases.pop();
			}
		}
		if ( mRequestUIQueue.size() > 0 )
		{
			eUIType requestUI = mRequestUIQueue.front();
			mRequestUIQueue.pop();
			OnLoad(requestUI);
		}
	}
	void UIManager::LateUpdate()
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while ( !uiBases.empty() )
		{
			UIBase* uiBase = uiBases.top();
			if ( uiBase )
			{
				uiBase->LateUpdate();
				uiBases.pop();
			}
		}
	}
	void UIManager::Render(HDC hdc)
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while ( !uiBases.empty() )
		{
			UIBase* uiBase = uiBases.top();
			if ( uiBase )
			{
				uiBase->Render(hdc);
				uiBases.pop();
			}
		}
	}
	void UIManager::OnComplete(UIBase * addUI)
	{
		if ( addUI == nullptr )
			return;

		addUI->Init();
		addUI->Update();
		addUI->LateUpdate();

		// 만약 현재 추가된 ui가 전체화면으로 그려진다면 그 ui 말고 나머지를 전부 비활성화한다
		if ( addUI->IsFullScreen() )
		{
			std::stack<UIBase*> uiBases = mUIBases;
			while ( !uiBases.empty() )
			{
				UIBase* uiBase = uiBases.top();
				uiBases.pop();
				if ( uiBase )
				{
					uiBase->InActive();
				}
			}
		}

		mUIBases.push(addUI);
		mActiveUI = nullptr;
	}
	void UIManager::OnFail()
	{
		mActiveUI = nullptr;
	}
	void UIManager::Release()
	{
		for ( auto& iter : mUIs )
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	void UIManager::Push(eUIType type)
	{
		mRequestUIQueue.push(type);
	}
	void UIManager::Pop(eUIType type)
	{
		if ( mUIBases.size() <= 0 )
			return;
		// 해당 ui 한개만 스택에서 빼기
		std::stack<UIBase*> tempStack;
		UIBase* uibase = nullptr;
		while ( mUIBases.size() > 0 )
		{
			uibase = mUIBases.top();
			mUIBases.pop();
			if ( uibase->GetUIType() != type )
			{
				tempStack.push(uibase);
				continue;
			}
			if ( uibase->IsFullScreen() )
			{
				std::stack<UIBase*> uiBases = mUIBases;
				while ( !uiBases.empty() )
				{
					UIBase* uiBase = uiBases.top();
					uiBases.pop();
					if ( uiBase )
					{
						uiBase->Active();
						break;
					}
				}
			}
			uibase->UIClear();
		}

		while ( tempStack.size() > 0 )
		{
			uibase = tempStack.top();
			tempStack.pop();
			mUIBases.push(uibase);
		}
	}
}