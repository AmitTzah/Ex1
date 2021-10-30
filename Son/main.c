#define _CRT_SECURE_NO_WARNINGS
#define NUM_OF_BYTES_TO_WRITE 16

#include <stdio.h>
#include < stddef.h >
#include <stdlib.h>
#include <Windows.h>


int main(int argc, char *argv[])
{
	HANDLE message_file;
	HANDLE Encrypted_message_file;
	
	OVERLAPPED offset_bytes;
	LPDWORD num_of_bytes_written=NULL;
	offset_bytes.Offset = 0;
	offset_bytes.OffsetHigh = 0;

	char test_[] = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";

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

	WriteFile(Encrypted_message_file, test_, NUM_OF_BYTES_TO_WRITE, num_of_bytes_written , &offset_bytes);

	printf("%ld", *num_of_bytes_written);

	return 0;

}
// test push