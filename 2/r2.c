
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main(){
	FILE* fptr = fopen("input", "r");
	int currentNum = 0;
	if(!fptr){
		return 1;
	}
	fseek(fptr, 0, SEEK_END);
	int size = ftell(fptr) + 1;
	fseek(fptr, 0, SEEK_SET);
	printf("%d\n", size);
	char* data = malloc(size);
	fread(data, 1, size - 1, fptr);
	data[size] = 0;
	for(int i = 0; i < size; i++){
		if(data[i] == '\r' || data[i] == '\n')
			data[i] = 0;
	}
	int lines = 0;
	int valid = 0;
	for(int i = 0; i < size; i++){
		char* line = &data[i];
		if(!strlen(line))
			continue;
		char* ptr = line;
		int min = strtol(ptr, &ptr, 10);
		if(*ptr++ != '-'){
			goto invalid;
		}
		int max = strtol(ptr, &ptr, 10);
		if(*ptr++ != ' '){
			goto invalid;
		}
		char ch = *ptr++;
		if(*ptr++ != ':'){
			goto invalid;
		}
		ptr++; // skip space
		int pwlen = strlen(ptr);
		if(min - 1 >= pwlen || max - 1 >= pwlen)
			goto invalid;
		if((ptr[min - 1] == ch && ptr[max - 1] != ch) || (ptr[min - 1] != ch && ptr[max - 1] == ch))
			valid++;
		printf("%d %d %c %s\n", min, max, ch, ptr);
		lines++;
		goto end;
		invalid:
		printf("Invalid %d\n", i + 1);
		end:
		i += strlen(line);
	}
	printf("%d lines, %d valid\n", lines, valid);
	fclose(fptr);
}





