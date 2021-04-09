#include <stdio.h>
#include<string.h>

/*
Jewels and Stones: https://www.codechef.com/problems/STONES
*/

//https://www.codechef.com/viewsolution/43924601
int sol1(char* s, char* j)
{
	int a[26],b[26],aa[26],bb[26];
	int i;
	for(i=0;i<26;i++)
	{
	    a[i]=0;
	    aa[i]=0;
	    b[i]=0;
	    bb[i]=0;
	}
	for(i=0;i<strlen(s);i++)
	{
	    if(s[i]>='a'&&s[i]<='z')
		    a[s[i]-'a']++;
	    else
	        aa[s[i]-'A']++;
	}
	for(i=0;i<strlen(j);i++)
	{
	    if(j[i]>='a'&&j[i]<='z')
	        b[j[i]-'a']++;
	    else
	        bb[j[i]-'A']++;
	}
	int ans=0;
	for(i=0;i<26;i++)
	{
	    if(aa[i]!=0&&bb[i]!=0)
	        ans=ans+bb[i];
	    if(a[i]!=0&&b[i]!=0)
	        ans=ans+b[i];
	}
	return ans;
}


//https://www.codechef.com/viewsolution/39115230
int sol2(char* s, char* j)
{
	char pro=0;
    //scanf("%s %s",j,s);
    int i,l;
    for(i=0;s[i]!='\0';i++)
    {
        for(l=0;j[l]!='\0';l++)
        {
            if(s[i]==j[l])
            {
    	        pro++;
                break;
        	}
        }
    }
    return pro;
}


//https://www.codechef.com/viewsolution/38904602
int sol3(char*s, char* j)
{
	int count = 0;
	for(int k = 0; k<strlen(s); k++){
	    for(int l = 0; l<strlen(j); l++){
	        if(j[l] == s[k]){
	            ++count;
	            break;
	        }
	    }
	}
	return count;
}


//https://www.codechef.com/viewsolution/38100111
int sol4(char* s, char* j)
{
	int a[27]={0},b[27]={0},i,count=0,k;
	for(i=0;i<strlen(s);i++)
	{
	    for(k=0;k<strlen(j);k++)
	    {
	        if(s[i]==j[k])
	        {
	            count++;
	            break;
	        }
	    }
	}
	return count;
}


int main()
{
	char s[100],j[100];
	if(strlen(s)<1 || strlen(s)>100 || strlen(j)>100 || strlen(j)<1)
	{
		return 0;
	}
		__CPROVER_assert(sol1(s,j)==sol2(s,j),"sol1Vsol2");
    __CPROVER_assert(sol1(s,j)==sol3(s,j),"sol1Vsol3");
    __CPROVER_assert(sol1(s,j)==sol4(s,j),"sol1Vsol4");
    __CPROVER_assert(sol2(s,j)==sol3(s,j),"sol2Vsol3");
    __CPROVER_assert(sol2(s,j)==sol4(s,j),"sol2Vsol4");
    __CPROVER_assert(sol3(s,j)==sol4(s,j),"sol3Vsol4");
    return 0;
}

//Tested using cbmc and found no counterexample. Unsatisfiable
//Bruteforce check not attempted