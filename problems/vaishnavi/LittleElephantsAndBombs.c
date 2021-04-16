#include<string.h>
#include<stdio.h>
/*
Little Elephant and Bombs: https://www.codechef.com/problems/LEBOMBS
*/

//https://www.codechef.com/viewsolution/33405369
int sol1(int n, char* str)
{
	int j,len=strlen(str),count=0;
	    for(j=0;j<len;j++)
	    {
	       if(str[j]=='1'||str[j+1]=='1'||str[j-1]=='1')
	       count+=1;
	    }
	return len-count;
}

//https://www.codechef.com/viewsolution/40969992
int sol2(int n, char* arr)
{
	int i,count=0;
	if(n==1)
        {
            if(arr[0]=='0')count++;
        }
        else
        {
            for(i=0;i<n;i++)
            {
                if(i==0)
                {
                    if((arr[1]=='0')&&(arr[0]=='0'))count++;
                }
                else if(i!=(n-1))
                {
                    if(arr[i]=='0')
                    {
                        if((arr[(i-1)]=='0')&&(arr[(i+1)]=='0'))count++;
                    }
                }
                else
                {
                    if((arr[(n-2)]=='0')&&(arr[(n-1)]=='0'))count++;
                }
            }
        }
    return count;
}


//https://www.codechef.com/viewsolution/14562045
int sol3(int n, char* a)
{
	int d,cnt,i;
	cnt=0;
		for(i=0;i<n;i++)
		{ d=0;
		  
			if(a[i]=='1')
			{
				d=1;
			}
			if(i>0&&a[i-1]=='1')
			{
				d=1;
			}
			if(i<n&&a[i+1]=='1')
			{
				d=1;
			}
			if(d==0)
			{
				cnt++;
			}
			
		}
	return cnt;
}

//https://www.codechef.com/viewsolution/33550771
int sol4(int n, char* str)
{
	int count =0,i;
        //scanf("%d",&n);
        //char str[n];
       int val[n];
       for(i=0;i<n;i++)
            val[i] = 1;
        //scanf("%s",str);
       int l = strlen(str);
       for(i=0;i<l;i++) {
            if(i==0 && str[i] == '1') {
                val[i+1] = 0;
                val[i] = 0;
            }
            if(i==l-1 && str[i] == '1' ) {
                val[i-1] = 0;
                val[i] = 0;
            }
            if(str[i]=='1') {
                val[i] = 0;
                val[i+1] = 0;
                val[i-1] = 0;
            }            
       }
       for(i=0;i<n;i++) {
            if(val[i] == 1)
               count++;
       }
    return count;
}



int main()
{
	int n;
	int m = (n > 0 ? n : 1);
  	char x[m];
  	char *a = (n > 0 ? x : NULL);
    	__CPROVER_assert(sol1(n,a)==sol2(n,a),"sol1Vsol2");
    __CPROVER_assert(sol1(n,a)==sol3(n,a),"sol1Vsol3");
    __CPROVER_assert(sol1(n,a)==sol4(n,a),"sol1Vsol4");
    __CPROVER_assert(sol2(n,a)==sol3(n,a),"sol2Vsol3");
    __CPROVER_assert(sol2(n,a)==sol4(n,a),"sol2Vsol4");
    __CPROVER_assert(sol3(n,a)==sol4(n,a),"sol3Vsol4");
    return 0;
}
