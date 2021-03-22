//https://www.codechef.com/problems/TECH04
/*
The strings would consist of only letters 'a'-'z'.
 Each string would consist of no more than 20 characters.
*/
// TRY CBMC

//https://www.codechef.com/viewsolution/40563573
#include <string.h>
#include <math.h>
#include <stdlib.h>
char *sol1(char *s1[100000],char *s2[100000]);
char *sol1(char *s1[100000],char *s2[100000])
{
    int l1= strlen(s1);
        int l2 = strlen(s2), j = 0;
        if( l1 != l2){
            return "NO";
        }
        else{
            int c[26]={ 0 },x;
            for(int i= 0; i< l1; i++){
                x = (int) s1[i];
                c[x -97]++;
                x = ( int) s2[i];
               // printf("%d\n",x);
                c[x-97]--;
            }
            for(j =0;j <26;j++){
                if( c[j] != 0){
                    return "NO";
                    break;
                }
            }
            if(j ==26){
                return "YES";
            }
        }
}

//https://www.codechef.com/viewsolution/36860356

check_anagram(char a[],char b[]){
    int c[26]={0},d[26]={0},i=0;

     while (a[i] != '\0'){
         c[a[i]-'a']++;
         i++;
    }
    i=0;
       while (b[i] != '\0'){
         d[b[i]-'a']++;
         i++;
    }
    for (int i= 0; i < 26; i++)
    if (c[i] != d[i])
      return 0;

  return 1;

}
char *sol2(char *s1[1000],char *s2[1000]);
char *sol2(char *s1[1000],char *s2[1000])
{
    if (check_anagram(s1, s2))
    return "YES";
  else
   return "NO";
}

//https://www.codechef.com/viewsolution/12607765

#include<math.h>
#define size 200

char *sol3(char *A[size],char *B[size]);
char *sol3(char *A[size],char *B[size])
{
    int i,j,k,count1,count2,flag,a,b,hello;
    count1=1;
  count2=0;
  flag=hello=1;
  a=strlen(A);
  b=strlen(B);
  if(a!=b)
   return "NO";
  else
  {
   for(i=0;i<a;i++)
   {
    count1=1;
    flag=1;
    count2=0;
    for(k=0;k<i;k++)
    {
     if(A[k]==A[i])
     {
      flag=0;
      break;
      }
     }

     if(flag==1)
     {
      for(j=i+1;j<a;j++)
      {
       if(A[i]==A[j])
        count1++;
       }
       for(j=0;j<b;j++)
       {
        if(A[i]==B[j])
         count2++;
        }
      }
     else
      continue;

     if(count1!=count2)
     {
       hello=0;
       break;
       }
    }
    if(hello==0)
     return "NO";
    else if(hello==1)
     return "YES";
   }
}


//https://www.codechef.com/viewsolution/2593841

char *sol4(char *str1[300],char *str2[300]);
char *sol4(char *str1[300],char *str2[300])
{
    int i,j,k,n,count1[300]={0},count2[300]={0},flag=0;
    for(i=0;str1[i]!='\0';i++)
    {
        for(j=97;j<123;j++)
        {
            if(str1[i]==j)
            {
                count1[j]++;
            }
        }
    }
    for(i=0;str2[i]!='\0';i++)
    {
        for(j=97;j<123;j++)
        {
            if(str2[i]==j)
            {
                count2[j]++;
            }
        }
    }
    for(j=97;j<123;j++)
    {
        if(count1[j]!=count2[j])
        {

            flag=1;
        }    }
        if(flag==0)
        {
            return "YES";
        }
        else
        {

            return "NO";
        }

}



int main()
{
    int n,p;
    int m = (n > 0 ? n : 1);
    char x[m];
    char *s1 = (n > 0 ? x : NULL);
    int m = (p > 0 ? p : 1);
    char z[m];
    char *s2 = (p > 0 ? z : NULL);
    if(n<1||n>20||p<1||p>20)
    {
        return 0;
     }
 for(int i=0;(s1[i]!='\0'&&s2[i]!='\0');++i)
 {
  if(((int)s1[i]<97||(int)s1[i]>122)||((int)s2[i]<97||(int)s2[i]>122))
   return 0;
 }

    __CPROVER_assert(sol1(s1,s2)==sol2(s1,s2),"sol1vsol2");
    __CPROVER_assert(sol1(s1,s2)==sol3(s1,s2),"sol1vsol3");
    __CPROVER_assert(sol1(s1,s2)==sol4(s1,s2),"sol1vsol4");
    __CPROVER_assert(sol2(s1,s2)==sol3(s1,s2),"sol2vsol3");
    __CPROVER_assert(sol2(s1,s2)==sol4(s1,s2),"sol2vsol4");
    __CPROVER_assert(sol3(s1,s2)==sol4(s1,s2),"sol3vsol4");
}

//Tested using cbmc and found no counterexamples
//Brute force not tried


