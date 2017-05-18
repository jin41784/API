#include <Windows.h>
#include <tchar.h>

	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam,
	LPARAM IParam) {

		static UINT iCount = 0;
		static char szCount[10];

		switch (iMsg) {
			case WM_LBUTTONDOWN:
			MessageBox(hWnd, TEXT("마우스 좌클릭"), TEXT ("Test"),
			MB_OK);
			break;
			case WM_DESTROY:
			MessageBox(hWnd, TEXT("X 버튼을 눌렀습니다"), TEXT("Test"),
			MB_OK);

			_itoa_s(iCount, szCount, 10);
			MessageBoxA(hWnd, szCount, "호출된 횟수", MB_OK);

			PostQuitMessage(0);
			break;

			}

		iCount += 1;

		return DefWindowProc(hWnd, iMsg, wParam, IParam);
		}

	INT APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, TCHAR
	*pszLine, INT nshow) {
		HWND hWnd;
		WNDCLASS wc;
		MSG msg;

		wc.style = CS_OWNDC;
		wc.lpfnWndProc = WndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInstance;
		wc.hIcon = LoadIcon(NULL, IDC_ICON);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		//wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
		wc.hbrBackground = CreateSolidBrush(RGB(255,0,0));
		wc.lpszMenuName = NULL;
		wc.lpszClassName = TEXT("MyApp");

		RegisterClass(&wc);

		hWnd = CreateWindow(TEXT("MyApp"), TEXT("테스트박스"),

		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

		// hWnd = CreateWindow(TEXT("MyApp"), TEXT("테스트박스"),
		//WS_POPUP, 400, 200, 600, 400, NULL, NULL, hInstance, NULL);

		ShowWindow(hWnd, SW_SHOW);

		while (GetMessage(&msg, NULL, NULL, NULL)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		}
	return 0;
}

