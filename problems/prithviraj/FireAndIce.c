//https://www.codechef.com/problems/FICE

/*
1<=T<=10^6
1<=N<=10^3
1<=M<=10^6
*/

//https://www.codechef.com/viewsolution/33333110

long long int nways[1005];


long long int ways(long long int n, long long int m){
	if (nways[n] != -1) return nways[n];
	nways[n] = (ways(n-1,m) + ways(n-2,m));
	if (nways[n] >= m) nways[n] = nways[n] - m;
	return nways[n];
}

long long int sol1(long long int n,long long int m);
long long int sol1(long long int n,long long int m)
{
    for (int j = 0; j <= n; j++) nways[j] = -1;
		nways[1] = nways[2] = 2;
		int ans = ways(n,m);
		return ans % m;
}


//https://www.codechef.com/viewsolution/23764860

void multiply(long long int F[2][2],long long int M[2][2],long long int m)
{
	    int x = (F[0][0]*M[0][0] + F[0][1]*M[1][0])%m;
		int y = (F[0][0]*M[0][1] + F[0][1]*M[1][1])%m;
		int z = (F[1][0]*M[0][0] + F[1][1]*M[1][0])%m;
		int w = (F[1][0]*M[0][1] + F[1][1]*M[1][1])%m;

		F[0][0] = x;
		F[0][1] = y;
		F[1][0] = z;
		F[1][1] = w;

}


void power(long long int F[2][2],long long int n,long long int m)
{
        long long int M[2][2] = {{1,1},{1,0}};
	    if(n==0 || n==1)
			return;
		power(F,n/2,m);
		multiply(F,F,m);
		if(n%2 !=0)
			multiply(F,M,m);
}

int fib1(long long int n,long long int m)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if(n==0)
	  return 0;
  power(F,n-1,m);
  return F[0][0];
}
long long int sol2(long long int n,long long int m);
long long int sol2(long long int n,long long int m)
{
    long long int sum=0;
    return (2*fib1(n,m))%m;
}


//https://www.codechef.com/viewsolution/19972971

#include <stdlib.h>

long long int sum(long long int a, long long int b, long long int m){
    return ((a % m) + (b % m) % m);
}

long long int mul(long long int a, long long int b, long long int m){
    return ((a % m) * (b % m) % m);
}

long long int fib(long long int n, long long int m){
long long int f[1001];
    if (n == 0){
        return 0;
    }
    if (n == 1 || n == 2){
        f[n] = 1;
        return f[n] % m;
    }
    if (f[n] >= 0){
        return f[n] % m;
    }

    long long int k = (n + 1) / 2;

    f[k]=fib(k, m);
    f[k-1]=fib(k-1, m);


    if(n % 2){
        k = (n + 1) / 2;
        f[n] = sum(mul(fib(k, m), fib(k, m), m), mul(fib(k-1, m), fib(k-1, m), m), m);
    }
    else{
        k = n / 2;
        f[n] = mul(sum(mul(2, fib(k - 1, m), m), fib(k, m),m), fib(k, m), m);
    }

    return f[n] % m;
}

long long int sol3(long long int n,long long int m);
long long int sol3(long long int n,long long int m)
{
long long int f[1001];
    long long int i;
    for(i = 0 ; i < 1001; i ++){
    	    f[i] = -1;
    	//    printf("%lld\n", (fib(i, 1000000) % 1000000));
    	}
	   return (fib(n, m) * 2) % m;
}


int main()
{
    long long int n,m;
    if((n<1||n>1000)||(m<1||m>1000000))
        return 0;
    __CPROVER_assert(sol1(n,m)==sol2(n,m),"sol1vsol2");
    __CPROVER_assert(sol1(n,m)==sol3(n,m),"sol1vsol3");
    __CPROVER_assert(sol2(n,m)==sol3(n,m),"sol2vsol3");
}


//Tested using CBMC and found no counter example
//Brute Force check not done










