#include <stdio.h>
#include<string.h>

/*
Your Name is Mine: https://www.codechef.com/problems/NAME2
*/

//https://www.codechef.com/viewsolution/45008138
char* sol1( char* w, char* m)
{
	int l1,l2,i,j=0,p=0;
        //scanf("%s %s",w,m);
        l1=strlen(w);
        l2=strlen(m);
       if(l1<l2)
       {
        for (i = 0; i <l2; i++) 
        {
           if(w[p]==m[i])
           {
           p++;
           if(p==l1)
           i=l2;
           }
        }
        if(p==l1)
        j=1;
       }
       else
       {
        for (i = 0; i <l1; i++) 
        {
           if(m[p]==w[i])
           {
           p++;
           if(p==l2)
           i=l1;
           }
        }
        if(p==l2)
        j=1;
       }
        if(j==1)
        return "YES\n";
        else
        return "NO\n";
}


//https://www.codechef.com/viewsolution/39705263
int compare(char a[],char b[])
{
  int c,d;
  c=d=0;
  while(a[c]!='\0')
    {
      while((a[c]!=b[d])&&(b[d]!='\0'))
      {
        d++;
       }
       if(b[d]=='\0')
          break;
          d++;
          c++;
        }
        if(a[c]=='\0')
           return(1);
        else
           return(0);
           }

char* sol2( char* w, char* m)
{
	int l1,l2,t;
    l1=strlen(m);
    l2=strlen(w);
    if(l1<l2)
       t=compare(m,w);
    else
       t=compare(w,m);
    if(t==1)
       return "YES\n";
     else
        return "NO\n";
}


//https://www.codechef.com/viewsolution/37656879
char* sol3(char* s1, char* s2)
{
	int x=strlen(s1),y=strlen(s2);
        int i=0,j=0;
        for(int k=0;k<y;k++)
        {
            if(s1[i]==s2[k])
                i++;
        }
        for(int k=0;k<x;k++)
        {
            if(s2[j]==s1[k])
                j++;
        }
        if(i==x)
            return "YES\n";
        else if(j==y)
            return "YES\n";
        else
            return "NO\n";
}



int main()
{
	char m[25001],w[25001];
		__CPROVER_assert(sol1(w,m)==sol2(w,m),"sol1Vsol2");
    __CPROVER_assert(sol1(w,m)==sol3(w,m),"sol1Vsol3");
    __CPROVER_assert(sol2(w,m)==sol3(w,m),"sol2Vsol3");
    return 0;
}
