//https://www.codechef.com/problems/ICL1902
//Constraints
//1≤T≤1000
//1≤N≤1000

//https://www.codechef.com/viewsolution/43733147
//#include <stdio.h>
//#include <math.h>

int sol1(int n);
int sol1(int n)
{
    for (int i = 0; i < t; i++)
    {
        int n, m, s = 0;
        while (n != 0)
        {
            m = sqrt(n);
            n = n - pow(m, 2);
            s++;
        }
        retrun s;
    }
}

/*https://www.codechef.com/viewsolution/43950277
#include <stdio.h>
int sol2(int n);
int sol2(int n)
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
  
}

*/


//https://www.codechef.com/viewsolution/36842527
//#include <stdio.h>
//#include <math.h>
int sol3(int n);
int sol3(int n)
{
    int i,n;
    int a=0,d=0;
             for(i=0;i<T;i++)
        {
            int count = 0;
            do
            {
                a= sqrt(n);
                d= n-(a*a);
                count = count+1;
                n=d;
            }
            while(d>0);
            retrun count;
            
        }
    }




//https://www.codechef.com/viewsolution/30673290
//#include <stdio.h>
int sol4(int n);
int sol4(int n)
    for(int i=0;i<t;i++)
    {
        int j,f,c=0;
        for(;j*j<=n;j++)
        {
            f=((j+1)*(j+1));
            if(f>n)
            {
                c++;
                n-=(j*j);
                j=0;
            }
        }
        retrun c;
    }

int main()
{
    int num;
    if(num<1||num>1000) return 0;

    __CPROVER_assert(sol1(num)==sol2(num),"sol1vsol2");
    __CPROVER_assert(sol1(num)==sol3(num),"sol1vsol3");
    __CPROVER_assert(sol1(num)==sol4(num),"sol1vsol4");
    __CPROVER_assert(sol2(num)==sol3(num),"sol2vsol3");
    __CPROVER_assert(sol2(num)==sol4(num),"sol2vsol4");
}
	
