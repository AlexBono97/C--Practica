#include <iostream>
#define WINVER 0x0500
#define _WIN32_WINNT 0x0600

#include "windows.h"
#include <psapi.h>
#include "reason.h"

using namespace std;

//BOOL WINAPI GetProcessMemoryInfo( _In_ HANDLE Process, _Out_ PPROCESS_MEMORY_COUNTERS ppsmemCounters, _In_ DWORD cb);

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
