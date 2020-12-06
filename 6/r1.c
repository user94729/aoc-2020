
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


#ifdef _WIN32
typedef long long ssize_t;
ssize_t getline(char** buf, size_t* len, FILE* stream);
#endif


int main(){
	FILE* fptr = fopen("input", "r");
	int currentNum = 0;
	if(!fptr){
		return 1;
	}

	char* line = malloc(28);
	size_t bufLen = 28;
	ssize_t lineLen = 0;

	int sum = 0;
	uint8_t cgroup[26];
	memset(cgroup, 0, 26);
	int cgroupSize = 0;
	while((lineLen = getline(&line, &bufLen, fptr)) >= 0){
		if(lineLen > 1){
			for(int i = 0; i < lineLen - 1; i++){
				if(line[i] >= 97 && line[i] <= 122)
					cgroup[line[i] - 97]++;
			}
			cgroupSize++;
		}else{
			for(int i = 0; i < 26; i++){
#ifdef PART2
				if(cgroup[i] == cgroupSize)
#else
				if(cgroup[i])
#endif
					sum++;
			}
			memset(cgroup, 0, 26);
			cgroupSize = 0;
		}
	}
	printf("%d\n", sum);
	
	fclose(fptr);
}

#ifdef _WIN32
// LIMITED implementation of getline() for windows
ssize_t getline(char** buf, size_t* len, FILE* stream){
	if(!buf || !*buf || !len || !*len || !stream){
		errno = EINVAL;
		return -1;
	}
	ssize_t i = 0;
	for(; i < *len - 1;){
		char c = getc(stream);
		if(ferror(stream) || (c == EOF && i == 0) /* nothing to read */)
			return -1;
		if(c == EOF)
			break;
		(*buf)[i++] = c;
		if(c == '\n')
			break;
	}
	(*buf)[i] = 0;
	return i;
}
#endif

