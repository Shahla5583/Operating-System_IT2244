Q1)

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(){

printf("Program started".\n);

printf("Sleeping for 3 seconds...\n");
sleep(3);  

printf("Exiting the program\n");
exit(0);

return 0;

}

output:
[2021ict126@fedora ~]$ vi t1.c
[2021ict126@fedora ~]$ gcc t1.c -o t1
[2021ict126@fedora ~]$ ./t1
Program started.
Sleeping for 3 seconds...
Exiting the program

-------------------------------------------------

Q2)


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>


int main()
{
	pid_t pid;
	printf("Parent process started.PID: %d\n",getpid());
	
	pid=fork();
	
	if(pid<0)
	{
		perror("Fork failed");
		exit(1);
	}
	if(pid==0)
	{
		//child process
		printf("Child process.PID is:%d,sleeping for 2 seconds...\n",getpid());
		sleep(2);
		
		printf("Child process exiting.\n");
		exit(0);
	}
	else
	{
		//parent process but wait untill child process
		int status;
		printf("Parent waiting for child to finish....\n");
		wait(&status);
		// this part also a prent process
		if(WIFEXITED(status)){
			printf("Child exited with status:%d\n",WEXITSTATUS(status));
			
		}
		
		else
		{
			printf("Child did not exit normally.\n");
		}
		printf("Parent process ending...\n");
	}
	
	return 0;
	
}

-------------------------------------
[2021ict126@fedora ~]$ vi t2.c
[2021ict126@fedora ~]$ gcc t2.c -o t2
[2021ict126@fedora ~]$ ./t2
Parent process started.PID: 10230
Parent waiting for child to finish....
Child process.PID is:10231,sleeping for 2 seconds...
Child process exiting.
Child exited with status:0
Parent process ending...

Q3)
First child:Sleep for 1 second
second child:Slept for 3 seconds
Parent:Both chilren have finished


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>


int main()
{
	pid_t pid;
	printf("Parent process started.PID: %d\n",getpid());
	
	pid=fork();
	
	if(pid<0)
	{
		perror("Fork failed");
		exit(1);
	}
	if(pid==0)
	{
		//child process
		printf("Child process.PID is:%d,sleeping for 1 seconds...\n",getpid());
		sleep(1);
		
		printf("Child process exiting-1st child.\n");
		exit(0);
	}
	else
	{            
		             pid=fork();
	
	            if(pid<0)
	            {
		         perror("Fork failed");
		       exit(1);
	             }
	          if(pid==0)
	           {
		     //child process
		      printf("Child process.PID is:%d,sleeping for 3 seconds...\n",getpid());
		     sleep(3);
		
		      printf("Child process exiting-2nd.-\n");
		         exit(0);
	          }
	      else
	        {
		//parent process but wait untill child process
		int status;
		printf("Parent waiting for child to finish....\n");
		wait(&status);
		// this part also a prent process
		
		  if(WIFEXITED(status)){
			printf("Child exited with status:%d\n",WEXITSTATUS(status));
			
		                        }
		
	     else
		{
			printf("Child did not exit normally.\n");
		}
		printf("Parent process ending...\n");
	}
		
		
		
	}
	
	return 0;
	
}

----------------------
Parent process started.PID: 12783
Parent waiting for child to finish....
Child process.PID is:12784,sleeping for 1 seconds...
Child process.PID is:12785,sleeping for 3 seconds...
Child process exiting.
Child exited with status:0
Parent process ending...



Q4)
First child:Slept for 2 second .exit with status 2
Second Child:Slept  for 1 second,exit with status 1
Parent :waits twice,and prints which child by (by PID or exit code)
Finished first and second



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2;

    printf("Parent process started. PID: %d\n", getpid());

    // First child
    pid1 = fork();
    if (pid1 < 0)
    {
        perror("Fork failed");
        exit(1);
    }
    if (pid1 == 0)
    {
        // First child process
        printf("First child process. PID: %d, sleeping for 2 seconds...\n", getpid());
        sleep(2);
        printf("First child exiting with status 2.\n");
        exit(2);
    }
    else
    {
        // Parent creates second child
        pid2 = fork();
        if (pid2 < 0)
        {
            perror("Fork failed");
            exit(1);
        }
        if (pid2 == 0)
			
        {
            // Second child process
            printf("Second child process. PID: %d, sleeping for 1 second...\n", getpid());
            sleep(1);
            printf("Second child exiting with status 1.\n");
            exit(1);
        }
        else
        {
            // Parent process waits for both children separately
            int status;
            pid_t finished_pid;

            for (int i = 0; i < 2; i++)
            {
                finished_pid = wait(&status);
                if (finished_pid == -1)
                {
                    perror("wait failed");
                    exit(1);
                }

                if (WIFEXITED(status))
                {
                    printf("Child with PID %d exited with status: %d\n", finished_pid, WEXITSTATUS(status));
                }
                else
                {
                    printf("Child with PID %d did not exit normally.\n", finished_pid);
                }
            }
            printf("Parent: Both children have finished.\n");
        }
    }

    return 0;
}


---------------------------
Output:
.                                                                ~ 1
{ ~ }  » vi t.c                                                                          ~
{ ~ }  » gcc t.c -o t                                                                    ~
{ ~ }  » ./t
                                                                             ~
Parent process started. PID: 4384
First child process. PID: 16824, sleeping for 2 seconds...
Second child process. PID: 15884, sleeping for 1 second...
Second child exiting with status 1.

Child with PID 15884 exited with status: 1
First child exiting with status 2.
Child with PID 16824 exited with status: 2
Parent: Both children have finished.


---------------------------------------------------------
/*  EXPLANATION

What happens after the first fork():

The first child is created.
The child process starts running and goes to sleep for 2 seconds (sleep(2)).
Meanwhile, the parent process does NOT wait — it continues running.


⚙️ So what does the parent do next?
While the first child is sleeping, the parent executes the next fork() to create the second child.
This second child then sleeps for 1 second and exits.

*/
Q5)
The parent creates a child process
The child creates a grandchild process
The grandchild sleep 2 second and exits with status 2
The child waits for the grandchild , print its exit status
then exits with status 5


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid, grandchild_pid, waited_pid;
    int status;

    printf("Parent: PID %d starting\n", getpid());

    // Fork the child process
    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed for child");
        exit(1);
    }

    if (child_pid == 0) {
        // In child process
        printf("Child: PID %d, Parent PID %d\n", getpid(), getppid());

        // Fork the grandchild process
        grandchild_pid = fork();

                 if (grandchild_pid < 0) {
                 perror("Fork failed for grandchild");
                  exit(1);
                                         }

                 if (grandchild_pid == 0) {
                 // In grandchild process
                printf("Grandchild: PID %d sleeping for 2 seconds...\n", getpid());
                sleep(2);
                printf("Grandchild: Exiting with status 2\n");
                exit(2);
                                          }  
										  
                  else                    {
                 // Child process waits for grandchild
                 wait(&status);
				 
                            if (WIFEXITED(status)) {
                            printf("Child: Grandchild exited with status %d\n", WEXITSTATUS(status));
                                                   }
			               else {
                           printf("Child: Grandchild did not exit normally\n");
                                }
             printf("Child: Exiting with status 5\n");
            exit(5);
                                          
										  
										  }

    } 
	
else {
        // In parent process
        wait(&status); // Wait for child
        if (WIFEXITED(status)) {
            printf("Parent: Child exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Parent: Child did not exit normally\n");
        }
        printf("Parent: Finished\n");
    }

    return 0;
}
----------------------------------
Parent: PID 1234 starting

Child: PID 1235,Parent PID 1234
Grandchild: PID 1236 sleeping for 2 seconds...
Grandchild: Exiting with status 2
Child: Grandchild exited with status 2

Child: Exiting with status 5
Parent: Child exited with status 5
Parent: Finished
