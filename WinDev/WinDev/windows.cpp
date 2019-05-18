
#include <Windows.h>			
#include <tchar.h>			// T 매크로 

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First");		// const char *lpszClass = "First"; 헝가리안 표기법(ㅋㅋ) sz: 끝문자가 '\0'인 string을 의미

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdParam, int nCmdShow) { 
	// _tWinMain : (MBCS)WinMain, (UNICODE)wWinMain
	// LPTSTR lpszCmdParam(char * or wchar_t *) : 명령행인자 받는 변수
	// WINAPI : Windows의 함수호출 방식(__stdcall) 
	// int nCmdShow: 윈도우를 어떻게 띄워줄지
	HWND hWnd;			// HWND => 윈도우핸들에 대한 타입
	MSG Message;		
	WNDCLASSEX WndClass;		// 윈도우(창)의 각종 속성을 담는 객체(색, 크기 등)
	g_hInst = hInstance;

	// 윈도우클래스의 정보담기
	WndClass.cbClsExtra = 0;	// 일종의 Future Use용(나중에 사용하려고 미리 만들어놓은 것)
	WndClass.cbWndExtra = 0;    // 일종의 Future Use용(나중에 사용하려고 미리 만들어놓은 것)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// hbrBackground(Background Brush Handle)
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		// Cursor Handle, IDC_ARROW(ID Cursur Arrow)
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// IDI_APPLICATION(ID Icon ...)
	WndClass.hInstance = hInstance;		
	WndClass.lpfnWndProc = WndProc;		// lpfn(함수포인터)WndProc : 윈도우 프로시저 함수(아래의 WndProc)에 대한 포인터 받음 => WndProc함수는 개발자간의 표준이름
	WndClass.lpszClassName = lpszClass;	
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;	// 가로나 세로가 사이즈가 변경될 때마다 새로 reDraw 한다(OR연산? bit값이구나)
	WndClass.hIconSm = 0;		// small icon => 현재 사용X
	WndClass.cbSize = sizeof(WNDCLASSEX);		// 현재의 윈도우가 구/신버전인지 알아보기 위해 size체크하는 과정
	
	RegisterClassEx(&WndClass);		// 윈도우 등록
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, (HMENU)NULL, hInstance, NULL);
	// 윈도우 만들어서 해당 객체의 핸들값 리턴!
	// ATOM CreateWindow(lpszClassName, lpszWindowName, dwStyle, x, y, nWidth, nHeight, hwndParent, hmenu, hInst, lpvParam);
	// ATOM타입: 절대로 중복되지 않는 값임을 보장한다는 의미의 타입 => 핸들값은 절대로 중복되지 않으니까 사용가능
	// lpszClassName : 윈도우클래스명
	// lpszWindowName : 타이틀바 표시명
	// dwStyle :윈도우 스타일
	// x, y, nWidth, nHeight: 윈도우 위치, 크기정보
	// hwndParent: 부모 윈도우 핸들(NULL: 데스크탑을 부모로 가짐, 바탕화면 어디든지 위치가능)
	// hmenu: 윈도우에서 사용할 메뉴핸들(윈도우클래스에서 지정한 메뉴사용시 NULL)
	// hInst: 윈도우를 생성하는 주체
	// lpvParam:
	ShowWindow(hWnd, nCmdShow);	// 윈도우 표시! 쨔잔
	//UpdateWindow(hWnd);		// 지금은 필요없는 코드(윈도우메시지 관련)

	// 만든 윈도우에게 발생하는 메시지들을 수행하는 곳
	while (GetMessage(&Message, NULL, 0, 0)) { // 받은 메시지들을 보관하는 메시지큐에서 메시지를 하나씩 꺼내오는 역할
		TranslateMessage(&Message);
		DispatchMessage(&Message);		// 내부적으로, 꺼낸 메시지를 WndProc의 iMessge로 전달하여 수행
	}

	return (int)Message.wParam;		// 줘도 그만 안줘도 그만 return 0해도 됨(무엇)
}

// CALLBACK:  우리가 직접 호출하는 게 아니라,내부에서 작업하는 과정에서 호출되는 함수라는 의미
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM sParam, LPARAM lParam) {
	switch (iMessage) {// 결국 윈도우프로그래밍이란, 이 case별로 메시지를 처리하는 것.
	case WM_DESTROY:				// 닫기버튼 눌렀을때 발생하는 메시지
		PostQuitMessage(0);			// 위 while문을 종료하게 만들어줌 (꼭 넣어줘야 함)
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, sParam, lParam));		// 처리하지 않을 메시지는 DefWindowProc로 보내서 여기서 정의된대로(디폴트정의대로) 처리되도록 해야함
	// 예. 최소화버튼에 대해 정의안했지만 아래로 사라지는 기능은 수행됨
}

ATOM MyRegisterClass(HINSTANCE hInstance) {
	WNDCLASSEX WndClass;
	// 윈도우클래스의 정보담기
	WndClass.cbClsExtra = 0;	// 일종의 Future Use용(나중에 사용하려고 미리 만들어놓은 것)
	WndClass.cbWndExtra = 0;    // 일종의 Future Use용(나중에 사용하려고 미리 만들어놓은 것)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// hbrBackground(Background Brush Handle)
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		// Cursor Handle, IDC_ARROW(ID Cursur Arrow)
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// IDI_APPLICATION(ID Icon ...)
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;		// lpfn(함수포인터)WndProc : 윈도우 프로시저 함수(아래의 WndProc)에 대한 포인터 받음 => WndProc함수는 개발자간의 표준이름
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;	// 가로나 세로가 사이즈가 변경될 때마다 새로 reDraw 한다(OR연산? bit값이구나)
	WndClass.hIconSm = 0;		// small icon => 현재 사용X
	WndClass.cbSize = sizeof(WNDCLASSEX);		// 현재의 윈도우가 구/신버전인지 알아보기 위해 size체크하는 과정
	return RegisterClassEx(&WndClass);		// 윈도우 등록


}