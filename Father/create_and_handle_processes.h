#ifndef CREATE_AND_HANDLE_PROCESSES_H
#define CREATE_AND_HANDLE_PROCESSES_H
#include <windows.h>

DWORD CreateProcessSimpleMain(LPSTR command_line_arguments_to_run, int time_out_in_ms);
char* concatenate_command_line_arguments_into_a_string(int num_of_arguments, char* arguments_array[]);

#endif