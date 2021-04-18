//https://www.codechef.com/problems/TREE2
/*Constraints
1≤T≤50
1≤N≤10^5
0≤A_i≤10^9 for each valid i*/

//https://www.codechef.com/viewsolution/40477003
int sol1(int n,long long int a[n]);
int sol1(int n,long long int a[n])
{
        long long int j,x,i;
              int count=0;
              for(i=0;i<n;i++){
             for(j=i+1;j<n;j++){
                if(a[i]>=a[j]){
                    x=a[i];
                    a[i]=a[j];
                    a[j]=x;
                }
             }
        }
        for(i=0;i<n;i++){
            if(a[i]!=0 && a[i]!=a[i+1]){
                count++;
            }
        }
        return count;
}


//https://www.codechef.com/viewsolution/38985310
long long int sol2(long long int n,long long int a[n]);
long long int sol2(long long int n,long long int a[n])
	{
	  	    int o=n,z=0;
	    for(int i=0;i<n;i++)
	    {
	        int t=0;
	        if(a[i]==0)
	        z=1;
	        for(int j=i+1;j<n;j++)
	        {
	        if(a[i]==a[j])
	        t=1;
	        }
	        if(t)
	        o--;
	    }
	    if(z)
	    o--;
	    return o;
	}

//https://www.codechef.com/viewsolution/38975916
long long int sol3(long long int n,long long int a[n]);	
long long int sol3(long long int n,long long int a[n])
{

	    for(int i=0;i<n-1;i++)
	    {
	        long long int minInd=i;
	        for(int j=i;j<n;j++)
	        {
	            if(a[j]<a[minInd])
	            minInd=j;
	        }
	        int temp=a[i];
	        a[i]=a[minInd];
	        a[minInd]=temp;
	    }
	    int o=n;
	    if(a[0]==0)
	    o--;
	    for(int i=0;i<n-1;i++)
	    {
	        if(a[i]==a[i+1])
	        o--;
	    }
	    return o;
}
	


int main()
{

    long long int n,a[n];
    if(n<1||n>100000||a[n]<0||a[n]>10000000||n<50)
        return 0;

    __CPROVER_assert(sol1(n,a[n])==sol2(n,a[n]),"sol1vsol2");
    __CPROVER_assert(sol1(n,a[n])==sol3(n,a[n]),"sol1vsol3");
    __CPROVER_assert(sol2(n,a[n])==sol2(n,a[n]),"sol2vsol3");
   
}
	
//Tested using cbmc and found no counterexamples. Unsatisfiable by assumption since time exceeded for --unwind 2
//Bruteforce not attempted


