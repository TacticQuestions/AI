#include <windows.h> // inculdes windows32 api

LRESULT CALLBACK WindowProcidure(HWND, UINT, WPARAM, LPARAM); // reserves the main procedure function

int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSW wc = {0}; // Stores the Properties of the Window
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor =  LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"AIClass";
    wc.lpfnWndProc = WindowProcidure;

    if(!RegisterClassW(&wc)) // checks if program is not working correctly
    {
        return -1; // exists program
    }

    CreateWindowW(L"AIClass", L"AI", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 200,200,500,500,NULL,NULL,NULL,NULL); // The major window that is shown
    MSG msg = {0};
    while( GetMessage(&msg, NULL, 0, 0) > 0) // loops until it gets exit command so window doesnt close
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
    case WM_DESTROY: // Checks for exit command
        PostQuitMessage(0); 
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp); //Checks for any message in the console
    }
    return 0;
}