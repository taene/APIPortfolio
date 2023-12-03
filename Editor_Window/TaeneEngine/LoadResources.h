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
		
		////Hollow Knight LoadingScene
		//Resources::Load<graphics::Texture>(L"LS_Logo1", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Menu\\team_cherry_logo_main_menu.png");
		//Resources::Load<graphics::Texture>(L"LS_Logo2", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Menu\\Hidden_Dreams_Logo.png");
		
		//LoadingScene
		Resources::Load<graphics::Texture>(L"LS_StartMenu", L"C:\\GithubProjects\\APIPortfolio\\Assets\\The Binding of Isaac\\Sprite\\MainMenu\\TitleMenu1.bmp");

		//MainMenuScene
		/*Resources::Load<graphics::Texture>(L"MMS_Title", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Stacklands\\UserAssets\\MainTitle.bmp");
		Resources::Load<graphics::Texture>(L"MMS_bg1", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Stacklands\\UserAssets\\MainBg_1.png");
		Resources::Load<graphics::Texture>(L"MMS_bg2", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Stacklands\\UserAssets\\MainBg_2.png");
		Resources::Load<graphics::Texture>(L"MMS_bg3", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Stacklands\\UserAssets\\MainBg_3.png");
		Resources::Load<graphics::Texture>(L"MMS_bg4", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Stacklands\\UserAssets\\MainBg_4.png");
		Resources::Load<graphics::Texture>(L"MMS_bg5", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Stacklands\\UserAssets\\MainBg_5.png");
		Resources::Load<graphics::Texture>(L"MMS_bg6", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Stacklands\\UserAssets\\MainBg_6.png");
		Resources::Load<graphics::Texture>(L"MMS_bg7", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Stacklands\\UserAssets\\MainBg_7.png");
		Resources::Load<graphics::Texture>(L"MMS_bg8", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Stacklands\\UserAssets\\MainBg_8.png");*/
		
		//InGameScene
		Resources::Load<graphics::Texture>(L"IGS_BG", L"C:\\GithubProjects\\APIPortfolio\\Assets\\The Binding of Isaac\\Sprite\\Map\\basement.bmp");
		Resources::Load<graphics::Texture>(L"Player_Death", L"C:\\GithubProjects\\APIPortfolio\\Assets\\The Binding of Isaac\\Sprite\\Player\\death.bmp");
		Resources::Load<graphics::Texture>(L"Player_MoveBodyLeft", L"C:\\GithubProjects\\APIPortfolio\\Assets\\The Binding of Isaac\\Sprite\\Player\\moveBody_Left.bmp");
		Resources::Load<graphics::Texture>(L"Player_MoveBodyRight", L"C:\\GithubProjects\\APIPortfolio\\Assets\\The Binding of Isaac\\Sprite\\Player\\moveBody_Right.bmp");
		Resources::Load<graphics::Texture>(L"Player_MoveBodyUpDown", L"C:\\GithubProjects\\APIPortfolio\\Assets\\The Binding of Isaac\\Sprite\\Player\\moveBody_UpDown.bmp");

	}
}