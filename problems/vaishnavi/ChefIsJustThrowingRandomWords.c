#include<stdio.h>

/*
Chef is just throwing Random Words: https://www.codechef.com/problems/SSO
Constraints:
>	1 <= N <= 10^5
>	1 <= a(i) < 2^30 for each valid i
*/


//https://www.codechef.com/viewsolution/39317665
long long int sol1(long long int n, long long int a[])
{
	//long long int n,i;
    //scanf("%lld \n",&n);
    long long int i,sum=0,temp=0;
    for(i=0;i<n;i++)
	{
        //scanf("%lld ",&a[i]);
        sum=sum+a[i];
    	temp=temp|sum;
    }
    long long int ans=sum;
    for(i=0;i<n;i++)
	{
        temp=temp|a[i];
    }
    return temp;
}


//https://www.codechef.com/viewsolution/39817742
long long int sol2(long long int N, long long int a[])
{
	/*scanf("%d",&N);
	long int a[N];
	for(i=0;i<N;i++)
	{
		scanf("%ld",&a[i]);
	}*/
	long int sum=0,pref_sum=0,i;
	for(i=0;i<N;i++)
	{
	    pref_sum=pref_sum+a[i];
		sum=(sum|a[i])|pref_sum;
	}
	return sum;
}



//https://www.codechef.com/viewsolution/39248567
long long int sol3(long long int n, long long int a[])
{
	//int n;
    //scanf("%d",&n);
    long long int sum=0,c,ans=0;
    for(int i=0;i<n;i++)
    {
        //scanf("%lld",&a);
        ans=ans|a[i];
        sum=sum+a[i];
        ans=sum|ans;    
    }
    return ans;
}



int main()
{
	long long int n;
	if(n<1 || n>100000)
		return 0;
	int m = (n > 0 ? n : 1);
	long long int x[m];
	long long int *a = (n > 0 ? x : NULL);
	__CPROVER_assert(sol1(n,a)==sol2(n,a),"sol1Vsol2");
    __CPROVER_assert(sol1(n,a)==sol3(n,a),"sol1Vsol3");
    __CPROVER_assert(sol2(n,a)==sol3(n,a),"sol2Vsol3");
	return 0;
}
