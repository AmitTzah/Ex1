#ifndef CREATE_AND_HANDLE_PROCESSES_H
#define CREATE_AND_HANDLE_PROCESSES_H
#include <windows.h>

DWORD CreateProcessSimpleMain(LPSTR command_line_arguments_to_run, int time_out_in_ms);

#endif