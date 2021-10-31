#define _CRT_SECURE_NO_WARNINGS
#define NUM_OF_BYTES_TO_WRITE_OR_READ 16

#include "file_IO.h"


int main(int argc, char *argv[])
{
	char bytes_read_from_message[NUM_OF_BYTES_TO_WRITE_OR_READ + 1];//this is a null terminated string.
	char bytes_read_from_key[NUM_OF_BYTES_TO_WRITE_OR_READ+1]; //this is a null terminated string.
	char encrypted_bytes_read_from_message[NUM_OF_BYTES_TO_WRITE_OR_READ + 1];

	//read key into a null terminated buffer.
	WinReadFromFile(argv[3], bytes_read_from_key, NUM_OF_BYTES_TO_WRITE_OR_READ, 0);


	//read 16 bytes from messagefile into buffer with the correct offset. 
	WinReadFromFile(argv[1], bytes_read_from_message, NUM_OF_BYTES_TO_WRITE_OR_READ, atoi(argv[2]));

	
	//perform xor operation with key, put the encrypted bytes into a encrypted_buffer defined in main.
	// 
	// 
	//write this buffer to encrypted message file with the correct offset. 






	//testing


	printf("%s", bytes_read_from_key);


	/*  
	HANDLE message_file;
	HANDLE Encrypted_message_file;
	
	OVERLAPPED offset_bytes;
	DWORD num_of_bytes_written;
	LPDWORD  num_of_bytes_written_pointer= &num_of_bytes_written;

	offset_bytes.Offset = atoi(argv[2]);
	offset_bytes.OffsetHigh = 0;
	offset_bytes.hEvent = 0;

	char test_[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	message_file = CreateFileA(
		argv[1],
		GENERIC_READ,
		0, 
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	Encrypted_message_file = CreateFileA(
		"Encrypted_message.txt",
		GENERIC_WRITE, 
		0,
		NULL, 
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	

	if (message_file == INVALID_HANDLE_VALUE || Encrypted_message_file == INVALID_HANDLE_VALUE)
	{
		printf("Error opening file!");
		exit(1);
	}

	WriteFile(Encrypted_message_file, test_, NUM_OF_BYTES_TO_WRITE, num_of_bytes_written_pointer, &offset_bytes);

	printf("%ld", *num_of_bytes_written_pointer);

	return 0;
	*/
}
