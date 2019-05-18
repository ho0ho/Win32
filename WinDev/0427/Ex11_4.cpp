#include <Windows.h>
#include <tchar.h>
#include "resource.h"

#include <CommCtrl.h>
#pragma comment(lib, "comctl32.lib")

#define MAX_STR 100
TCHAR wndClassName[MAX_STR] = TEXT("Class Name");
TCHAR wndTitleName[MAX_STR] = TEXT("Title Name");

typedef struct tagDATA {
	TCHAR str[20];
	int   num;
} DATA;

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
	static DATA* pData;
	switch (msg) {
	case WM_INITDIALOG: 
	{		
		pData = (DATA*)lParam;
		SetDlgItemText(hDlg, IDC_EDIT1, pData->str);
		SetDlgItemInt(hDlg, IDC_EDIT2, pData->num, 0);
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDOK:
			GetDlgItemText(hDlg, IDC_EDIT1, pData->str, sizeof(pData->str));
			pData->num = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 0);
			EndDialog(hDlg, IDOK);
			return TRUE;
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			return TRUE;
		}
	}
	return FALSE; // 메세지 처리를 안한경우..
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_LBUTTONDOWN:
	{
		DATA  data = { TEXT("홍길동"), 20 };
		UINT ret = DialogBoxParam(GetModuleHandle(0),// hinstance
			MAKEINTRESOURCE(IDD_DIALOG1),
			hwnd,		// 부모
			DlgProc, // 메세지 함수.
			(LPARAM)& data); // WM_INITDIALOG의 lParam로 전달된다.
		if (ret == IDOK) {
			// 이제 Dialog에 입력한 값은 data에 있다.
			TCHAR buf[128];
			wsprintf(buf, TEXT("%s / %d"), data.str, data.num);
			SetWindowText(hwnd, buf);
		}
	}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

ATOM MyRegisterClass(HINSTANCE hInst) {
	WNDCLASSEX wndClassEX;
	wndClassEX.cbSize = sizeof(WNDCLASSEX);
	wndClassEX.cbClsExtra = 0;
	wndClassEX.cbWndExtra = 0;

	wndClassEX.style = 0/*CS_HREDRAW | CS_VREDRAW*/;
	wndClassEX.lpfnWndProc = WndProc;
	wndClassEX.hInstance = hInst;
	wndClassEX.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClassEX.hIconSm = 0;
	wndClassEX.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClassEX.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH)/*(HBRUSH)(COLOR_WINDOW + 1)*/;
	wndClassEX.lpszClassName = wndClassName;
	wndClassEX.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);

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
	MyRegisterClass(hInst);
	HWND hWnd = InitInstance(hInst, nShowCmd);
	if (!hWnd) return FALSE;

	//HMENU hMenu = LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU1));
	//SetMenu(hWnd, hMenu);
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}