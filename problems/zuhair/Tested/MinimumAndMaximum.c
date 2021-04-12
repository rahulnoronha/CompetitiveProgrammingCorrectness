//https://www.codechef.com/problems/MMAX
/*Constraints
1≤T≤10
2≤N≤10^5
2≤K≤10^100,000*/



//https://www.codechef.com/viewsolution/30904002

#include<stdlib.h>
#include<string.h>
int sol1(int n,char k[])
{
        //char k[100001] ;
        //scanf("%s",&k) ;

        int one=0,result,i=0 ;
        int len = strlen(k) ;
        for(i=0;i<len;i++)
        {
           one = (one*10 +(k[i] -'0'))%n ;
        }
        if( n%2 == 0)
        {
            if(one < n/2)
              result = 2*one ;

            else if(one == n/2)
                result = n-1 ;

            else
                result = 2*(n-one) ;
        }
        else
        {
           if(one > n/2)
            result = 2*(n-one) ;
           else
            result = 2*one ;
        }
     return result;
}



//https://www.codechef.com/viewsolution/32214858

#include<stdlib.h>
#include<string.h>
long long int sol2(long long int n,char k[])
{
        int i;
        //char k[100000];
        long long int count = 0;
        for(i = 0 ; i < strlen(k); i++)
        {
            count=(count*10+(k[i]-'0'))%n;
        }
        if(count > n-count)
        {
            count = n-count;
        }

        if(count == n-count)
        {
            return 2*count-1;
        }
        else
            return 2*count;
}




//https://www.codechef.com/viewsolution/26757797

//#include<stdio.h>
#include<math.h>
long long int sol3(long long int n,long long int k)
{
long long int i,h;
long long int s[n],a,b,c,temp,j,sum=0,b1=0,c1=0;
a=(k%n);
b=n-a;
if(a>b)
return b*2;
else if(b>a)
return a*2;
else if(b==a)
return a*2-1;
}



//https://www.codechef.com/viewsolution/25644461

//#include<stdio.h>
#include<string.h>
int sol4(int n,char k[])
{
            int i,rem=0;
            //char k[100001];
            int l=strlen(k);
            for(i=0;i<l;i++)
            rem=(rem*10+(int)k[i]-'0')%n;
       	       if(rem==0)
               return 0;
        		else
       	 		{
            			int one=rem;
            			int zero=n-rem;
           			int ans;
            			if(one<zero)
            			ans=one*2;
            			if(one>zero)
           			ans=zero*2;
           			if(one==zero)
           			ans=one*2-1;
            			return ans;
        		}
}




int main()
{

	long long int n;
        char k[100001];
	if(n<2||n>100000||strlen(k)>1000000||strlen(k)<2)
        return 0;
      	 __CPROVER_assert(sol1(n,k)==sol2(n,k),"sol1vsol2");
       	 __CPROVER_assert(sol1(n,k)==sol3(n,k),"sol1vsol3");
      	 __CPROVER_assert(sol2(n,k)==sol3(n,k),"sol2vsol3");
     	 __CPROVER_assert(sol1(n,k)==sol4(n,k),"sol1vsol4");
         __CPROVER_assert(sol2(n,k)==sol4(n,k),"sol2vsol4");
       	 __CPROVER_assert(sol3(n,k)==sol3(n,k),"sol3vsol4");

}

//Tested using cbmc and found no counterexamples. Unsatisfiable by time exceeded
//Bruteforce not attempted







