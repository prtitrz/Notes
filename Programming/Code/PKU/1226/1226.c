#include <stdio.h>
#include <string.h>

int t,n;
char str[100][101];

void strrev1(char* s)
{
	int i,j;
	for (i = 0, j = strlen(s)-1; i < j; i++,--j) {
		*(s+i) ^= *(s+j);
		*(s+j) ^= *(s+i);
		*(s+i) ^= *(s+j);
	}
}

int search(char* source)
{
	int substrlen = strlen(source);
	int sourcestrlen = strlen(source);
	int i,j,found;
	char substr[101],revsubstr[101];

	while(substrlen > 0)
	{
		for (i = 0; i <= sourcestrlen-substrlen; i++) {
			strncpy(substr,source+i,substrlen);
			strncpy(revsubstr,source+i,substrlen);
			substr[substrlen] = revsubstr[substrlen] = '\0';
			strrev1(revsubstr);
			found = 1;
			for (j = 0; j < n; j++) {
				if (strstr(str[j],substr) == NULL&&strstr(str[j],revsubstr)==NULL) {
					found = 0;
					break;
				}
			}
			if (found) {
				return substrlen;
			}
		}
		substrlen--;
	}
	return 0;
}

int main(int argc, const char *argv[])
{
	int i,minstrlen,substrlen;
	char minstr[101];

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		minstrlen = 100;
		for (i = 0; i < n; i++) {
			scanf("%s",str[i]);
			if (strlen(str[i])<minstrlen) {
				strcpy(minstr,str[i]);
				minstrlen = strlen(minstr);
			}
		}
		substrlen = search(minstr);
		printf("%d\n",substrlen);
	}
	return 0;
}
