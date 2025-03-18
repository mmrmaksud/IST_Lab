//Write a C program that creates two children and connects the standard output of one to the standard input of the other using the pipe() system call.

#include <windows.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int main() {
    HANDLE hReadPipe, hWritePipe;
    SECURITY_ATTRIBUTES saAttr;
    PROCESS_INFORMATION pi1, pi2;
    STARTUPINFO si1, si2;
    char buffer[BUFFER_SIZE];
    DWORD dwRead, dwWritten;

    // Set up security attributes for the pipe
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE; // Handles are inherited by child processes
    saAttr.lpSecurityDescriptor = NULL;

    // Create a pipe
    if (!CreatePipe(&hReadPipe, &hWritePipe, &saAttr, 0)) {
        fprintf(stderr, "CreatePipe failed. Error: %lu\n", GetLastError());
        return 1;
    }

    // Set up the first child process (writes to the pipe)
    ZeroMemory(&pi1, sizeof(PROCESS_INFORMATION));
    ZeroMemory(&si1, sizeof(STARTUPINFO));
    si1.cb = sizeof(STARTUPINFO);
    si1.hStdOutput = hWritePipe; // Redirect stdout to the write end of the pipe
    si1.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    si1.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
    si1.dwFlags |= STARTF_USESTDHANDLES;

    if (!CreateProcess(
            NULL,           // No module name (use command line)
            "cmd.exe /c more", // Command to execute (reads from stdin)
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
            TRUE,           // Handles are inherited
            0,              // No creation flags
            NULL,           // Use parent's environment block
            NULL,           // Use parent's starting directory
            &si1,           // Pointer to STARTUPINFO structure
            &pi1           // Pointer to PROCESS_INFORMATION structure
        )) {
        fprintf(stderr, "CreateProcess failed for Child 1. Error: %lu\n", GetLastError());
        return 1;
    }

    // Set up the second child process (reads from the pipe)
    ZeroMemory(&pi2, sizeof(PROCESS_INFORMATION));
    ZeroMemory(&si2, sizeof(STARTUPINFO));
    si2.cb = sizeof(STARTUPINFO);
    si2.hStdInput = hReadPipe; // Redirect stdin to the read end of the pipe
    si2.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    si2.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    si2.dwFlags |= STARTF_USESTDHANDLES;

    if (!CreateProcess(
            NULL,           // No module name (use command line)
            "cmd.exe /c more", // Command to execute (reads from stdin)
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
            TRUE,           // Handles are inherited
            0,              // No creation flags
            NULL,           // Use parent's environment block
            NULL,           // Use parent's starting directory
            &si2,           // Pointer to STARTUPINFO structure
            &pi2           // Pointer to PROCESS_INFORMATION structure
        )) {
        fprintf(stderr, "CreateProcess failed for Child 2. Error: %lu\n", GetLastError());
        return 1;
    }

    // Close unused pipe ends in the parent process
    CloseHandle(hWritePipe);
    CloseHandle(hReadPipe);

    // Get user input
    printf("Enter some text: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Write user input to the pipe
    if (!WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), buffer, strlen(buffer), &dwWritten, NULL)) {
        fprintf(stderr, "WriteFile failed. Error: %lu\n", GetLastError());
        return 1;
    }

    // Wait for both child processes to finish
    WaitForSingleObject(pi1.hProcess, INFINITE);
    WaitForSingleObject(pi2.hProcess, INFINITE);

    // Close process and thread handles
    CloseHandle(pi1.hProcess);
    CloseHandle(pi1.hThread);
    CloseHandle(pi2.hProcess);
    CloseHandle(pi2.hThread);

    printf("Parent process: Both children have finished.\n");

    return 0;
}