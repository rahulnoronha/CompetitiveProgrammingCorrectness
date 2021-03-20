//problem link ->  https://www.codechef.com/problems/LEFROT
/*
1≤n≤10^5
1≤d≤n
1≤ai≤10^6 where Ai is the ith element of array
*/
#include<stdio.h>

//SOLUTION LINK -> https://www.codechef.com/viewsolution/36212673
//TRY BRUTE FORCE !!
long int *sol1(long int n,long int r,long int *arr);  //r is the same constraint variable as d
long int *sol1(long int n,long int r,long int *arr)
{
    int x,i;
      while(r--)
    {
            for(i=0;i<n-1;i++)
            {
                x=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=x;
            }
    }
return arr;
}


//SOLUTION LINK -> https://www.codechef.com/viewsolution/40449471
//TRY BRUTE FORCE !!



long int *sol2(long int n,long int r,long int *v);  //r is the same constraint variable as d
long int *sol2(long int n,long int r,long int *v)
{
    int vi[20000];
    for(int i = 0; i<2*n; i++){
		if(i<n)
			vi[i] = v[i];
		else
			vi[i] = v[i-n];
	}
	return vi;
}

int main()
{
long int n;
long int d;
if(n<1||n>100000||d<1||d>n)
{
    return 0;
}
 long int m = (n > 0 ? n : 1);
 long int x[m];
 long int *y = (n > 0 ? x : NULL);
  __CPROVER_assert(sol1(n,d,y)==sol2(n,d,y),"sol1vsol2");
  //Tested using CBMC and found a counter example for unwinding 3
}






