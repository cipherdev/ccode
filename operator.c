#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * const argv[])
{
	char str1[15];
	char str2[15];
	int ret;

	memcpy(str1, "abc", 7);
	memcpy(str2, "ABCDEFa", 7);

	ret = memcmp(str1, str2, 5);

	if(ret > 0)
	{
		printf("str2 is less than str1\n");
	}
	else if(ret < 0) 
	{
		printf("str1 is less than str2\n");
	}
	else 
	{
		printf("str1 is equal to str2\n");
	}
	printf(">>>%s\n", str1);
	printf(">>>%s\n", str2);
	return(0);
}
