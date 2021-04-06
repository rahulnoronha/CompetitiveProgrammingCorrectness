//https://www.codechef.com/problems/XYSTR
/*
1≤T≤100
1≤N≤10^5
|S|=N
S contains only characters 'x' and 'y'
the sum of N over all test cases does not exceed 3 X 10^5
*/

//using CBMC
//https://www.codechef.com/viewsolution/42416806

#include <string.h>
#define length 100000

int sol1(char s[length]);
int sol1(char s[length])
{
    int pair=0;
    for(int j=0;j<strlen(s);j++)
		{
			if((s[j]=='x'&&s[j+1]=='y')|| (s[j]=='y'&&s[j+1]=='x'))
			{
				pair++;
				j++;
			}
		}
		return pair;
}

//https://www.codechef.com/viewsolution/43718478

#include<string.h>

int sol2(char stud[100001]);
int sol2(char stud[100001])
{
    int i,n=strlen(stud),pairs=0;
        for(i=0;i<n-1;i++){
            if(stud[i]!=stud[i+1]){
                pairs++;
                i++;
            }
        }
        return pairs;
}

int main()
{
    /*
1≤T≤100
1≤N≤10^5
|S|=N
S contains only characters 'x' and 'y'
the sum of N over all test cases does not exceed 3 X 10^5
*/
    int n;
    if(n<1||n>100000)
    {
    return 0;
    }
    int l = (n > 0 ? n : 1);
    char s[l];
    char *y = (n > 0 ? s : NULL);

    __CPROVER_assert(sol1(s)==sol2(s),"sol1vsol2");




}

//Tested using cbmc and found a counterexample for sol1vsol2 for --unwind 3
//Bruteforce approach not attempted
