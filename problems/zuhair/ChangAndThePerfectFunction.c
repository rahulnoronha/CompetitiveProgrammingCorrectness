//https://www.codechef.com/problems/CHNGFUNC
/*
Constraints
1 ≤ A, B ≤ 106
*/


//https://www.codechef.com/viewsolution/27430817
#include<math.h>
int sol1(int a,int b);
int sol1(int a,int b)
{   
	int t,i,l,j,h;
	t=0;
 	l=((a*a)+b);
   	 l=sqrt(l);
    	for(i=1;i<=a;i++)
    	{
      		 for(j=1;j<=l;j++)
       		{
      	     		h=((j*j)-(i*i));
          		if((h<=b)&&(h>0))
           		t=(t+1);
       		}
       
       }
       return t;
}

//https://www.codechef.com/viewsolution/35615187
//#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int sol2(long long int a, long long int b);
long long int sol2(long long int a, long long int b)
{
	
		long long int i,j,x,count=0,f,chk;
		float res;
		for(i=1;i<=a;i++)
		{
			x=2*i+1;
			while(x<=b)
			{
				f=i*i+x;
				x+=1;
				res=sqrt(f);
				chk=sqrt(f);
				if((res-chk)==0)
				count++;
			}
		}
		return count;

}

//https://www.codechef.com/viewsolution/38765839\

#include<math.h>
long long int sol3(long long int a, long long int b);
long long int sol3(long long int a, long long int b)
{
	long long int i,j,c=0,f;
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			f=(int)sqrt(i*i+j);
			if((f*f)==(i*i+j))
				c++;
		}
	}
	return c;

}

int main()
{
    long long int a,b;
    if(a<1||b>100000)
        return 0;


    __CPROVER_assert(sol1(a,b)==sol2(a,b),"sol1vsol2");
    __CPROVER_assert(sol1(a,b)==sol3(a,b),"sol1vsol3");
    __CPROVER_assert(sol2(a,b)==sol3(a,b),"sol2vsol3");


}