//PROBLEM LINK -> https://www.codechef.com/problems/CMB01
/*
THIS PROBLEM DOES'NT HAVE ANY CONSTRAINTS


*/
// I HAVE FOUND ONE RECURSIVE SOLUTION AND ONE ITERATIVE(SOL1 & SOL2), SO I WOULD PREFER CBMC
//SOLUTION LINK ->  https://www.codechef.com/viewsolution/37290889
int f(int n);
int f(int n)
{
    int rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}
int sol1(int a,int b);
int sol1(int a,int b)
{
    return f(f(a) + f(b));
}
//solution link -> https://www.codechef.com/viewsolution/28069448

int sol2(int num1,int num2);
int sol2(int num1,int num2)
{
        int revnum1=0,revnum2=0;
	    while(num1>0)
	    {
	        revnum1=revnum1*10+num1%10;
	        num1=num1/10;
	    }
	     while(num2>0)
	    {
	        revnum2=revnum2*10+num2%10;
	        num2=num2/10;
	    }
	    int sum=revnum1+revnum2;
	    int revsum=0;
	    while(sum>0)
	    {
	        revsum=revsum*10+sum%10;
	        sum=sum/10;
	    }
return revsum;
}
//SOLUTION LINK -> https://www.codechef.com/viewsolution/4366311
#include <stdlib.h>

long int sol3(long int x,long int y);
long int sol3(long int x,long int y)
{
    int a=0,b=0,sum,sumrev=0,flag=0;
    while(x>0)
        {
            if(x%10!=0)
                flag=1;
            else if(flag==0)
            {
                x/=10;
                continue;
            }
            a*=10;
            a=a+(x%10);
            x/=10;
        }
        flag=0;
        while(y>0)
        {
            if(y%10!=0)
                flag=1;
            else if(flag==0)
            {
                y/=10;
                continue;
            }

                b*=10;
                b=b+(y%10);
                y/=10;
        }
        sum=a+b;
        flag=0;
        while(sum>0)
        {
             if(sum%10!=0)
                flag=1;
            else if(flag==0)
            {
                sum/=10;
                continue;
            }
                sumrev*=10;
                sumrev=sumrev+(sum%10);
                sum/=10;

        }
return sumrev;
}


//SOLUTION LINK -> https://www.codechef.com/viewsolution/1183814

int sol4(int x,int y);
int sol4(int x,int y)
{
    int n,i,j,k;
    i=0;
              j=0;
              k=0;
    while(x%10==0)
              {
                            x=x/10;
              }
              // printf("%d\n",x);
              while(y%10==0)
              {
                            y=y/10;
              }
             //  printf("%d\n",y);
              while(x!=0)
              {
                      i=i*10;
                      i=i+x%10;
                      x=x/10;
              }
             //  printf("%d\n",i);
              while(y!=0)
              {
                      j=j*10;
                      j=j+y%10;
                      y=y/10;
              }
              // printf("%d\n",j);
              k=i+j;
              j=0;
            //  printf("%d\n",k);
              while(k!=0)
              {
                      j=j*10;
                      j=j+k%10;
                      k=k/10;
              }
return j;
}

int main()
{
    int a, b;
    __CPROVER_assert(sol1(a,b)==sol2(a,b),"sol1vsol2");
    __CPROVER_assert(sol1(a,b)==sol3(a,b),"sol1vsol2");
    __CPROVER_assert(sol2(a,b)==sol3(a,b),"sol1vsol2");
    //Tested with CBMC and found no counterexample
    //Did not create a brute force checker
}
