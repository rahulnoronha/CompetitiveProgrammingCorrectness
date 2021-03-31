/*
Chef and The Modulo Game: https://www.codechef.com/problems/MGAME

Constraints:
1 <= N <= P <= 10^6

*/

#include<stdio.h>
#include<math.h>

//https://www.codechef.com/viewsolution/22489682
long long int sol1(long long int n, long long int p)
{
	long long int times,i,j;
    //scanf("%lld %lld",&n,&p);
    if(n<=2)
    {
      times=pow(p,3);
      return (times);
    }
    else
    {
      i=(p-(n-1)/2);
      j=p-n;
      times=i*i;
      times=times+(i*j);
      times=times+(j*j);
      return (times);
    }
}




//https://www.codechef.com/viewsolution/32427002
long long int sol2(long long int n, long long int p)
{
	//long long int n,p;
	//scanf("%lld",&n);scanf("%lld",&p);
	long long int res=0;
	if(n<=2)
	    return (p*p*p);
	else 
	{
	    res=(p-n)*(p-n);
	    res+=(p-n)*(p-(n-1)/2);
		res+=(p-(n-1)/2)*(p-(n-1)/2);
	    return (res);
	}
}




//https://www.codechef.com/viewsolution/23752668
long long int sol3(long long int n, long long int p)
{
	long long int i,j,n,p,k;
	//scanf("%lld %lld",&n,&p);
    i=(n-1)/2;
    j=(p-i)*(p-i)+(p-n)*(p-i)+(p-n)*(p-n);
    if(n==1 || n==2)
    {
        k=p*p*p;
    	return k;
    }
    else
    	return j;
}



//https://www.codechef.com/viewsolution/22489892
long long int sol4(long long int n, long long int p)
{
	sum=0;
	//scanf("%lld %lld",&n,&p);
	m=n-( (n/2)+1 );
	if(n==1 || m==0)
	{
		sum=(p)*p*p;
		return sum;
		continue;
	}
	i=1; //p/2 +1
	j=p-m;
	k=p-m;
	sum=i*j*k;
	i=p-n;
	j=p-n;
	k=1;
	sum=sum+i*j*k;
	i=p-n;
	j=1;
	k=p-m;
	sum=sum+i*j*k;
	return sum;
}


int main()
{
	long long int n,p;
	if((n<1||n>1000000)||(p<1||p>1000000))
    {
    return 0;
    }
    __CPROVER_assert(sol1(n,p)==sol2(n,p),"sol1Vsol2");
    __CPROVER_assert(sol1(n,p)==sol3(n,p),"sol1Vsol3");
    __CPROVER_assert(sol1(n,p)==sol4(n,p),"sol1Vsol4");
    __CPROVER_assert(sol2(n,p)==sol3(n,p),"sol2Vsol3");
    __CPROVER_assert(sol2(n,p)==sol4(n,p),"sol2Vsol4");
    __CPROVER_assert(sol3(n,p)==sol4(n,p),"sol3Vsol4");
    return 0;
}
