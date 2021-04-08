//https://www.codechef.com/problems/FCTRL
/*


one positive integer number N, 1≤N≤10^9

*/

//Using CBMC

//https://www.codechef.com/viewsolution/44743811

int sol1(int n);
int sol1(int n)
{
    int total=0;
    int a=5;
    int sum=0;

    while(1)
        {
            total=n/a;
            if(total<1)
            {
                break;
            }
            sum=sum+total;
            a=a*5;
        }

        return sum;

}

//https://www.codechef.com/viewsolution/44675305
int sol2(int n);
int sol2(int n)
{
    int res=0;
        for(int i=5; i<=n; i=i*5){
            res=res+n/i;
        }
        return res;
}

//https://www.codechef.com/viewsolution/30604336


#include<math.h>
int sol3(int n);
int sol3(int n)
{
    int t=0;

   int j;
   for(j=1;j<15;j++)
   {t+=n/(pow(5,j));}

   return t;
}




int main()
{

    int n;
    if(n<1||n>1000000000)
        return 0;
    __CPROVER_assert(sol1(n)==sol2(n),"sol1vsol2");
    __CPROVER_assert(sol1(n)==sol3(n),"sol1vsol3");
    __CPROVER_assert(sol2(n)==sol3(n),"sol2vsol3");


}

//Tested using cbmc and found no counterexample. Unsatisfiable
//Bruteforce not attempted
