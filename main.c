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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char *randString1(int length) {
    char *string = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t string_length = 62;
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
