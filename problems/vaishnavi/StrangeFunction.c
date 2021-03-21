#include<stdio.h>
#include<math.h>

/*
Strange Function: https://www.codechef.com/problems/ABX01

There were 3 subtasks in here, All the solutions I've picked satisfy subtask 1, So contraints only from sub task one are taken into condieration.
Constraints:
>	1 <= N <= 3
>	1 <= A <= 10^5
*/

//https://www.codechef.com/viewsolution/33226376
int sum1(unsigned long long num)
{
    unsigned long long value;
    if(num/10==0)
    {
        return (int)num;
    }
    while(num>0)
    {
        value+=num%10;
        num/=10;
    }
    sum1(value);
    return;
}

int sol1(long long int A, long long int n)
{
	int ans,a;
	//unsigned long long A;
	//unsigned long n;
	int val2[]={2,4,8,7,5,1};
	int val4[]={4,7,1};
	int val5[]={5,7,8,4,2,1};
	int val7[]={7,4,1};
	int val8[]={8,1};
	//scanf("%llu %lu",&A,&n);
	a=sum1(A);
	if(n==1)
	{
	    ans=a;
	}
	else
	{
	    if(a==3 || a==6 || a==9)
    	{
    	    ans=9;
    	}
    	else if(a==1)
    	{
    	    ans=1;
    	}
    	else if(a==2)
    	{
    	    ans=val2[(n-1)%6];
    	}
    	else if(a==4)
    	{
    	    ans=val4[(n-1)%3];
    	}
    	else if(a==5)
    	{
    	    ans=val5[(n-1)%6];
    	}
    	else if(a==7)
    	{
    		ans=val7[(n-1)%3];
    	}
    	else if(a==8)
    	{
    	    ans=val8[(n-1)%2];
    	}
	}
	return ans;
}



//https://www.codechef.com/viewsolution/33205906
int sum2(unsigned long num)
{
    if(num==0)
    {
        return 0;
    }
    return (num%10 + sum2(num/10));
}

unsigned long answer(unsigned long S)
{
    if(S/10==0)
    {
        return S;
        //return;
    }
    answer(sum2(S));
}

int sol2(long long int A, long long int N)
{
	//int A,N;
	answer(pow(A,N));
	
}



//https://www.codechef.com/viewsolution/22504197
int sol3(long long int a, long long int n)
{
	long long int i;
	//scanf("%llu %llu",&a,&n);
	long long int d=pow(a,n);
    for(i=1;i<=100000000000000;i++)
    {
		if(d<=9)
    	{
			return d;
        	break;
    	}
    else
    {	
		long long int s,sum=0;
        while(d!=0)
        {
			s=d%10;
        	sum+=s;
        	d/=10;
        }
        d=sum;
    }
        
    }
}


int main()
{
	long long int a, n;
	if(a<1 || a>100000 || n<1 || n>4 )
		return 0;
	__CPROVER_assert(sol1(a,n)==sol2(a,n),"sol1vsol2");
	__CPROVER_assert(sol1(a,n)==sol3(a,n),"sol1vsol3");
	__CPROVER_assert(sol2(a,n)==sol3(a,n),"sol1vsol2");

}
