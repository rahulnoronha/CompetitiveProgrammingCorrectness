#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
#define MOD 1000000007 


/*
Climbing Stairs: https://www.codechef.com/problems/CLMBSTRS
Constraints:
>	1 <= N <= 1000000
>	0 <= G <= 50
*/


//https://www.codechef.com/viewsolution/43955885
void mul(long long F[][2],long long M[][2]) // FUNCTION TO MULTIPLY TWO MATRIX
{
	long long x=((F[0][0]*M[0][0])%1000000007 + (F[0][1]*M[1][0])%1000000007)%1000000007;
	long long y=((F[0][0]*M[0][1])%1000000007 + (F[0][1]*M[1][1])%1000000007)%1000000007;
	long long z=((F[1][0]*M[0][0])%1000000007 + (F[1][1]*M[1][0])%1000000007)%1000000007;
	long long w=((F[1][0]*M[0][1])%1000000007 + (F[1][1]*M[1][1])%1000000007)%1000000007;
	F[0][0]=x;
	F[0][1]=y;
	F[1][0]=z;
	F[1][1]=w;
}
void powerf(long long F[2][2],long long n) // RECURSIVE FUNCTION FOR MATRIX
{
	if(n==0 || n==1)
		return;
		
	long long M[2][2]={0,1,1,1};
	
	powerf(F,n/2);
	mul(F,F);
	if(n%2!=0)
		mul(F,M);
}

long long fib1(long long n) //FUNCTION CALLED FROM main
{
	long long F[2][2]={0,1,1,1};
	long long result;
	
	if(n==0)
		return 0;
	else if(n==1 || n==2)
		return 1;
	
		
	powerf(F,(n-1));
	
	return (F[0][0]+F[0][1]);
}

char* sol1(long long int num, long long int guess)
{
	num++;
	long long ways=fib1(num);
	ways=ways%1000000007;
	long ones=0;
	while(ways!=0)
	{
		ones+=(ways%2);
		ways/=2;
	}
	//printf("ones= %ld\n",ones);
	if(guess==ones)
		return "CORRECT\n";
	else
		return "INCORRECT\n";
}






//https://www.codechef.com/viewsolution/26913090
char* sol2(long long int M, long long int G)
{
	int i, a[1000006], temp, N, count, value;
    a[1]=1;a[2]=2;
    for (i = 3; i < 1000001; i++) {
        a[i] = (a[i-1] + a[i-2]) % MOD;
    }
    count=0;
    temp = a[M];
    while(temp != 0)
	{
    	if(temp % 2 == 1)
		{
            count++;
        }
        temp/=2;
    }
    if(count==G)
	{
       return "CORRECT\n";
    }
    else
	{
    	return "INCORRECT\n";
    }
}




//https://www.codechef.com/viewsolution/13425997
long long int fib3(long long int n)
{
    long long int i = n - 1, a = 1, b = 0, c = 0, d = 1, t;
    if (n <= 0)
        return 0;
    while (i > 0) 
	{
        if (i % 2 == 1) 
		{
            t = (d*(b + a) + c*b) % MOD;
            a = (d*b + c*a) % MOD;
            b = t;
        }
        t = (d*(2*c + d)) % MOD;
        c = (c*c + d*d) % MOD;
        d = t;
        i = i / 2;
    }
    return (a + b) % MOD;
}

long long int countSetBits(long long int n)
{
    long long int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}

char* sol3(long long int number, long long int guess)
{
	long long int ways, rem, number_of_ones;
	//scanf("%lld%lld",&number, &guess);
    ways = fib3(number + 1);
    number_of_ones = 0;
    number_of_ones = countSetBits(ways);
    //printf("Number of ones = %ld\n", number_of_ones);
    if(number_of_ones == guess) 
	{
        return "CORRECT\n";
    }
    else 
	{
    	return "INCORRECT\n";
    }
}




int main()
{
	long long int n,g;
	if((n<1||n>1000000)||(g<1||g>50))
    {
    return 0;
    }
    __CPROVER_assert(sol1(n,g)==sol2(n,g),"sol1Vsol2");
    __CPROVER_assert(sol1(n,g)==sol3(n,g),"sol1Vsol3");
    __CPROVER_assert(sol2(n,g)==sol3(n,g),"sol2Vsol3");
    return 0;
}
