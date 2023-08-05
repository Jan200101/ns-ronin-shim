#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define ARRAY_LEN(arr) sizeof(arr) / sizeof(arr[0])

bool (*InitialiseRonin)() = NULL;

__declspec(dllexport) bool InitialiseNorthstar()
{
    FARPROC InitialiseRonin = NULL;
    wchar_t exe_path[4096];
    wchar_t buffer[8192];
    HMODULE current_module = NULL;

    if (GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | 
            GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
            (LPCWSTR)&InitialiseNorthstar, &current_module) == 0)
    {
        int ret = GetLastError();
        fprintf(stderr, "GetModuleHandleExW failed, error = %d\n", ret);

        return false;
    }

    if (GetModuleFileNameW(current_module, exe_path, sizeof(exe_path)) == 0)
    {
        int ret = GetLastError();
        fprintf(stderr, "GetModuleFileNameW failed, error = %d\n", ret);
        return false;
    }

    {
        wchar_t* path_end = exe_path + wcslen(exe_path);
        while (*path_end != '\\') --path_end;
        *path_end = '\0';
    }

    swprintf_s(buffer, ARRAY_LEN(buffer), L"%s\\Ronin.dll", exe_path);
    HMODULE dll = LoadLibraryExW(buffer, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
    if (dll)
    {
        InitialiseRonin = GetProcAddress(dll, "InitialiseRonin");
    }

    if (!dll || InitialiseRonin == NULL)
    {
        return false;
    }

    return ((bool (*)())InitialiseRonin)();
}

