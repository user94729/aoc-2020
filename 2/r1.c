
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


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
		int count = 0;
		int pwlen = strlen(ptr);
		for(int j = 0; j < pwlen; j++){
			if(ptr[j] == ch)
				count++;
		}
		if(count <= max && count >= min)
			valid++;
		printf("%d %d %c %s %d\n", min, max, ch, ptr, count);
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





