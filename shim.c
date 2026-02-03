#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define ARRAY_LEN(arr) sizeof(arr) / sizeof(arr[0])

static const wchar_t* paths[] = {
    L"%ls\\roninsdk.dll",
    L"%ls\\..\\roninsdk.dll",

    // Just to support old Ronin
    L"%ls\\Ronin.dll",
    L"%ls\\..\\Ronin.dll",
};

__declspec(dllexport) bool InitialiseNorthstar()
{
    FARPROC InitialiseRonin = NULL;
    wchar_t exe_path[4096];
    wchar_t buffer[8192];
    HMODULE current_module = NULL;
    HMODULE dll = NULL;

    if (GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | 
            GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
            (LPCWSTR)&InitialiseNorthstar, &current_module) == 0)
    {
        int ret = GetLastError();
        fprintf(stderr, "[ronin-shim] GetModuleHandleExW failed, error = %d\n", ret);

        return false;
    }

    if (GetModuleFileNameW(current_module, exe_path, sizeof(exe_path)) == 0)
    {
        int ret = GetLastError();
        fprintf(stderr, "[ronin-shim] GetModuleFileNameW failed, error = %d\n", ret);
        return false;
    }

    {
        wchar_t* path_end = exe_path + wcslen(exe_path);
        while (*path_end != '\\') --path_end;
        *path_end = '\0';
    }

    for (size_t i = 0; i < ARRAY_LEN(paths); ++i)
    {
        swprintf_s(buffer, ARRAY_LEN(buffer), paths[i], exe_path);
        dll = LoadLibraryExW(buffer, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
        if (!dll)
            continue;

        InitialiseRonin = GetProcAddress(dll, "InitialiseRonin");
        break;
    }

    if (!dll)
        return false;

    // Legacy Ronin is based on Northstar and has an init function
    if (InitialiseRonin)
        return ((bool (*)())InitialiseRonin)();

    // RoninSDK initializes via DllMain so no extra logic is needed
    return true;
}

