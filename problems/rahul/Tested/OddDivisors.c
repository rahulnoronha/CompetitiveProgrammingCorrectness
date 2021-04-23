//problem link: https://www.codechef.com/problems/ODDDIV
/*
Constraints
1 ≤ T ≤ 10
1 ≤ l ≤ r ≤ 10^5
*/

#include<stdio.h>
long long baal[100005];

//Solution Link: https://www.codechef.com/viewsolution/29108523
long long oddsum(int n)
{
	long long s=0,i,a;
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			if(i%2==1)
			{

				s=s+i;
				a=n/i;
				if(a!=i)
				if(a%2==1)
					s=s+a;
			}
			else if(i%2==0)
			{
				a=n/i;
				if(a%2==1)
					s=s+a;
			}
		}
	}
    return s;
}

long long int sol1(int l, int r)
{
	long long i;
	for(i=1;i<=100000;i++){
		baal[i]=oddsum(i);
	}
	
		long long s=0;
		for(i=l;i<=r;i++){
			s=s+baal[i];
		}
		return s;
}


//Solution Link: https://www.codechef.com/viewsolution/33219405
long long int sol2(long long int l, long long int r)
{
	long long int i,total=0;
	for(i=1;i<=r;i+=2)
	    total=total+(r/i)*i-((l-1)/i)*i;
	return total;
}

//Solution Link: https://www.codechef.com/viewsolution/40680881
long long int sol3(int l, int r)
{
	int i;
	long long int s2,s1;
	s2=0;s1=0;

		for(i=1;i<=r;i=i+2)
			s2 = s2 + i*(r/i);
		for(i=1;i<=l-1;i=i+2)
			s1 = s1 + i*((l-1)/i);
		return (s2-s1);
}

int main()
{
	int l, r;
	if(l<1||l>100000||r<1||r>100000)
		return 0;
	__CPROVER_assert(sol1(l,r)==sol2(l,r),"sol1vsol2");
	__CPROVER_assert(sol1(l,r)==sol3(l,r),"sol1vsol3");
	__CPROVER_assert(sol2(l,r)==sol3(l,r),"so21vsol3");
}

//Tested using CBMC, --unwind 10 time exceeded, Unsatisfiable
//Bruteforce not done