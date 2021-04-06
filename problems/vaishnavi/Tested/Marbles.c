/*
Marbles: https://www.codechef.com/problems/MARBLES
Constraints:
>	1 <= k <=n <= 1000000
*/


#include <stdio.h>
#define min(a,b) (a>b?b:a)

//https://www.codechef.com/viewsolution/44350737
long long int sol1(long long int n, long long int k)
{
	n=n-1;
    k=k-1;
    long long ans=1;
    if (n-k<k)
		{k=n-k;}
    for(long long int j=0;j<k;j++)
	{
        ans = ans*(n-j);
	    ans = ans/(j+1);
	}
    return ans;
}


//https://www.codechef.com/viewsolution/36187061
long long int sol2(long long int n, long long int k)
{
	int i,div,mul;
	long long int ans=1LL;
    if(n<k){ans=0;}
    else if(n==k){ans=1;}
    else
        {
    	    n=n-1;
        	k=k-1;
            k=min((n-k),k);
            div=1;
            mul=n;
            while(div<=k)
            {
                ans=(ans*mul--)/(div++);
            }
        }
    return ans;
}


//https://www.codechef.com/viewsolution/36223124
long long int sol3(long long int n, long long int r)
{
	long long int ncr = 1;
    //scanf("%d %d", &n, &r);
	n--, r--;
	int nu[r], dn[r];
	r = (r < n-r ? r : n-r);   
	for(int i=0; i<=r; i++)
	{
		nu[i] = n-i;
	    dn[i] = r-i;
    }
    for(int i=0; i<=r; i++)
	{       
        for(int j=0; j<=r; j++)
		{
        	for(int k=dn[j]; k>=2; k--)
			{
				if(dn[j] % k == 0 && nu[i] % k == 0)
				{
                    nu[i] = nu[i]/k;
                    dn[j] = dn[j]/k;
                    k = dn[j]/k;
                }
            }
        }
    }
    for(int i=0; i<r; i++)
        ncr = ncr*nu[i];
	return ncr;
}



//https://www.codechef.com/viewsolution/29024629
long c(int n, int r)
{
    if(r == 0) 
        return 1;
    return c(n - 1, r - 1) * n / r;
}
long long int sol4(long long int n, long long int k)
{
	return c(n-1,k-1);
}



int main()
{
	long long int n,k;
    if((n<1||n>1000000)||(k<1||k>1000000))
    {
    return 0;
    }
    __CPROVER_assert(sol1(n,k)==sol2(n,k),"sol1Vsol2");
    __CPROVER_assert(sol1(n,k)==sol3(n,k),"sol1Vsol3");
    __CPROVER_assert(sol1(n,k)==sol4(n,k),"sol1Vsol4");
    __CPROVER_assert(sol2(n,k)==sol3(n,k),"sol2Vsol3");
    __CPROVER_assert(sol2(n,k)==sol4(n,k),"sol2Vsol4");
    __CPROVER_assert(sol3(n,k)==sol4(n,k),"sol3Vsol4");
    return 0;
}

//Tested using CBMC and found counterexamples for --unwind 1 for sol1vsol2 sol1vsol4 sol2vsol3 and sol3vsol4
//Bruteforce not attempted