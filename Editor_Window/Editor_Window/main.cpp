// Editor_Window.cpp : 애플리케이션에 대한 진입점을 정의합니다.


#include "framework.h"
#include "main.h"
#include "..\\Engine_SourceCode\\tApplication.h"
#include "..\\Engine_SourceCode\\tResources.h"
#include "..\\Engine_SourceCode\\tTexture.h"
#include "..\\Engine_SourceCode\\SceneManager.h"
#include "..\\TaeneEngine\\LoadScenes.h"
#include "..\\TaeneEngine\\LoadResources.h"
#include "..\\TaeneEngine\\ToolScene.h"

ULONG_PTR gpToken;
Gdiplus::GdiplusStartupInput gpsi;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

t::Application application;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance , const wchar_t* name , WNDPROC proc);
BOOL                InitInstance(HINSTANCE, int);
BOOL                InitToolScene(HINSTANCE);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, //프로그램의 인스턴스 핸들
                     _In_opt_ HINSTANCE hPrevInstance,  //바로앞에 실행된 현재 프로그램의 인스턴스 핸들 - 없을경우 NULL, 신경X
                     _In_ LPWSTR    lpCmdLine,  //명령행으로 입력된 프로그램 인수
                     _In_ int       nCmdShow)   //프로그램이 실행될 형태 - 보통 모양 정보 등이 전달됨
{

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    //메모리 릭 테스트
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(366);


    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EDITORWINDOW, szWindowClass, MAX_LOADSTRING);

    // 1) 윈도우 창 정보 등록
    MyRegisterClass(hInstance , szWindowClass , WndProc);
    MyRegisterClass(hInstance , L"TILEWINDOW" , WndTileProc);

    // 2) 윈도우 창 생성
    if (!InitInstance (hInstance, nCmdShow))
        return FALSE;

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOW));

    MSG msg = {};

    // 3) 메인 루프
    // - 입력
    // - 로직
    // - 렌더링
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            // 게임 로직
            application.Run();
        }
    }
    Gdiplus::GdiplusShutdown(gpToken);

    application.Release();

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance , const wchar_t* name , WNDPROC proc)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = proc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITORWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = name;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   RECT windowRect = { 0,0,1440,816 };
   ::AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, false);

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, nullptr, nullptr, hInstance, nullptr);

   
   // 윈도우 창을 만들 때 한번 Init으로 핸들을 받아옴
   application.Init(hWnd, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   Gdiplus::GdiplusStartup(&gpToken, &gpsi, NULL);

   //리소스, 씬 로드
   t::LoadResources();
   t::LoadScenes();

   InitToolScene(hInstance);

   return TRUE;
}


BOOL InitToolScene(HINSTANCE hInstance)
{
    t::Scene* activeScene = t::SceneManager::GetActiveScene();
    std::wstring name = activeScene->GetName();

    RECT windowRect = { 0,0,1440,816 };

    if ( name == L"ToolScene" )
    {
        HWND ToolhWnd = CreateWindowW(L"TILEWINDOW" , L"TileWindow" , WS_OVERLAPPEDWINDOW ,
               0 , 0 , windowRect.right - windowRect.left , windowRect.bottom - windowRect.top , nullptr , nullptr , hInstance , nullptr);

        //Tile 윈도우 크기 조정 -- TOOL
        t::graphics::Texture* texture
            = t::Resources::Find<t::graphics::Texture>(L"basementTile");

        RECT rect = { 0, 0, ( LONG ) texture->GetWidth(), ( LONG ) texture->GetHeight() };
        AdjustWindowRect(&rect , WS_OVERLAPPEDWINDOW , false);

        UINT toolWidth = rect.right - rect.left;
        UINT toolHeight = rect.bottom - rect.top;

        SetWindowPos(ToolhWnd , nullptr , windowRect.right - windowRect.left , 0 , toolWidth , toolHeight , 0);
        ShowWindow(ToolhWnd , true);
        UpdateWindow(ToolhWnd);
    }

    return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}