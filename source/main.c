/**
*
* @Name : RandString.C
* @Version : 1.0
* @Programmer : Max
* @Date : 2019-03-05
* @Released under : https://github.com/BaseMax/RandStringC/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/RandStringC
*
**/
#include <unistd.h>
#include <stdlib.h>
// #include <sys/types.h>
// #include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

const char *string = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *randString1(int length) {
	const size_t string_length = 62;
	char *result = malloc(sizeof(char) * (length +1));
	if(!result) {
		return (char*)0;
	}
	unsigned int key = 0;
	for(int index = 0;index<length;index++) {
		key = rand() % string_length;
		result[index] = string[key];
	}
	result[length] = '\0';
	return result;
}
char *randString2(char *result,size_t length,size_t charLimit)
{
	if (length) {
		--length;
		for (size_t index = 0;index<length;index++) {
			int key = rand() % (int) (charLimit);
			result[index] = string[key];
		}
		result[length] = '\0';
	}
	return result;
}
void randString3(char *result)
{
	int random = open("/dev/random", O_RDONLY);
	if(random >= 0)
	{
		char temp[30];
		size_t length = 0;
		while(length < sizeof temp)
		{
			ssize_t result = read(random, temp + length, (sizeof temp) - length);
			if(result >= 0)
			{
				length += result;
			}
		}
		close(random);
		strcpy(result,temp);
	}
}
int main()
{
	char* str;
	str=randString1(25);
	printf("==>%s\n",str);
	randString2(str,25,7);
	printf("==>%s\n",str);
	randString3(str);
	printf("==>%s\n",str);
	return 0;
}
