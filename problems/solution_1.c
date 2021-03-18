#include<stdio.h>
#include<stdio.h>
int main()
{
   int tt,input,nn,i;
   char arr[1000000],c,m;
   printf("Enter test cases\n");
	scanf("%d",&tt);
	for(int j=0;j<tt;j++)
    {
        scanf("%d",&input);

	nn=input;
	scanf("%s", arr);
	if(input%2==1)
    {
        input=input-1;
    }

	for(int i=0;i<input;i=i+2)
	{
	    c=arr[i];
	    arr[i]=arr[i+1];
	    arr[i+1]=c;
	}

	for(i=0;i<nn;i=i+1)
	{
	   arr[i]=219-arr[i];

	}
	printf("%s\n",arr);

    }



}
//SOLUTION_1 FUNCTION

https://www.codechef.com/problems/CHO1

/*1≤T≤1,000


1≤N≤100


|S|=N*/

char *solution_1(int len,char *arr);
char *solution_1(int len,char *arr)
{
    char temp;
    int temp_forsize=len;
    if(len%2==1)
    {
        len-=1;
    }

	for(int i=0;i<len;i+=2)
	{
	    temp=arr[i];
	    arr[i]=arr[i+1];
	    arr[i+1]=temp;
	}

	for(int i=0;i<temp_forsize;i++)
	{
	   arr[i]=219-arr[i];

	}
return arr;
}
