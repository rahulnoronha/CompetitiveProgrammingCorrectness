//Problem link:https://www.codechef.com/problems/GMEDIAN
/*Constraints
1≤T≤30
1≤N≤1,000
1≤Ai≤2N for each valid i
*/

#include<stdio.h>
#include<stdlib.h>
#define mod1 1000000007
long long arr[1005];
long long m = 1005, mod = (long long)(1e9+7);


//Solution link: https://www.codechef.com/viewsolution/38348396
long long int b[1001][1001];
void preprocess()
{
    int i,j;
    b[0][0]=1;
    for(i=1;i<1001;i++)
    {
        b[i][0]=1;
        for(j=1;j<i;j++)
        {
            b[i][j]=(b[i-1][j-1]+b[i-1][j])%mod1;
        }
        b[i][i]=1;
    }
}
long long int my_power(int a,int n)
{
 if(!n)
 {
     return 1;
 }
 long long int pt=my_power(a,n/2);
 pt=(pt*pt)%mod1;
 if(n%2)
 {
     return (pt*a)%mod1;
 }
 else
 {
     return pt;
 }
}
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

long long int sol1(int n , int a[])
{

        int i;

        qsort(a,n,sizeof(int),cmpfunc);
        preprocess();
        long long int ans=my_power(2,n-1);
        int j;
        for(i=0;i<n;i++)
        {
            j=i+1;
            while((j<n)&&(a[i]==a[j]))
            {
                int r=n-1-j;
                int l=i;
                ans=(ans+b[l+r][l])%mod1;
               // printf("b--%d r=%d l=%d \n",b[l+r][l],r,l);
                j++;
            }
        }
        return ans;


}



//Solution Link: https://www.codechef.com/viewsolution/24961234
void merge(long long arr[], long long l, long long m, long long r) 
{ 
    long long int i, j, k; 
    long long int n1 = m - l + 1; 
    long long int n2 =  r - m;
    long long int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(long long arr[], long long l, long long r) 
{ 
    if (l < r) 
    { 
        long long int m = (l+r)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
}

long long power(long long x, long long n) { 
    if(n == 0) 
        return 1;
    long long temp = power(x, n/2) % mod; 
    if(n % 2 == 0) 
        return ((temp % mod) * (temp % mod)) % mod; 
    else 
    	return ((((x % mod) * (temp % mod)) % mod) * (temp % mod)) % mod;
}

long long int sol2(long long int n, long long int arr[])
{
	long long  i, fact[m], ifact[m];
	fact[0] = 1;
	for(i=1; i<m; i++)
	    fact[i] = (fact[i-1] * i) % mod;
	ifact[m-1] = power(fact[m-1], mod-2);
	for(i=m-2; i>=0; i--)
	    ifact[i] = (ifact[i+1] * (i+1))%mod;

	    long long  l, r, ans=0, j;

	    mergeSort(arr, 0, n-1);
	    for(i=0; i<n; i++)
	    {
	        for(j=i; j<n; j++)
	        {
	            if(i==j || arr[i] == arr[j])
	            {
	                l = i;
	                r = n-j-1;
	                ans = (ans + ((fact[l+r] * ifact[l])%mod * ifact[r])%mod)%mod;
	            }
	            else
	                break;
	        }
	    }
	
	
	return ans;
}


//Solution Link: https://www.codechef.com/viewsolution/24864828
int cmpfunc1 (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int min(int a, int b){
    if(a<b) return a;
    return b;
}

long long int sol3(int n, int a[])
{
    long long int comb[1001][1001];
    for(int i=0; i<=1000; i++){
        comb[0][0] = 1;
        comb[i][0] = 1;
        comb[0][i] = 0;
    }
    for(int i=1; i<=1000; i++){
        for(int j=1;j<=1000;j++){
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % 1000000007;
            
        }
    }

        long long int cnt=1;

        int a[n];
        int b[2*n+1];
        for(int i=0; i<n; i++){
            b[a[i]]++;
        }
        //sort array
        qsort(a, n, sizeof(int), cmpfunc1);
        // For odd subsequences
        for(int i=1; i<n; i++){
            cnt = (cnt*2)%1000000007;
        }
        // for even subsequences
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(a[i]==a[j]){
                    cnt = (cnt + comb[i+n-j-1][i])%1000000007;
                }
            }

    
        }
         return cnt % 1000000007;
}   

 
int main()
{
	int n;
	int m = (n>0?n:1);
	int x[m];
	int *y = (n>0?x:NULL);
	if(n<1||n>1000)
	{
		return 0;
	}


	__CPROVER_assert(sol1(m,y) == sol2(m,y),"sol1vsol2");
	__CPROVER_assert(sol1(m,y) == sol3(m,y),"sol1vsol3");
	__CPROVER_assert(sol2(m,y) == sol3(m,y),"sol2vsol3");

}

//Tested using cbmc and found no counterexample. Unsatisfiable by time exceeded for --unwind 10
//Bruteforce not attempted
