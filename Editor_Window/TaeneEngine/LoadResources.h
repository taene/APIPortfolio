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

		//<ToolScene>
		Resources::Load<graphics::Texture>(L"basementTile" , L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Map\\Tile\\01_basement.bmp");


		//<LoadingScene>
		Resources::Load<graphics::Texture>(L"LS_StartMenu", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\MainMenu\\TitleMenu.bmp");

		//<MainMenuScene>
		Resources::Load<graphics::Texture>(L"MMS_Bg", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\MainMenu\\MainMenuBg.bmp");
		Resources::Load<graphics::Texture>(L"MMS_NewRunMenu", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\MainMenu\\NewRunMenu.bmp");
		Resources::Load<graphics::Texture>(L"MMS_OutMenu", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\MainMenu\\OutMenu.bmp");
		Resources::Load<graphics::Texture>(L"MMS_Button", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\MainMenu\\MenuButton.bmp");
		
		//<InGameScene>
		Resources::Load<graphics::Texture>(L"IGS_BG1", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Map\\Tile\\StartMap.bmp");
		Resources::Load<graphics::Texture>(L"IGS_BG2", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Map\\Tile\\basement.bmp");

		//player dead
		Resources::Load<graphics::Texture>(L"Player_Death", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Player\\death.bmp");
		
		//body move
		Resources::Load<graphics::Texture>(L"Player_MoveBodyLeft", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Player\\moveBody_Left.bmp");
		Resources::Load<graphics::Texture>(L"Player_MoveBodyRight", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Player\\moveBody_Right.bmp");
		Resources::Load<graphics::Texture>(L"Player_MoveBodyUpDown", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Player\\moveBody_UpDown.bmp");
		//head move
		Resources::Load<graphics::Texture>(L"Player_HeadDown", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Player\\headDown.bmp");
		Resources::Load<graphics::Texture>(L"Player_HeadUp", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Player\\headUp.bmp");
		Resources::Load<graphics::Texture>(L"Player_HeadLeft", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Player\\headLeft.bmp");
		Resources::Load<graphics::Texture>(L"Player_HeadRight", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Player\\headRight.bmp");
		//player pickUp
		Resources::Load<graphics::Texture>(L"Player_BodyPickUp", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Player\\bodyPickUp.bmp");
		Resources::Load<graphics::Texture>(L"Player_HeadPickUp", L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Player\\headPickUp.bmp");
		
		//bullet
		Resources::Load<graphics::Texture>(L"Bullet" , L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Bullet\\bullet.bmp");
		Resources::Load<graphics::Texture>(L"BulletFinish" , L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Bullet\\bulletFinish.bmp");
		Resources::Load<graphics::Texture>(L"RedBullet" , L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Bullet\\redBullet.bmp");
		Resources::Load<graphics::Texture>(L"RedBulletFinish" , L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\Bullet\\redBulletFinish.bmp");

		//bomb
		Resources::Load<graphics::Texture>(L"BombIdle" , L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\PickUp\\bomb\\bombIdle.bmp");
		Resources::Load<graphics::Texture>(L"BombAppear" , L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\PickUp\\bomb\\bombAppear.bmp");
		Resources::Load<graphics::Texture>(L"BombCollect" , L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\PickUp\\bomb\\bombCollect.bmp");
		Resources::Load<graphics::Texture>(L"BombPulse" , L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\PickUp\\bomb\\bombPulse.bmp");
		Resources::Load<graphics::Texture>(L"BombExplosion" , L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\PickUp\\bomb\\bombExplosion.bmp");
		Resources::Load<graphics::Texture>(L"BombExplosionBack" , L"..\\..\\Assets\\The_Binding_of_Isaac\\Sprite\\PickUp\\bomb\\bombExplosionBack.bmp");


	}
}