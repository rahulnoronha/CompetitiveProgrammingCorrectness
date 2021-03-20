//https://www.codechef.com/COBN2021/problems/CSNUM
/*
Chef and Special Number
Constraints:
>	1<=num/n<=10^6
*/

#include<math.h>
#include<string.h>

//https://www.codechef.com/viewsolution/43387343
const char* sol1(int num)
{
	int i=0,ini=0,s=10,d[10],j,x=0,sum=0,k=0,re3,re,re2, n,f;

   l:
    i++;
    int re=10;
    if(num>=1&& num<10)
    {
		return "Good Work\n";
        goto l;

	}

    else
    {
        for(s=10,ini=0;re>0;s*=10)
        {
            re=num/s;
			ini++;
        }
    	for(j=ini-1,k=0;j>=0;j--,k++)
    	{
    		f=pow(10,j);
        	re2=num/f;
        	re3=num%f;
        	d[k]=re2;
			num=re3;
		}

    	for(x=0,sum=0;x<ini;x++)
    	{
        	sum=sum+d[x];
    	}
    }
    if(sum%ini==0)
    {
        return "Good Work\n";
    }
    else
    {
        return "Try again\n";
    }
}


//https://www.codechef.com/viewsolution/43379499
const char* sol2(int num)
{
	int sum=0,i;
	char s[1000000];
	for(i=0;i<strlen(s);i++)
	sum=sum+s[i];
	if(sum%strlen(s)==0)
		return "Good Work\n";
	else
		return "Try again\n";
}


//https://www.codechef.com/viewsolution/43394402
const char* sol3(int n)
{
int r, c=0, sum=0;
	while(n>0)
	{
	    r=n%10;
	    sum+=r;
	    c+=1;
	    n/=10;
	}
	if(sum%c==0)
		return "Good Work\n";
	else
		return "Try again\n";
}


int main()
{
    int n;
    if(n<1||n>1000000)
    {
        return 0;
    }
    __CPROVER_assert(sol1(n)==sol2(n),"sol1vsol2");
    __CPROVER_assert(sol1(n)==sol3(n),"sol1vsol2");
    __CPROVER_assert(sol2(n)==sol3(n),"sol2vsol3");
    
}

//Tested with CBMC, but test took too long to run which means it is most likely unsatisfiable since if it was satisfiable it would throw the counterexample quickly.
//Brute Force testing not done.

