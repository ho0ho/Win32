#include <Windows.h>
#include <tchar.h>

#define WM_MYMESSAGE WM_USER + 100

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	switch (iMessage) {
	case WM_MYMESSAGE:
	{
		TCHAR buf[20];
		wsprintf(buf, TEXT("%d + %d = %d"), wParam, lParam, wParam + lParam);
		MessageBox(hWnd, buf, TEXT(""), MB_OK);
	}
	return wParam + lParam;
	case WM_DESTROY: // 닫기버튼 누르면 불려지는 메시지
		PostQuitMessage(0);
		return 0;
	//case WM_LBUTTONDOWN:
	//	SendMessage(hWnd, WM_MYMESSAGE, 10, 20);
	//	return 0;
	case WM_LBUTTONDOWN:
	{	// case내에서 변수 선언문이 있으면 {}필요
		HDC hdc = GetDC(hWnd);
		Rectangle(hdc, 120, 10, 210, 100);
		ReleaseDC(hWnd, hdc);
	}
	return 0;
	case WM_RBUTTONDOWN:
	{
		RECT r = { 120, 10, 210, 100 };
		InvalidateRect(hWnd, &r, FALSE);
	}
	return 0;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		Rectangle(hdc, 10, 10, 100, 100);
		EndPaint(hWnd, &ps);
	}
	return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
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
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
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