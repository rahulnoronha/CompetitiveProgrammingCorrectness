/*
Subtraction Game 1: https://www.codechef.com/problems/AMSGAME1
*/
#include<stdio.h>

//https://www.codechef.com/viewsolution/42193076
int gcd1(int a,int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
int sol1(int n, int arr[])
{
	int temp=arr[0];
	    for(int j=1;j<n;j++)
	    {
	        temp=gcd1(temp,arr[j]);
	    }
	return temp;
}




//https://www.codechef.com/viewsolution/22300542
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
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
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}

int hcf(int a[],int n)
{
    int count=0,i;
    mergeSort(a, 0, n - 1);
    for(i=1;i<n;i++)
    {
        if(a[i]!=a[0])
        {
            a[i]=a[i]%a[0];
            if(a[i]==0)
            a[i]=a[0];
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==a[0])
        count++;
    }
    if(count==n)
    return a[0];
    else return hcf(a,n);
    
}
int sol2(int n, int a[])
{
	int r=hcf(a,n);
    return r;
}




//https://www.codechef.com/viewsolution/13980175
int gcd3(int a,int b)
{
	if(b==0)
	return a;
	else
	return gcd3(b,a%b);
}
int sol3(int n, int a[])
{
	int i, b;
	if(n==1)
		return a[0];
		else
		{
			for(i=1;i<=n-1;i++)
			{
				b=gcd3(a[i-1],a[i]);
				a[i]=b;
			}
		}
	return b;
}


int main()
{
	int n;
	int m = (n > 0 ? n : 1);
  	int x[m];
  	int *a = (n > 0 ? x : NULL);
    __CPROVER_assert(sol1(n,a)==sol2(n,a),"sol1Vsol2");
    __CPROVER_assert(sol1(n,a)==sol3(n,a),"sol1Vsol3");
    __CPROVER_assert(sol2(n,a)==sol3(n,a),"sol2Vsol3");
   
}
//Tested using cbmc and counterexample found for --uniwnd 1 for all the 3 assertions
//Bruteforce not attempted