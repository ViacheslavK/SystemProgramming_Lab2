// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#define ID_BTNCRT_FLDS 0
#define ID_BTNDEL_FLDS 1
#define ID_BTNTRA_FLDS 2
#define ID_BTNCRE_FLDS 3
#define ID_BTNCPY_FLDS 4
#define ID_BTNSRC_FLDS 5
#define ID_BTNREA_FLDS 6
#define ID_BTNWRT_FLDS 7
#define ID_BTNBLC_FLDS 8
#define ID_BTNATT_FLDS 9

// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Files and Folders Management Lab Work");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int CALLBACK WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // Store instance handle in our global variable
    hInst = hInstance;

    // The parameters to CreateWindow explained:
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        10, 10,
        500, 370,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    HWND hwndCreateButton = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"Create folders structure",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        10, 30,        
        180, 25,        
        hWnd, (HMENU)ID_BTNCRT_FLDS,       // Event reference
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);      // Pointer not needed.

    HWND hwndDelButton = CreateWindow(
        L"BUTTON", 
        L"Delete folders structure",    
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  
        10, 60, 
        180, 25, 
        hWnd, (HMENU)ID_BTNDEL_FLDS, 
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);     

    HWND hwndDirTraversalButton = CreateWindow(
        L"BUTTON",  
        L"Go through directories",    
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
        10, 90, 
        180, 25,
        hWnd, (HMENU)ID_BTNTRA_FLDS,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);      

    HWND hwndCrtFileButton = CreateWindow(
        L"BUTTON", 
        L"Create new file",   
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
        10, 120, 
        180, 25,
        hWnd, (HMENU)ID_BTNCRE_FLDS,  
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);    

    HWND hwndCpyFilesButton = CreateWindow(
        L"BUTTON", 
        L"Copy existing files",    
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
        10, 150, 
        180, 25, 
        hWnd, (HMENU)ID_BTNCPY_FLDS, 
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);

    HWND hwndSrchSrtFilesButton = CreateWindow(
        L"BUTTON",
        L"Search and sort files",  
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
        10, 180, 
        180, 25,
        hWnd, (HMENU)ID_BTNSRC_FLDS,     
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL); 

    HWND hwndReadFileButton = CreateWindow(
        L"BUTTON", 
        L"Read from file", 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        10, 210, 
        180, 25, 
        hWnd, (HMENU)ID_BTNREA_FLDS,  
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);    

    HWND hwndWrteFileButton = CreateWindow(
        L"BUTTON", 
        L"Write to file", 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
        10, 240, 
        180, 25,
        hWnd, (HMENU)ID_BTNWRT_FLDS,     
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);    

    HWND hwndBlcFileButton = CreateWindow(
        L"BUTTON",
        L"Block file",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        10, 270, 
        180, 25, 
        hWnd, (HMENU)ID_BTNBLC_FLDS,    
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);    

    HWND hwndSetAttrFileButton = CreateWindow(
        L"BUTTON",
        L"Set attributes for file", 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
        10, 300, 
        180, 25,  
        hWnd, (HMENU)ID_BTNATT_FLDS,    
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);      

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Click on next buttons one-by-one");
    TCHAR greeting2[] = _T("Click on second button");
    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);

        // Here your application is laid out.
        // For this introduction, we just print out "Hello, Windows desktop!"
        // in the top left corner.
        TextOut(hdc,
            10, 5,
            greeting, _tcslen(greeting));
        // End application-specific layout section.

        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_BTNCRT_FLDS:
            CreateDirectoryA("..\\FILE11", NULL);
            CreateDirectoryA("..\\FILE11\\FILE12", NULL);
            CreateDirectoryA("..\\FILE11\\FILE12\\FILE13", NULL);
            CreateDirectoryA("..\\FILE21", NULL);
            CreateDirectoryA("..\\FILE21\\FILE22", NULL);
            CreateDirectoryA("..\\FILE21\\FILE22\\FILE23", NULL);
            break;
        case ID_BTNDEL_FLDS:
            RemoveDirectoryA("..\\FILE11\\FILE12\\FILE13");
            RemoveDirectoryA("..\\FILE11\\FILE12");
            RemoveDirectoryA("..\\FILE11");
            RemoveDirectoryA("..\\FILE21\\FILE22\\FILE23");
            RemoveDirectoryA("..\\FILE21\\FILE22");
            RemoveDirectoryA("..\\FILE21");
            break;
        default:
            break;
        }
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}