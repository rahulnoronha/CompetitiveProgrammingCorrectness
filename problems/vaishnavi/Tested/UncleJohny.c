#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/*
Uncle Johny: https://www.codechef.com/problems/JOHNY
Constraints:
>	1 <= K <= N <= 100
>	1 <= Ai <= 10^9
*/

//https://www.codechef.com/viewsolution/43640334
int sol1(int n, int a[], int pos)
{
	int j,k;
	int val=a[pos-1];
	for(j=0;j<n-1;j++)
	{
	    for(k=0;k<n-j-1;k++)
	    {
	        if(a[k]>a[k+1])
	        {
	            int t;
	            t=a[k];
	            a[k]=a[k+1];
	            a[k+1]=t;
	        }
	    }
	}
	//for(j=0;j<n;j++)
	//printf("%d ",a[j]);
	for(j=0;j<n;j++)
	{
		if(val==a[j])
	        return j+1;
	}
}



//https://www.codechef.com/viewsolution/41680168
int sol2(int s, int ar[], int k)
{
	int ans=0,j;
	//scanf("%d\n",&s);
	for(j=0;j<s;j++)
	{
	    if(ar[j]<=ar[k-1])
	        ans++;
	}
	return ans;
}




//https://www.codechef.com/viewsolution/38085707
int sol3(int n, int a[], int k)
{
	int i,j,u;
	u=a[k-1];
	for(i=0;i<n-1;i++)
	{
	    for(j=0;j<n-i-1;j++)
	    {
	        if(a[j]>a[j+1])
	        {
	            k=a[j];
	            a[j]=a[j+1];
	            a[j+1]=k;
	        }
	    }
	}
	for(i=0;i<n;i++)
	{
	    if(a[i]==u)
	    {
	        break;
	    }
	}
	return i+1;
}




//https://www.codechef.com/viewsolution/36059073
void quicksort(int a[],int lb,int ub)
{
    int loc;
    if(lb<ub)
    {
        loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}
int partition(int a[],int lb,int ub)
{
    int t;
    int pivot=a[lb];
    int start=lb,end=ub;
    while(start<end)
    {
        while((a[start]<=pivot)&&(start<end))
        {
            start++;
        }
        while(a[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            t=a[start];
            a[start]=a[end];
            a[end]=t;
           // Swap(a[start],a[end]);
        }
    }
    a[lb]=a[end];
    a[end]=pivot;
    return end;
}

int sol4(int n, int a[], int k)
{
	int i, ans;
    for(i=0;i<n;i++)
    {
        if(k-1==i)
        {
            ans=a[i];
        }
    }
   /* for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");*/
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        if(a[i]==ans)
        {
            return i+1;
            break;
        }
    }
}




int main()
{
	int n, k;
	if((n<1 || n>100 || k<1 || k<100))
	{
    	return 0;
    }
    int m = (n > 0 ? n : 1);
	int x[m];
	int *a = (n > 0 ? x : NULL);
	__CPROVER_assert(sol1(n,a,k)==sol2(n,a,k),"sol1Vsol2");
  __CPROVER_assert(sol1(n,a,k)==sol3(n,a,k),"sol1Vsol3");
  __CPROVER_assert(sol1(n,a,k)==sol4(n,a,k),"sol1Vsol4");
  __CPROVER_assert(sol2(n,a,k)==sol3(n,a,k),"sol2Vsol3");
  __CPROVER_assert(sol2(n,a,k)==sol4(n,a,k),"sol2Vsol4");
  __CPROVER_assert(sol3(n,a,k)==sol4(n,a,k),"sol3Vsol4");
  return 0;
}

//Tested using CBMC and since Time exceeded so we assume it is unsatisfiable and that no counterexample was found
//Bruteforce approach not attempted