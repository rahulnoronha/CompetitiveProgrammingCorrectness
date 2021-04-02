//https://www.codechef.com/problems/LASTDIG
/*
T ≤ 1000
0 ≤ A ≤ B ≤ 400,000,000

*/
//using CBMC


//https://www.codechef.com/viewsolution/40300607


int ls( long int x)
{
	int temp=0;
	while(x!=0)
	{
		if((x%10)%2==0)
			temp+=2*x%10;
		else
			temp+=x%10;
		x=x/10;
	}
	return temp%10;
}
int sol1(long int a,long int b);
int sol1(long int a,long int b)
{
    long  int j;
		int sum=0;
		while((a<b)&&(a%10!=0))
		{
			sum+=ls(a);
			a++;
		}
		while((b>a)&&(b%10!=0))
		{
			sum+=ls(b);
			b--;
		}
		sum+=((b-a)/10)*45;
		sum+=ls(b);
		return sum;
}


//https://www.codechef.com/viewsolution/11957509

long long int sol2(long int A,long int B);
long long int sol2(long int A,long int B)
{
    long int a,b,n;
    long long int sum;
    a=A/10;
        b=B/10;
        b++;
        n=b-a;
        sum=n*45;
        long int j;
        int l;
        for(j=10*a;j<A;j++)
        {
          l=0;
          n=j;
          while(n>0)
          {
           if((n%10)%2==0)
           {
             l+=(n%10)*2;
           }
           else
           {
             l+=n%10;
           }
           n=n/10;
          }
          sum-=l%10;
        }
        for(j=B+1;j<b*10;j++)
        {
          l=0;
          n=j;
          while(n>0)
          {
           if((n%10)%2==0)
           {
             l+=(n%10)*2;
           }
           else
           {
             l+=n%10;
           }
           n=n/10;
          }
          sum-=l%10;
        }
        return sum;
}


//https://www.codechef.com/viewsolution/2352101

long long int d(long long int n)
{
long long int res=0,temp;
while(n)
{
temp=n%10;
if(temp%2==0)
res+=2*temp;
else
res+=temp;
n=n/10;
}
return res%10;
}
long long int c(long long int n)
{
long long int temp,res=0,i,k;
k=n;
temp=n%10;
n=n-temp;
res=(45*n)/10+d(n);
i=n+1;
while(i<=k)
{
res+=d(i);
i++;
}
return res;
}
long long int sol3(long int a,long int b);
long long int sol3(long int a,long int b)
{
    return c(b)-c(a)+d(a);
}

int main()
{
    long int a,b; //0 ≤ A ≤ B ≤ 400,000,000
    if((a<0||b<0)||(a>400000000||b>400000000))
       return 0;
    __CPROVER_assert(sol1(a,b)==sol2(a,b),"sol1vsol2");
    __CPROVER_assert(sol1(a,b)==sol3(a,b),"sol1vsol3");
    __CPROVER_assert(sol2(a,b)==sol3(a,b),"sol2vsol3");
}

//Tested with cbmc and found counter example for unwind 2
//Bruteforce not tried




