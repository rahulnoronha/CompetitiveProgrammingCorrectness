#incldue<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

/*
Self Destructing Strings: https://www.codechef.com/problems/SDSTRING
Constraints:
>	1 <= |s| <= 10^6
>	String s contains only characters '0' and '1'
>	The sum of |s| over all test cases does not exceed 10^6

*/

//https://www.codechef.com/viewsolution/40721031
long long int sol1(char* str)
{
	char ch;
	long long int res;
	//scanf("%c",&ch);;
	long long int count1=0,count2=0;
	long long int len = strlen(str);
	for(long long int i=0;str[i]!='\0';i++)
	{
	    if(str[i]=='0')
	        count1++;
	    else if(str[i]=='1')
	        count2++;
	}
	if(strlen(str)%2==1 || count1==0 || count2==0)
	    res=-1;
	else
	{
	    res=abs(count1-count2)/2;
	}
	return res;
}


//https://www.codechef.com/viewsolution/40921913
long long int sol2(char*)
{
    long long int i=0,n=0,count=0,count1=0,count2=0,count3=0;
	  while(s[i]!='\0')
    {
        i++;
        n++;
    }
    if(n%2!=0)
        return -1;
    else
    {
    	for(long long int k=0;k<n;k++)
        {
            if(s[k]=='1')
                count++;
            else
            {
                count1++;
            }
        }
        if(count==0||count1==0)
        	return -1;
        else
        {
            count2=count-count1;
            if(count2<0)
                count2=(-1)*count2;
            count3=count2/2;
            return count3;
        }
    }
}


//https://www.codechef.com/viewsolution/40645178
long long int sol3(char* str)
{
	long long int i,s1=0,s0=0,n,res;
	n=strlen(str);
	if(n%2!=0)
		return -1;
	else
	{
	   for(i=0;i<n;i++)
	   {
	   		if(str[i]=='1')
			   s1++;
			else
				s0++;   	
		}
		if(s1==0||s0==0)
			return -1;
		else
		{
			res=(abs(s1-s0))/2;  
			return res; 
	    }     
}

int main()
{
    int n;
    if (n<1||n>1000000)
    {
        return 0;
    }
    char m = (n>0?n:1);
    char *y = (n>0?y:NULL);
    __CPROVER_assert(sol1(y)==sol2(y),"sol1vsol2");
    __CPROVER_assert(sol1(y)==sol2(y),"sol1vsol3");
    __CPROVER_assert(sol1(y)==sol2(y),"sol2vsol3");
    
}


