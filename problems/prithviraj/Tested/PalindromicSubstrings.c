//https://www.codechef.com/problems/STRPALIN

/*
1 ≤ |A|, |B| ≤ 1000
*/
//Using CBMC

//https://www.codechef.com/viewsolution/45302701
char *sol1(char a[1000],char b[1000])
{
    int c1=0,c2=0,i,j,flag=0;
        for(i=0;a[i];i++){

            for(j=0;b[j];j++){

                if(a[i]==b[j]){
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(flag==1)
            return "Yes";
        else
            return "No";


}

//https://www.codechef.com/viewsolution/45335195
#include <string.h>
char *sol2(char a[1000],char b[1000])
{
     a[1000]='\0';
     b[1000]='\0';

        int c1[26]={0},c2[26]={0},i,j,flag=0;
        for(i=0;i<1000;i++)
            c1[a[i]-'a']++;
        for(i=0;i<1000;i++)
        c2[b[i]-'a']++;

        for(i=0;i<26;i++)
        {
            if(c1[i]>0 && c2[i]>0) {flag=1;break;}
            else
                flag=0;
        }
        if(flag==1)
            return "Yes";
        else
            return "No";


}

//https://www.codechef.com/viewsolution/24758697
#include<stdlib.h>
#include<string.h>
char *sol3(char a[1000],char b[1000])
{
    int arr[26];
	int ar[26];

		int len = strlen(a);
		int length = strlen(b);
		for(int i=0; i<26; i++){
			arr[i] = 0;
			ar[i] = 0;
		}
		for(int i=0; i<len; i++){
			arr[a[i]-97]++;
		}
		for(int i=0; i<length; i++){
			ar[b[i]-97]++;
		}
		int i;
		for(i=0; i<26; i++){
			if(arr[i] != 0 && ar[i] != 0){
				return "Yes";
				break;
			}
		}
		if(i == 26)
			return "No";
}

int main()
{
/*
1 ≤ |A|, |B| ≤ 1000
*/
int n;
if(n<1||n>1000)
    return 0;

char x[n],y[n];
char *a=(n>0?x:NULL);
char *b=(n>0?y:NULL);

__CPROVER_assert(sol1(a,b)==sol2(a,b),"sol1vsol2");
__CPROVER_assert(sol1(a,b)==sol3(a,b),"sol1vsol3");
__CPROVER_assert(sol2(a,b)==sol3(a,b),"sol2vsol3");
return 0;





}

//Tested using cbmc and found no counterexample. Unsatisfiable.
//Bruteforce approach not attempted