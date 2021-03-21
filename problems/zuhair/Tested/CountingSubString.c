//https://www.codechef.com/problems/CSUB
//1 ≤ T ≤ 10^5
//1 ≤ N ≤ 10^5
//Sum of N over all testcases ≤ 10
#include <stdio.h>
#include<stdlib.h>
//https://www.codechef.com/viewsolution/42196062

long int *sol1(char *str,long int n);
long int *sol1(char *str,long int n)
{
  long int count = 0;
   for(long int i=0;str[i]!='\0';i++){
       if(str[i]=='1')
{
count++;
   }
                            }
return count+(((count-1)*(count))/2);
}


//https://www.codechef.com/viewsolution/42140936

long int *sol2(char *arr,long long int n);
long int *sol2(char *arr,long long int n)
{
long long int count = 0;
for(long long int i=0;i<n;i++){
   if(arr[i]=='1')
      {
         count++;
         }                   
                               } 
return (count*(count+1))/2; 
}


int main()
{
    long int n;
    if(n<1||n>100000)
    {
        return 0;
    }
    long int m = (n > 0 ? n : 1);
    long long int s=m;
    char x[m];
    char *y = (n > 0 ? x : NULL);
    __CPROVER_assert(sol1(y,n)==sol2(y,n),"sol1vsol2");
}

//Tested using cbmc and found a counterexample which means it is satisfiable and sol1!=sol2
//Brute Force Check not done
