#include<stdio.h>
#include<stdlib.h>

/*
Carvans:	https://www.codechef.com/problems/CARVANS
*/

//https://www.codechef.com/viewsolution/39821573
int sol1(int N, int n[])
{
	int i, temp, count=0;
	temp=n[0];
    for(i=0;i<N;i++)
        if(temp>=n[i]) {
            count++; temp=n[i]; }
    return count;
}

//https://www.codechef.com/viewsolution/34468511
int sol2(int n, int ar[])
{
	int i,c=1,j,b=0;
    for(i=1;i<n;i++)
    {
		b=0;
        for(j=0;j<i;j++)
        {
            if(ar[j]<ar[i])
            b++;
        }
        if(b==0)
            c++;
    }
    return c;
}


//https://www.codechef.com/viewsolution/33363579
int sol3(int n, int a[])
{
	register int i,j,count=0,flag=0;
	for(i=n-1;i>=0;i--)
	{
        for(j=0; j<=i;j++)
		{
            if(a[j]>=a[i])
				count++;
        }
		if(count==j)flag++;
           count=0;
    }
	return flag;
}


//https://www.codechef.com/viewsolution/33029357
int sol4(int n, int a[])
{
	int count,i;
	count=n;
	for(i=1;i<n;i++)
	{
		if(a[i-1]<a[i])
		{
			--count;
			a[i]=a[i-1];
		}
	}
	return count;
}


int main()
{
	int n;
	if(n<1 || n>10000)
	{
    	return 0;
    }
	int m = (n > 0 ? n : 1);
	int x[m];
	int *a = (n > 0 ? x : NULL);
	__CPROVER_assert(sol1(n,a)==sol2(n,a),"sol1Vsol2");
  __CPROVER_assert(sol1(n,a)==sol3(n,a),"sol1Vsol3");
  __CPROVER_assert(sol1(n,a)==sol4(n,a),"sol1Vsol4");
  __CPROVER_assert(sol2(n,a)==sol3(n,a),"sol2Vsol3");
  __CPROVER_assert(sol2(n,a)==sol4(n,a),"sol2Vsol4");
  __CPROVER_assert(sol3(n,a)==sol4(n,a),"sol3Vsol4");
    return 0;
}

//Tested using cbmc and found no counterexmaple
//Bruteforce not attempted
