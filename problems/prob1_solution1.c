#include <stdio.h>
#include <conio.h>
int main() {
    syscls();
	int T , i , count=0;
	long int n;
	char name[1000000];

	printf("Enter test cases\n");
	scanf("%d",&T);

	while(T != 0)
	{
	    printf("Enter size of array\n");
	    scanf("%d",&n);

	    printf("Enter starting letters of %d toys\n",n);
	    scanf("%s",&name);

	    for(i=0;i<n-1;i++)
	    {
	        if(name[i] == name[i+1])
	        {
	            count++;
	        }
	    }

	    printf("%d\n",count);
	    T--;
	    count=0;
	}

	return 0;
}


//https://www.codechef.com/problems/COINYS

 /*  1 ≤ T≤ 1000

1 ≤ N≤ 100000*/

// SOLUTION_1 FUNCTION
int solution_1(int size,char *str);
int solution_1(int size,char *str)
{
    int count=0;
    for(int i=0;i<size-1;i++)
	    {
	        if(str[i] == str[i+1])
	        {
	            count++;
	        }
	    }
return count;
}

