#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ParseBrackets(char* str)
{
	int k = -1;
	int count = 0;
	int lastClosed = 0;
	char open = '(';
	char closed = ')';
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i]==open)
		{
			++count;
		}
		else if (str[i] == closed)
		{
			--count;
			lastClosed = i + 1;
		}
	}
	if (count < 0)
		return lastClosed - 1;
	else if (count > 0)
		return -1;
	else
		return 0;
}

int main()
{
  char* str = (char*)malloc(1024 * sizeof(char));
	if (!str)
	{
		printf("Memory Error");
		return 0;
	}
	gets_s(str, 1024);
	printf("%d", ParseBrackets(str));
  return 0;
}
