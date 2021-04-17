#include<stdio.h>
#include<stdlib.h>
/*
Magic Pairs: https://www.codechef.com/problems/ALEXNUMB
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
  	for(n=1;n<100000;n++)
    {
        int a[100000]={1};
        int s[3] = {0};
        s[0] = sol1(n, a);
        s[1] = sol2(n, a);
        s[2] = sol3(n, a);
        for (int i = 0; i < 2; ++i) {
          for (int j = i+1; j < 3; ++j) {
            if (s[i] != s[j]) {
              printf("%d vs %d: (%d) gives (%d, %d)\n",
                     i+1, j+1, n, s[i], s[j]);
                     exit(-1);
            }
          }
        }
}
}
//Bruteforce is a success and no counterexample is found