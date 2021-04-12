//https://www.codechef.com/problems/CTHREE


/*
1 ≤ N ≤ 10^9
1 ≤ a, b, c ≤ 10^6
*/


//Using CBMC
//https://www.codechef.com/viewsolution/27151580

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

long int sol1(long int n,long int a,long int b,long int c);
long int sol1(long int n,long int a,long int b,long int c)
{
 long int x[10000],y[10000],k=0,l=0,i,j,ans=0,p;
 for(i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                p=n/i;
                if(i<=a)
                    x[k++]=i;
                if(i<=b)
                    y[l++]=i;
                if(p<=a&&p!=i)
                    x[k++]=p;
                if(p<=b&&p!=i)
                    y[l++]=p;
            }
        }
        for(i=0;i<k;i++)
        {
            for(j=0;j<l;j++)
            {
                 p=x[i]*y[j];
                 if(n%p==0)
                 {
                     if(n/p<=c)
                        ans++;
                 }
            }
        }
        return ans;

}

//https://www.codechef.com/viewsolution/17969979

int arr[1000000],arr1[1000000],arr2[1000000];
long int sol2(long int n,long int a,long int b,long int c);
long int sol2(long int n,long int a,long int b,long int c)
{
    int count=0;
    arr[a],arr1[b],arr2[c];
int p=0,q=0,r=0;
for(int i=1;i<=a;i++)
{
if(n%i==0)
{
arr[p]=i;
p++;
}
}
for(int i=1;i<=b;i++)
{
if(n%i==0)
{
arr1[q]=i;
q++;
}
}
for(int i=1;i<=c;i++)
{
if(n%i==0)
{
arr2[r]=i;
r++;
}
}
int ans=0;
for(int i=0;i<p;i++)
{
for(int j=0;j<q;j++)
{
if(n%(arr[i]*arr1[j])==0)
{
ans=n/(arr[i]*arr1[j]);

for(int ll=0;ll<r;ll++)
{
if(ans==arr2[ll])
{
count++;
break;
}
}
}
else if(arr[i]*arr1[j]>n)
break;
}
}

return count;

}

//https://www.codechef.com/viewsolution/17490294

long int sol3(long int n,long int a,long int b,long int c);
long int sol3(long int n,long int a,long int b,long int c)
{
    long int factors[2000]={0};
        long int k=0,i,j,count=0;
        long max=(a>b)?((c>a)?c:a):((c>b)?c:b);
        long int increment=(n%2==0)?1:2;
        for(i=1;(i<=n && i<=max);i+=increment)
        {
            if(n%i==0)
            {
                factors[k++]=i;
            }
        }
        k--;
        for(i=0;i<=k;i++)
        {
            if(factors[i]<=a)
            {
                for(j=0;j<=k;j++)
                {
                    if(factors[j]<=b)
                    {
                        long long mult=factors[i]*factors[j];
                        long long r=n%mult;
                        mult=n/mult;
                        if(r==0 && mult<=c)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
}


int main()
{
    /*
    1 ≤ N ≤ 10^9
1 ≤ a, b, c ≤ 10^6
    */

    long int n,a,b,c;
    if(n<1||n>1000000000)
        return 0;
    else if(a<1||a>1000000||b<1||b>1000000||c<1||c>1000000)
        return 0;
    __CPROVER_assert(sol1(n,a,b,c)==sol2(n,a,b,c)"sol1vsol2");
    __CPROVER_assert(sol1(n,a,b,c)==sol3(n,a,b,c)"sol1vsol3");
    __CPROVER_assert(sol2(n,a,b,c)==sol3(n,a,b,c)"sol2vsol3");


    //return 0;
}
