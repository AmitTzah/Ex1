#include "file_IO.h"
#include <stdio.h>
#include < stddef.h >
#include <stdlib.h>
#include <Windows.h>



/// <summary>
/// 
/// <Function to read from a given file with given offset>
/// <param name="pathToFile"></path to file to be read >
/// <param name="buffer_for_bytes_read"></the buffer to read into the bytes. Null terminated.>
/// <param name="num_of_bytes_to_read"></Number of bytes that will be read from offset>
/// <param name="read_from_offset"></offset from which to start reading>
/// <returns></returns the number of bytes that were read>
/// 


//based on the example from :
/*
https://riptutorial.com/winapi/example/5736/create-a-file-and-write-to-it

*/

int WinReadFromFile(char* pathToFile, char* buffer_for_bytes_read, int num_of_bytes_to_read, int read_from_offset)
{
	

	OVERLAPPED offset_bytes;
	DWORD num_of_bytes_read;
	LPDWORD  num_of_bytes_read_pointer = &num_of_bytes_read;

	offset_bytes.Offset = read_from_offset;
	offset_bytes.OffsetHigh = 0;
	offset_bytes.hEvent = 0;



	// Open a handle to the file
	HANDLE hFile = CreateFileA(

		pathToFile,    //(LPCTSTR)(pathToFile)
		GENERIC_READ,        // Desired access
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
		printf("Error opening file %s! %d", pathToFile, error);
		exit(1);
	}

	int res;
	res = ReadFile(hFile, buffer_for_bytes_read, num_of_bytes_to_read, num_of_bytes_read_pointer, &offset_bytes);

	buffer_for_bytes_read[num_of_bytes_to_read] = '\0'; //null terminate the array of bytes read, to get a string.

	if (FALSE == res)
	{
		const int error = GetLastError();
		printf("Error reading file! %d", error);
		exit(1);
	}
	CloseHandle(hFile);

	return num_of_bytes_read;
}


//write to a file using the win API lib
//based on the example from :
/* 
https://riptutorial.com/winapi/example/5736/create-a-file-and-write-to-it 

*/ 
	
	int WinWriteToFile(char* pathToFile, char* stringToWrite, int StringLen, int write_from_offset)
{

		OVERLAPPED offset_bytes;

		offset_bytes.Offset = write_from_offset;
		offset_bytes.OffsetHigh = 0;
		offset_bytes.hEvent = 0;

		// Open a handle to the file
	HANDLE hFile = CreateFileA(
		pathToFile,   //(LPCTSTR)(pathToFile)
		GENERIC_WRITE,        // Desired access
		NULL,
		NULL, // Security attributes
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
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
		stringToWrite,  // Buffer to write
		StringLen,   // Buffer size
		&bytesWritten,    // Bytes written
		&offset_bytes);         // Overlapped

	 // Close the handle once we don't need it.
	CloseHandle(hFile);

	return bytesWritten;
}
