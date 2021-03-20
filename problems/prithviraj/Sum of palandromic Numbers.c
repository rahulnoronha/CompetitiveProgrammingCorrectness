//PROBLEM LINK -> https://www.codechef.com/problems/SPALNUM
/*
1 ≤ T ≤ 100
Subtask 1 (34 points) : 1 ≤ L ≤ R ≤ 10^3
Subtask 2 (66 points) : 1 ≤ L ≤ R ≤ 10^5
*/

//SOLUTION LINK-> https://www.codechef.com/viewsolution/39987650
// TRY CBMC OR BRUTE FORCE WHICHEVER SEEMS APPROPRIATE FOR THIS, I THINK CBMC IS BETTER FOR THIS!!


long int sol1(int a,int b);
long int sol1(int a,int b)    //finds the sum of palindrome numbers between range :[a,b]
{
    int i; long int s=0;
    	for(i=a;i<=b;i++)
    	{
        	int reverse=0, rem,temp=i;
        	while(temp!=0)
            {
                rem=temp%10;
                reverse=reverse*10+rem;
                temp/=10;
            }
            if(reverse==i) s+=i;
        }
return s;
}


//SOLUTION LINK-> https://www.codechef.com/viewsolution/40223743

#include<stdlib.h>

int sol2(int x,int y);
int sol2(int x,int y)
{
    int sum=0,i;
    for(i=x;i<=y;i++)
                {
                if(ispalin(i))
                    sum+=i;
                }
return sum;
}
int reverse(int);
int ispalin(int);

int ispalin(int n)
{
    int rev;
    rev=reverse(n);
    if(n==rev)
        return 1;
    else
        return 0;
}

int reverse(int n)
{
    int temp,rev=0;
    while(n!=0)
        {
        temp=n%10;
        n/=10;
        rev=rev*10+temp;
        }
    return rev;
}



//SOLUTION LINK-> https://www.codechef.com/viewsolution/39821768

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

long long int sol3(long long int l,long long int r);
long long int sol3(long long int l,long long int r)
{
    long long int sum=0;
    for (int i=l; i<=r; i++)
        {
            char A[100001];
            sprintf(A, "%d", i);
            int len = strlen(A), k=len-1, j=0;
            bool flag=true;
            while(j<k)
            {
                if (A[j]!=A[k])
                {
                    flag=false;
                    break;
                }
                j++;
                k--;
            }
            if (flag==true)
            {
                sum+=i;
            }
        }
return sum;
}

