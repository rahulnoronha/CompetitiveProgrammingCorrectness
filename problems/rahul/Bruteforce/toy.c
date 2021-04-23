//TOY STORY-> https://www.codechef.com/problems/COINYS

/*CONSTRAINTS:
1 ≤ T≤ 1000
1 ≤ N≤ 100000
SOLUTION LINK-> https://www.codechef.com/viewsolution/39466541 */
#include<stdlib.h>
#include <stdio.h>
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
    int n=0;
    
    for (n = 1; n <= 100000; ++n) 
    {
      int s[2]={0};
      char m[n+1];
      int i = 0;
      for( ;i<=n;++i)
      {
      m[i]='M';
      }
      m[i]='\0';
      
        s[0] = sol1(n,m);
        s[1] = sol2(n,m);
            if (s[0] != s[1]) {
              printf("sol1vsol2  %d != %d\n",s[0],s[1]);
              //break;
            }
          }
        
      
    
    return 0;
}




