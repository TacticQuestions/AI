#include <windows.h>

LRESULT CALLBACK WindowProcidure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor =  LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"AIClass";
    wc.lpfnWndProc = WindowProcidure;

    if(!RegisterClassW(&wc))
    {
        return -1;
    }

    CreateWindowW(L"AIClass", L"AI", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 200,200,500,500,NULL,NULL,NULL,NULL);
    MSG msg = {0};
    while( GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProcidure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch ( msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}