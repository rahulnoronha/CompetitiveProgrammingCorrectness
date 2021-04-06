//https://www.codechef.com/problems/SMVOL
/*

1 ≤ L ≤ 10^9

*/

//https://www.codechef.com/viewsolution/37963240

long long int sol1(long long int l);
long long int sol1(long long int l)
{
    long long int a,b,c,v;

	  a=l*l*l;
	  b=l-2;
	  c=b*b*b;
	  v=a-c;
	  if(l<=2)
	  return a;
	  else
	  return v;
}


//https://www.codechef.com/viewsolution/33257867
#include<math.h>
#include<stdlib.h>

long long int sol2(long long int n);
long long int sol2(long long int n)
{
    long long count=0;

            if(n==1)
                return 1;
            else if(n==2)
                return 8;
            else {
                count = count + 6*((n - 2) * (n - 2));
                count = count + 8;
                count = count + 12 * (n - 2);
                return count;
            }
}

int main()
{
    long long int num;
    if(num<1||num>1000000000)
        return 0;
    __CPROVER_assert(sol1(num)==sol2(num),"sol1vsol2");

}



