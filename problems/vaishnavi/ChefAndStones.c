#include<stdio.h>

/*
Ched And Stones: https://www.codechef.com/problems/CHEFSTON

Constrains:
>	1 <= n<= 10^5
> 	1 <= k <= 10^9
*/

//https://www.codechef.com/viewsolution/42966375
int sol1(int n, int k, int a[], int b[])
{
	int i,max = 0;
	    
	    for(i=0;i<n;i++)
	    {
	         max = maximum(max,(k/a[i])*b[i]);
	    }
	    
	return max;
}

//https://www.codechef.com/viewsolution/40169419
int sol2(int n, int k, int a[], int b[])
{
	int i, ans=0;
	for(i=0;i<n;i++)
	{
		int x=(k/a[i])*b[i];
		ans=x>ans?x:ans;
	}
	return ans;
}

//https://www.codechef.com/viewsolution/38100899
int sol3(int n, int k ,int a[], int b[])
{
	int i;
	 for(i=0;i<n;i++)
	{
	        a[i]=k/a[i];
	}
	for(i=0;i<n;i++)
	{
	    b[i]=a[i]*b[i];
	}
	k=b[0];
	for(i=1;i<n;i++)
	{
	    if(b[i]>k)
	    {
	        k=b[i];
	    }
	}
	return k;
}


int main()
{
	int n,k;
	if(n<1 || n>100000 || k<1 || k>1000000000)
		return 0;
		int m = (n > 0 ? n : 1);
  	int x[m];
  	int *a = (n > 0 ? x : NULL);
  	int *b = (n > 0 ? x : NULL);
  	__CPROVER_assert(sol1(n,k,a,b)==sol2(n,k,a,b),"sol1Vsol2");
    __CPROVER_assert(sol1(n,k,a,b)==sol3(n,k,a,b),"sol1Vsol3");
    __CPROVER_assert(sol2(n,k,a,b)==sol3(n,k,a,b),"sol2Vsol3");
}
