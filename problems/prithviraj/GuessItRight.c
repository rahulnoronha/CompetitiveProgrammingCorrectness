//https://www.codechef.com/problems/GUESSRT
/*
1≤N<K≤3*10^4
1≤M≤3*10^4
*/
//Using CBMC


//https://www.codechef.com/viewsolution/23156193

#include <math.h>

long long M = 1000000007;

long long gcd(long long a,long long b)
{
    if(b<=0)
     return a;
   else
     return gcd(b,a%b);
}

long long int modmult(long long int a,long long int b)
{
  return (a*b)%M;
}

int power(int a,int b)
{
  if(b<=0)
    return 1;
  else
  {
    long long r;
    r = power(a,b/2)%M;
    if(b%2!=1)
    {
      return modmult(r,r);
    }
    else
    {
      return modmult(a,modmult(r,r));
    }
  }
}
long long int fun1(long long n, long long k ,long long m)
{
  long long int p,q,qp,ans,d1,d2;
  q = power(n,(m+1)/2)%M;
  p = (q - power(n-1,(m+1)/2))%M;
  if(p<0)
    p = p+M;
  qp = power(q,M-2)%M;
  ans = (p*qp)%M;
  return ans ;

}

long long int fun2(long long n, long long k ,long long m)
{
  long long int p,q,qp,ans,d1,d2;
  d1 = gcd(n+k-1,n);
  d2 = gcd(n+k,n-1);
  q = (((power(n,(m-2)/2)*(n/d1))%M)*(n+k)/d2)%M;
  p = (q - (((power(n-1,(m-2)/2)*((n-1)/d2))%M)*(n+k-1)/d1)%M)%M;
  if(p<0)
    p = p+M;
  qp = power(q,M-2)%M;
  ans = (p*qp)%M;
  return ans;
}

int sol1(long long int n,long long int k,long long int m);
int sol1(long long int n,long long int k,long long int m)
{
    long long int a;
    if(m%2!=0)
    {
      a=fun1(n,k,m);

    }
    else
    {
      a=fun2(n,k,m);

    }
    return a;
}

//https://www.codechef.com/viewsolution/23088836


long long int gcd2(long long int a,long long int b)
{
    if(b==0)
    return a;
    return gcd2(b,a%b);
}
long long int powr(long long int a,long long int n,long long int m){
    long long int res=1;
    while(n>0){
        if(n&1)
        res=(res*a)%m;

        a=(a*a)%m;
        n=n>>1;
    }
    return res;
}
int sol2(long long int n,long long int k,long long int m)
{
    long long int i,j,mod=1000000007,p,q;
    if(m%2==1)
    {
    p = (powr(n,(m+1)/2,mod) - powr(n-1,(m+1)/2,mod)+mod)%mod;
        q=powr(n,(m+1)/2,mod)%mod;
    }
   else
   {    j=m;
        m--;
    p = (powr(n,(m+1)/2,mod) - powr(n-1,(m+1)/2,mod)+mod)%mod;
    q=powr(n,(m+1)/2,mod)%mod;
p=((p%mod)*(((powr(n,j/2,mod))*(n+k))%mod)+(powr(n-1,j/2,mod)*q)%mod+mod)%mod;
       q=((q*((powr(n,j/2,mod)))%mod)*(n+k))%mod;
    }
    i=gcd2(p,q);
    q=q/i;
    p=p/i;
    q=powr(q,mod-2,mod);
    return (p*q)%mod;
}

//https://www.codechef.com/viewsolution/23085915

#include <stdlib.h>
#include <math.h>

long long int gcd3(long long int a,long long int b);
long long int modInverse(long long int a,long long int m);
long long int power2(long long int x,long long int y, long long int m);

int sol3(long long int n,long long int k,long long int m)
{
    long long int i,j,p,q,l,NIX,x,NI,NX;
        if(n==1) { p=1; q=1; return 1;}
        if(m%2>0)
        {
            x=floor(m/2)+1;
            NX=power2(n,x,1000000007);
            NIX=power2(n-1,x,1000000007);
            if(NX-NIX<0) { NX+=1000000007; }
            p=(NX-NIX)%1000000007;
            q=NX%1000000007;
        }
        if(m%2==0)
        {
            x=m/2;
            NX=power2(n,x,1000000007);
            NIX=power2(n-1,x,1000000007);
            if(NX-NIX<0) { NX+=1000000007; }
            p=(((NX-NIX)%1000000007*(n+k))%1000000007+NIX)%1000000007;
            q=(NX*((n+k)%1000000007))%1000000007;
        }
        j=modInverse(q,1000000007)%1000000007;
        //if(NX-NIX<0){ printf("no");}
        l=(p*j)%1000000007;
        return l;
}

long long int gcd3(long long int a,long long int b)
{
    if (b == 0)
        return a;
    return gcd3(b, a % b);
}

long long int modInverse(long long int a,long long int m)
{
    long long int g = gcd3(a, m);
    /*if (g != 1)
        printf("Inverse doesn't exist"); */

        return power2(a, m-2, m);
}
long long int power2(long long int x,long long int y, long long int m)
{
    if (y == 0)
        return 1;
    long long int p = power2(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

int main()
{
    long long int n,k,m;
/*
1≤N<K≤3*10^4
1≤M≤3*10^4
*/
    if(n<1||k>3*10000||n>k)
        return 0;
    if(m<1||m>3*10000)
        return 0;
    __CPROVER_assert(sol1(n,k,m)==sol2(n,k,m),"sol1vsol2");
    __CPROVER_assert(sol1(n,k,m)==sol3(n,k,m),"sol1vsol3");
    __CPROVER_assert(sol2(n,k,m)==sol3(n,k,m),"sol2vsol3");

}




