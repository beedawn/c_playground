#include <stdio.h>
//#include <stdlib.h>
/*
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void){
char filename_str[25]="testfile.txt";
FILE* fptr;
int err=mkdir("/secret/",0755);
	printf("%d",err);

	fptr = fopen(filename_str, "a");


	if(fptr == NULL) {
		printf("This file is not opened, program will exit. Are you root?");
		return(1);

	}

		char buf[100];
		if(fscanf(fptr,"%s",buf)==0)
		{
		printf("File has been created");
		}
		
		printf("else land");
		for(int i =0;i<1000000;i++){
			fprintf(fptr,"%d",i);
		}
		
	

return 0;
}
