#include<stdio.h>
#include<stdlib.h>

//Vaishnavi you hadn't included this 10^18=>n>=2
//For sol1
#define ll unsigned long long int
#define max 1000000000
ll prime[]={2,3,5,7,11,13,17,19,23,31,37};

/*For sol2
typedef unsigned long long int ull;
Because this was a repetition, I changed every ull in sol2's context to ll
*/


/*
SOLUTION 1: https://www.codechef.com/viewsolution/10759301
91 Lines 0.54 sec 2M
*/

ll mult_mod(ll a,ll b,ll mod);
ll mult_mod(ll a,ll b,ll mod)
{
	ll a_low=a%max;
	ll a_high=a/max;
	ll b_low=b%max;
	ll b_high=b/max;
	ll value,value1,value2,i;
	value=(a_high*b_high)%mod;
	for(i=1;i<=9;i++)
	{
		value=(value*10)%mod;
	}
	value1=(a_high*b_low)%mod;
	value2=(a_low*b_high)%mod;
	value1=(value1+value2)%mod;
	value=(value+value1)%mod;
	for(i=1;i<=9;i++)
	{
		value=(value*10)%mod;
	}
	value=(value+(a_low*b_low)%mod)%mod;
	return value;
}

ll power_mod(ll a,ll m,ll p);
ll power_mod(ll a,ll m,ll p)
{
	ll value=1;
	while(m>0)
	{
		if(m%2==1)
		{
		    if(value>max||a>max)
			    value=mult_mod(value,a,p);
			else
			    value=(value*a)%p;
		}
		if(a>max)
		    a=mult_mod(a,a,p);
		else
		    a=(a*a)%p;
		m>>=1;
	}
	return value;
}


ll primes1(ll n)
{
	ll m=n-1,iteration=11,i,value,j;
	ll k=0;
	while((m&1)==0)
	{
		m>>=1;
		k++;
	}
	for(i=1;i<=iteration&&prime[i-1]<n;i++)
	{
		value=power_mod(prime[i-1],m,n);
		if(value==1)
		{
			continue;
		}
		for(j=1;j<=k&&value!=n-1;j++)
		{
	    	if(value>max)
			{	
		    	value=mult_mod(value,value,n);
	    	}
			else
			{
		    	value=(value*value)%n;
			}
		}
		if(value!=n-1)
		{
			return 0;
		}
	}
	return 1;
}



ll sol1(ll n)
{
	ll i;
	for(i=n;i>=2;i--)
		{
			if(primes1(i))
			{
				return i;
				break;
			}
		}
}







/*
SOLUTION 2: https://www.codechef.com/viewsolution/6057530
88 Lines 0.02 sec 2M
*/

ll mul(ll a,ll b,ll n)	// Multiplication of two long long nos. modulo n
{
	ll s = ((long double)a*b/n) - 1;
	return (a*b - s*n)%n;
}

ll mo(int a,ll b,ll p)
{
	if(b==0) 
		return 1;
	ll res=mo(a,b/2,p);
	res=mul(res,res,p);
	if(b&1) 
		res=mul(a,res,p);
	return res;
}

int prime2(ll n)
{
	ll t = n-1,w;
	int s=0,i,j,flag=0;
	int a[]={2,3,5,7,11,13,17,19,23};
	for(i=0;i<9;i++)
	{
		if(n==a[i])
			return 1;
		if((n%a[i])==0)
			return 0;
	}
	while((t%2)==0)
	{
		t/=2;
		s++;
	}
	for(i=0;i<9;i++) 			// WitnessLoop : 9 times
	{
		flag=0;
		ll w=mo(a[i],t,n);		// a in the range[2,n-2]
		if(w==1 || w==(n-1))	//if 1 or n-1 do next WitnessLoop
		{
			continue;
		}
		for(j=1;j<s;j++)		//repeat (s-1) times
			{
				w=mul(w,w,n);	//x <- x2 mod n
				if(w == (n-1)) 
				{
				 flag=1; 
				 break; 
				}
				  				// n-1 -> next WitnessLoop
				if(w == 1) 
					return 0;	// x=1 : composite
			}
		if(flag) 
			continue;			// next WitnessLoop
		else 
			return 0;			//return composite
	}
	return 1;					//return prob. prime
}

ll sol2(ll n)
{
	ll n;
	if(n==2) 
	{
		return 2; 
		
	}
	if((n%2)==0) 
		n--;
	while(!prime2(n))
		n-=2;
	return n;
}


int main()
{
    long long int n;
    if (n<2)
    {
        return 0;
    }
    __CPROVER_assert(sol1(n)==sol2(n),"sol1vsol2");
    
}

//Tested with CBMC and found that it has no counterexample
//Brute force check not done

