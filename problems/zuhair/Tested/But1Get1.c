//https://www.codechef.com/problems/BUY1GET1
//Constraints
//1 ≤ T ≤ 100
//1 ≤ |S| ≤ 200, where |S| represents the length of the string S.
//The string S is case sensitive, and will contain only English characters in the range [a-z], [A-Z].

//https://www.codechef.com/viewsolution/38302474
#include <stdio.h>
int sol1(int *arr, int len);
int sol1(int *arr, int len)
{
int c=0 , i;
for(i=0;i<len;i++) arr[i]=0;
        {
            arr[arr[i]-'A']++;
        }
        for(i=0;i<100;i++)
        {
            c = c + arr[i]/2;
	        if(arr[i]%2 == 1)
	        c++;
        }
        return c;
}

//https://www.codechef.com/viewsolution/36223608
#include <stdio.h>
#include<string.h>
int sol2(int *arr, int len);
int sol2(int *arr, int len)
{
int count=0, i;
for(i=0;i<len;i++) arr[i]=0;
        {
            arr[arr[i]-65]++;
        }
        for(i=0;i<58;i++)
        {
            count+=((arr[i]/2)+(arr[i]%2));
        }
        return count;
}


//https://www.codechef.com/viewsolution/30625052
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int sol3(int *str, int len);
int sol3(int *str, int len)
{
int small[26];
int capital[26];
int ans;
for(int i=0;i<26;i++)
	    {
	        small[i]=0;
	        capital[i]=0;
	    }
	    
	    for(int i=0;i<len;i++)
	    {
	        int ch=str[i];
	        if(islower(ch))
	        small[ch-'a']++;
	        else
	        capital[ch-'A']++;
	    }
	    
	    for(int i=0;i<26;i++)
	    {
	    ans+=(small[i]+1)/2;
	    ans+=(capital[i]+1)/2;
	    }
return ans;
}


//https://www.codechef.com/viewsolution/8583229
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int sol4(int *count , int *str , int len);
int sol4(int *count , int *str , int len)
{
int i, sum=0;
for(i=0;i<len;i++)
      count[str[i]]++;
     for(i=50;i<140;i++)
   {  if(count[i]==0)
   continue;
       if(count[i]%2==0)
       sum+=count[i]/2;
       else if(count[i]%2!=0)
       sum+=(count[i]-1)/2+1;
          }
   return sum ;
}

int main()
{
    int n;
    if(n<1||n>200)
    {
        return 0;
    }
     int m = (n > 0 ? n : 1);
     int x[m];
     int z[m];
     int *y = (n > 0 ? x : NULL);
     int *w = (n > 0 ? z : NULL);
     __CPROVER_assert(sol1(y,n)==sol2(y,n),"sol1vsol2");
     __CPROVER_assert(sol1(y,n)==sol3(y,n),"sol1vsol3");
     __CPROVER_assert(sol1(y,n)==sol4(y,w,n),"sol1vsol4");
     __CPROVER_assert(sol2(y,n)==sol3(y,n),"sol2vsol3");
     __CPROVER_assert(sol2(y,n)==sol4(y,w,n),"sol2vsol4");
     __CPROVER_assert(sol3(y,n)==sol4(y,w,n),"sol3vsol4");
     
}

//Tested But1Get1.c and found no counter example.
//Did not perform brute force check.

