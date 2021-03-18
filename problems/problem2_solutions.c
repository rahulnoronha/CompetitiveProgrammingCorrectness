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

//second solution

#include <stdio.h>
#include <string.h>

int main(void) {


	char arr[100] , temp  ;
	long int T ;
	int i  , n , check , k=0 ;

	scanf("%ld",&T);

	while(T != 0)
	{
	    scanf("%d",&n);

	    scanf("%s",arr);

	   for(i=0;i<(n/2);i++)
    {
        temp = arr[k];
        arr[k] = arr[k+1];
        arr[k+1] = temp;
        k=k+2;
    }

    for(i=0;i<n;i++)
    {
        check = arr[i] - 97;
        arr[i] = 122 - check;
    }

    printf("%s\n",arr);
	   T--;
	   k=0;
	}

	return 0;
}
//SOLUTION_2 FUNCTION

https://www.codechef.com/problems/CHO1

/*1≤T≤1,000


1≤N≤100


|S|=N*/

char *solution_2(int len,char *arr);
char *solution_2(int len,char *arr)
{
    int i,n,check,k=0;
    char temp;
    for(i=0;i<(n/2);i++)
    {
        temp = arr[k];
        arr[k] = arr[k+1];
        arr[k+1] = temp;
        k=k+2;
    }

    for(i=0;i<n;i++)
    {
        check = arr[i] - 97;
        arr[i] = 122 - check;
    }
return arr;
}

//third solution

#include <stdio.h>

/*void swap(char *p,char *q){
    char temp=*p;
    *p=*q;
    *q=temp;
}*/

int main(){
	int T;
	scanf("%d",&T);
	while(T!=0){
	    int N,i;
	    scanf("%d",&N);
	    char S[N];
	    scanf("%s",S);
	    if(N%2 == 0){
	        for(i=0;i<N;i++){
	            swap(&S[i],&S[i+1]);
	            i++;
	        }
	    }
	    else{
	        for(i=0;i<N-1;i++){
	            swap(&S[i],&S[i+1]);
	            i++;
	        }
	    }
	    int change;
	    for(i=0;i<N;i++){
	        change=S[i]-97;
	        S[i]= 122 - change;
	    }

	    for(i=0;i<N;i++){
	        printf("%c",S[i]);
	    }
	    printf("\n");
	    T--;
	}
	return 0;
}
//SOLUTION_3 FUNCTIONS
void swap(char *p,char *q){
    char temp=*p;
    *p=*q;
    *q=temp;

}

https://www.codechef.com/problems/CHO1

/*1≤T≤1,000


1≤N≤100


|S|=N*/

char *solution_3(int len,char *arr);
char *solution_3(int len,char *arr)
{

    int i;
    if(len%2 == 0){
	        for(i=0;i<len;i++){
	            swap(&arr[i],&arr[i+1]);
	            i++;
	        }
	    }
	    else{
	        for(i=0;i<len-1;i++){
	            swap(&arr[i],&arr[i+1]);
	            i++;
	        }
	    }
	    int change;
	    for(i=0;i<len;i++){
	        change=arr[i]-97;
	        arr[i]= 122 - change;
	    }
return arr;
}

