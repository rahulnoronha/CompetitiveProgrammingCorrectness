#include <stdio.h>
#include<stdlib.h>

/*
Suraj Goes Shopping:
Constraints:
>	1 <= N <= 1000
>	1 <= Cost of items <= 1000
*/


//https://www.codechef.com/viewsolution/36862266
int sol1(int n, int a [])
{
	 //unsigned long sum=0;
	 int i,flag=0,j,temp, sum=0;
	    for(i=0;i<n;i++)
	    {
	        for(j=i+1;j<n;j++)
	        {
	            if(a[i] > a[j])
	            {
	                temp=a[i];
	                a[i]=a[j];
	                a[j]=temp;
	            }
	        }
	    }
	    for(i=n-1;i>=0;)
	    {
	        if(flag == 0)
	        {
	            sum = sum + a[i] + a[i-1];
	            i=i-2;
	            flag=1;
	        }
	        else
	        {
	            flag=0;
	            i=i-2;
	        }
	    }
	return sum;
	    //sum=0;flag=0;
	    //printf("\n");
}


//https://www.codechef.com/viewsolution/39158078
int swarag(const void *z,const void *x)
{
	const int *u=z;
	const int *n=x;
	return *n-*u;}
int sol2(int d, int a[])
{
	int b,c,e,g,f,h,j;
	qsort(a,d,sizeof(long long int),swarag);
		j=0;
		for(e=0;e<d;)
		{
			j=j+a[e];
			e=e+1;
			if(e<d)
			j=j+a[e];
			e=e+3;}
	return j;
}


//https://www.codechef.com/viewsolution/42147325
int sol3(int c, int f[])
{
	int a,b,d,e;
	int g,h=0,i=0,j;
	for(d=0;d<c;d=d+1)
	      {
	            for(e=d+1;e<c;e=e+1)
	            {
	                  if(f[d]>f[e])
	                  {g=f[d];f[d]=f[e];f[e]=g;
	                  }
	                        
	            }
	      }
	     
	            for(d=c-1;d>=0;d=d-4)
	            h=h+f[d];
	            
	             for(d=c-2;d>=0;d=d-4)
	             i=i+f[d];
	            
	             j=i+h;
	return j;
}

int main()
{
	int n;
	if(n<1 || n> 1000)
		return 0;
	int m = (n > 0 ? n : 1);
  	int x[m];
  	int *a = (n > 0 ? x : NULL);
    __CPROVER_assert(sol1(n,a)==sol2(n,a),"sol1Vsol2");
    __CPROVER_assert(sol1(n,a)==sol3(n,a),"sol1Vsol3");
    __CPROVER_assert(sol2(n,a)==sol3(n,a),"sol2Vsol3");
}
