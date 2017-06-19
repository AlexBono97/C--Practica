// To ensure correct resolution of symbols, add Psapi.lib to TARGETLIBS
// and compile with -DPSAPI_VERSION=1

#include "stdafx.h"

#include <windows.h>
#include <conio.h>
#include <psapi.h>

#include <stdint.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <memory>

static const int buffer_size = 16;

std::string addr_to_hex_string(INT_PTR addr)
{	
	std::stringstream result;
	result << std::hex << std::uppercase << std::setfill('0');
	result << std::setw(sizeof(addr) * 2) << addr;

	return result.str();
}

std::string bytes_to_hex_string(uint8_t* buffer, SIZE_T size)
{
	std::stringstream result;
	result << std::hex << std::uppercase << std::setfill('0');

	for (; size > 0; buffer++, size--)
	{
		result << std::setw(2) << (unsigned int) *buffer;
		if (size > 1)
			result << " ";
	}

	return result.str();
}

std::string bytes_to_ascii_string(uint8_t* buffer, SIZE_T size)
{
	std::stringstream result;

	for (; size > 0; buffer++, size--)
	{
		if (*buffer >= ' ')
			result << (char) *buffer;
		else
			result << ".";
	}

	return result.str();
}

std::wstring GetAPIErrorMessage(DWORD error)
{
	LPWSTR errorText = NULL;

	FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_IGNORE_INSERTS, NULL, error,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&errorText, 0, NULL);

	std::wstring result;
	if (NULL != errorText)
	{
		result = errorText;
		LocalFree(errorText);
	}
	return result;
}

bool HasReadAccess(DWORD pid)
{
	HANDLE processHandle = OpenProcess(PROCESS_VM_READ, false, pid);
	CloseHandle(processHandle);

	return processHandle != NULL;
}

// Slightly adapted from "Enumerating All Processes" at http://msdn.microsoft.com/en-us/library/windows/desktop/ms682623%28v=vs.85%29.aspx
void PrintProcessNameAndID(DWORD processID)
{
	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
		false, processID);

	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;

		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
			GetModuleBaseName(hProcess, hMod, szProcessName,
			sizeof(szProcessName)/sizeof(TCHAR));
	}
	_tprintf(TEXT("%s  (PID: %u)\n"), szProcessName, processID);

	CloseHandle(hProcess);
}

// Slightly adapted from "Enumerating All Processes" at http://msdn.microsoft.com/en-us/library/windows/desktop/ms682623%28v=vs.85%29.aspx
bool PrintProcessList()
{
	DWORD processesIDs[1024], cbNeeded;

	if (!EnumProcesses(processesIDs, sizeof(processesIDs), &cbNeeded))
		return false;

	DWORD cProcesses = cbNeeded / sizeof(DWORD);

	for (int i = 0; i < cProcesses; i++)
		if (processesIDs[i] != 0 && HasReadAccess(processesIDs[i]))
			PrintProcessNameAndID(processesIDs[i]);

	return true;
}

const char* testtext = "sometest\7A B C\t\n";

int _tmain(int argc, _TCHAR* argv[])
{
	if (PrintProcessList())
	{
		std::cout << "\nTest data address for current process (PID: " << GetCurrentProcessId() << "): 0x" << (void*)testtext << std::endl;

		std::cout << "\nChoose one of the above PIDs: ";

		DWORD pid = 0;
		std::cin >> pid;
		if (pid == 0)
			pid = GetCurrentProcessId();

		INT_PTR foreignProcessAddress;
		std::cout << "Read " << buffer_size << " bytes starting at address: ";
		std::cin >> std::hex >> foreignProcessAddress;
		if (pid == GetCurrentProcessId() && foreignProcessAddress == 0)
			foreignProcessAddress = (INT_PTR) testtext;

		uint8_t buffer[buffer_size];
		SIZE_T bytesRead;

		{
			std::cout << std::endl;

			HANDLE processHandle = OpenProcess(PROCESS_VM_READ, false, pid);
			// RAII - execute CloseHandle(processHandle) when block is left
			std::shared_ptr<void> managed_processHandle(processHandle, &CloseHandle);

			if (ReadProcessMemory(processHandle, (LPCVOID)foreignProcessAddress, buffer, buffer_size, &bytesRead))
				std::cout << addr_to_hex_string(foreignProcessAddress) << "  " << bytes_to_hex_string(buffer, bytesRead) << "  " << bytes_to_ascii_string(buffer, bytesRead) << std::endl;
			else
				std::wcout << "Error reading process memory: " << GetAPIErrorMessage(GetLastError()) << std::endl;
		}
	}
	else
		std::cout << "Could not enumerate processes. Try running as administrator.\n";

	std::cout << std::endl << "Press any key to exit...\n";
	_getch();

	return 0;
}
