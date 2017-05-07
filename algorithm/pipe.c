#include <stdio.h>
#include <stdlib.h>

//  read file
void main() {
	FILE *in_file;
	int readCount, buf[80];
	in_file = fopen("mypipe", "r");
	if (in_file == NULL) {
		printf("Failed ot open file!");
		exit(-1);
	}
	while((readCount = fread(in_file, 1, 80, buf))>0) {
		printf("received from the pipe, %s", buf);
	}
	fclose(in_file);
}


	
