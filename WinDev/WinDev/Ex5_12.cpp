#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static POINTS start, end;
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		end = start = MAKEPOINTS(lParam);
		SetCapture(hwnd);	// HWND SetCapture(HWND hWnd);
		return 0;
	case WM_MOUSEMOVE:
		if (GetCapture() == hwnd) {
			POINTS pt = MAKEPOINTS(lParam);
			HDC hdc = GetDC(hwnd);
			SetROP2(hdc, R2_NOTXORPEN); // 겹쳐지는 부분만 그린다->NULL BRUSH로
			// NULL BRUSH로 그린다 => 안그린다
			// NULL BRUSH로 안그린다 => 그린다
			SelectObject(hdc, GetStockObject(NULL_BRUSH));
			Rectangle(hdc, start.x, start.y, end.x, end.y);
			Rectangle(hdc, start.x, start.y, pt.x, pt.y);		// 지웠다가 새로 그려야 해서
			end = pt;
			ReleaseDC(hwnd, hdc);			
		}
		return 0;
	case WM_LBUTTONUP:
		if (GetCapture() == hwnd) {
			ReleaseCapture();
			HDC hdc = GetDC(hwnd);
			SelectObject(hdc, GetStockObject(NULL_BRUSH));
			Rectangle(hdc, start.x, start.y, end.x, end.y);
			ReleaseDC(hwnd, hdc);
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
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