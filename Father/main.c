
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
	int NumOfCharsInFile = 0;
	//char* command_arguments_to_path_to_son[NumberOfParameters2Pass2Son];
	char* command_arguments_to_path_to_son = NULL;
	command_arguments_to_path_to_son= malloc(sizeof(char) * MAX_LENGTH_OF_PATH_TO_A_FILE);;

	//strcpy_s(command_arguments_to_path_to_son, MAX_LENGTH_OF_PATH_TO_A_FILE, "Son.exe plaintext.txt 0 key.txt");
	
	/*
	command_arguments_to_path_to_son[0] = "Son.exe";
	command_arguments_to_path_to_son[1] = argv[1];
	command_arguments_to_path_to_son[2] = offset;
	command_arguments_to_path_to_son[3] = argv[2];
	*/

	
	NumOfCharsInFile = return_numbers_of_chars_in_file(command_arguments_to_path_to_son[1]);
	CreateProcessSimpleMain(&command_arguments_to_path_to_son, TIMEOUT_IN_MILLISECONDS);
	

} 


