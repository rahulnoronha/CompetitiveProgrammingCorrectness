//https://www.codechef.com/problems/CMB03
/*
Given two binary strings, A (of length 10) and B (of length 5).
*/

//try CBMC


//https://www.codechef.com/viewsolution/40333033


#include<stdlib.h>
#include<string.h>

int sol1(char *A[10],char *B[5]);
int sol1(char *A[10],char *B[5])
{
    int i,flag=0;
    for(i=0;i<5;i++)
                {
                    if(strncmp((A+i),B,5)==0)
                        flag=1;
                }
            return flag;
}

//https://www.codechef.com/viewsolution/37290778


#include <string.h>


int sol2(char *a[11],char *b[6]);
int sol2(char *a[11],char *b[6])
{
    return (strstr(a, b) != NULL) ? 1 : 0;
}


//https://www.codechef.com/viewsolution/5494806


#include<stdlib.h>

int isSubString(char a[],char b[])
{
    int i,j,ci;
    for(i=0,j=0;a[i];i++)
    {
        ci=i;
        while(a[i]==b[j])
        {
            i++;
            j++;
        }
        if(!b[j])
            return 1;
        i=ci;
        j=0;
    }
    return 0;
}

int sol3(char *a[11],char *b[6]);
int sol3(char *a[11],char *b[6])
{
    if(isSubString(a,b))
            return 1;
        else
            return 0;
}


//https://www.codechef.com/viewsolution/2216469


int sol4(char *a[11],char *b[6]);
int sol4(char *a[11],char *b[6])
{
    int flag=0,i,j;
    for(i=0;i<=5;i++)
              if(a[i]==b[0] && a[i+1]==b[1] && a[i+2]==b[2] && a[i+3]==b[3] && a[i+4]==b[4])
              {
                                             flag=1;
                                             break;
              }
              return flag;
}


//https://www.codechef.com/viewsolution/216699


#include <string.h>

int sol5(char *A[11],char *B[6]);
int sol5(char *A[11],char *B[6])
{
    return strstr(A,B)!=NULL);
}


int main()
{
    char A[10],B[5]; //BINARY STRINGS
    if(sizeof(A)>10||sizeof(B)>5)
        return 0;
    __CPROVER_assert(sol1(A,B)==sol2(A,B),"sol1vsol2");
    __CPROVER_assert(sol1(A,B)==sol3(A,B),"sol1vsol3");
    __CPROVER_assert(sol1(A,B)==sol4(A,B),"sol1vsol4");
    __CPROVER_assert(sol1(A,B)==sol5(A,B),"sol1vsol5");
    __CPROVER_assert(sol2(A,B)==sol3(A,B),"sol2vsol3");
    __CPROVER_assert(sol2(A,B)==sol4(A,B),"sol2vsol4");
    __CPROVER_assert(sol2(A,B)==sol5(A,B),"sol2vsol5");
    __CPROVER_assert(sol3(A,B)==sol4(A,B),"sol3vsol4");
    __CPROVER_assert(sol3(A,B)==sol5(A,B),"sol3vsol5");
    __CPROVER_assert(sol4(A,B)==sol5(A,B),"sol4vsol5");
}

