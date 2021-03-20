//https://www.codechef.com/problems/CSUB
//1 ≤ T ≤ 105
//1 ≤ N ≤ 105
//Sum of N over all testcases ≤ 10
//#include <stdio.h>

//https://www.codechef.com/viewsolution/42196062

long int *sol1(char *str,int i);
long int *sol1(char *str,int i)
{
  long count = 0;
   for(i=0;str[i]!='\0';i++){
       if(str[i]=='1')
{
count++;
   }
return count+(((count-1)*(count))/2);
}


//https://www.codechef.com/viewsolution/42140936

long int *sol2(int *arr,int a);
long int *sol2(int *arr,int a)
{
int count = 0;
for(long long int i=0;i<a;i++)
   if(arr[i]=='1')
      {
         count++;
         }
return (count*(count+1))/2; 
		}


long int sol2_buggy(int* srr , int z);
long int sol2_buggy(int* srr , int z)
{
int count;
for(long long int i=0;i<z;i++)
   if(srr[i]=='1')
      {
         count++;
         }
return (count*(count+1))/2; 
}
