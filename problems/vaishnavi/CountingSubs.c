#include <stdio.h>
#include<stdlib.h>
/*
Counting Subs: https://www.codechef.com/problems/CSUB
*/

//https://www.codechef.com/viewsolution/43954662
long long int sol1(int n, char* a)
{
	int i,m=0;
    long long int x=0;
    for (i = 0; i<n; i++)
    {
        if(a[i]=='1')
        {
          m++;
        }  
    }
    for(i=1;i<=m;i++)
    {
      x=x+i;  
    }
    return x;
}

//https://www.codechef.com/viewsolution/38269773
long long int sol2(int N, char *s)
{
	long long int res,i,j;
	res=0;
	for(i=0;i<=N;i++)
	{
		//scanf("%c",&s);
		if(s[i]=='1')
			res=res+1;
	}
	return (res*(res+1)/2);
}

//https://www.codechef.com/viewsolution/30754595
long long int sol3(int n, char *ar)
{
	int f[100001];
	long long subs;
	for(int i=0;i<n;i++)
         f[i]=0;
    
        if(ar[0]=='1')
       {
           f[0]=1;
           subs++;
       }
    for(int i=1;i<n;i++)
    {
        if(ar[i]=='1')
        {
            f[i]=f[i-1]+1;          
        }
        else
        	f[i]=f[i-1];
    } 
    for(int i=1;i<n;i++)
    {
        if(ar[i]=='1')
    		subs=subs + f[i];
    } 
    return subs;
}

//https://www.codechef.com/viewsolution/28029771
long long int sol3(int N, char *str)
{
	long int no1=0;
	for(int i=0;i<N;i++)
	{  
	    if(str[i]=='1')
		{   //printf("entered\t");
	        no1++;  
	    }
	}
    
	long int count=(no1*(no1+1))/2;
	return count;
}

int main()
{
	int n;
	if(n<1 || n>100000 )
	{
    	return 0;
    }
    int m = (n > 0 ? n : 1);
	char x[m];
	char *a = (n > 0 ? x : NULL);
	__CPROVER_assert(sol1(n,a)==sol2(n,a),"sol1Vsol2");
  __CPROVER_assert(sol1(n,a)==sol3(n,a),"sol1Vsol3");
  __CPROVER_assert(sol2(n,a)==sol3(n,a),"sol2Vsol3");
}
