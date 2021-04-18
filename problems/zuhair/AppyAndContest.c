//https://www.codechef.com/problems/HMAPPY2
/*Subtasks
Subtask #1 (15 points):
1≤T≤15
1≤K≤N≤10^6
1≤A,B≤10^3*/

//https://www.codechef.com/viewsolution/36124226
int sol1(int n,int a,int b,int k)
{
	int i,c,d,j;
  
	     c=0;
	    d=0;
	   for(j=1;j<=n;j++)
	    {
	        if(j%a==0 && j%b!=0)
	        c=c+1;
	        else if(j%a!=0 && j%b==0)
	        d=d+1;
	       else
	       continue;
	    }
	    if(k<=(c+d))
	    return "Win";
	    else
	    return "Lose";
	}

//https://www.codechef.com/viewsolution/44723895
int sol2(int n,int a,int b,int k)
{
            int count=0;
             for(int i=1; i<=n; i++){
            if(i%a==0 && i%b!=0){
                count++;
            }
            if(i%b==0 && i%a!=0){
                count++;
            }
        }
        if(count>=k){
            return "Win";
        }
        else{
            return "Lose";
        }
        
}

//https://www.codechef.com/viewsolution/35551160
int sol3(int n,int a,int b,int k)
{
	int j;
	int n,a,b,k,i;
	int count=0,count1=0,count2=0;
	for(i=1;i<=n;i++)
		{
			if(i%a==0 && i%b==0)
			{
			count2++;
			}
				if(i%a==0)
				{
				count++;
				}
				if(i%b==0)
				{
				count1++;
				}
		}
	count=count-count2;
	count1=count1-count2;
	if(count+count1>=k)
	{
	return "Win";
	}
	else
	{
	return "Lose";
	}
}



int main()
{
     int n,a,b,k;
     if(k<1||k>1000000||n<1||n>1000000||a<1||a>1000000||b<1||b>100)
        return 0;

   	__CPROVER_assert(sol1(n,a,b,k)==sol2(n,a,b,k),"sol1vsol2");
 	__CPROVER_assert(sol1(n,a,b,k)==sol3(n,a,b,k),"sol1vsol3");
 	__CPROVER_assert(sol2(n,a,b,k)==sol3(n,a,b,k),"sol2vsol3");
  
   
}

