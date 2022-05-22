#include <stdlib.h>
#include <string.h>

struct BigNumber
{
    char* num;
    int size;
};

struct BigNumber* BigNumberContructor(const char* num)
{
	struct BigNumber* obj = malloc(sizeof(struct BigNumber));
	if (!obj)
	{
		printf("Memory error");
		return NULL;
	}

	obj->number = malloc(strlen(num) * sizeof(char));
	if (!obj->number)
	{
		printf("memory error");
		free(obj);
		return NULL;
	}
	obj->size = strlen(num);
	obj->number[0] = 0;
  
	for (int i = 1; i < strlen(num); ++i)
		obj->number[i] = num[i];

	return obj;
}

void printBigNumber(struct BigNumber* obj)
{
	if (!obj)
	{
		printf("obj NULL");
		return;
	}
	for (int i = 0; i < obj->size; ++i)
	{
		if (obj->number[i] == -1)
			break;
		printf("%i", obj->number[i]);
	}
}

