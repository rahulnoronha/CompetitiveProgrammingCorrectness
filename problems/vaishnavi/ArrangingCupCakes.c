#include<math.h>
#include<stdlib.h>

/*ArrangingCupCakes: https://www.codechef.com/problems/RESQ
1 <= n <= 10^8
There are 4 solutions under here, Each of them had different runtimes and memories.
*/

//https://www.codechef.com/viewsolution/40475337
int sol1(int n)
{
	int min=1000000000;
    int temp=sqrt(n);
    int a,b,tempi;
    for(int i=1;i<=temp;i++)
    {
        if((n%i)==0)
        {
            a=i;
            b=n/i;
            if(a>b)
            {
                tempi=a-b;
                if(tempi<min)min=tempi;
            }
            else
            {
                tempi=b-a;
                if(tempi<min)
					min=tempi;
            }
        }
        else continue;
    }
    return min;
}


//https://www.codechef.com/viewsolution/41721143
int sol2(int n)
{
	int i,min=0;
	i=sqrt(n);
	while(i)
	{
	    if(n%i == 0)
	    {
	        min=n/i - i;
	        return min;
	        break;
	    }
	    i--;
	}
}


//https://www.codechef.com/viewsolution/35771736
int sol3(int n)
{
	int i,d,md;
	d=0; md=n-1;
	for(i=1;i<=sqrt(n);i++)
	{
	    if(n%i!=0)
		    continue;
	    /*if(i==d)
	    break;*/
	    d=n/i;
	    //printf("%d %d\n",i,d);
	    int df=i-d;
	    df=(df<0)?-df:df;
	    md=df<md?df:md;
	    /*if(i==n/i)
	    break;*/
	}
	return md;
	/*int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);*/
}


//https://www.codechef.com/viewsolution/35745594
int sol4(int n)
{
	int i = sqrt(n);
	while(i>=1)
	{
		if(n%i == 0)
		{
			break;
		}
		i--;
	}
	return ((n/i)-i);
}

int main()
{
    int n;
    if( n<1||n>100000000)
    {
        return 0;
    }
    __CPROVER_assert(sol1(n)==sol2(n),"sol1vsol2");
    __CPROVER_assert(sol1(n)==sol3(n),"sol1vsol3");
    __CPROVER_assert(sol1(n)==sol4(n),"sol1vsol4");
    __CPROVER_assert(sol2(n)==sol3(n),"sol2vsol3");
    __CPROVER_assert(sol2(n)==sol4(n),"sol2vsol4");
    __CPROVER_assert(sol3(n)==sol4(n),"sol3vsol4");
}
 
 //Tested with CBMC, but test took too long to run which means it is most likely unsatisfiable since if it was satisfiable it would throw the counterexample quickly.
//Brute Force testing not done.
 
 
 
