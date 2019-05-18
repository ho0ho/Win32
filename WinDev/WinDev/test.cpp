#include <Windows.h>
#include <tchar.h>

#define MAX_STR 100
TCHAR wndClassName[MAX_STR] = TEXT("Class Name");
TCHAR wndTitleName[MAX_STR] = TEXT("Title Name");


ATOM MyRegisterClass(HINSTANCE hInst) {
	WNDCLASSEX wndClassEX;
	wndClassEX.cbSize = sizeof(WNDCLASSEX);
	wndClassEX.cbClsExtra = 0;
	wndClassEX.cbWndExtra = 0;

	wndClassEX.style = CS_HREDRAW | CS_VREDRAW;
	wndClassEX.lpfnWndProc = DefWindowProc;
	wndClassEX.hInstance = hInst;
	wndClassEX.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClassEX.hIconSm = 0;
	wndClassEX.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClassEX.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndClassEX.lpszClassName = wndClassName;
	wndClassEX.lpszMenuName = wndTitleName;

	return RegisterClassEx(&wndClassEX);
}

HWND InitInstance(HINSTANCE hInst, int nCmdShow) {
	HWND hWnd = CreateWindow(wndClassName, wndTitleName, WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInst, NULL);
	if (!hWnd) return 0;
	ShowWindow(hWnd, nCmdShow);
	return hWnd;
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd) {
	MyRegisterClass(hInst);		// 윈도우클래스 속성 채우고, 등록
	HWND hWnd = InitInstance(hInst, nShowCmd);		// 윈도우 인스턴스 생성 후 화면출력
	if (!hWnd) return FALSE;
	
	TCHAR buf[MAX_STR];
	HWND f_hwnd = FindWindow(0, TEXT("계산기"));
	wsprintf(buf, TEXT("f_wnd: %d"), f_hwnd);
	if (!f_hwnd)
		MessageBox(0, buf, TEXT("Notification"), MB_OK | MB_ICONERROR);
	else 
		MessageBox(0, buf, TEXT("Title"), MB_OK);
	return 0;
}