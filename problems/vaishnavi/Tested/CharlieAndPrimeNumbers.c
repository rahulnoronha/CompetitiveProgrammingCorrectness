#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*
Charlie And Prime Numbers: https://www.codechef.com/problems/CDQU1
Subtask 1: (30 Points): M <=10^3, N<=10^3
Subtask 2: (70 Points): M<=5*10^6, N<=5*10^6 

All solutions clear both subtasks, Solution wise. 
Sol1, TLE.
*/

//For sol2
#define SIEVE_SIZE 5000100

//For sol3
int prime[5000000];

//https://www.codechef.com/viewsolution/37147613 
//Points scored, only 30, Correct solution but TLE, So shoudln't matter.
long long int sol1(int m, int n)
{
	long long int x,y,z,k,sum=0,s;
    while(m<=n)
    {
    	if(m==1)
			sum--;
		x=s;
    	z=0;
    	y=2;
    	k=sqrt(x);
    	while(y<=k)
    	{ 
    		if(x%y==0)
    		{		 
    			z=1;
    			break; 
    		}
    		y++;
    	} 
    	if(z==0)
    		sum+=x;
    	s++;
    }
   return sum;
}


//https://www.codechef.com/viewsolution/39067580
long long int sol2(int m, int n)
{
	long long *sieve, psum;
    int i, j, t;
    sieve = malloc((SIEVE_SIZE + 6) * sizeof(long long));
    sieve[0] = sieve[1] = 0;
    sieve[2] = sieve[3] = 1;
    for (i=4; i<SIEVE_SIZE; ) {
        sieve[i++] = 0;
        sieve[i++] = 1;
        sieve[i++] = 0;
        sieve[i++] = 1;
        sieve[i++] = 0;
        sieve[i++] = 0;
    }
    i = 4;
    while (i * i <= SIEVE_SIZE) {
        do {
            i++;
        } while (!sieve[i]);
        for (j=i*i; j<SIEVE_SIZE; j+=i) {
            sieve[j] = 0;
        }
    }
    for (i=psum=0; i<SIEVE_SIZE; i++) {
        if (sieve[i]) psum += i;
        sieve[i] = psum;
    }
    if (m < 1) m = 1;
        return (sieve[n] - sieve[m-1]);
}


//https://www.codechef.com/viewsolution/24174863
long long int sol3(int m, int n)
{
	long long int sum,x,y,i,j;

    prime[0]=prime[1]=1;
    for(i=4;i<=5000000;i+=2)
        prime[i]=1;
    for(i=3;i*i<=5000000;i+=2)
        for(j=i*i;j<=5000000;j+=2*i)
            prime[j]=1;
    sum=0;
    if(m>n)
    {
        x=m;y=n;
    }
    else
    {
        x=n;y=m;
    }
    for(i=y;i<=x;i++)
        if(prime[i]==0)
            sum+=i;
    
    return sum;
}

int main()
{
    int m,n;
    if(n<1||m<1||n>5000000||m>5000000)
    {
        return 0;
    }
    __CPROVER_assert(sol1(m,n)==sol2(m,n),"sol1vsol2");
    __CPROVER_assert(sol1(m,n)==sol3(m,n),"sol1vsol2");
    __CPROVER_assert(sol2(m,n)==sol3(m,n),"sol1vsol2");
}

//Tested using CBMC program takes long time to run suggesting Unsatisfiability
//Brute Force check not done


