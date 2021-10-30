#define _CRT_SECURE_NO_WARNINGS
#define NUM_OF_BYTES_TO_WRITE 16

#undef UNICODE
#include <stdio.h>
#include < stddef.h >
#include <stdlib.h>
#include <Windows.h>
#include "main.h"


int main(int argc, char* argv[])
{
	HANDLE message_file;
	HANDLE Encrypted_message_file;
	const char TARGET_FILE[] = "./Encrypted_message.txt";
	OVERLAPPED offset_bytes;
	LPDWORD num_of_bytes_written = NULL;
	//offset_bytes.Offset = atoi(argv[2])- NUM_OF_BYTES_TO_WRITE;// accourding to instruction the first arg is the offset val and from the example
																// there is a 16 bit offset
	offset_bytes.OffsetHigh = 0;
	offset_bytes.hEvent = 0;
	char Key[NUM_OF_BYTES_TO_WRITE];
	char EncryptedMessage[NUM_OF_BYTES_TO_WRITE];
	char Message [NUM_OF_BYTES_TO_WRITE];

	//char* FileName = argv[1];// accourding to instruction the first arg is the file path

	//char* KeyFileName = argv[3];
	//char* Message = NULL;
	char test_[] = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";



	// just for test delete later
	//---------#############TEST#############################---------
	char FileName[] = "./plaintext.txt";
	offset_bytes.Offset = 0;
	char KeyFileName[] = "./key.txt";
	WinReadFromFile(&FileName, Message, NUM_OF_BYTES_TO_WRITE, offset_bytes);
	WinReadFromFile(&KeyFileName, Key, NUM_OF_BYTES_TO_WRITE, offset_bytes);
	printf("Message = %s \n", Message);
	printf("Key = %s \n", Key);
	EncryptMessage(Key, Message, NUM_OF_BYTES_TO_WRITE, EncryptedMessage);
	printf("EncryptedMessage = %s \n", EncryptedMessage);
	WinWriteToFile(TARGET_FILE, EncryptedMessage, NUM_OF_BYTES_TO_WRITE, offset_bytes);

	return 0;
}

void EncryptMessage(char* key, char* message, int length, char* encryptedMessage)
{
	int i = 0;
	
	char* Ptrkey = key;
	char* PtrMessge = message;
	/*if (NULL == strcpy(*Encrypt, *message))
	{
		printf("failed to copy string \n");
	}*/


	for (i = 0; i < length; ++i) {
		printf("message[i]= %c\n", PtrMessge[i]);
		encryptedMessage[i] = PtrMessge [i] ^ Ptrkey[i];
	}
	printf("Encrypt= %s\n", encryptedMessage);
}

/*
* write to a file using the win API lib
* based on the example from:
* https://riptutorial.com/winapi/example/5736/create-a-file-and-write-to-it
*/
int WinWriteToFile(char* pathToFile, char* stringToAppend, int MessegeLen, OVERLAPPED offset_bytes)
{
	//// Open a handle to the file
	//HANDLE hFile = CreateFileA(
	//	(LPCTSTR)(pathToFile),     // Filename
	//	FILE_APPEND_DATA,          // Desired access
	//	GENERIC_READ | GENERIC_WRITE,        // Share mode
	//	NULL,                   // Security attributes
	//	OPEN_ALWAYS,              // Creates a new file, only if it doesn't already exist and open it if the file exsits
	//	FILE_ATTRIBUTE_NORMAL,  // Flags and attributes
	//	NULL);                  // Template file handle

		// Open a handle to the file
	HANDLE hFile = CreateFileA(
		pathToFile,//(LPCTSTR)(pathToFile),     // Filename
		FILE_APPEND_DATA,        // Desired access
		NULL,
		NULL, // Security attributes
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		// Share mode
		NULL
	);


	if (hFile == INVALID_HANDLE_VALUE)
	{
		const int error = GetLastError();
		printf("WinWriteToFile Error opening file %s! %d", pathToFile, error);
		exit(1);
	}


	//printf("%ld", *num_of_bytes_written);
	DWORD bytesWritten;
	WriteFile(
		hFile,            // Handle to the file
		stringToAppend,  // Buffer to write
		MessegeLen,   // Buffer size
		&bytesWritten,    // Bytes written
		&offset_bytes);         // Overlapped

	 // Close the handle once we don't need it.
	CloseHandle(hFile);
}

//int WinReadFromFile(LPCTSTR pathToFile, char** message, int MessegeLen, OVERLAPPED offset_bytes)
int WinReadFromFile(char* pathToFile, char* message, int messageLen, OVERLAPPED offset_bytes)
{
	// Open a handle to the file
	HANDLE hFile = CreateFileA(
		pathToFile,//(LPCTSTR)(pathToFile),     // Filename
		GENERIC_READ,        // Desired access
		NULL,
		NULL, // Security attributes
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		// Share mode
		NULL
	);                  // Template file handle


	if (hFile == INVALID_HANDLE_VALUE)
	{
		const int error = GetLastError();
		printf("Error opening file %s! %d", pathToFile, error);
		exit(1);
	}

	DWORD res = SetFilePointer(hFile, offset_bytes.Offset, NULL, FILE_BEGIN);
	if (res == INVALID_SET_FILE_POINTER) {
		const int error = GetLastError();
		printf("Error setting file pointer! %d", error);
		exit(1);
	}
	DWORD bytesRead;
	 res = ReadFile(hFile, message, messageLen, &bytesRead, NULL);

	if (FALSE == res)
	{
		const int error = GetLastError();
		printf("Error reading file! %d", error);
		exit(1);
	}
	CloseHandle(hFile);

	return 0;
}