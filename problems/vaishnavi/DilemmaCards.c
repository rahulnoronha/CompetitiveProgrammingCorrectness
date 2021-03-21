#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

/*
Dilemma: https://www.codechef.com/problems/CHEFDIL
Constraints:
>	1 <= |S| <= 10^5
>	Single string S describing the row of cards initially placed on the table. 
+	Each character of this string is either '1', denoting a face up card, or '0', denoting a face down card.
*/

//https://www.codechef.com/viewsolution/40531763
char* sol1(char* cardRow)
{	
	int i, count=0;
	for(i=0;i<strlen(cardRow);i++)
	{
	    if(cardRow[i] == '1')
	        count++;
	}
	if(count%2==0)
	{
	    return "LOSE\n";
	}
	else
	{
	    return "WIN\n";
	}
}


//https://www.codechef.com/viewsolution/33684834
char* sol2(char* s)
{
	int i,j,k,l,m,n;
	m=1;
	l=strlen(s);
	for (i=0;i<l;i++)
	{
		if (s[i]==48&&i<l-1)
		{
			j=i;
			while (s[j]!=49&&j<l-1) 
				j++;
			i=j;
		}
		if (s[i]==48&&i==l-1)
		{
			m=0;break;
		}	
		if (s[i]==49)
		{ 
			s[i+1]=(s[i+1]+1)%2+48;
		}
	}
	if (m==1) 
		return "WIN\n";
	else 
		return "LOSE\n";
}



//https://www.codechef.com/viewsolution/30535427
char* sol3(char* s)
{
    int flag;
    if(s[strlen(s)-1]=='0')
    	flag=0;
    else
        flag=1;
    for(int i=strlen(s)-2;i>=0;i--)
    {
        if(s[i]=='1')
        {
            if(flag==0)
    	        flag=1;
            else
        	    flag=0;    
        }
    }
    if(flag==0)
        return "LOSE\n";
    else
        return "WIN\n";
}
