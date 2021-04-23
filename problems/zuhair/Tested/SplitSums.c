//https://www.codechef.com/problems/SPSUM
/*Constraints
1 ≤ T ≤ 20
1 ≤ N ≤ 1,000,000,000
0 ≤ M ≤ 10^18*/


//https://www.codechef.com/viewsolution/39816467
long long int sol1(long long int n,long long int m)
{
    	int k;   
        long long int s,x,y,temp;
        s=(n*(n+1))/2;
        x=(s-m)/2;
        if(x<=0||(s-m)%2!=0)
        {
            return "No";
            //continue;
        }
        y=x+m;
        while(x!=0)
        {
            temp=y%x;
            y=x;
            x=temp;
        }
        if(y==1)
        return "Yes";
        else
        return "No";
}



//https://www.codechef.com/viewsolution/20267975
unsigned long long int sol2(unsigned long long int n,unsigned long long int m)
{
	  unsigned long long int gcdfind(unsigned long long int,unsigned long long int);
	  unsigned long long int sum,x,a,b,g;
	  //scanf("%llu %llu",&n,&m);
	  sum=n*(n+1)/2;
	   x=sum-m;
	  if(x%2!=0)
	{  
	return "No";
	 //continue;
}
	  b=(x/2);
	  a=sum-b;
	g=gcdfind(a,b);
	  if(g==1)
	  return "Yes";
	  else
	  return "No";
	      
	  	    }
unsigned long long int gcdfind(unsigned long long int a,unsigned long long int b)
{if(a==0)
return b;
else
return gcdfind(b%a,a);
    
}

    
int main()
{
long long int n,m;
if(n<1||n>1000000000||m<0||m>1000000000000000000)
    return 0;
__CPROVER_assert(sol1(n,m)==sol2(n,m),"sol1vsol2");
}