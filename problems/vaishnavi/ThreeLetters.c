/*
THREE LETTERS: https://www.codechef.com/problems/THREE

Input:
The first and only line of each test case contains a single string S.

Output:
Print a single line containing one integer - the maximum number of coins you can get.

Constraints:
>	1 <= |S| <= 10^5
>	S contains only lowercase English letters

Subtasks, All solutions picked here have been graded 100.

>	Subtask #1 (20 points): S contains only letters 'a' and 'b'
>	Subtask #2 (20 points): 1 <= |S| <= 100 and S contains only letters 'a', 'b' and 'c'
>	Subtask #3 (60 points): original constraints
*/

#include<stdio.h>
#include<string.h>

//https://www.codechef.com/viewsolution/40878041
long int sol1(char arr[])
{
    long int n,count,p=0,count2=0;
    n=strlen(arr);
    int arr2[n];
    long int i=0,j=0;
    // printf("%d\n",strlen(arr));
    for(i=0;i<n;i++)
    {
        count=1;
        if(arr[i]!='%')
        {
	        if(i!=n-1)
    	    for(j=i+1;j<n;j++)
            {
               if(arr[i]==arr[j])
               {
                   count++;
                   arr[j]='%';
               }
            }
            arr2[p]=count;
            p++;
        }
       // printf("%d\n",strlen(arr));
    }
    long int n1=0;
    for(i=0;i<p;i++)
    {
       // printf("%d ",arr2[i]);
        long int n2=arr2[i]/2;
        if(arr2[i]>1 )//&& n-arr2[i]-n1>=arr2[i]/2 )
        {
            if(n-arr2[i]-n1>=arr2[i]/2 )
           {
            count2+=arr2[i]/2;
            n1+=3*n2;
           }
           else if(n-n1>=3)
           {
               count2+=(n-n1)/3;
               n1+=3*((n-n1)/3);
           }
           
           // n1-=(arr2[i]%2);
           // printf(" c= %d ",arr2[i]);
        }
    }
    return cout2;
}




//https://www.codechef.com/viewsolution/40975252
long int sol2(char s[])
{
	long int count[27]={0},i=0,ans=0,j,f=0;
    //scanf("%s",s);
    while(s[i]!='\0')
    {
		count[(int)(s[i]-'a')]++;
		i++;
	}
    for(i=0;i<26;i++)
    {
        while(count[i]>=2)
        {
            f=0;
            for(j=0;j<26;j++)
            {
                if(count[j]>=1 && j!=i)
                {f=1;break;}
            }
            if(f==1)
    	        {count[i]-=2;count[j]-=1;ans++;}
            else
                break;
        }
    }
    for(i=0;i<26;i++)
    	ans+=count[i]/3;
    return ans;
}





//
long int sol3(char ch[])
{
	//char ch[100000];
    //scanf("%s",ch);
    int visit[strlen(ch)];
    long int coin = 0;
    for(int i=0; i<strlen(ch); i++)
    	visit[i] = 0;
    for(int i=0; i<strlen(ch); i++)
	{
        int count = 1;
        if(visit[i]==0)
		{
            for(int j=i+1; j<strlen(ch); j++)
			{
                if(ch[i]==ch[j])
				{
                    ++count;
                    visit[j] = 1;
                }
            }
        }
        coin += count/2;
    }
    if(coin<strlen(ch)/3)
        return coin;
    else
        return (strlen(ch)/3);
}



int main()
{
	char s[];
    
	/*Constraints:
	>	1 <= |S| <= 10^5
	>	S contains only lowercase English letters
	*/
	//Rahul, HELP, I don't understand how to write this constraints?
	
    __CPROVER_assert(sol1(s)==sol2(s),"sol1vsol2");
    __CPROVER_assert(sol1(s)==sol2(s),"sol1vsol3");
    __CPROVER_assert(sol1(s)==sol2(s),"sol2vsol3");
	
}
