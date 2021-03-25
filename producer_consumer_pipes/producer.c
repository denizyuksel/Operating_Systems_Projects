#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <time.h>

#define N 1000
// N CHARACTERS WILL BE READ AT A TIME.
int main( int argc, char *argv[])
{
	if( argc == 2)
	{
		srand(time(NULL));
		char allChars[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int M = atoi(argv[1]);
		char charGroup[M];
		int i = 0;
		int charCounter = 0;
		//edge case:
		
		if(N > M)
		{
			for( i = 0; i < N	; i++)
			{
				char randomChar = allChars[rand() % (sizeof(allChars) - 1)];
				charGroup[i] = randomChar;
			}
			write(1, charGroup, M);		
			printf("\n");
		}
		
		else{
	//write random chars N by N...
			for( charCounter = 0; charCounter < M; charCounter = charCounter + N)
			{
				for(i = 0; i < N; i++)
				{
					charGroup[i] = allChars[rand() % (sizeof(allChars) - 1)];
				}
				write(1, charGroup, N);
				
			}
		/*	
		int excess = M % N;
		char remChars[excess];		
		for(i = 0; i < excess; i++) {
			remChars[i] = allChars[rand() % (sizeof(allChars) -1)];		
		}
		//write the excess chars here.
		write(1, charGroup, excess);
		*/
		printf("\n");
		}	
	}
	return 0;
}
