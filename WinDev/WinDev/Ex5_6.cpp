#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_PAINT:
	{
		TCHAR str[] = TEXT("�� ��° �μ��� ����� ������ ��� �ִ� ����ü �������̴�.�ټ���° �μ��� DrawText �Լ��� ���ڿ��� ����� ����������ϴ� �÷����̸� ������ ���� ���� ���� �÷����� ������ �����Ѵ�.");
		RECT rt = { 100,100,400,300 };
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		DrawText(hdc, str, -1, &rt, DT_RIGHT | DT_WORDBREAK );
		EndPaint(hwnd, &ps);
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