
#include <Windows.h>			
#include <tchar.h>			// T ��ũ�� 

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First");		// const char *lpszClass = "First"; �밡���� ǥ���(����) sz: �����ڰ� '\0'�� string�� �ǹ�

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdParam, int nCmdShow) { 
	// _tWinMain : (MBCS)WinMain, (UNICODE)wWinMain
	// LPTSTR lpszCmdParam(char * or wchar_t *) : ��������� �޴� ����
	// WINAPI : Windows�� �Լ�ȣ�� ���(__stdcall) 
	// int nCmdShow: �����츦 ��� �������
	HWND hWnd;			// HWND => �������ڵ鿡 ���� Ÿ��
	MSG Message;		
	WNDCLASSEX WndClass;		// ������(â)�� ���� �Ӽ��� ��� ��ü(��, ũ�� ��)
	g_hInst = hInstance;

	// ������Ŭ������ �������
	WndClass.cbClsExtra = 0;	// ������ Future Use��(���߿� ����Ϸ��� �̸� �������� ��)
	WndClass.cbWndExtra = 0;    // ������ Future Use��(���߿� ����Ϸ��� �̸� �������� ��)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// hbrBackground(Background Brush Handle)
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		// Cursor Handle, IDC_ARROW(ID Cursur Arrow)
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// IDI_APPLICATION(ID Icon ...)
	WndClass.hInstance = hInstance;		
	WndClass.lpfnWndProc = WndProc;		// lpfn(�Լ�������)WndProc : ������ ���ν��� �Լ�(�Ʒ��� WndProc)�� ���� ������ ���� => WndProc�Լ��� �����ڰ��� ǥ���̸�
	WndClass.lpszClassName = lpszClass;	
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;	// ���γ� ���ΰ� ����� ����� ������ ���� reDraw �Ѵ�(OR����? bit���̱���)
	WndClass.hIconSm = 0;		// small icon => ���� ���X
	WndClass.cbSize = sizeof(WNDCLASSEX);		// ������ �����찡 ��/�Ź������� �˾ƺ��� ���� sizeüũ�ϴ� ����
	
	RegisterClassEx(&WndClass);		// ������ ���
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, (HMENU)NULL, hInstance, NULL);
	// ������ ���� �ش� ��ü�� �ڵ鰪 ����!
	// ATOM CreateWindow(lpszClassName, lpszWindowName, dwStyle, x, y, nWidth, nHeight, hwndParent, hmenu, hInst, lpvParam);
	// ATOMŸ��: ����� �ߺ����� �ʴ� ������ �����Ѵٴ� �ǹ��� Ÿ�� => �ڵ鰪�� ����� �ߺ����� �����ϱ� ��밡��
	// lpszClassName : ������Ŭ������
	// lpszWindowName : Ÿ��Ʋ�� ǥ�ø�
	// dwStyle :������ ��Ÿ��
	// x, y, nWidth, nHeight: ������ ��ġ, ũ������
	// hwndParent: �θ� ������ �ڵ�(NULL: ����ũž�� �θ�� ����, ����ȭ�� ������ ��ġ����)
	// hmenu: �����쿡�� ����� �޴��ڵ�(������Ŭ�������� ������ �޴����� NULL)
	// hInst: �����츦 �����ϴ� ��ü
	// lpvParam:
	ShowWindow(hWnd, nCmdShow);	// ������ ǥ��! ¹��
	//UpdateWindow(hWnd);		// ������ �ʿ���� �ڵ�(������޽��� ����)

	// ���� �����쿡�� �߻��ϴ� �޽������� �����ϴ� ��
	while (GetMessage(&Message, NULL, 0, 0)) { // ���� �޽������� �����ϴ� �޽���ť���� �޽����� �ϳ��� �������� ����
		TranslateMessage(&Message);
		DispatchMessage(&Message);		// ����������, ���� �޽����� WndProc�� iMessge�� �����Ͽ� ����
	}

	return (int)Message.wParam;		// �൵ �׸� ���൵ �׸� return 0�ص� ��(����)
}

// CALLBACK:  �츮�� ���� ȣ���ϴ� �� �ƴ϶�,���ο��� �۾��ϴ� �������� ȣ��Ǵ� �Լ���� �ǹ�
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM sParam, LPARAM lParam) {
	switch (iMessage) {// �ᱹ ���������α׷����̶�, �� case���� �޽����� ó���ϴ� ��.
	case WM_DESTROY:				// �ݱ��ư �������� �߻��ϴ� �޽���
		PostQuitMessage(0);			// �� while���� �����ϰ� ������� (�� �־���� ��)
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, sParam, lParam));		// ó������ ���� �޽����� DefWindowProc�� ������ ���⼭ ���ǵȴ��(����Ʈ���Ǵ��) ó���ǵ��� �ؾ���
	// ��. �ּ�ȭ��ư�� ���� ���Ǿ������� �Ʒ��� ������� ����� �����
}

ATOM MyRegisterClass(HINSTANCE hInstance) {
	WNDCLASSEX WndClass;
	// ������Ŭ������ �������
	WndClass.cbClsExtra = 0;	// ������ Future Use��(���߿� ����Ϸ��� �̸� �������� ��)
	WndClass.cbWndExtra = 0;    // ������ Future Use��(���߿� ����Ϸ��� �̸� �������� ��)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// hbrBackground(Background Brush Handle)
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		// Cursor Handle, IDC_ARROW(ID Cursur Arrow)
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// IDI_APPLICATION(ID Icon ...)
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;		// lpfn(�Լ�������)WndProc : ������ ���ν��� �Լ�(�Ʒ��� WndProc)�� ���� ������ ���� => WndProc�Լ��� �����ڰ��� ǥ���̸�
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;	// ���γ� ���ΰ� ����� ����� ������ ���� reDraw �Ѵ�(OR����? bit���̱���)
	WndClass.hIconSm = 0;		// small icon => ���� ���X
	WndClass.cbSize = sizeof(WNDCLASSEX);		// ������ �����찡 ��/�Ź������� �˾ƺ��� ���� sizeüũ�ϴ� ����
	return RegisterClassEx(&WndClass);		// ������ ���


}