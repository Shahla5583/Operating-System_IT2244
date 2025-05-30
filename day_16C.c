#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int num1,num2,num3;

int main(){
	
int fact=1,i=0,j=0,k=1;

printf("Enter a number:");
	scanf("%d",&num1);
	
 printf("Enter a number:");
	           scanf("%d",&num2);
	
printf("Enter a number:");
	             scanf("%d",&num3);
int f=fork();

if(f==0){
	printf("\nThis is child-A");
	printf("\n My pid:%d",getpid());
    printf("\n parent pid:%d",getppid());
	
	
	for(i=1;i<=num1;i++)
	{
		fact=fact*i;
	}
	printf("\n factorial of child:%d",fact);
	
}
else
{
	int f1=fork();
	        
	  if(f1==0)
	  {
		  
	  printf("\nThis is sibiling-D");
	  printf("\n My pid:%d",getpid());
	  printf("\n parent pid:%d",getppid());
			
              int f2=fork();
              if(f2==0)
              {
	           printf("\nThis is child-B");
	           printf("\n My pid:%d",getpid());
               printf("\n parent pid:%d",getppid());
			   
			  
			   
			   int a=0;
			   int b=1;
			   for (j=0;j<=num2;j++)
			   {
				   printf("%d",a);
				   printf(" ");
				  
				   int c=a+b;
				   a=b;
				   b=c;
			   }
              }
              else
			  {
	             int f3=fork();
	          
			     if(f3==0)
				 {
	             printf("\nThis is sibiling-C");
	             printf("\n My pid:%d",getpid());
	             printf("\n parent pid:%d",getppid());
				 
				
	
				 
				 int count=0;
				 for(k=1;k<=num3;k++)
				 {
					 
					int mod=num3%k;
					if(mod==0)
					{
						count++;
					}
				 }
					if(count==2)
					{
						printf("%d is a prime number",num3);
					}
					else
					{
						printf("%d is a not a prime number",num3);
					}
					
				 
				 
                 }

	           }
	   }
					 
	    else{
		 	printf("\nThis is parent");
            printf("\n My pid:%d",getpid());
			printf("\n parent pid:%d",getppid());
		  
	       }
}		
return 0;
}
----------------------------------
{ ~ }  » vi Q3New.c                                                                    ~ 1
{ ~ }  » gcc Q3New.c -o Q3New                                                            ~
{ ~ }  » ./Q3new         
Enter a number:5
Enter a number:3
Enter a number:5

This is parent
 My pid:14724
 parent pid:6328 
 
 
This is child-A
 My pid:12392
 parent pid:14724
 factorial of child:120
 
 
This is sibiling-D
My pid:7644
parent pid:14724

This is child-B
My pid:8684
parent pid:7644
0 1 1 2  



This is sibiling-C
My pid:2128
parent pid:7644
5 is a prime number 
                                                                                    