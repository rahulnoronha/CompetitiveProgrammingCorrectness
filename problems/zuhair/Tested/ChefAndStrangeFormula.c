//https://www.codechef.com/problems/STFM
/*Constraints
1 ≤ n ≤ 10^5
1 ≤ pi ≤ 10^18
1 ≤ m ≤ 10^7*/


//https://www.codechef.com/viewsolution/26135425
long long int sol1(long long int n,long long int m,long long int p);
long long int sol1(long long int n,long long int m,long long int p)
{
long long int i,ans=0 ;
long long int fact[m+1];
fact[0]=1;
for(i=1;i<m+1;i++)
{
	fact[i]=((long long int)fact[i-1]*i)%m;
}

for(i=0;i<n;i++)
{
	long long int t1=0;
	if(p+1<m)
		t1=fact[p+1];
	long long int x=p;
	long long int y=p+1;
	if(x%2==0)
		x=x/2;
	else
		y=y/2;

	long long int t2 = ((x%m)*(y%m))%m;
	t2= (t2 * (p%m))%m;
	long long int ans1 =(t1+t2-1)%m;
	ans = (ans + ans1)%m; 
}

return ans;
}

//https://www.codechef.com/viewsolution/10830555
long long int sol2(int n,int m,long long int p);
long long int sol2(int n,int m,long long int p)
{
    int sum=0,b,i,j,fact,k;
    for(i=0;i<n;i++)
    {
        b=p%m;
        fact=1;
        k=(p>m?m:p);
        for(j=1;j<=k;j++)
        {
            fact=(fact*j)%m;
            sum+=(j*fact)%m;
        }
        if(p%2==0)
            sum=(sum+(((((p/2)%m)*b)%m)*((p+1)%m))%m)%m;
        else
            sum=(sum+(((b*b)%m)*(((p+1)/2)%m))%m)%m;
    }
    return sum;
}

//https://www.codechef.com/viewsolution/10166187
long long int sol3(long long int n,long long int m,long long int p);
long long int sol3(long long int n,long long int m,long long int p)
{

    long long int i,j,k,a=1,s=0,b=0,x;
     for(i=1;i<=n;i++)
    {
        s=0;
        x=0;
        for(j=1;j<=p;j++)
        {
            a=1;
            for(k=1;k<=j;k++)
            {
                a=(a*k)%m;
                if(a==0)
                {
                    x=1;
                    break;
                }
            }
            a=(a*j)%m;
            s=(s+a)%m;
            if(x==1)
                break;
        }
        if(p%2==0)
            s=(s+((((((p/2)%m)*(p+1))%m)*p)%m))%m;
        else
            s=(s+(((((p%m)*((p+1)/2))%m)*p)%m))%m;
        b=(b+s)%m;
    }
    return b;
}


int main()
{
long long int n,m,p; 

if(n<1||n>100000||m<1||m>10000000||p<1||p>10000000000)
    return 0;
__CPROVER_assert(sol1(n,m,p)==sol2(n,m,p),"sol1vsol2");
__CPROVER_assert(sol1(n,m,p)==sol3(n,m,p),"sol1vsol3");
__CPROVER_assert(sol2(n,m,p)==sol3(n,m,p),"sol2vsol3");

}

//Tested using cbmc and found counterexample for --unwind 3 for sol1vsol2 and sol1vsol3. Satisfiable
//Bruteforce not attempted
