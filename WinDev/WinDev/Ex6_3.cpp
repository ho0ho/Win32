#include <Windows.h>
#include <tchar.h>
#include "resource1.h"

//#pragma warning(disable : 4996) // ��ó���⿡ ��ũ�� �߰���

#define MBox(x) MessageBox(0, x, TEXT(""), MB_OK)
#define IsKeyPress(vk) (GetKeyState(vk) & 0xFF00)
#define IsKeyToggle(vk) (GetKeyState(vk) & 0x00FF)		// ����������Ʈ �˻�

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
	//	wsprintf(temp, TEXT("Ŭ���̾�Ʈ ��ǥ = %d:%d\r\n��ũ�� ��ǥ = %d:%d"),
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
	//	wsprintf(buf, TEXT("%d�� %d�ð� %d�� %d�� �� ����Ͽ����ϴ�."),
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
	//		// IsKeyToggle(k) : k�� ������ �ٽ� ���������� ������(toggle)
	//		MBox(TEXT("CTRL + F1"));
	//	return 0;
	/*case WM_LBUTTONDOWN:*/
	//{
	//	HDC hdc = GetDC(hwnd);
	//	HDC memDC = CreateCompatibleDC(hdc);
	//	HBITMAP hBitmap = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_YSJ));		BITMAP bm;
	//	GetObject(hBitmap, sizeof(bm), &bm);
	//	SelectObject(memDC, hBitmap);
	//	TextOut(memDC, 5, 5, TEXT("LoadBitmap���� ���"), 15);
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
	//	// ȭ�� DC�� ȣȯ(���ϻ���)�Ǵ� �޸� DC�� ����..
	//	HDC memDC = CreateCompatibleDC(hdc);
	//	HBITMAP hBitmap = (HBITMAP)LoadImage(0,  // ���ҽ����� �ε��Ҷ��� ���
	//		TEXT("imagesICLYCZR8.bmp"), IMAGE_BITMAP,
	//		0, 0, // Ŀ��, Icon load�ø� ���
	//		LR_LOADFROMFILE);
	//	BITMAP bm;
	//	GetObject(hBitmap, sizeof(bm), &bm);
	//	// �޸� DC�� ��Ʈ�� ����
	//	SelectObject(memDC, hBitmap);
	//	// ��Ʈ���������
	//	TextOut(memDC, 5, 5, TEXT("LoadImage�� ���"), 13);
	//	// �޸� DC --> ȭ�� DC//
	//	POINTS pt = MAKEPOINTS(lParam);
	//	BitBlt(hdc, pt.x, pt.y, bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCCOPY);
	//	// �޸� ����
	//	DeleteDC(memDC);
	//	ReleaseDC(hwnd, hdc);
	//	DeleteObject(hBitmap);
	//}
	//return 0;
	case WM_SETCURSOR:
	{
		int code = LOWORD(lParam);  // hit test code�� ��� �ִ�.
		POINT pt;
		GetCursorPos(&pt);          // ���� Ŀ���� ��ġ(��ũ�� ��ǥ)
		ScreenToClient(hwnd, &pt); // ��ũ�� ��ǥ�� Ŭ���� ��Ʈ ��ǥ��..
		// Ŭ���̾�Ʈ �ȿ����� Ư����ġ������ �ٸ� Ŀ���� ����ϴ� ���.
		if (code == HTCLIENT && PtInRect(&rc, pt))
		{
			SetCursor(LoadCursor(0, IDC_ARROW));
			return TRUE;
		}
		//�׿��� Client������ DefWindowProc�� ������ �ٰ��̴�!!!!!
		//----------------------------------------------------------
		if (code == HTLEFT || code == HTRIGHT)
		{
			SetCursor(h2);
			return TRUE; // Ŀ���� ������ ��� TRUE ����
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