#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

char *readAll(const char* file)
{
	size_t size = 0;
	char *buffer = NULL;
	size_t result  = 0;
	if(NULL == file) {
		return NULL;
	}
	FILE *fp = fopen(file, "rb");
	if(NULL == fp) {
		return NULL;
	}
	fseek(fp, 0, SEEK_END);  //from SEEK_END offset 0
	size = ftell(fp);   // from curr position to the beginning, get the size
	rewind(fp);  //restore position pointer to the beginning
	buffer = (char *)malloc(sizeof(char) * (size+1));
	result = fread(buffer, 1, size, fp);  //  read 1*(<=size) data from fp to buffer, result is read data size
	if (size != result) {
		return NULL;
	}
	*(buffer+1+size) = '\0';
	fclose(fp);
	return buffer;
}

bool verifyResult(const char* file1, const char* file2)
{
	assert(file1!=NULL && file2!=NULL);
	char *buff1 = readAll(file1);
	char *buff2 = readAll(file2);
	return (strcmp(buff1, buff2) == 0);
}

int main()
{
	const char* file1 = "/tmp/test1.log";
	const char* file2 = "/tmp/test2.log";
	printf("%s", readAll(file1));
	printf("%s", readAll(file2));
	if(verifyResult(file1, file2)) {
		printf("file1 is same as file2");
	} else {
		printf("file1 is different with file2");
	}
	return 1;
}
