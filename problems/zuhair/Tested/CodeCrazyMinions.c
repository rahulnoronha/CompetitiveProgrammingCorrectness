//https://www.codechef.com/status/NOCODING?sort_by=All&sorting_order=asc&language=11&status=15&handle=&Submit=GO
//Constraints
//1 ≤ T ≤ 100
//1 ≤ length of word ≤ 1000


//https://www.codechef.com/viewsolution/41685620

//#include<stdio.h>
#include<string.h>
char sol1(char *s);
char sol1(char *s)
{
        int i,l,n,count;
        //char s[1001];
        l=strlen(s);
        count=l+1;
        for(i=1;i<l;i++)
        {
            n=(int)s[i]-(int)s[i-1];
            if(n<0)
            {
              n=n+26;
            }
            count=count+n;
        }
        if(count<=(11*l))
        // return YES
		return 1;
        else
	// return No
        return 0;
    }

//https://www.codechef.com/viewsolution/42971528
//#include <stdio.h>
char sol2(char *str);
char sol2(char *str)
{
	    int i,x;
	    //char str[1001];
	    int len = strlen(str);
	    i=0,x=1;
	    while(i != len-1)
	    {
	        if(str[i] > str[i+1])
	        {
	            x = x+ (26 - (str[i] - str[i+1]));
	        }
	        else if(str[i] < str[i+1])
	        {
	            x = x - (str[i] - str[i+1]);
	        }
	        i++;
	    }
	    if((len+x) <= (11*len))
		    // return YES
	    return 1;
	    else
		    // return No
	    return 0;
}



int main()
{
    char string[1000];
    if(string==NULL) return 0;
    __CPROVER_assert(sol1(string)==sol2(string),"sol1vsol2");
}

//Tested with cbmc and found no counterexamples, ie it is unsatisfiable
//Brute Force Checking not done

