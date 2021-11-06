#include "HardCodedData.h"
#include "file_IO.h"
#include "encryption.h"

void main(int argc, char *argv[])
{
	char string_read_from_message[NUM_OF_BYTES_TO_WRITE_OR_READ + 1];//this is a null terminated string.
	char string_read_from_key[NUM_OF_BYTES_TO_WRITE_OR_READ+1]; //this is a null terminated string.
	char encrypted_message_string[NUM_OF_BYTES_TO_WRITE_OR_READ + 1]; //this is a null terminated string.

	//read key into a null terminated buffer.
	WinReadFromFile(argv[3], string_read_from_key, NUM_OF_BYTES_TO_WRITE_OR_READ, 0);
	
	printf("started son");

	//read 16 bytes from messagefile into buffer with the correct offset. 
	WinReadFromFile(argv[1], string_read_from_message, NUM_OF_BYTES_TO_WRITE_OR_READ, atoi(argv[2]));

	
	//perform xor operation with key, put the encrypted bytes into a encrypted_buffer defined in main.
	
	EncryptMessage_xor_operation(string_read_from_key, string_read_from_message, NUM_OF_BYTES_TO_WRITE_OR_READ, encrypted_message_string);



	//write this buffer to encrypted message file with the correct offset. 

	WinWriteToFile(PATH_TO_ENCRYPTION_MESSAGE_FILE, encrypted_message_string, NUM_OF_BYTES_TO_WRITE_OR_READ, atoi(argv[2]));

	
 
}
