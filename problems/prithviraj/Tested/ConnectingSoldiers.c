//https://www.codechef.com/problems/NOKIA
/*
(1 ≤ N ≤ 30 , 1 ≤ M ≤ 1000).
*/
//Using CBMC
//https://www.codechef.com/viewsolution/40948560
int find_min (int n)
{
 int first, last;

 if (n == 0)
  return 0;
 else
 {
  if (n & 1)
   first = last = n/2;
  else
  {
   first = n/2 - 1;
   last = n/2;
  }
  return ((n+1) + find_min(first) + find_min(last));
 }
}
int sol1(int n,int m);
int sol1(int n,int m)
{
    int  M, N, min, max;
    min = find_min(N);
  max = N * (N + 3) / 2;

  if (M < min)
   return -1;
  else if (M > max)
   return (M - max);
  else
   return 0;
}
//https://www.codechef.com/viewsolution/37044959
#include<math.h>
int sol2(int n,int m);
int sol2(int n,int m)
{
    int p[35],i;
    p[1]=0;
    p[0]=0;
    p[2]=2;

    for(i=2;i<=31;i++)
     {p[i]=i+p[(int)ceil((float)i/2)]+ p[(int)floor((float)i/2)];
     }
     int flag=0,a,b;

       a=n*(n+3)/2;
       b=p[n+1];

       if(m<b)
         {return -1;

         }
        if(m>=a)
           return m-a;
        else
           return 0;
}
//https://www.codechef.com/viewsolution/36177414
int sol3(int n,int m);
int sol3(int n,int m)
{
    int i,s[50],r;
    s[1]=2;
    s[2]=5;
    for(i=3;i<34;i++)
        s[i]=s[i/2]+s[(i-1)/2]+i+1;

    r=(n*(n+3))/2;
        if(m>=r)
        return m-r;
        else if(m>=s[n])
        return 0;
        else if(m<s[n])
        return -1;
}
//https://www.codechef.com/viewsolution/33143106
int wire(int n){
    if(n==1)
    return(2);
    else if(n==0)
    return(0);
    else{
        if(n%2==0){
            return(n+1+wire(n/2)+wire((n)/2-1));
        }
        else{
            return(n+1+2*wire(((n+1)/2)-1));
        }
    }
}
int sol4(int n,int m);
int sol4(int n,int m)
{
    int l=wire(n);
        int u=(n*(n+3))/2;
        if(m>=l&&m<=u){
            return 0;
        }
        else if(m<l){
            return -1;
        }
        else{
            return m-u;
        }
}
int main()
{
    /*
(1 ≤ N ≤ 30 , 1 ≤ M ≤ 1000).
*/
    int n,m;
    if(n<1||n>30||m<1||m>1000)
        return 0;
    __CPROVER_assert(sol1(n,m)==sol2(n,m),"sol1vsol2");
    __CPROVER_assert(sol1(n,m)==sol3(n,m),"sol1vsol3");
    __CPROVER_assert(sol1(n,m)==sol4(n,m),"sol1vsol4");
    __CPROVER_assert(sol2(n,m)==sol3(n,m),"sol2vsol3");
    __CPROVER_assert(sol2(n,m)==sol4(n,m),"sol2vsol4");
    __CPROVER_assert(sol3(n,m)==sol4(n,m),"sol3vsol4");

}


//Tested using cbmc and found no counterexample. Unsatisfiable for --unwind 10 by assumption due to time exceeded
//Bruteforce not attempted

