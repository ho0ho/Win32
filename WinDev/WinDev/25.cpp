#include <Windows.h>
#include <tchar.h>

//int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd) {
//	// HWND FindWindow(LPCTSTR lpClassName, LPCTSTR lpWindowName);
//	// lpClassName, lpWindowName(캡션바이름) : 모르면 0으로 설정
//	// 리턴: 해당 객체의 핸들값. 없으면 0 리턴 
//	HWND hWnd = FindWindow(0, _TEXT("계산기"));
//	if (hWnd == 0) { 
//		MessageBox(0, _TEXT("계산기 핸들을 얻을 수 없습니다."), _TEXT("알림"), MB_OK | MB_ICONERROR);
//		return 0;
//	}
//	else {
//		TCHAR temp[20];
//		wsprintf(temp, _TEXT("계산기 핸들 : %d"), hWnd);
//		MessageBox(0, temp, _TEXT("알림"), MB_OK);
//	}
//	return 0;
//}
//
//int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd) {
//	HWND hWnd = FindWindow(0, _TEXT("계산기"));
//	TCHAR name[60];
//	RECT rcCalc;
//	GetClassName(hWnd, name, sizeof(name));
//	GetWindowRect(hWnd, &rcCalc);		// 해당윈도우의 영역을 rcCalc에 읽어들이는 것
//
//	TCHAR info[256];
//	wsprintf(info, _TEXT("클래스명: %s\n위치: %d, %d ~ %d, %d"), name, rcCalc.left, rcCalc.top, rcCalc.right, rcCalc.bottom);
//	MessageBox(0, info, _TEXT("계산지 정보"), MB_OK);
//
//	MoveWindow(hWnd, 10, 10, rcCalc.right - rcCalc.left, rcCalc.bottom - rcCalc.top, TRUE);
//
//	MessageBox(0, _TEXT("계산기"), TEXT("계산기 숨기기"), MB_OK);
//	ShowWindow(hWnd, SW_HIDE);
//
//	MessageBox(0, _TEXT("계산기"), TEXT("계산기 보이기"), MB_OK);
//	ShowWindow(hWnd, SW_SHOW);
//
//	MessageBox(0, _TEXT("계산기"), TEXT("계산기 종료하기"), MB_OK);
//	SendMessage(hWnd, WM_CLOSE, 0, 0);
//
//	return 0;
//}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd) {
	HWND hWnd = FindWindow(TEXT("Shell_TrayWnd"), 0);
	if (IsWindowVisible(hWnd))
		ShowWindow(hWnd, SW_HIDE);
	else
		ShowWindow(hWnd, SW_SHOW);
	return 0;
}