Q1)
#include <stdio.h>
#include <unistd.h>

int main(){

fork();
fork();
printf("\n Hello World");

}

---------------------
[2021ict126@fedora ~]$ vi Q1.c
[2021ict126@fedora ~]$ gcc Q1.c -o Q1
[2021ict126@fedora ~]$ ./Q1
Output:

Hello World

 Hello World Hello World
 Hello World
 ----------------------------
 
 Q2)
#include <stdio.h>
#include <unistd.h>

int main(){

int f=fork();

if(f==0)
{
printf("\n I am the child process");
}
else
{
printf("\n I am the parent process");

}

}
--------------------------
Output:
[2021ict126@fedora ~]$ vi Q2.c
[2021ict126@fedora ~]$ gcc Q2.c -o Q2
[2021ict126@fedora ~]$ ./Q2

 
 I am the parent process
 I am the child process
 
 Q3)
 
 1-5 child 5-10 parent
 
 //print numbers from 1 to 10 and ato 5 should be print by child
 //process and from 6 to 10 should be parent process
 //calculate summation of these numbers
 
#include <stdio.h>
#include <unistd.h>

int main(){

int number;
int f=fork();

int sum1=0;
int sum2=0;
int Total=0;

if(f==0)
{
	
	for(int i=1;i<6;i++)
	{
		
	      printf("\n%d",i);
		  sum1=sum1+i;
     }
}
else
{
		   for(int i=6;i<=10;i++)
            {
              printf("\n%d",i);
			  sum2=sum2+i;
            }
	   }

Total=sum1+sum2;
printf("Summation is:%d",Total);

}
------------------------------------
Output:
[2021ict126@fedora ~]$ vi num.c
[2021ict126@fedora ~]$ gcc num.c -o num
[2021ict126@fedora ~]$ ./num

6
7
8
9
10Summation is:40
1
2
3
4
5Summation is:15