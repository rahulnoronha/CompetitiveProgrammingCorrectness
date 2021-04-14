//https://www.codechef.com/problems/MAXPRODU

/*
1≤N≤10^9
1≤K≤10^4

*/

//Using CBMC


//https://www.codechef.com/viewsolution/22339523


long long int sol1(long long int n,long long int k);
long long int sol1(long long int n,long long int k)
{
    int i, r, q, sum, a[10005];
    long long int ans, MOD = 1e9 + 7;
    ans = 1;

        sum = (k * (k + 1)) / 2;
        if(n < sum)
            ans = -1;
        else if(n == sum)
            ans = 0;
        else
        {
            r = n - sum;
            q = r / k;
            for(i = 1; i <= k; i++)
                a[i-1] = i;

            for(i = 0; i < k; i++)
            {
                a[i] += q;
            }
            r -= q * k;

            i = k-1;
            while(r != 0)
            {
                a[i--]++;
                r--;
            }
            for(i = 0; i < k; i++)
            {
                ans = (((ans * (a[i] - 1)) % MOD) * a[i]) % MOD;
            }
        }
        return ans;
}

//https://www.codechef.com/viewsolution/21345487


long long int sol2(long long int n,long long int k);
long long int sol2(long long int n,long long int k)
{
    if(n<k*(k+1)/2){ return -1;}
	    long long int a[k],s=0,i;
	    for(i=0;i<k;i++)
	        a[i]=i+1;
	    s=n-k*(k+1)/2;

	    for(i=0;i<k;i++){
	        if(s/k==0) break;
	        a[i]+=s/k;
	    }
	    s=s%k;
	    i=k-1;
	    while(s>0){
	        a[i]+=1;
	        s--;
	        i--;
	    }
	    long long int p=1;
	    for(i=0;i<k;i++){
            p*=a[i];
            p%=1000000007;
            p*=(a[i]-1);
            p%=1000000007;
	    }
        return p%1000000007;
}

//https://www.codechef.com/viewsolution/21337315


int mod=1000000007;
long long int pro(long long int a)
{
	return (a*a-a)%mod;
}

long long int sol3(long long int n,long long int k);
long long int sol3(long long int n,long long int k)
{
    long long int a,b,res,i,t;
    res=1;
    if(n<k*(k+1)/2)
		{
			return -1;
		}
		else
		{
			a=(n-k*(k+1)/2)/k;
			b=(n-k*(k+1)/2)%k;
			for(i=1;i<=k;i++)
			{
				if(i==k-b+1)
				a++;
				res=(res*(pro(a+i)%mod))%mod;
			}
			return res;
		}
}


int main()
{
    /*
1≤N≤10^9
1≤K≤10^4

*/
long long int n,k;
if(n<1||n>1000000000||k<1||k>10000)
    return 0;

    __CPROVER_assert(sol1(n,k)==sol2(n,k),"sol1vsol2");
    __CPROVER_assert(sol1(n,k)==sol3(n,k),"sol1vsol3");
    __CPROVER_assert(sol2(n,k)==sol3(n,k),"sol2vsol3");


}

//Tested using cbmc and found no counterexample. Unsatisifiable by time exceeded.
//Bruteforce not attempted