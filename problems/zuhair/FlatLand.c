//https://www.codechef.com/problems/ICL1902
//Constraints
//1≤T≤1000
//1≤N≤1000

//https://www.codechef.com/viewsolution/43733147
//#include <stdio.h>
//#include <math.h>

int sol1(int t, int n);
int sol1(int t, int n)
{
int i;
    for (int i = 0; i < t; i++)
    {
        int  m, s = 0;
        while (n != 0)
        {
            m = sqrt(n);
            n = n - pow(m, 2);
            s++;
        }
        return s;
    }
}
   


/*https://www.codechef.com/viewsolution/43950277
#include <stdio.h>
int sol2(int t, int n);
int sol2(int t, int n)
{
    while(t--)
    {
        int ans=0;
        while(n!=0)
        {
            int k=sqrt(n);
            n=n-(k*k);
            ans++;
        }
      return ans;
    }
}*/


//https://www.codechef.com/viewsolution/36842527
//#include <stdio.h>
//#include <math.h>
int sol3(int t, int n);
int sol3(int t, int n)
{
    int i;
    int a=0,d=0;
        for(i=0;i<T;i++)
        {
             int count = 0;
            do
            {
                a= sqrt(N);
                d= N-(a*a);
                count = count+1;
                N=d;
            }
                while(d>0);
            return count;
          
        }
    }



//https://www.codechef.com/viewsolution/30673290
//#include <stdio.h>
int sol4(int t, int n);
int sol4(int t, int n)
{
    for(int i=0;i<t;i++)
    {
        int i, j,f,c=0;
        for(j*j<=n;j++)
        {
            f=((j+1)*(j+1));
            if(f>n)
            {
                c++;
                n-=(j*j);
                j=0;
            }
        }
       return c;
    }

