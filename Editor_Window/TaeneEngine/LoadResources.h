#pragma once
#include "..\\Engine_SourceCode\\tResources.h"
#include "..\\Engine_SourceCode\\tTexture.h"

//#ifdef DEBUG
//#pragma comment(lib, "..\\TaeneEngine\\x64\\Debug\\TaeneEngine.lib")
//#endif // DEBUG

namespace t
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"LS_BG", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Hollow Knight sprites 1.4.3.2 (Voidheart edition)\\Menu\\Voidheart_menu_BG.png");
		Resources::Load<graphics::Texture>(L"MMS_BG", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Hollow Knight sprites 1.4.3.2 (Voidheart edition)\\Menu\\controller_prompt_bg.png");
		Resources::Load<graphics::Texture>(L"MMS_Title", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Hollow Knight sprites 1.4.3.2 (Voidheart edition)\\Backend\\title.png");
		Resources::Load<graphics::Texture>(L"IGS_BG", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Hollow Knight sprites 1.4.3.2 (Voidheart edition)\\Back Ground Image\\20201106232225_1.jpg");
		Resources::Load<graphics::Texture>(L"IGS_Player", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Hollow Knight sprites 1.4.3.2 (Voidheart edition)\\The Knight\\knight.png");
	}
}