
#include "file_IO.h"
#include "HardCodedData.h"
#include "create_and_handle_processes.h"
#include <stdio.h>
#include < stddef.h >
#include <stdlib.h>
#include <Windows.h>

void main(int argc, char* argv[])
{
	int offset = 0;
	char command_arguments_to_path_to_son[MAX_LENGTH_OF_PATH_TO_A_FILE];

	strcpy_s(command_arguments_to_path_to_son, MAX_LENGTH_OF_PATH_TO_A_FILE, "Son.exe plaintext.txt 0 key.txt");



	CreateProcessSimpleMain(command_arguments_to_path_to_son, TIMEOUT_IN_MILLISECONDS);
	

} 


