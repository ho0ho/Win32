#include <Windows.h>
#include <tchar.h>

//int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd) {
//	// HWND FindWindow(LPCTSTR lpClassName, LPCTSTR lpWindowName);
//	// lpClassName, lpWindowName(ĸ�ǹ��̸�) : �𸣸� 0���� ����
//	// ����: �ش� ��ü�� �ڵ鰪. ������ 0 ���� 
//	HWND hWnd = FindWindow(0, _TEXT("����"));
//	if (hWnd == 0) { 
//		MessageBox(0, _TEXT("���� �ڵ��� ���� �� �����ϴ�."), _TEXT("�˸�"), MB_OK | MB_ICONERROR);
//		return 0;
//	}
//	else {
//		TCHAR temp[20];
//		wsprintf(temp, _TEXT("���� �ڵ� : %d"), hWnd);
//		MessageBox(0, temp, _TEXT("�˸�"), MB_OK);
//	}
//	return 0;
//}
//
//int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd) {
//	HWND hWnd = FindWindow(0, _TEXT("����"));
//	TCHAR name[60];
//	RECT rcCalc;
//	GetClassName(hWnd, name, sizeof(name));
//	GetWindowRect(hWnd, &rcCalc);		// �ش��������� ������ rcCalc�� �о���̴� ��
//
//	TCHAR info[256];
//	wsprintf(info, _TEXT("Ŭ������: %s\n��ġ: %d, %d ~ %d, %d"), name, rcCalc.left, rcCalc.top, rcCalc.right, rcCalc.bottom);
//	MessageBox(0, info, _TEXT("����� ����"), MB_OK);
//
//	MoveWindow(hWnd, 10, 10, rcCalc.right - rcCalc.left, rcCalc.bottom - rcCalc.top, TRUE);
//
//	MessageBox(0, _TEXT("����"), TEXT("���� �����"), MB_OK);
//	ShowWindow(hWnd, SW_HIDE);
//
//	MessageBox(0, _TEXT("����"), TEXT("���� ���̱�"), MB_OK);
//	ShowWindow(hWnd, SW_SHOW);
//
//	MessageBox(0, _TEXT("����"), TEXT("���� �����ϱ�"), MB_OK);
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