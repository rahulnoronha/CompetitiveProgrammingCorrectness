#include<stdio.h>

/*
Distribute Apples: https://www.codechef.com/problems/DSTAPLS
Constraints:
>	1 <= N,K <= 10^18
>	N is divisible by K
*/


//https://www.codechef.com/viewsolution/36885072
char* sol1(long long int n, long long int k)
{
	if((n/k)%k==0)
        return "YES";
    else
    	return "NO";
}

//https://www.codechef.com/viewsolution/30728119
char* sol2(long long int n, long long int k)
{
	int sum1,sum2,i,x;
	sum1=0;
	int a[n];
	while(n!=(k*sum1))
	{
	    sum1=sum1+1;
	}
	sum2=0,x=0;
	while(sum2!=n)
	{
	    for(i=0;i<k;i++)
	    {
	        a[i]=k+x*k;
	        sum2=sum2+k;
	        if(sum2==n)
			{
	            break;
			}
	    }
	    x++;
	    if(sum2==n)
	    {
	        break;
	    }
	}
	if(a[k-1]==sum1)
	{
	    return "NO";
	}
	else
	{
	    return "YES";
	}
}


int main()
{
    int m,n;
    if(m<0||n<0)
    {
        return 0;
    }
    __CPROVER_assert(sol1(m,n)==sol2(m,n),"sol1vsol2");
}
//Tested with CBMC and counter example found for unwinding 1
//Brute force Check not done


