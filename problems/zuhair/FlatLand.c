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
int t;
    for (int i = 0; i < t; i++)
    {
        int n, m, s = 0;
        while (n != 0)
        {
            m = sqrt(n);
            n = n - pow(m, 2);
            s++;
        }
        return s;
    }
}


//https://www.codechef.com/viewsolution/36842527
//#include <stdio.h>
//#include <math.h>
int sol2(int n);
int sol2(int n)
{
    int i,n,T;
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
            return count;
            
        }
    }




//https://www.codechef.com/viewsolution/30673290
//#include <stdio.h>
int sol3(int n);
int sol3(int n)
{
int t;
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
        return c;
    }
}

int main()
{
    int num;
    if(num<1||num>1000) return 0;

    __CPROVER_assert(sol1(num)==sol2(num),"sol1vsol2");
    __CPROVER_assert(sol1(num)==sol3(num),"sol1vsol3");
    __CPROVER_assert(sol2(num)==sol3(num),"sol2vsol3");
}
	
