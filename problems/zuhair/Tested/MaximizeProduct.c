//https://www.codechef.com/problems/MAXPRODU

/*Constraints
1≤T≤1,000
1≤N≤10^9
1≤K≤10^4*/


//https://www.codechef.com/viewsolution/21360166
int sol1(int n,int k)
{
    long long total_sum=1;
    int i,j;
             total_sum=1;
             int A[k];
        int a=(2*n-k*(k+1))/(2*k);
        if(a<0) 
	{
            return -1;
            //continue;
        }
        int diff=n-(a*k+k*(k+1)/2);
        //printf("diff:%d\n",diff);
        for(j=0;j<k;j++){
            A[j]=a+j+1;
        }
        for(j=k-1;j>k-1-diff;j--)
	{
            A[j]++;
        }
        for(j=0;j<k;j++)
	{
            total_sum=(total_sum*((A[j]*(A[j]-1))%1000000007))%1000000007;
            total_sum=total_sum%1000000007;
        }
        return total_sum;

}


//https://www.codechef.com/viewsolution/22339523
int sol2(int n,int k)
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
long long int sol3(long long int n,long long int k)
{
	    if(n<k*(k+1)/2)
	    { 
	    return -1;
	    //continue;
 	    } 
	    long long int a[k],s=0,i;
	    for(i=0;i<k;i++)
	        a[i]=i+1;
	    s=n-k*(k+1)/2;
	    //printf(" %d ",s/k);
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




int main()
{
long long int n,k;
if(n<1||n>100000000||k<1||k>10000)
    return 0;
__CPROVER_assert(sol1(n,k)==sol2(n,k),"sol1vsol2");
__CPROVER_assert(sol2(n,k)==sol3(n,k),"sol2vsol3");
__CPROVER_assert(sol1(n,k)==sol3(n,k),"sol1vsol3");

}

//Tested using cbmc and assumed it is Unsatisfiable because time limit exceeded
//Brutforce not attempted