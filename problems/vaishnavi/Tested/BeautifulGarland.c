#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
Beautiful Garland: https://www.codechef.com/problems/BEAUTGAR

>	The first and only line of each test case contains a single string s describing the garland.
>	Each character of s is either 'R' or 'G', denoting a red or green flower respectively.
Constraints:
>	2 <= |s| <= 10^5
>	the sum of |s| over all test cases does not exceed 10^6 //irrelevant in this context
*/

//https://www.codechef.com/viewsolution/24478541
char* sol1(char* str)
{
	int i,num,rc,gc;
	//char str[100000];
	num=0;
	rc=0;
	gc=0;
	//scanf("%s",&str);
	for(i=0;i<strlen(str)-1;i++)
	{
	    if(str[i]==str[i+1])
		{
	        num++;
	    	if(str[i]=='R')
			{
	        	rc++;
	        }
	        else
			{
	            gc++;
	        }
	           if(str[i+1]=='R')
			   {
	               rc++;
	            }
	            else{
	                gc++;
	            }
	        }
	    }
	    if(str[0]==str[strlen(str)-1])
		{
            if(str[0]=='R')
			{
                rc++;
            }
            else
			{
                gc++;
            }
            if(str[strlen(str)-1]=='R')
			{
                rc++;
            }
            else
			{
                gc++;
            }
            num++;
	    }
	    if(num==0)
		{
	        return "yes\n";    
	    }
	    else if(num==1)
		{
	        return "no\n";
	    }
	    else if(num==2)
		{
	        if(rc==gc)
			{
	           return "yes\n"; 
	        }
	        else
			{
	            return "no\n";
	        }
	    }
	    else
		{
	        return "no\n";
	    }
}




//https://www.codechef.com/viewsolution/28450274
char* sol2(char *arr)
{
	int  flag, r, r2, g, g2;
	flag = 1;
	r = r2 = g = g2 = 0;
	if (arr[0] == 'R')
		r++;
	else 
		g++;
	if (strlen(arr) % 2 == 1) 
		flag = 0;
	else
	{
		for (int i = 0; i < strlen(arr) - 1; i++)
		{
			if (arr[i + 1] == 'R') 
				r++;
			else 
				g++;
			if ((arr[i] == 'R') && (arr[i + 1] == 'R'))
			{
				r2++;
				if (r2 > 1)
				{
					flag = 0;
					break;
				}
			}
			if ((arr[i] == 'G') && (arr[i + 1] == 'G'))
			{
				g2++;
				if (g2 > 1)
				{
					flag = 0;
					break;
				}
			}
		}
	}
	if (flag == 1)
	{
		if ((strlen(arr) == 2) && ((g2 == 1) || (r2 == 1)))
			flag = 0;
		if (r != g) flag = 0;
	}
	if (flag == 0)
		return "no\n";
	else
		return "yes\n";
}



//https://www.codechef.com/viewsolution/21658761
char* sol3(char* str)
{
	int i,c=0,j,m=0,n=0;
	//scanf("%s",str);
	i=strlen(str);
	for(j=0;j<i;j++)
	{ 
	    if(str[j]=='R')
	        m++;
	    if(str[j]=='G')
	        n++;
	}
	if(m!=n)
	{ 
		return "no\n";
	}
	else
	{
		for(j=0;j<i;j++)
	    {   
	       if(str[j]==str[j+1])
	       c++;
	    }
	    if(str[0]==str[i-1])
	    	c++;
	    if(c==0||c==2)
	    	return "yes\n";
	    else
	    	return"no\n";
	}
}



//Cannot use this solution, Keeps scanning letters in string one by one instead of the whole string at once.
/*
char* sol4(char*)
{
	char c;
	char f;
	char prev;
	char l;
	scanf("%c",&c);
	f=c;
	prev=c;
	int r=0;
	int g=0;

  		while(c!='\n'){
  			scanf("%c",&c);
  			if(prev==c){
  				if(prev=='R'){
  					r++;
  				}

  				if(prev=='G'){
  					g++;
  				}
  			}
  			if(c!='\n'){
  			prev=c;
  		}
  		}

  		l=prev;

  		if(l==f){
  			   if(l=='R'){
  					r++;
  				}

  				if(l=='G'){
  					g++;
  				}
  		}
if(r==1 && g==1){
	printf("yes\n");
}
else if(r==0 && g==0){
	printf("yes\n");
}
else{
	printf("no\n");
}
}*/



int main()
{
	char* s;
	if(strlen(s)<2 || strlen(s)>100000)
		return 0;
	__CPROVER_assert(sol1(s)==sol2(s),"sol1vsol2");
  __CPROVER_assert(sol1(s)==sol3(s),"sol1vsol2");
  __CPROVER_assert(sol2(s)==sol3(s),"sol2vsol3");
	
}


//Test conducted on cbmc for unwindings of 1,2,3,4,5 and 10 and they are all Unsatisfiable 
//which implies sol1==sol2, sol1==sol3, sol2==sol3
//Brute force approach not tried.
