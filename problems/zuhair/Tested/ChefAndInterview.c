//https://www.codechef.com/problems/CHEFLCM

/* Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 10^9
Subtask 1 (30 points):

1 ≤ T ≤ 100
1 ≤ N ≤ 10^5
Subtask 2 (70 points):

original constraints */

//https://www.codechef.com/viewsolution/28748109
long int sol1(long int n);
long int sol1(long int n)
{
	    int i,a[100],j=0;
	    long int sum=0;
	    for(i=1;i<=n;i++)
	    {
	        if(n%i==0)
	        {
	            a[j]=i;
	            j++;
	        }
	    }
	    for(i=0;i<j;i++)
	    {
	        sum=sum+a[i];
	    }
	   return sum;
}

//https://www.codechef.com/viewsolution/37369015
#include<math.h>
long long int sol2(long long int n);
long long int sol2(long long int n)
{
    long long i,l,sum;
        l=sqrt(n);
        sum=0;
        for(i=1;i<=l; i++)
        {
            if(n%i==0)
                sum=sum+i;
            if(i*i!=n && n%i==0)
                sum=sum+(n/i);
        }
       return sum;

}



int main()
{
    long long int n;
    if(n<1||n>1000000000)
        return 0;


    __CPROVER_assert(sol1(n)==sol2(n),"sol1vsol2");

}

//Tested using cbmc and found no counterexamples. Unsatisfiable
//Bruteforce not attempted
