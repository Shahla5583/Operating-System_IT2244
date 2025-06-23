Q1)

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//A normal c function hat is executed as athread 
//when its name is specified in pthread_create()

void *helloWorld(void*vargp){
sleep(1);
printf("Hello World\n");
return NULL;
}
int main()
{

pthread_t thread_id;
printf("Before thread\n");
pthread_create(&thread_id,NULL,helloworld,NULL);
pthread_join(thread_id,NULL);
printf("After thread\n");
exit(0);
}
----------------------------------------------------------
Output:
[2021ict126@fedora ~]$ vi thread1.c
[2021ict126@fedora ~]$ gcc thread1.c -o thread1
[2021ict126@fedora ~]$ ./thread1
Before thread
Hello World
After thread
[2021ict126@fedora ~]$

Q2)

//multi.threaded process

#include<stdio.h>
#include<pthread.h>

//function to be executed by the threaded

void* print_message(void* arg){
char *message=(char*)arg;
printf("%s\n",message);
return NULL;
}

int main()
{
pthread_t thread1,thread2;
//create first thread
pthread_create(&thread1,NULL,print_message,"Hello from thread 1 !");

//create second thread
pthread_create(&thread2,NULL,print_message,"Hello from thread 2 !");
//wait for both threads to finish
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);

printf("Both threads completed .\n");
return 0;
}
--------------------------------------------------------
output:

[2021ict126@fedora ~]$ vi multi.c
[2021ict126@fedora ~]$ gcc multi.c -o multi
[2021ict126@fedora ~]$ ./multi
Hello from thread 1 !
Hello from thread 2 !
Both threads completed .
[2021ict126@fedora ~]$

Q3)


#include <stdio.h>
#include <pthread.h>

// Function to be executed by the thread
void* print_message(void* arg) {
    char *message = (char*)arg;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t threads[3];  // Corrected array declaration for thread IDs

    // Array of messages for threads
    char *messages[] = {
        "Thread 1 says hi!",
        "Thread 2 says hello!",
        "Thread 3 says hey!"
    };

    // Create threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, print_message, (void*)messages[i]);  // Pass address of thread id & cast argument
    }

    // Wait for threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads done.\n");
    return 0;
}

----------------------------------------------------------
Output:
[2021ict126@fedora ~]$ vi threadEx.c
[2021ict126@fedora ~]$ gcc threadEx.c -o threadEx
[2021ict126@fedora ~]$ ./threadEx
Thread 1 says hi!
Thread 2 says hello!
Thread 3 says hey!
All threads done.

//Q2)
//Usin threads to compute parts of a sum(Parellel sum)