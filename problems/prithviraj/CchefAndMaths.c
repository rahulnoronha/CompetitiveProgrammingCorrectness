//https://www.codechef.com/problems/MATHL

/*
1≤N≤10^6
*/

//Using CBMC

//https://www.codechef.com/viewsolution/38034089

#include<math.h>
typedef long long int ll;
ll mod=1000000007;
long long int sol1(long long int n);
long long int sol1(long long int n)
{
    ll t,i,arr[1000000],ans[1000000];
    arr[0]=1;
    ans[0]=1;
    for(i=1;i<=1000000;i++)
    {
        arr[i]=(arr[i-1]*i)%mod;
        ans[i]=(ans[i-1]*arr[i])%mod;
    }
    return ans[n]%mod;

}

//https://www.codechef.com/viewsolution/32553731




#define mod 1000000007


#define mod 1000000007

int arr[1000005];

long long int sol2(long long int n);
long long int sol2(long long int n)
{
    long long fact = 1;
	arr[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		fact = (fact * i) % mod;
		arr[i] = (fact * arr[i - 1]) % mod;

	}
	return arr[n];
}

//https://www.codechef.com/viewsolution/29992055


#define M 1000000007
#define N 1000000

long long int sol3(long long int n);
long long int sol3(long long int n)
{
    long long int h=1,b[N],c[N],t,i;
	for(i=1;i<=N;i++)
        {	    h *= i;
	    h = h%M;
	    b[i-1] = h%M;	}
	h=1;
	for(i=0;i<N;i++)
	{	    h *=(b[i]);
	    h = h%M;
	    c[i] = h%M;	}

	    return c[n-1];
}

int main()
{

    long long int n;
    if(n<1||n>1000000)
        return 0;

    __CPROVER_assert(sol1(n)==sol2(n),"sol1vsol2");
    __CPROVER_assert(sol1(n)==sol3(n),"sol1vsol3");
    __CPROVER_assert(sol2(n)==sol3(n),"sol2vsol3");

    return 0;
}
