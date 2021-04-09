#include<stdio.h>
#include<string.h>
#include<math.h>

/*
Paying Up: https://www.codechef.com/problems/MARCHA1
*/

//https://www.codechef.com/viewsolution/37377638
char* sol1(int n, int m, int banknote[])
{
	int i, j;
	char flag=1;
    for(i=0;i<(1<<n) && flag;i++)
    {
        int sum=0,j=1,bit=0;
        for(j;j<=(1<<n);j<<=1,bit++)
            if(j&i)
				sum+=banknote[bit];
    	if(sum==m)
			flag=0;
    }
    if(flag==0) return "Yes\n";
    else return "No\n";
}


//https://www.codechef.com/viewsolution/39949517
char* sol2(int n, int m, int arr[])
{
	int i,j,rem,cnt,flag=0;
	int sum=0;
	// printf("%d",2^n);
	for(i=1;i<pow(2,n);i++)
	{
	    sum=0;
	    j=i;
	    cnt=0;
	    while(j)
	    {
	        rem=j%2;
	        if(rem==1)
	        sum+=arr[cnt];
	        //printf("%d\t",sum);
	        cnt++;
	        j/=2;
	    }
		// if(i==7)
	    // printf("%d",sum);
	    if(sum==m)
	    {
	        flag=1;
	        //printf("%d\n",i);
	        break;
	    }
	}
	if(flag==1)
		return "Yes\n";
	else 
		return "No\n";
}


//https://www.codechef.com/viewsolution/34931027
char* sol3(int n, int m, int arr[])
{
	int sum, i, j, k;
	//scanf("%d%d",&n,&m);
	int s[n+1];
	for(i=1;i<pow(2,n);i++){
		k=i;
		sum=0;
		for(j=n-1;j>=0;j--){
			arr[j] = k%2;
			k/=2;
			if(arr[j]==1){
				sum+=s[j];
			}
		}
		if(sum==m)break;
	}
	if(sum==m){
		return "Yes\n";
	}
	else
		return "No\n";
}


int main()
{
	int n, m;
	if(n>20)
		return 0;
	int y = (n > 0 ? n : 1);
	int x[y];
	int *a = (n > 0 ? x : NULL);
	for(int i=0; i<n; i++)
		if(a[i]>100)
			return 0;
	__CPROVER_assert(sol1(n,m,a)==sol2(n,m,a),"sol1Vsol2");
  __CPROVER_assert(sol1(n,m,a)==sol3(n,m,a),"sol1Vsol3");
  __CPROVER_assert(sol2(n,m,a)==sol3(n,m,a),"sol2Vsol3");
  return 0;
}

//Tested using cbmc and found counterexample for --unwind 1 for sol1vsol3 and sol2vsol3. Satisfiable
//Bruteforce check not done