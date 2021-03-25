#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/wait.h>

#define N 1000

int main(int argc, char* argv[])
{
	if( argc == 2)
	{
		int M = atoi(argv[1]);	
		int readBytes = 0;
   	char charGroup[N];
    
   	while (readBytes < M) {
        readBytes = readBytes + read(0, charGroup, N);
    	}
	
	}
	return 0;
}

