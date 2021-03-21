#include<stdio.h>
#include<string.h>

/*
Penalty Shoot Out: https://www.codechef.com/problems/PSHOT
Constraints:
>	1 <=N <= 10^5
> 	S contains only characters '0' and '1'
>	The sum of N over all test cases does not exceed 10^6

I've used strncpy to get the passed string s to the size 2*n according to the question.
*/

//https://www.codechef.com/viewsolution/40016333
int sol1(int n, char* s)
{
	int i,a=0,b=0,ans=2*N;
    char arr[2*N];
    strncpy(arr,s,2*N);
    for(i=0; i<=2*N-2; i=i+2)
    {
        if(arr[i]=='1')
			a++;
        if(((N-i/2)+b<a) || (b-a>N-(i+2)/2) )
        {
            ans=i+1;
            break;
        }
        if(arr[i+1]=='1')
			b++;
        if(((N-(i+2)/2)+b<a) || (b-a>N-(i+2)/2))
        {
            ans=i+2;
            break;
        }
	}
	return ans;
}



//https://www.codechef.com/viewsolution/30687024
int sol2(int n, char* s)
{
	int a=0,b=0,flag,i,k1=0,k2=0;
    char str[2*n];
    strncpy(str,s,2*n);
    for(i=0;i<2*n;i++)
    {
		if(str[i]=='1'&&i%2==0)
        {
        	a++;
            k1++;
        }
        else if(str[i]=='1'&&i%2==1)
        {
        	b++;
            k++;
        }
        else if(str[i]=='0'&&i%2==1)
        	k2++;
        else if(str[i]=='0'&&i%2==0)
            k1++;
        if(a>=b&&(a-b)>(n-k2))
            break;
        else if(b>a&&(b-a)>(n-k1))
            break;
    }
    if(i==2*n)
    	return (2*n);
    else
		return (i+1);
}



//https://www.codechef.com/viewsolution/29829328
int sol3(int n, char* source)
{
	int i,f=0,f1=0,l=0,l1=0,boo=1;
	strncpy(s,source,2*n);
	for(i=0;i<2*n;i++)
	{
	    if(i%2==0)
	    {
	        f+=s[i]-'0';f1++;
	    }
	    else
	    {
	        l+=s[i]-'0';l1++;
	    }
		//printf("%ld %ld %ld %ld",f,l,f1,l1);
	    if((l>(n-f1)+f)||(f>(n-l1)+l))
	    {
	        return (i+1);
	        boo=0;
	    	break;
	    }
	}
	if(boo==1)
		return (2*n);
}

int main()
{
    int n;
    if(n<0||n>100000)
    {
        return 0;
    }
    int m = (n>0?n:1);
    char x[m] ;
    char* y = (n>0?x:NULL);
    __CPROVER_assert(sol1(n,y)==sol2(n,y),"sol1vsol2");
    __CPROVER_assert(sol1(n,y)==sol3(n,y),"sol1vsol3");
    __CPROVER_assert(sol2(n,y)==sol3(n,y),"sol1vsol2");
}


