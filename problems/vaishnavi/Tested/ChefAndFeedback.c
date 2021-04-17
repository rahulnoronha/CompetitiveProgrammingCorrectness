#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Ched and Feedback: https://www.codechef.com/problems/ERROR
*/

//https://www.codechef.com/viewsolution/44835153
char* sol1(char* s)
{
	int flag;
	long long int j=2;
	while(s[j]!=0)
	{
	    if(s[j]=='1' && s[j-1]=='0' && s[j-2]=='1')
	    {
	        flag=1;
	        break;
	    }
	    else
	    {
	        if(s[j]=='0' && s[j-1]=='1' && s[j-2]=='0')
	        {
	            flag=1;
	            break;
	        }
	    }
	    j++;
	}
	if(flag==1)
		return "Good\n";
	else
	    return "Bad\n";
}


//https://www.codechef.com/viewsolution/43848560
char* sol2(char* s)
{
	int flag=0;
	    long int n=strlen(s);
	    for(int i=0;s[i]!='\0';i++)
	    {
	        if(s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0'&&i!=n-1&&i!=n-2)
	        {
	            flag=1;   
	        }
	        if(s[i]=='1'&&s[i+1]=='0'&&s[i+2]=='1'&&i!=n-1&&i!=n-2)
	        {
	            flag=1;
	        }
	    }
	    if(flag==0)
	    {
	        return "Bad\n";
	    }
	    else
	    {
	        return "Good\n";
	    }
}



//https://www.codechef.com/viewsolution/41632698
char* sol3(char* s)
{
	int flag=0;
	int l=strlen(s);
        if(l<3)
        {
            return "Bad\n";
            //continue;
        }
        for(int i=0;i<l-2;i++)
        {
            if((s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0')||(s[i]=='1'&&s[i+1]=='0'&&s[i+2]=='1'))
            {
                return "Good\n";
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return "Bad\n";
        }
}



//https://www.codechef.com/viewsolution/37210435
char* sol4(char* feed)
{
	int flag=0,i;
	//gets(feed);
	for(i=0;feed[i]!='\0';i++)
	{
		if((feed[i]=='0'&&feed[i+1]=='1'&&feed[i+2]=='0')||(feed[i]=='1'&&feed[i+1]=='0'&&feed[i+2]=='1'))
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		return "Good\n";
	}
	else
		return "Bad\n";
}


int main()
{
	char* s;
	if(strlen(s)>100000)
	{
		return 0;
	}
	for(int i=0;i<strlen(s)-1;i++)
		if(s[i]!=0 || s[i]!=1)
			return 0;
    __CPROVER_assert(sol1(s)==sol2(s),"sol1Vsol2");
    __CPROVER_assert(sol1(s)==sol3(s),"sol1Vsol3");
    __CPROVER_assert(sol1(s)==sol4(s),"sol1Vsol4");
    __CPROVER_assert(sol2(s)==sol3(s),"sol2Vsol3");
    __CPROVER_assert(sol2(s)==sol4(s),"sol2Vsol4");
    __CPROVER_assert(sol3(s)==sol4(s),"sol3Vsol4");
}

//Tested using cbmc and found no counterexample. Unsatisfiable
//Bruteforce check not attempted
