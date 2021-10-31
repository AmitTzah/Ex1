#include "encryption.h"
#include <stdio.h>
#include < stddef.h >
#include <stdlib.h>

/// <summary>
/// 
/// </Executing xor encryption between key and message. >
/// <param name="key"></The key of encryption, null terminated>
/// <param name="message"></The message to be encrypted by xor operation with key,null terminated.>
/// <param name="length_of_key_and_message"></Key and message should be at the same length.>
/// <param name="encryptedMessage"></the buffer to hold the encrypted message, null terminated.>


void EncryptMessage_xor_operation(char* key, char* message, int length_of_key_and_message, char* encryptedMessage) {
	int i = 0;

	/*if (NULL == strcpy(*Encrypt, *message))
	{
		printf("failed to copy string \n");
	}*/


	for (i = 0; i < length_of_key_and_message; ++i) {
		
		encryptedMessage[i] = message[i] ^ key[i];
	}

	encryptedMessage[length_of_key_and_message] = '\0';

	printf("encryptedMessage= %s\n", encryptedMessage);
}