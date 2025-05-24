#include<stdio.h>
#include<unistd.h>
int main(){

printf("\nHello world");
int f=fork();
int p=getpid();
printf("\n the pid is %d",p);
printf("\n the pid is %d",f);


return 0;
}

[2021ict109@fedora ~]$ vi fork.c
[2021ict109@fedora ~]$ gcc fork.c -o fork
[2021ict109@fedora ~]$ ./fork

Hello world
 the pid is 11107
 the pid is 11108Hello world
 the pid is 11108
 the pid is 0[2021ict109@fedora ~]$ cat fork.c

-----------------------------------------------------------------
#include<stdio.h>
#include<unistd.h>
int main(){

printf("\nHello world");
int f=fork();
int p=getpid();

if(f==0){
printf("\nThis is child%d,",f);
}
else{
printf("\nThis is a parent%d,",f);
}

return 0;
}

[2021ict109@fedora ~]$ vi fork.c
[2021ict109@fedora ~]$ gcc fork.c -o fork
[2021ict109@fedora ~]$ ./fork

Hello world
This is a parent16649,
This is child0,

--------------------------------------------------------------------

#include<stdio.h>
#include<unistd.h>
int main(){

int B=fork();
int C=fork();


if(B==0){
printf("\nThis is child");
}
else if(C==0){
	printf("\nThis is child");
}
else{
printf("\nThis is a parent");
}

return 0;
}

This is child: 0This is child: 0[2021ict109@fedora ~]$ vi fork.c
[2021ict109@fedora ~]$ gcc fork.c -o fork
[2021ict109@fedora ~]$ ./fork

---------------------------------------------------------

This is a parent
This is child

This is childThis is child

------------------------------------------------------


#include<stdio.h>
#include<unistd.h>
int main(){

int f=fork();
if(f==0){
	printf("\nThis is child");
    printf("\n parent pid:%d",getppid());
}
else{
	int f1=fork();
	if(f1==0){
	printf("\nThis is sibiling");
    printf("\n parent pid:%d",getppid());
	}
	else{
			printf("\nThis is parent");
         printf("\n My pid:%d",getppid());
	    printf("\n My parent pid:%d",getppid());


	}
} 
return 0;
}


This is parent
 My pid:8228
 My parent pid:8228
This is child
 parent pid:26946
This is sibiling
 parent pid:26946