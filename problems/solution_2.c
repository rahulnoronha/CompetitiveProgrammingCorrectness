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

