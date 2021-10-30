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
	const wchar_t TARGET_FILE[] = L"./Encrypted_message.txt";
	OVERLAPPED offset_bytes;
	LPDWORD num_of_bytes_written=NULL;
	offset_bytes.Offset = atoi(argv[2]);// accourding to instruction the first arg is the offset val
	offset_bytes.OffsetHigh = 0;
	char* Key = NULL;
	char* EncryptedMessage = NULL;
	char* Message = NULL;

	//char* FileName = argv[1];// accourding to instruction the first arg is the file path
	
	//char* KeyFileName = argv[3];
	//char* Message = NULL;
	char test_[] = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";



	// just for test delete later
	//---------#############TEST#############################---------
	char FileName[] =  "./plaintext.txt";
	int OffSet = 16;
	char KeyFileName[] = ". / key.txt";
	
	EncryptMessage(&Key, &Message, NUM_OF_BYTES_TO_WRITE, &EncryptedMessage);
	printf("EncryptedMessage = %s \n", EncryptedMessage);
	WinWriteToFile(TARGET_FILE, &EncryptedMessage, NUM_OF_BYTES_TO_WRITE);

	


	return 0;

}

void EncryptMessage(char** key, char** message, int length, char** encryptedMessage)
{
	int i = 0;
	char* Encrypt = NULL;
	char* Ptrkey = *key;
	char* PtrMessge = *message;
	Encrypt = malloc(sizeof(char) * length);
	/*if (NULL == strcpy(*Encrypt, *message))
	{
		printf("failed to copy string \n");
	}*/


	for (i = 0; i < length; ++i) {
		printf("message[i]= %c\n", *PtrMessge);
		Encrypt[i] = *PtrMessge ^ *Ptrkey;

		PtrMessge++;
		Ptrkey++;
	}
	printf("Encrypt= %s\n", Encrypt);

	*encryptedMessage = Encrypt;
}

/*
* write to a file using the win API lib
* based on the example from:
* https://riptutorial.com/winapi/example/5736/create-a-file-and-write-to-it
*/
int WinWriteToFile(wchar_t  pathToFile[], char** stringToAppend, int MessegeLen)
{
	// Open a handle to the file
	HANDLE hFile = CreateFile(
		(LPCTSTR)(pathToFile),     // Filename
		FILE_APPEND_DATA,          // Desired access
		FILE_SHARE_READ,        // Share mode
		NULL,                   // Security attributes
		OPEN_ALWAYS,              // Creates a new file, only if it doesn't already exist and open it if the file exsits
		FILE_ATTRIBUTE_NORMAL,  // Flags and attributes
		NULL);                  // Template file handle

	
	if (hFile == INVALID_HANDLE_VALUE || hFile == INVALID_HANDLE_VALUE)
	{
		printf("Error opening file!");
		exit(1);
	}


	//printf("%ld", *num_of_bytes_written);
	DWORD bytesWritten;
	WriteFile(
		hFile,            // Handle to the file
		(DWORD)*stringToAppend,  // Buffer to write
		MessegeLen,   // Buffer size
		stringToAppend,    // Bytes written
		NULL);         // Overlapped

	 // Close the handle once we don't need it.
	CloseHandle(hFile);
}

