#include <Windows.h>
#include <tchar.h>
#include "resource1.h"

//#pragma warning(disable : 4996) // 전처리기에 매크로 추가함

#define MBox(x) MessageBox(0, x, TEXT(""), MB_OK)
#define IsKeyPress(vk) (GetKeyState(vk) & 0xFF00)
#define IsKeyToggle(vk) (GetKeyState(vk) & 0x00FF)		// 마지막바이트 검사

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//static POINTS pt = { 100, 100 };
	//PAINTSTRUCT ps;
	//HDC hdcDisplay, hdcClient;
	//static int cxClient, cyClient;
	static HCURSOR h1 = LoadCursorFromFile(TEXT("C:\\windows\\cursors\\size1_i.cur"));
	static HCURSOR h2 = LoadCursorFromFile(TEXT("C:\\windows\\cursors\\size1_il.cur"));
	static RECT rc = { 100,100,300,300 };
	switch (msg)
	{
	//case WM_LBUTTONDOWN:
	//{
	//	POINT pt = { LOWORD(lParam), HIWORD(lParam) };
	//	POINT pt1 = pt;
	//	ClientToScreen(hwnd, &pt);
	//	TCHAR temp[256];
	//	wsprintf(temp, TEXT("클라이언트 좌표 = %d:%d\r\n스크린 좌표 = %d:%d"),
	//		pt1.x, pt1.y, pt.x, pt.y);
	//	MessageBox(NULL, temp, TEXT("context"), MB_OK);
	//}
	//return 0;
	//case WM_MOVE:
	//	InvalidateRect(hwnd, 0, TRUE);
	//	return 0;
	//case WM_SIZE:
	//	cxClient = LOWORD(lParam);
	//	cyClient = HIWORD(lParam);
	//	return 0;
	//case WM_ERASEBKGND:
	////	return TRUE;
	//case WM_PAINT:
	//	hdcDisplay = CreateDC(TEXT("Display"), 0, 0, 0);
	//	hdcClient = BeginPaint(hwnd, &ps);
	//	BitBlt(hdcClient, 0, 0, cxClient, cyClient, hdcDisplay, 0, 0, SRCCOPY);
	//	DeleteDC(hdcDisplay);
	//	EndPaint(hwnd, &ps);
	//	return 0;
	//case WM_LBUTTONDOWN:
	//{
	//	DWORD count = GetTickCount();
	//	int second = count / 1000;
	//	int minute = (second % 3600) / 60;
	//	int hour = (second % 86400) / 3600;
	//	int day = second / 864000;
	//	TCHAR buf[50];
	//	wsprintf(buf, TEXT("%d일 %d시간 %d분 %d초 가 경과하였습니다."),
	//		day, hour, minute, second % 60);
	//	SetWindowText(hwnd, buf);
	//}
	//case WM_LBUTTONDOWN:
	//	SetCapture(hwnd);
	//	return 0;
	//case WM_LBUTTONUP:
	//	if (GetCapture() == hwnd)
	//		ReleaseCapture();
	//	return 0;
	//case WM_MOUSEMOVE:
	//	if (GetCapture() == hwnd) {
	//		POINT pt;
	//		GetCursorPos(&pt);
	//		hdcDisplay = CreateDC(TEXT("DISPLAY"), 0, 0, 0);
	//		hdcClient = GetDC(hwnd);
	//		StretchBlt(hdcClient, 0, 0, cxClient, cyClient, hdcDisplay, pt.x, pt.y, 100, 100, SRCCOPY);
	//		DeleteDC(hdcDisplay);
	//		ReleaseDC(hwnd, hdcClient);
	//	}
	//	return 0;
	//case WM_KEYDOWN:
	//	if (wParam == VK_F1 && IsKeyToggle(VK_CAPITAL)) 
	//		// IsKeyToggle(k) : k가 눌리면 다시 누를때까지 값유지(toggle)
	//		MBox(TEXT("CTRL + F1"));
	//	return 0;
	/*case WM_LBUTTONDOWN:*/
	//{
	//	HDC hdc = GetDC(hwnd);
	//	HDC memDC = CreateCompatibleDC(hdc);
	//	HBITMAP hBitmap = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_YSJ));		BITMAP bm;
	//	GetObject(hBitmap, sizeof(bm), &bm);
	//	SelectObject(memDC, hBitmap);
	//	TextOut(memDC, 5, 5, TEXT("LoadBitmap으로 출력"), 15);
	//	POINTS pt = MAKEPOINTS(lParam);
	//	BitBlt(hdc, pt.x, pt.y, bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCCOPY);
	//	DeleteDC(memDC);
	//	ReleaseDC(hwnd, hdc);
	//	DeleteObject(hBitmap);
	//}
	//	return 0;
	//{
	//	HDC hdc = GetDC(hwnd);
	//	HICON hIcon = LoadIcon(GetModuleHandle(0), MAKEINTRESOURCE(IDI_ICON1));
	//	DrawIcon(hdc, 10, 10, hIcon);
	//	ReleaseDC(hwnd, hdc);
	//}
	return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	//case WM_NCLBUTTONDOWN:
	//	MessageBox(NULL, TEXT("NC_context"), TEXT("title"), MB_OK);
	//	return 0;
	//case WM_NCHITTEST:
	//{
	//	DWORD code = DefWindowProc(hwnd, msg, wParam, lParam);
	//	if (code == HTCLIENT && GetKeyState(VK_CONTROL) < 0)
	//		code = HTCAPTION;
	//	if (code == HTLEFT) code = HTRIGHT;
	//	return code;
	//}
	//case WM_KEYDOWN:
	//{
	//	switch (wParam) {
	//	case VK_LEFT: pt.x -= 10; break;
	//	case VK_RIGHT: pt.x += 10; break;
	//	case VK_UP: pt.y -= 10; break;
	//	case VK_DOWN: pt.y += 10; break;
	//	}
	//	HDC hdc = GetDC(hwnd);
	//	TextOut(hdc, pt.x, pt.y, TEXT("+"), 1);
	//	ReleaseDC(hwnd, hdc);
	//}
	//return 0;
	//case WM_RBUTTONDOWN:
	//{
	//	HDC hdc = GetDC(hwnd);
	//	// 화면 DC와 호환(동일색상)되는 메모리 DC를 얻음..
	//	HDC memDC = CreateCompatibleDC(hdc);
	//	HBITMAP hBitmap = (HBITMAP)LoadImage(0,  // 리소스에서 로드할때만 사용
	//		TEXT("imagesICLYCZR8.bmp"), IMAGE_BITMAP,
	//		0, 0, // 커서, Icon load시만 사용
	//		LR_LOADFROMFILE);
	//	BITMAP bm;
	//	GetObject(hBitmap, sizeof(bm), &bm);
	//	// 메모리 DC에 비트맵 선택
	//	SelectObject(memDC, hBitmap);
	//	// 비트맵으로출력
	//	TextOut(memDC, 5, 5, TEXT("LoadImage로 출력"), 13);
	//	// 메모리 DC --> 화면 DC//
	//	POINTS pt = MAKEPOINTS(lParam);
	//	BitBlt(hdc, pt.x, pt.y, bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCCOPY);
	//	// 메모리 제거
	//	DeleteDC(memDC);
	//	ReleaseDC(hwnd, hdc);
	//	DeleteObject(hBitmap);
	//}
	//return 0;
	case WM_SETCURSOR:
	{
		int code = LOWORD(lParam);  // hit test code가 들어 있다.
		POINT pt;
		GetCursorPos(&pt);          // 현재 커서의 위치(스크린 좌표)
		ScreenToClient(hwnd, &pt); // 스크린 좌표를 클라이 언트 좌표로..
		// 클라이언트 안에서도 특정위치에서는 다른 커서를 사용하는 방법.
		if (code == HTCLIENT && PtInRect(&rc, pt))
		{
			SetCursor(LoadCursor(0, IDC_ARROW));
			return TRUE;
		}
		//그외의 Client에서는 DefWindowProc이 변경해 줄것이다!!!!!
		//----------------------------------------------------------
		if (code == HTLEFT || code == HTRIGHT)
		{
			SetCursor(h2);
			return TRUE; // 커서를 변경한 경우 TRUE 리턴
		}
		else if (code == HTTOP || code == HTBOTTOM)
		{
			SetCursor(h1);
			return TRUE;
		}
	}
	return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

ATOM MyRegisterClass(HINSTANCE hInst) {
	WNDCLASSEX WndClass;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.cbSize = sizeof(WNDCLASSEX);

	WndClass.style = 0/*CS_HREDRAW | CS_VREDRAW*/;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszMenuName = 0;
	WndClass.lpszClassName = TEXT("First");
	WndClass.hInstance = hInst;
	WndClass.hIconSm = 0;
	WndClass.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	return RegisterClassEx(&WndClass);
}

HWND InitInstance(HINSTANCE hInst, int nCmdShow) {
	HWND hWnd = CreateWindowEx(0, TEXT("First"), TEXT("hello"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInst, NULL);
	if (!hWnd) return 0;
	ShowWindow(hWnd, nCmdShow);
	return hWnd;
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd) {


	MyRegisterClass(hInst);
	HWND hWnd = InitInstance(hInst, nShowCmd);
	if (!hWnd) return FALSE;

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}



	return 0;
}