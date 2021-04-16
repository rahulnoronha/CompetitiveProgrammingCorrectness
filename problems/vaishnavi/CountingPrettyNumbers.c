#include <stdio.h>

/*
Counting Pretyy Numbers: https://www.codechef.com/problems/NUM239

1 <= L <= R <= 10^5

*/

//https://www.codechef.com/viewsolution/33377972
int sol1(int l, int r)
{
	int j,d,c=0;
	 for(j=l;j<=r;j++)
	    {
	        while(j!=0)
	        {
	            d=j%10;
	            if(d==2||d==3||d==9)
	            c++;
	            break;
	        }
	    }
	    return c;
}


//https://www.codechef.com/viewsolution/44990460
int sol2(int a, int b)
{
	int count=0;
	for(int i=a;i<=b;i++)
	    {
	        int u=i%10;
	        if(u==2 || u==3 || u==9)
	        {
	            count++;
	        }
	    }
	return count;
}


//https://www.codechef.com/viewsolution/45023487
int sol3(int a, int b)
{
	int count=0,rem;
	for(i=a;i<=b;i++)
	    {
	        rem=i%10;
	        if(rem==2 || rem==3 || rem==9)
	        {
	            count++;
	        }
	    }
	return count;
}


//https://www.codechef.com/viewsolution/39084812
int sol4(int l, int r)
{
	int i,count=0;
	    for(i=l;i<=r;i++)
	    {
	        if(i%10==2 || i%10==3 || i%10==9)
	        count++;
	    }
	return count;
}


int main()
{
	int n, a;
	if(n<1 || n>100000 || a<1 || a>100000)
	{
    	return 0;
    }
    	__CPROVER_assert(sol1(n,a)==sol2(n,a),"sol1Vsol2");
    __CPROVER_assert(sol1(n,a)==sol3(n,a),"sol1Vsol3");
    __CPROVER_assert(sol1(n,a)==sol4(n,a),"sol1Vsol4");
    __CPROVER_assert(sol2(n,a)==sol3(n,a),"sol2Vsol3");
    __CPROVER_assert(sol2(n,a)==sol4(n,a),"sol2Vsol4");
    __CPROVER_assert(sol3(n,a)==sol4(n,a),"sol3Vsol4");
}
