//TOY STORY-> https://www.codechef.com/problems/COINYS

/*CONSTRAINTS:
1 ≤ T≤ 1000
1 ≤ N≤ 100000
SOLUTION LINK-> https://www.codechef.com/viewsolution/39466541 */
#include<stdlib.h>
int sol1(int size,char *str);
int sol1(int size,char *str)
{
    int count=0;
    for(int i=0;i<size-1;i++)
	    {
	        if(str[i] == str[i+1])
	        {
	            count++;
	        }
	    }
return count;
}


//SECOND SOLUTION
//SOLUTION LINK-> https://www.codechef.com/viewsolution/39507415

int sol2(int size,char *string);
int sol2(int size,char *string)
{
    int count=0;
    for(int i=0;i<size;i++){
        if(string[i] == string[i+1] && string[i] == 'K'){
            count++;
        }
        if(string[i] == string[i+1] && string[i] == 'L'){
            count++;
        }
        if(string[i] == string[i+1] && string[i] == 'M'){
            count++;
        }
        }
return count;
}

int main()
{
    int n;
    if(n<1||n>100000)
    {
    return 0;
    }
    int l = (n > 0 ? n : 1);
    char x[l];
    char *y = (n > 0 ? x : NULL);
    
     __CPROVER_assert(sol1(n,y) == sol2(n, y), "sol1vsol2");
}

//Tested and Found Counter Example for 3 unwindings

