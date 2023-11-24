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
		
		//LoadingScene
		Resources::Load<graphics::Texture>(L"LS_BG", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Menu\\Voidheart_menu_BG.png");
		Resources::Load<graphics::Texture>(L"LS_Logo1", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Menu\\team_cherry_logo_main_menu.png");
		Resources::Load<graphics::Texture>(L"LS_Logo2", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Menu\\Hidden_Dreams_Logo.png");
		
		//MainMenuScene
		Resources::Load<graphics::Texture>(L"MMS_BG", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Menu\\controller_prompt_bg.png");
		Resources::Load<graphics::Texture>(L"MMS_Title", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Backend\\title.png");
		
		//InGameScene
		Resources::Load<graphics::Texture>(L"IGS_BG1", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_BG_set_02_0005_01.png");
		Resources::Load<graphics::Texture>(L"IGS_BG2", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_BG_set_02_0004_02.png");
		Resources::Load<graphics::Texture>(L"IGS_BG3", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_BG_set_02_0000_06.png");
		Resources::Load<graphics::Texture>(L"IGS_BG4", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_BG_set_02_0001_05.png");
		
		Resources::Load<graphics::Texture>(L"IGS_Ground", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_land_floor_0003_01.png");
		
		Resources::Load<graphics::Texture>(L"IGS_RWall1", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_wall_r_0001_05.png");
		Resources::Load<graphics::Texture>(L"IGS_RWall2", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_wall_r_0002_04.png");
		Resources::Load<graphics::Texture>(L"IGS_RWall3", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_wall_r_0000_06.png");
		Resources::Load<graphics::Texture>(L"IGS_RWall4", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_wall_r_0005_01.png");
		Resources::Load<graphics::Texture>(L"IGS_RWall5", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_wall_r_0004_02.png");
		
		Resources::Load<graphics::Texture>(L"IGS_LWall1", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_wall_l_0000s_0000_Color-Balance-1-copy-9.png");
		Resources::Load<graphics::Texture>(L"IGS_LWall2", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_wall_l_0000s_0001_Color-Balance-1-copy-7.png");
		Resources::Load<graphics::Texture>(L"IGS_LWall3", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_wall_l_0000s_0000_Color-Balance-1-copy-5.png");
		Resources::Load<graphics::Texture>(L"IGS_LWall4", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_wall_l_0000s_0000_Color-Balance-1-copy-3.png");
		Resources::Load<graphics::Texture>(L"IGS_LWall5", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_wall_l_0000s_0000_Color-Balance-1-copy-1.png");

		Resources::Load<graphics::Texture>(L"IGS_FGRock", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\Architecture _ Environment\\Area specfic architecture\\00 King_s Pass\\tut_rocks_0007_02.png");
		

		Resources::Load<graphics::Texture>(L"IGS_Player", L"C:\\GithubProjects\\APIPortfolio\\Assets\\Sprites\\The Knight\\knight.png");
	}
}