//https://www.codechef.com/problems/STRCH/
//1≤T≤1,000 
//1≤N≤106
//S contains only lowercase English letters
//X is a lowercase English letter
//the sum of N over all test cases does not exceed 106

//https://www.codechef.com/viewsolution/25938639

int sol1(char *str, int n, int i);
int sol1(char *str, int n, int i)
{
int count=0;
int k;
for(i=0;i<n;i++)
	    {
	        k++;
	        if(str[i]==c)
	        {
	           count=count+k+k*(n-i-1);
	           k=0;
	        }
	    }
	    return count;
}


//https://www.codechef.com/viewsolution/28043605

long int sol2(char* s, int flag, int res);
long int sol2(char* s, int flag, int res)
{
res=0;
flag=-1;
 for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]==c)
            {
              flag=i+1;
              res=res+(i+1);
            }
            else
            {
                if(flag!=-1)
                {
                    res=res+flag;
                }
            }
        }
        return res;
}