#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>

int num1,fact=1,square_of_Num=1,twoPower_Num=1;
int i,j,k,m;

int main(){
	
	printf("Enter a number:");
	scanf("%d",&num1);
	
	int f=fork();
	
if(f==0)
{
	printf("\nThis is child-c1");
	printf("\n My pid:%d",getpid());
    printf("\n parent pid:%d",getppid());
	
	
	for(i=1;i<=num1;i++)
	{
		fact=fact*i;
	}
	printf("\n The factorial of:%d is: %d ",num1,fact);
	
	int f3=fork();
	    if(f3==0)
	   {
		printf("\nThis is child-c5");
	    printf("\n My pid:%d",getpid());
        printf("\n parent pid:%d",getppid());
		
		       int a=0;
			   int b=1;
			   for (j=0;j<=num1;j++)
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
		   printf("\nThis is parent");
           printf("\n My pid:%d",getpid());
		
	   }
}
else{
	int f1=fork();
	        
			if(f1==0)
			{
	          printf("\nThis is sibiling-c2");
	          printf("\n My pid:%d",getpid());
	          printf("\n parent pid:%d",getppid());
 
               for(k=1;k<=num1;k++)
			    {
				twoPower_Num=twoPower_Num*2;
			    }
				printf("The twoPower_Num of number %d is: %d",num1,twoPower_Num);
			}
	            
				
		  else 
		  {
					
					int f2=fork();
					
					if(f2==0)
				{
			          printf("\nThis is sibiling-c3");
	                  printf("\n My pid:%d",getpid());
	                  printf("\n parent pid:%d",getppid());
                     
					 for(m=1;m<=2;m++)
					 {
						 square_of_Num= square_of_Num*num1;
					 }
				       printf("The square_of_Num of number %d is: %d",num1,square_of_Num);
						  
			  }
					 
		  
					else
					{
					printf("\nThis is parent");
                    printf("\n My pid:%d",getpid());
					}
		 	
		  
	      }
					
}		
	
	
	
	
	return 0;
}
-----------------------
{ ~ }  » vi Q3New.c                                                                    ~ 1
{ ~ }  » gcc Q3New.c -o Q3New                                                            ~
{ ~ }  » ./Q3new 
Enter a number: 5

This is parent
 My pid:19900

This is child-c1
 My pid:20544
 parent pid:19900
 The factorial of: 5 is: 120


This is sibiling-c2
 My pid:23328
 parent pid:19900
 The twoPower_Num of number 5 is: 32

This is sibiling-c3
 My pid:15720
 parent pid:19900
 The square_of_Num of number 5 is: 25

This is child-c5
 My pid:20112
 parent pid:20544
 Fibonacci series: 0 1 1 2 3 5