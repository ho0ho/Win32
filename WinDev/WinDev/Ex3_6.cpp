#include <Windows.h>
#include <tchar.h>

#define MAX_LOADSTRING 100

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First");
TCHAR szWindowClass[MAX_LOADSTRING] = _TEXT("BIT");
TCHAR szTitle[MAX_LOADSTRING] = _TEXT("First Sample");

ATOM MyRegisterClass(HINSTANCE hInst) {
	WNDCLASSEX WndClass;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;

	WndClass.cbSize = sizeof(WNDCLASSEX);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = DefWindowProc;
	WndClass.hInstance = hInst;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	WndClass.lpszMenuName = 0;
	WndClass.lpszClassName = szWindowClass;
	WndClass.hIconSm = 0;
	return RegisterClassEx(&WndClass);
}

BOOL fun_ModifyStylpe(HWND hwnd, LONG_PTR Add, LONG_PTR Remove, BOOL bRedraw)
{
	BOOL  bFlag = FALSE;
	LONG_PTR style = GetWindowLongPtr(hwnd, GWL_STYLE);
	style |= Add;			// �߰�����(on ���)
	style &= ~Remove;		// ��������(on ���)
	bFlag = (BOOL)SetWindowLongPtr(hwnd, GWL_STYLE, style);
	if (bFlag && bRedraw)
		SetWindowPos(hwnd, 0, 0, 0, 0, 0,
			SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_DRAWFRAME);
	return bFlag;
}

HWND InitInstance(HINSTANCE hInst, int nCmdShow) {
	HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		NULL, NULL, hInst, NULL);
	if (!hWnd) return 0;
	ShowWindow(hWnd, nCmdShow);
	return hWnd;
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	MyRegisterClass(hInst);
	HWND hwnd = InitInstance(hInst, nShowCmd);
	if (hwnd == 0) {
		return FALSE;
	}
	// �ǽð� ������ ��ü ���� ����
	HWND hWnd = FindWindow(0, _TEXT("���� ���� - �׸���"));
	fun_ModifyStylpe(hWnd, WS_THICKFRAME, WS_SYSMENU, TRUE);	// WS_SYSMENU(�ý��۸޴�)�� (�����µ�) �۵��ϰ� �����ϰ�, WS_THICKFRAME�� ����
//	fun_ModifyStylpe(hWnd, WS_SYSMENU, WS_THICKFRAME, TRUE);	// WS_SYSMENU(�ý��۸޴�)�� (�����µ�) �۵��ϰ� �����ϰ�, WS_THICKFRAME�� ����
	MessageBox(0, TEXT("����"), TEXT("Ÿ��Ʋ"), MB_OK);
	return 0;
}
