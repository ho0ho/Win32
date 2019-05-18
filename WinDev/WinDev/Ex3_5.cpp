#include <Windows.h>
#include <tchar.h>

#define MAX_LOADSTRING 100

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First");
TCHAR szWindowClass[MAX_LOADSTRING] = _TEXT("BIT");
TCHAR szTitle[MAX_LOADSTRING] = _TEXT("First Sample");

HWND InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
	if (!hWnd) {
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	/*UpdateWindow(hWnd);*/	// 없어도 되는 코드 return 0

	return hWnd;
}

ATOM MyRegisterClass(HINSTANCE hInst) {
	WNDCLASSEX WndClass;
	WndClass.cbSize = sizeof(WNDCLASSEX);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = DefWindowProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInst;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	WndClass.lpszMenuName = 0;
	WndClass.lpszClassName = szWindowClass;
	WndClass.hIconSm = 0;
	return RegisterClassEx(&WndClass);
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	MyRegisterClass(hInst);
	HWND hwnd = InitInstance(hInst, nShowCmd);
	if (hwnd == 0) { return FALSE; }

	//실시간 클래스 정보 수정
	MessageBox(0, TEXT("실시간 정보 수정"), TEXT("First"), MB_OK);
	SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG)GetStockObject(DKGRAY_BRUSH));
	InvalidateRect(hwnd, NULL, TRUE);
	MessageBox(0, TEXT("Hello,API"), TEXT("First"), MB_OK);

	//실시간 클래스 정보 획득
	TCHAR temp[126];
	WORD w;
	DWORD flag = GetClassLongPtr(hwnd, GCLP_HBRBACKGROUND);			// DWORD(unsigned long), 백그라운드 color값을 리턴
	// flag: 백그라운드 color값(4바이트,unsigned long)
	// GetRValue(flag): flag값의 맨아래 바이트값 리턴			 #define GetRValue(rgb) (LOBYTE(rgb))
	// GetGValue(flag): flag값의 그다음 아래 바이트값 리턴	 #define GetGValue(rgb) (LOBYTE(rgb >> 8))
	// GetBValue(flag): flag값의 그다음 아래 바이트값 리턴	 #define GetBValue(rgb) (LOBYTE(rgb >> 16))
	wsprintf(temp, _TEXT("R : %d, G : %d, B : %d"), GetRValue(flag), GetGValue(flag), GetBValue(flag));
	// sprintf()의 윈도우용(여기 w는 wide가 아니라 windows의 약자)
	MessageBox(0, temp, TEXT("획득정보"), MB_OK);
	return 0;
}


