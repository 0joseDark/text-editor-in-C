#include <windows.h>
#include <commdlg.h>
#include <stdio.h>

#define ID_NEW 1
#define ID_OPEN 2
#define ID_SAVE 3
#define ID_SAVE_AS 4
#define ID_EXIT 5
#define ID_TEXTBOX 6

HWND hwndTextBox;
char currentFile[MAX_PATH] = "";

// Função para abrir um ficheiro
void OpenFile(HWND hwnd) {
    OPENFILENAME ofn;
    char fileName[MAX_PATH] = "";

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = fileName;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(fileName);
    ofn.lpstrFilter = "Text Files\0*.TXT\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn)) {
        FILE *file = fopen(fileName, "r");
        if (file) {
            char buffer[1024];
            fread(buffer, sizeof(char), sizeof(buffer) - 1, file);
            buffer[sizeof(buffer) - 1] = '\0';
            SetWindowText(hwndTextBox, buffer);
            fclose(file);
            strcpy(currentFile, fileName);
        }
    }
}

// Função para salvar num ficheiro
void SaveFile(HWND hwnd) {
    if (strlen(currentFile) == 0) {
        SaveFileAs(hwnd);
    } else {
        FILE *file = fopen(currentFile, "w");
        if (file) {
            int len = GetWindowTextLength(hwndTextBox);
            char *buffer = (char *)malloc(len + 1);
            GetWindowText(hwndTextBox, buffer, len + 1);
            fwrite(buffer, sizeof(char), len, file);
            fclose(file);
            free(buffer);
        }
    }
}

// Função para salvar como num ficheiro
void SaveFileAs(HWND hwnd) {
    OPENFILENAME ofn;
    char fileName[MAX_PATH] = "";

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = fileName;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(fileName);
    ofn.lpstrFilter = "Text Files\0*.TXT\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST;

    if (GetSaveFileName(&ofn)) {
        FILE *file = fopen(fileName, "w");
        if (file) {
            int len = GetWindowTextLength(hwndTextBox);
            char *buffer = (char *)malloc(len + 1);
            GetWindowText(hwndTextBox, buffer, len + 1);
            fwrite(buffer, sizeof(char), len, file);
            fclose(file);
            free(buffer);
            strcpy(currentFile, fileName);
        }
    }
}

// Função de callback da janela
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            hwndTextBox = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE,
                                       0, 0, 800, 600, hwnd, (HMENU)ID_TEXTBOX, NULL, NULL);
            break;
        }
        case WM_SIZE: {
            RECT rect;
            GetClientRect(hwnd, &rect);
            SetWindowPos(hwndTextBox, NULL, 0, 0, rect.right, rect.bottom, SWP_NOZORDER);
            break;
        }
        case WM_COMMAND: {
            switch (LOWORD(wParam)) {
                case ID_NEW:
                    SetWindowText(hwndTextBox, "");
                    currentFile[0] = '\0';
                    break;
                case ID_OPEN:
                    OpenFile(hwnd);
                    break;
                case ID_SAVE:
                    SaveFile(hwnd);
                    break;
                case ID_SAVE_AS:
                    SaveFileAs(hwnd);
                    break;
                case ID_EXIT:
                    PostQuitMessage(0);
                    break;
            }
            break;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// Função principal
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "TextEditor";

    RegisterClass(&wc);

    HWND hwnd = CreateWindow("TextEditor", "Editor de Texto", WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
                             NULL, NULL, hInstance, NULL);

    HMENU hMenu = CreateMenu();
    AppendMenu(hMenu, MF_STRING, ID_NEW, "Novo");
    AppendMenu(hMenu, MF_STRING, ID_OPEN, "Abrir");
    AppendMenu(hMenu, MF_STRING, ID_SAVE, "Salvar");
    AppendMenu(hMenu, MF_STRING, ID_SAVE_AS, "Salvar Como");
    AppendMenu(hMenu, MF_STRING, ID_EXIT, "Sair");
    SetMenu(hwnd, hMenu);

    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
