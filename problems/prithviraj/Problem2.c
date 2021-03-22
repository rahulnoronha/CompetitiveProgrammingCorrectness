//https://www.codechef.com/problems/CMB02
/*
given positive integer K of not more than 5 digits.
*/

//TRY CBMC

//https://www.codechef.com/viewsolution/40333320

#include<stdlib.h>


int reverse(int);

int ispalin(int x)
{
    int rev=reverse(x);
    if(rev==x)
        return 1;
    else
        return 0;
}

int reverse(int x)
{
    int temp,rev=0;
    while(x!=0)
    {
        temp=x%10;
        x/=10;
        rev=rev*10+temp;
    }
    return rev;
}

int sol1(int N);
int sol1(int N)
{
    for(int i=N+1;1;i++)
                if(ispalin(i)==1)
                    break;
            return i;
}

//https://www.codechef.com/viewsolution/29290611

int is_palindrome(int N)
{int sum=0,r,num=N;
 while(num)
 {r=num%10;
  sum=10*sum+r;
  num/=10;
 }
  if(sum==N)
     return 1;
  return 0;
}


int sol2(int N);
int sol2(int N)
{
    int i;
    for(i=N+1;1;i++)
      if(is_palindrome(i))
      {	 return i;
     	 break;
      }
}


//https://www.codechef.com/viewsolution/215240

int reverse2(int n)
{
     int temp=0,rev=0;

     while(n>0)
     {temp=n%10;

                rev=rev*10+temp;
                //temp=n%10;
                n=n/10;
                }
                return rev;
                }
int sol3(int n);
int sol3(int n)
{
    int n,i,temp,p;
    for(i=n+1;;i= i+1)
              {
                           temp=i;
                          p= reverse2(i);
                          //printf("%d %d ",i,temp);
                          if(p==temp)
                          break;
              }
                          return i;
}


int main()
{
    int k;
    if(k<0)return 0;

    int t=k,count=0;
    while (t != 0) {
        t /= 10;
        ++count;
    }
    if(count>5) return 0;


    __CPROVER_assert(sol1(k)==sol2(k),"sol1vsol2");
    __CPROVER_assert(sol1(k)==sol3(k),"sol1vsol3");
    __CPROVER_assert(sol2(k)==sol3(k),"sol2vsol3");
}



