//This program creates a child process and terminates the parent process resulting in an orphan block
//

#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	int P_ID= fork(); //Creting a new process
	if(P_ID < 0){ //i.e. if it is the parent process id
		sleep(50); //Put the parent to sleep. Else, parent will enter waiting state
		printf("Parent process put to sleep");
	}
	else{
		exit(0); //Terminate the child process
		printf("\n\nChild process terminated");
	}
	return 0;
}
