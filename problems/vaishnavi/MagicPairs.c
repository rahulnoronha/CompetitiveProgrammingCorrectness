#include<stdio.h>
/*
Magic Pairs: https://www.codechef.com/problems/ALEXNUMB
PLEASE JUST PERFORM BRUTE FORCE ON THIS FILE, DO not wate your time, all answers are the same, and correct.
1<=n<=100000
1<=ai<=1000000000
*/

//https://www.codechef.com/viewsolution/42615462
int sol1(int n, int a[])
{
	return n*(n-1)/2;
}

//https://www.codechef.com/viewsolution/33606834
int sol2(int n, int a[])
{
	int l=(n*(n-1))/2;
	return l;
}


int sol3(int count2, int a[])
{
	return (count2*(count2-1)/2);
}

int main()
{
	int n;
	int m = (n > 0 ? n : 1);
  	int x[m];
  	int *a = (n > 0 ? x : NULL);
  		__CPROVER_assert(sol1(n,a)==sol2(n,a),"sol1Vsol2");
    __CPROVER_assert(sol1(n,a)==sol3(n,a),"sol1Vsol3");;
    __CPROVER_assert(sol2(n,a)==sol3(n,a),"sol2Vsol3");
}

//Tested using Bruteforce and it failed
//Tested using cbmc and it is satisfiable and found counterexample for --unwind 2
