#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tchar.h> 
#include <stdio.h>
#include <atlstr.h>
#include <strsafe.h>

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

void DisplayErrorBox(LPTSTR lpszFunction);
std::wstring s2ws(const std::string& s);

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
    HANDLE hFile;
    TCHAR greeting[] = _T("Click on next buttons one-by-one");
    TCHAR greeting2[] = _T("Click on second button");

    WIN32_FIND_DATA ffd;
    LARGE_INTEGER filesize;
    TCHAR szDir[MAX_PATH];
    size_t length_of_arg;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    DWORD dwError = 0;

    LPCWSTR searchFolder = L"D:\\CopyTest\\*";
    LPCSTR target_folder = "..\\FILE11\\FILE12";
    LPCSTR source;
    LPCSTR target;

    std::string filename;

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
            CreateDirectoryA(target_folder, NULL);
            CreateDirectoryA("..\\FILE11\\FILE12\\FILE13", NULL);
            CreateDirectoryA("..\\FILE21", NULL);
            CreateDirectoryA("..\\FILE21\\FILE22", NULL);
            CreateDirectoryA("..\\FILE21\\FILE22\\FILE23", NULL);
            break;
        case ID_BTNDEL_FLDS:
            RemoveDirectoryA("..\\FILE11\\FILE12\\FILE13");
            RemoveDirectoryA(target_folder);
            RemoveDirectoryA("..\\FILE11");
            RemoveDirectoryA("..\\FILE21\\FILE22\\FILE23");
            RemoveDirectoryA("..\\FILE21\\FILE22");
            RemoveDirectoryA("..\\FILE21");
            break;
        case ID_BTNTRA_FLDS:
            break;
        case ID_BTNCRE_FLDS:
            hFile = CreateFileA("..\\FILE11\\FILE12\\zero.txt",
                GENERIC_READ | GENERIC_WRITE, // open for writing 
                0, // do not share 
                0, // default security 
                CREATE_NEW, // overwrite existing 
                0, // normal file 
                0); // no attr. Template
            break;
        case ID_BTNCPY_FLDS:
            // Init search
            hFind = FindFirstFile(searchFolder, &ffd);
            
            // If search folder is invalid - return error
            if (INVALID_HANDLE_VALUE == hFind)
            {
                DisplayErrorBox(LPTSTR("FindFirstFile"));
                return dwError;
            }

            // Execute search
            do
            {
                if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                {
                    _tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);
                    CopyFile(ffd.cFileName, L"..\\FILE11\\FILE12\\1.txt", TRUE);
                }
                else
                {
                    filesize.LowPart = ffd.nFileSizeLow;
                    filesize.HighPart = ffd.nFileSizeHigh;
                    _tprintf(TEXT("  %s   %ld bytes\n"), ffd.cFileName, filesize.QuadPart);
                    std::wstring ws(ffd.cFileName);
                    std::string temp_source = "D:\\CopyTest\\" + std::string(ws.begin(), ws.end());
                    std::string temp_target = "..\\FILE11\\FILE12\\" + std::string(ws.begin(), ws.end());
                    std::wstring middle_source = s2ws(temp_source);
                    LPCWSTR source = middle_source.c_str();
                    std::wstring middle_target = s2ws(temp_target);
                    LPCWSTR target = middle_target.c_str();
                    CopyFile(source, target, TRUE);
                }
            } while (FindNextFile(hFind, &ffd) != 0);

            dwError = GetLastError();
            if (dwError != ERROR_NO_MORE_FILES)
            {
                DisplayErrorBox(LPTSTR("FindFirstFile"));
            }

            FindClose(hFind);
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

void DisplayErrorBox(LPTSTR lpszFunction)
{
    // Retrieve the system error message for the last-error code

    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError();

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0, NULL);

    // Display the error message and clean up

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
        (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
    StringCchPrintf((LPTSTR)lpDisplayBuf,
        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s failed with error %d: %s"),
        lpszFunction, dw, lpMsgBuf);
    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
}

std::wstring s2ws(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}