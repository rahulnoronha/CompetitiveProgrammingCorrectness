//https://www.codechef.com/problems/STRCH/
//1≤T≤1,000 
//1≤N≤10^6
//S contains only lowercase English letters
//X is a lowercase English letter
//the sum of N over all test cases does not exceed 106
#include<stdlib.h>
//https://www.codechef.com/viewsolution/25938639

long int sol1(char *str, long long int n, char c);
long int sol1(char *str, long long int n, char c)
{
int count=0;
int k=0;
int i=0;
for(i=0;i<n;i++)
	    {
	        k++;
	        if(str[i]==c)
	        {
	           count=count+k+k*(n-i-1);
	           k=0;
	        }
	    }
	    return count;
}


//https://www.codechef.com/viewsolution/28043605

long int sol2(char* s,long int n, char c);
long int sol2(char* s,long int n, char c)
{
int res=0;
int flag=-1;
 for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]==c)
            {
              flag=i+1;
              res=res+(i+1);
            }
            else
            {
                if(flag!=-1)
                {
                    res=res+flag;
                }
            }
        }
        return res;
}

int main()
{
    long int n;
    char m;
    if(n<1||n>1000000)
    {
        return 0;
    }
    long int p = (n > 0 ? n : 1);
    char x[p];
    long long int q = p;
    char *y = (n > 0 ? x : NULL);
    __CPROVER_assert(sol1(y,q,m)==sol2(y,n,m),"sol1vsol2");
}


