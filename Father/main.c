
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
	command_arguments_to_path_to_son= malloc(sizeof(char) * MAX_LENGTH_OF_PATH_TO_A_FILE);
	if (NULL == command_arguments_to_path_to_son)
	{
		printf("error alocating memory");
	}
	char* temp[MAX_LENGTH_OF_PATH_TO_A_FILE];
	//Exitcode of son is checked
	int son_exit_code;
	
	//strcpy_s(command_arguments_to_path_to_son, MAX_LENGTH_OF_PATH_TO_A_FILE, "Son.exe plaintext.txt 0 key.txt");
	
	//command_arguments_to_path_to_son= "Son.exe";
	//strcpy(command_arguments_to_path_to_son, SON_EXE_PATH_RELATIVE_TO_FATHER);
	strcpy(command_arguments_to_path_to_son, "Son.exe");
	strcat(command_arguments_to_path_to_son, " ");
	strcat(command_arguments_to_path_to_son, argv[1]);
	strcat(command_arguments_to_path_to_son," ");
	sprintf(temp, "%d", offset);
	strcat(command_arguments_to_path_to_son, temp);
	strcat(command_arguments_to_path_to_son, " ");
	strcat(command_arguments_to_path_to_son, argv[2]);
	/*
	command_arguments_to_path_to_son[0] = "Son.exe";
	command_arguments_to_path_to_son[1] = argv[1];
	command_arguments_to_path_to_son[2] = offset;
	command_arguments_to_path_to_son[3] = argv[2];
	*/

	
	NumOfCharsInFile = return_numbers_of_chars_in_file(argv[1]);
	son_exit_code = CreateProcessSimpleMain(command_arguments_to_path_to_son, TIMEOUT_IN_MILLISECONDS);
	if (son_exit_code != 0) {
		printf("procces creation failed");
	}
	free(command_arguments_to_path_to_son);
	
	

} 


