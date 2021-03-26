//https://www.codechef.com/problems/DISTCODE
/*Constraints
1 ≤ T ≤ 100
Subtask 1 (35 points): 2 ≤ |S| ≤ 3
Subtask 2 (65 points): 2 ≤ |S| ≤ 10^4*/
//https://www.codechef.com/viewsolution/40499685
//#include <stdio.h>
#include<string.h>

char sol1(char *str);
char sol1(char *str)
{
        //char str[10000];
        int flag=0,len=strlen(str),i;
        char strch[100000][3];
        int count=0;
        for(i=0;i<(len-1);i++)
        {
            flag=0;
            strch[i][0]=str[i];
            strch[i][1]=str[(i+1)];
            strch[i][2]='\0';
            for(int j=0;j<i;j++)
            {
                if(strcmp(strch[i],strch[j])==0)flag=1;
            }
            if(flag!=1)count++;
        }
        return count;
    }

//https://www.codechef.com/viewsolution/39789924
//#include<stdio.h>
#include<string.h>

char sol2(char *str);
char sol2(char *str)
{
	//char str[10001];
	int a[26][26]={0};
	int l=strlen(str);
	int i,j,k,c=0;
	for(i=0;i<l-1;i++)
	{
		j=str[i]-'A';
		k=str[i+1]-'A';
		a[j][k]=1;
	}
		for(i=0;i<26;i++)
		{
			for(j=0;j<26;j++)
			{
			if(a[i][j]==1)
			c++;
			}
		}
			return c;
}


int main()
{
    char str[10000]; int c=0;
    //Subtask 1 (35 points): 2 ≤ |STR| ≤ 3
    //Subtask 2 (65 points): 2 ≤ |STR| ≤ 10^4*/

     for(int i=0;str[i]!='\0';++i)
        c++;

    if(c<2||c>10000)
      return 0;

    __CPROVER_assert(sol1(str)==sol2(str),"sol1vsol2");
}
