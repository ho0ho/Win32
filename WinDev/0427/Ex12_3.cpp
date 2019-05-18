#include <Windows.h>
#include <tchar.h>
#include "resource.h"

typedef struct tagDATA {
	TCHAR str[20];
	int   num;
} DATA;

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_INITDIALOG: {	}
						return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL: EndDialog(hDlg, IDCANCEL);	return 0;
		}
		return TRUE;
	}
	return FALSE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_LBUTTONDOWN:
	{
		DATA  data = { TEXT("ȫ�浿"), 20 };
		UINT ret = DialogBoxParam(GetModuleHandle(0),// hinstance
			MAKEINTRESOURCE(IDD_DIALOG1),
			hwnd,		// �θ�
			DlgProc, // �޼��� �Լ�.
			(LPARAM)& data); // WM_INITDIALOG�� lParam�� ���޵ȴ�.
		if (ret == IDOK) {
			// ���� Dialog�� �Է��� ���� data�� �ִ�.
			TCHAR buf[128];
			wsprintf(buf, TEXT("%s / %d"), data.str, data.num);
			SetWindowText(hwnd, buf);
		}
	}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd) {
	UINT ret = DialogBox(hInst, // instance
		MAKEINTRESOURCE(IDD_DIALOG1),	// ���̾�α� ����
		0,			// �θ� ������
		DlgProc);			// Proc..
	return 0;
}