/**
  ******************************************************************************
  * @file           : main.cpp
  * @author         : ethan
  * @brief          : rebuild process
  * @attention      : windows
  * @date           : 2024/7/26
  ******************************************************************************
  */
#include <windows.h>
#include <vector>
#include <iostream>
#include <string>

// for Process32First, Process32Next
#include <tlhelp32.h>

// 服务端程序的名称
const std::string SERVICE_NAME = "MeshServer.exe";
std::string SERVICE_PATH = R"(E:\C++pro\libhvtest\cmake-build-release\libhvtest.exe )"; //空格需要
// 检查间隔，单位为毫秒
const int CHECK_INTERVAL = 5000;

bool IsProcessRunning(const std::string &processName) {
    bool exists = false;
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 13832);
    if (Process32First(snapshot, &entry)) {
        while (Process32Next(snapshot, &entry)) {
            if (std::string(reinterpret_cast<const char *const>(entry.szExeFile)) == processName) {
                exists = true;
                break;
            }
        }
    }

    CloseHandle(snapshot);
    return exists;
}


void StartService() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(
            nullptr, // No module name (use command line)
            reinterpret_cast<LPWSTR>((LPSTR) SERVICE_PATH.c_str()), // Command line
            nullptr, // Process handle not inheritable
            nullptr, // Thread handle not inheritable
            FALSE, // Set handle inheritance to FALSE
            0, // No creation flags
            nullptr, // Use parent's environment block
            nullptr, // Use parent's starting directory
            &si, // Pointer to STARTUPINFO structure
            &pi) // Pointer to PROCESS_INFORMATION structure
            ) {
        std::cerr << "CreateProcess failed (" << GetLastError() << ")." << std::endl;
        return;
    }

    // Close process and thread handles.
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

[[noreturn]] void Watchdog() {
    while (true) {
        if (!IsProcessRunning(SERVICE_NAME)) {
            std::cout << "Service is not running. Restarting..." << std::endl;
            StartService();
        }
        Sleep(CHECK_INTERVAL);
    }
}


int main(int argc, char *argv[]) {
    std::vector<std::string> args(argv + 1, argv + argc);
    for (const std::string &x: args) {
        SERVICE_PATH.append(x + " ");
    }
    Watchdog();
}