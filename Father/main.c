#define _CRT_SECURE_NO_WARNINGS
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
	int i = 0;
	int size_of_message_file;
	int num_of_Son_processes_required;

	char* command_line_string;

	char* command_line_arguments[NUMBER_OF_ARGUMENTS_TO_PASS_TO_SON + 1];

	for (int j = 0; j < NUMBER_OF_ARGUMENTS_TO_PASS_TO_SON + 1; ++j) {

		command_line_arguments[j] = malloc(MAX_LENGTH_OF_PATH_TO_A_FILE  *sizeof(char));

		if (command_line_arguments[j] == NULL) {
			printf("Error! memory not allocated to command_line_arguments.\n");
			exit(1);
		}
	}
	

	strcpy(command_line_arguments[0] , "Son.exe");
	strcpy(command_line_arguments[1], argv[1]);
	strcpy(command_line_arguments[2], "0");
	strcpy(command_line_arguments[3] , argv[2]);

	//printf("%s", concatenate_command_line_arguments_into_a_string(NUMBER_OF_ARGUMENTS_TO_PASS_TO_SON+1, command_line_arguments));
	
	//get size of message_file
	
	size_of_message_file = return_numbers_of_chars_in_file(argv[1]);
	
	//get the needed number of iterations needed by size_of_message_file/16
	 
	num_of_Son_processes_required = size_of_message_file / 16;
	
	//perform a for loop where each iteration Son.exe is created with the correct offset argument.

	for (i = 0; i < num_of_Son_processes_required; ++i) {


		// create the correct command line argument string, with the new offset
		char offset_str[MAX_LENGTH_OF_PATH_TO_A_FILE];

		sprintf(offset_str, "%d", offset);

		strcpy(command_line_arguments[2], offset_str);

		command_line_string= concatenate_command_line_arguments_into_a_string(NUMBER_OF_ARGUMENTS_TO_PASS_TO_SON + 1, command_line_arguments);
	

		//Exitcode of son is checked
		int son_exit_code;

		//create Son process
		son_exit_code= CreateProcessSimpleMain(command_line_string, TIMEOUT_IN_MILLISECONDS);

		free(command_line_string);

		if (son_exit_code != 0) {

			printf("Son.exe failed with exit code number %d, closing the program.", son_exit_code);
			exit(1);

		}
			
			offset = offset + 16;
	}


	

	
	for (int j = 0; j < NUMBER_OF_ARGUMENTS_TO_PASS_TO_SON + 1; ++j) {

		free(command_line_arguments[j]);

		
	}
	

	

} 


