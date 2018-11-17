#include "stdio.h"
//重现的几个C标准函数，方便后面使用
size_t basic_strlen(char * str){
	size_t count = 0;
	if (str != NULL){
		for (size_t i = 0; str[i]; i++)
			count++;
		return count;
	}
	else
		return 0;
}

size_t basic_strlen(const char * str){
	size_t count = 0;
	if (str != NULL){
		for (size_t i = 0; str[i]; i++)
			count++;
		return count;
	}
	else
		return 0;
}

char *basic_strcpy(char *aim, char * str){
	char *ret = aim;
	memcpy(ret, str, basic_strlen(str) + 1);
	return ret;

}

char *basic_strcpy(char * aim, const char * str){
	char *ret = aim;
	memcpy(ret, str, basic_strlen(str) + 1);
	return ret;
}
int basic_strcmp(char * str_1, const char * str_2){
	if (basic_strlen(str_1) > basic_strlen(str_2))
		return 1;
	else if (basic_strlen(str_1) < basic_strlen(str_2))
		return -1;
	else {
		for (int i = 0; str_1[i]; i++){
			if (str_1[i] > str_2[i])
				return 1;
			else if (str_1[i] < str_2[i])
				return -1;
		}
		return 0;
	}
}

