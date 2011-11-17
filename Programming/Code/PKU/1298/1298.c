#include <stdio.h>
#include <string.h>

void decipher(char message[]);

int main(int argc, const char *argv[])
{
	char message[201];
	gets(message);
	while (strcmp(message,"START")==0) {
		decipher(message);
		printf("%s\n",message);
		gets(message);
	}
	return 0;
}

void decipher(char message[])
{
	char plain[27] = "VWXYZABCDEFGHIJKLMNOPQRSTU";
	char cipherEnd[201];
	int i,cipherLen;
	gets(message);
	cipherLen = strlen(message);
	for (i = 0; i < cipherLen; i++) {
		if (message[i] >= 'A' &&message[i] <='Z') {
			message[i]=plain[message[i]-'A'];
		}
	}
	gets(cipherEnd);
}
