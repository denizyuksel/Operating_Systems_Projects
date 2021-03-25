/*
   	This is the C program experiment for 7th question.
   	Deniz Yüksel
   	21600880
   	CS 342 - 3
*/

#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]){

	int fd;
	int sz;
	int capacity = 100;
	char *buffer = (char *) calloc(capacity, sizeof(char)); 
	struct timeval startOpen, stopOpen, startWrite, stopWrite, startClose, stopClose, startOpen2, stopOpen2, startRead, stopRead;

	//Time to calculate open...
	printf("----- Open system call time calculation -----\n");
	gettimeofday(&startOpen, NULL);
	fd = open("myText.txt", O_CREAT | O_RDWR | O_EXCL, 0660);
	gettimeofday(&stopOpen, NULL);
	printf("Time elapsed for open: %ld %s", stopOpen.tv_usec - startOpen.tv_usec, "microseconds\n");
	
	char text[] = "This text piece is written to the file now. It can take at most 100 characters.\n";
	char text2[] = "New text.\n";
	
	//Time to calculate write...
	printf("----- Write system call time calculation -----\n");
	gettimeofday(&startWrite, NULL);
	write(fd, text, strlen(text));
	gettimeofday(&stopWrite, NULL);
	printf("Time elapsed for write: %ld %s", stopWrite.tv_usec - startWrite.tv_usec, "microseconds\n");
	
	
	//Time to calculate close...
	printf("----- Close system call time calculation -----\n");
	gettimeofday(&startClose, NULL);
	close(fd);
	gettimeofday(&stopClose, NULL);
	printf("Time elapsed for close: %ld %s", stopClose.tv_usec - startClose.tv_usec, "microseconds\n");

	//Time to calculate open...
	printf("----- Measuring open system call again to read -----\n");
	gettimeofday(&startOpen2, NULL);
	fd = open("myText.txt", O_RDONLY);
	gettimeofday(&stopOpen2, NULL);
	printf("Time elapsed for open: %ld %s", stopOpen2.tv_usec - startOpen2.tv_usec, "microseconds\n");
	
	//Time to calculate read...
	printf("----- Measuring read system call -----\n");
	gettimeofday(&startRead, NULL);
	sz = read(fd, buffer, capacity);
	gettimeofday(&stopRead, NULL);
	buffer[sz] = '\0';
	printf("Time elapsed for read: %ld %s", stopRead.tv_usec - startRead.tv_usec, "microseconds\n");
	
	close(fd);
	printf("The text read is: %s\n", buffer);
	printf("Reached at the end!\n");
	return 0;
}
