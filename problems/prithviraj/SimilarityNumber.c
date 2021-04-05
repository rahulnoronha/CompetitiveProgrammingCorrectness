//https://www.codechef.com/problems/SIMNUM

//1 <= |S| <= 100000

//using CBMC

//https://www.codechef.com/viewsolution/33392669

#include<string.h>
long int sol1(char s[]);
long int sol1(char s[])
{
    long int c=strlen(s),j=0,flag;


      for(int i=1;i<strlen(s);i++)
	    {
	        flag=0;
	        if(s[i]==s[0])
	        {
	            for(j=0;s[i+j]!='\0';j++)
	            {
	                if(s[j]==s[i+j])
	                flag++;
	                else
	                break;
	            }

	        }
	        c=c+flag;

	    }
	    return c;

}

//https://www.codechef.com/viewsolution/33280207

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
long int sol2(char str[]);
long int sol2(char str[])
{

    long int t,i,j;
    char *p,*q;
    long int c=1,l=0,g=0;
        long int n;
        n=strlen(str);
        for(i=0;i<n;i++)
        { p=str+i;

            for(j=0;j<n;j++)
            { q=str + j;

            if(*p==*q)
            {
                l++;
                p++;

            }
            else
            break;
            }
        }
        return l;


}

//https://www.codechef.com/viewsolution/33270995


#include<string.h>
long int sol3(char s[]);
long int sol3(char s[])
{
    long long int n=strlen(s);
	     long long int sum=0;
	     long long int i,j,k;
	     for(i=0;i<n;i++)
	     {       k=i;
	            for(j=0;j<n;j++)
	            {
	               if(s[k]==s[j]&&k<n)
	               {sum++;
	               k++;
	               }
	               else if(s[k]!=s[j])
	               break;
	            }

	     }
	     return sum;
}

int main() {

	char s[100000];
	if(strlen(s)>100000||strlen(s)<1)
        return 0;

    __CPROVER_assert(sol1(s)==sol2(s),"sol1vsol2");
    __CPROVER_assert(sol1(s)==sol3(s),"sol1vsol3");
    __CPROVER_assert(sol2(s)==sol3(s),"sol2vsol3");





}

