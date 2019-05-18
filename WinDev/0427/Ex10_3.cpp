#include <Windows.h>
#include <tchar.h>
#include "resource.h"

#define MAX_STR 100
TCHAR wndClassName[MAX_STR] = TEXT("Class Name");
TCHAR wndTitleName[MAX_STR] = TEXT("Title Name");

#define IDC_BUTTON 1
#define IDC_EDIT 2
#define IDC_LISTBOX 3
HWND hBtn, hEdit, hListBox;

void Draw3dRect(HDC hdc, int x, int y, int xx, int yy,
	BOOL down, int width)
{
	COLORREF clrMain = RGB(192, 192, 192),
		clrLight = RGB(255, 255, 255),
		clrDark = RGB(128, 128, 128);

	HPEN hPen1, hPen2, hOldPen;
	HBRUSH hBrush, hOldBrush;

	if (down)
	{
		hPen2 = CreatePen(PS_SOLID, 1, clrLight);
		hPen1 = CreatePen(PS_SOLID, 1, clrDark);
	}
	else
	{
		hPen1 = CreatePen(PS_SOLID, 1, clrLight);
		hPen2 = CreatePen(PS_SOLID, 1, clrDark);
	}
	hBrush = CreateSolidBrush(clrMain);
	hOldPen = (HPEN)SelectObject(hdc, hPen1);
	hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

	Rectangle(hdc, x, y, xx + 1, yy + 1);

	for (int i = 0; i < width; i++)
	{
		SelectObject(hdc, hPen1);

		MoveToEx(hdc, xx - 1, y, 0);
		LineTo(hdc, x, y);
		LineTo(hdc, x, yy - 1);

		SelectObject(hdc, hPen2);

		MoveToEx(hdc, x, yy, 0);
		LineTo(hdc, xx, yy);
		LineTo(hdc, xx, y);

		x++; y++; xx--; yy--;
	}
	SelectObject(hdc, hOldPen);
	SelectObject(hdc, hOldBrush);

	DeleteObject(hPen1);
	DeleteObject(hPen2);
	DeleteObject(hBrush);
}

// �ڽ�(��ư)�� �θ𿡰� WM_COMMAND�� ������ ����� �����ڵ�(�޼����� ������ ����)
#define BTN_LCLICK	1
#define BTN_RCLICK	2
#define BTN_LDBLCLK	3
#define BTN_RDBLCLK	4

// �θ� �ڽ�(��ư)�� ����� ���� �ڽĿ��� ������ �ִ� �޼����� �����Ѵ�.
// �θ� - �ڽ� ���� ���.
#define BM_CHANGESTYLE	WM_USER + 10
#define BM_CHANGETHICK  WM_USER + 11

//========================================================================
// �ڽĿ� �޼��� ó�� �Լ�.
LRESULT CALLBACK ChildProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static BOOL bDown = FALSE;
	static int  nThick = 2;

	switch (msg)
	{

		// �θ� ������ �޼���
	case BM_CHANGETHICK:
		nThick = (int)wParam;  // wParam�� �β��� �����ֱ�� ���...
		InvalidateRect(hwnd, 0, FALSE);
		return 0;

	case WM_LBUTTONDOWN:
		bDown = TRUE;  InvalidateRect(hwnd, 0, FALSE);
		SetCapture(hwnd);
		return 0;

	case WM_LBUTTONUP:
		if (GetCapture() == hwnd)
		{
			ReleaseCapture();
			bDown = FALSE;
			InvalidateRect(hwnd, 0, FALSE);

			//========================================
			// �ڽ��� �������� �θ𿡰� �˷��ش�.
			HWND hParent = GetParent(hwnd);
			UINT id = GetDlgCtrlID(hwnd);

			SendMessage(hParent, WM_COMMAND,
				MAKELONG(id, BTN_LCLICK),// ����16:id, ����16:�����ڵ�
				(LPARAM)hwnd);
		}
		return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		// �ڽ��� hdc �� ��� �ڽ��� �׸��� ���� �θ𿡰� hdc �� �������ش�.
		// �θ� �ڽ��� ������ ������ ������ �ֱ� ���ؼ�..
		// �̷� �뵵�� �̸� ������� �޼����� WM_CTLCOLORxxx �̴�.

		// wParam ���� hdc �� lParam ���� �ڽ��� �ڵ��� �־� �ش�.
		HWND hParent = GetParent(hwnd);

		SendMessage(hParent, WM_CTLCOLORBTN, (WPARAM)hdc, (LPARAM)hwnd);

		//========================================================

		RECT rc;
		GetClientRect(hwnd, &rc);

		Draw3dRect(hdc, 0, 0, rc.right, rc.bottom, bDown, nThick);

		// �θ� ������ ĸ�� ���ڿ��� ������ ��� ����Ѵ�
		TCHAR s[256];
		GetWindowText(hwnd, s, 256);

		SetBkMode(hdc, TRANSPARENT);

		if (bDown == TRUE)
			OffsetRect(&rc, nThick, nThick); // ������ �Ʒ��� �簢����
											// nThick ��ŭ �̵�

		DrawText(hdc, s, -1, &rc,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		//-----------------------------------------------------
		EndPaint(hwnd, &ps);
	}
	return 0;
	// user.chol.com/~downboard/mine.txt ���� Draw3dRect() ������ ������
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

WNDPROC old;
LRESULT CALLBACK foo(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {	
	switch(msg) {
	case WM_CHAR:
		if ((wParam >= '0' && wParam <= '9') || wParam == 8)
			// wParam == 8 : ASCII�ڵ� 8���� �齺���̽�
			return CallWindowProc(old, hwnd, msg, wParam, lParam);
		return 0;
	}
	return CallWindowProc(old, hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	////static int subMenu1 = ID_MENU1_TEST1;
	////static int subMenu2 = ID_MENU2_TEST4;
	////switch (msg)
	////{
	////case WM_CREATE:
	////{
	////	hEdit = CreateWindow(TEXT("Edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER,
	////		10, 10, 90, 20, hwnd, (HMENU)IDC_EDIT, 0, 0);
	////	// CreateWindow()�� ù��°����: Ŭ������ => ��ҹ� ���� X
	////	hBtn = CreateWindow(TEXT("button"), TEXT("Push"), WS_CHILD | WS_VISIBLE | WS_BORDER,
	////		10, 40, 90, 20, hwnd, (HMENU)IDC_BUTTON, 0, 0);
	////	hListBox = CreateWindow(TEXT("listBox"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER,
	////		150, 10, 90, 90, hwnd, (HMENU)IDC_LISTBOX, 0, 0);
	////	SendMessage(hEdit, EM_LIMITTEXT, 5, 0);
	////	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)TEXT("AAAA"));
	////	SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)TEXT("BBBB"));
	////}
	////return 0;
	////case WM_INITMENUPOPUP: 
	////{
	////	HMENU hMenu = (HMENU)wParam;
	////	CheckMenuItem(hMenu, ID_MENU1_TEST1, subMenu1 == ID_MENU1_TEST1 ? MF_CHECKED : MF_UNCHECKED);
	////	CheckMenuItem(hMenu, ID_MENU1_TEST2, subMenu1 == ID_MENU1_TEST2 ? MF_CHECKED : MF_UNCHECKED);
	////	CheckMenuItem(hMenu, ID_MENU1_TEST3, subMenu1 == ID_MENU1_TEST3 ? MF_CHECKED : MF_UNCHECKED);
	////	EnableMenuItem(hMenu, ID_MENU2_TEST4, subMenu2 == ID_MENU2_TEST4 ? MF_GRAYED : MF_ENABLED);
	////	EnableMenuItem(hMenu, ID_MENU2_TEST5, subMenu2 == ID_MENU2_TEST5 ? MF_GRAYED : MF_ENABLED);
	////	EnableMenuItem(hMenu, ID_MENU2_TEST6, subMenu2 == ID_MENU2_TEST6 ? MF_GRAYED : MF_ENABLED);
	////}
	////return 0;
	////case WM_COMMAND:
	////{
	////	//switch (LOWORD(wParam))
	////	//{
	////	//case ID_MENU1_TEST1:
	////	//	SetWindowText(hwnd, TEXT("ID_MENU1_TEST1"));
	////	//	subMenu1 = ID_MENU1_TEST1; break;
	////	//case ID_MENU1_TEST2:
	////	//	SetWindowText(hwnd, TEXT("ID_MENU1_TEST2"));
	////	//	subMenu1 = ID_MENU1_TEST2; break;
	////	//case ID_MENU1_TEST3:
	////	//	SetWindowText(hwnd, TEXT("ID_MENU1_TEST3"));
	////	//	subMenu1 = ID_MENU1_TEST3; break;
	////	//case ID_MENU2_TEST4:
	////	//	SetWindowText(hwnd, TEXT("ID_MENU2_TEST4"));
	////	//	subMenu2 = ID_MENU2_TEST4; break;
	////	//case ID_MENU2_TEST5:
	////	//	SetWindowText(hwnd, TEXT("ID_MENU2_TEST5"));
	////	//	subMenu2 = ID_MENU2_TEST5; break;
	////	//case ID_MENU2_TEST6:
	////	//	SetWindowText(hwnd, TEXT("ID_MENU2_TEST6"));
	////	//	subMenu2 = ID_MENU2_TEST6; break;
	////	//}
	////	switch (LOWORD(wParam)) 
	////	{
	////	case IDC_EDIT:
	////	{
	////		if (HIWORD(wParam) == EN_CHANGE) {
	////			TCHAR s[256];
	////			GetWindowText(hEdit, s, 256);
	////			SetWindowText(hwnd, s);
	////		}
	////		break;
	////	}
	////	case IDC_BUTTON:
	////		if (HIWORD(wParam) == BN_CLICKED) {
	////			TCHAR s[256];
	////			GetWindowText(hEdit, s, sizeof(s));
	////			SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)s);
	////		}
	////		break;
	////	}
	////}
	////return 0;
	////case WM_CONTEXTMENU: 
	////{
	////	HMENU hMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));
	////	HMENU hSubMenu = GetSubMenu(hMenu, 1);
	////	POINT pt = { LOWORD(lParam), HIWORD(lParam) };
	////	TrackPopupMenu(hSubMenu, TPM_LEFTBUTTON, pt.x, pt.y, 0, hwnd, 0);
	////}
	////return 0;
	//////case WM_LBUTTONDOWN:
	//////{
	//////	HMENU h = GetMenu(hwnd);
	//////	/*AppendMenu(h, MF_POPUP, 5000, TEXT("�߰��޴�"));*/
	//////	HMENU h1 = GetSubMenu(h, 2);		// 0 =>
	//////	HMENU a = CreateMenu();	// ���ο� �޴� �����
	//////	AppendMenu(a, MF_STRING, 5001, TEXT("BBB"));	// ���� ���� �޴��� �׸� �߰��ϰ�
	//////	AppendMenu(a, MF_SEPARATOR, 5002, TEXT(""));
	//////	AppendMenu(h, MF_POPUP, (UINT_PTR)a, TEXT("aaaa"));	// �޴��ٿ� �� �޴��� �߰��ϰ�
	//////	// AppendMenu(h, MF_STRING | MF_POPOP, (UINT)a, TEXT("�߰��޴�"));
	//////	DrawMenuBar(hwnd);
	//////}
	//////return 0;
	//////case WM_RBUTTONDOWN:
	//////{
	//////	HMENU h = GetMenu(hwnd);
	//////	HMENU hSub = GetSubMenu(h, 0);
	//////	RemoveMenu(hSub, ID_MENU1_TEST2, MF_BYCOMMAND);
	//////}
	//////return 0;
	////case WM_DESTROY:
	////	PostQuitMessage(0);
	////	return 0;
	////}
	//static HWND hChild;
	//switch (msg)
	//{
	//	// �ڽ��� �ڽ��� �׸��� ���� ������ �޼��� - �θ𿡰� ���� ������ ��ȸ�� �ش�.
	//case WM_CTLCOLORBTN:
	//{
	//	HDC hdc = (HDC)wParam;
	//	HWND h = (HWND)lParam;

	//	if (hChild == h)  // �ڽ��� 2�� �̻��̶�� ���� ���ϴ� �ڽ����� Ȯ��
	//	{
	//		SetTextColor(hdc, RGB(255, 0, 0));
	//	}
	//}
	//return 0;

	//case WM_LBUTTONDOWN:
	//{
	//	static int n = 2;
	//	++n;

	//	// �ڽĿ��� �޼����� ������ �β��� �����ϰ� �Ѵ�
	//	// wParam : ������ �β�,   lParam : not used 
	//	SendMessage(hChild, BM_CHANGETHICK, n, 0);
	//}
	//return 0;

	//// �ڽ�(��ư)�� ������ �޼���
	//case WM_COMMAND:
	//	switch (LOWORD(wParam)) // �ڽ� ID
	//	{
	//	case 1:
	//		if (HIWORD(wParam) == BTN_LCLICK) // �����ڵ� ����
	//		{
	//			MessageBox(hwnd, TEXT("Click!!"), TEXT(""), MB_OK);
	//		}
	//		break;
	//	}
	//	return 0;

	//case WM_CREATE:

	//	hChild = CreateWindow(TEXT("CHILD"), TEXT("�ڽ�"),
	//		WS_CHILD | WS_VISIBLE | WS_BORDER,
	//		10, 10, 100, 100,
	//		hwnd,	// �θ� ������ �ڵ�
	//		(HMENU)1, // �ڽ��� �޴��� ������ ����. ID�� ���
	//		0, 0);
	//	return 0;
	//case WM_DESTROY:
	//	PostQuitMessage(0);
	//	return 0;
	//}

	static HWND hEdit;
	switch (msg) {
	case WM_CREATE:
		hEdit = CreateWindow(TEXT("edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER,
			10, 10, 200, 200, hwnd, (HMENU)1, 0, 0);
		old = (WNDPROC)SetWindowLong(hEdit, GWL_WNDPROC, (LONG)foo);
		SetFocus(hEdit);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
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
	RegisterClassEx(&wndClassEX);		 

	wndClassEX.lpfnWndProc = ChildProc;
	wndClassEX.lpszClassName = TEXT("CHILD");
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