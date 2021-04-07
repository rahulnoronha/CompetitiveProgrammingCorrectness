/*
Racing Horses: https://www.codechef.com/problems/HORSES
*/

#include<stdio.h>

//https://www.codechef.com/viewsolution/44685603
int sol1(int n, int s[])
{
	int i,j,k;
	int min;
	min=abs(s[0]-s[1]);
    for(j=0;j<n;j++)
	{
        for(k=j+1;k<n;k++)
		{
            if(min>abs(s[j]-s[k]))
			{
                min=abs(s[j]-s[k]);
            }
        }
    }
    return min;
}

//https://www.codechef.com/viewsolution/43861344
void swap2(int* a, int* b) 
{ 
	int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition2 ( int arr[], int low, int high) 
{ 
   int pivot = arr[high]; // pivot 
   int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap2(&arr[i], &arr[j]); 
        } 
    } 
    swap2(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort2(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
       
       int pi = partition2(arr, low, high); 
  
        quickSort2(arr, low, pi - 1); 
        quickSort2(arr, pi + 1, high); 
    } 
}

int sol2(int n, int arr[])
{
	int i,min,diff;
	//scanf("%lld",&n);
	//int arr[n];
	quickSort2(arr,0,n-1);
	//for(i=0;i<n;i++){
    //       printf(" %d",arr[i]);}
    //       printf("\n");
    min=1000000000;
	for(i=1;i<n;i++)
	{
	    if(arr[i-1]>=arr[i])
	        diff=arr[i-1]-arr[i];
	    else
	        diff=arr[i]-arr[i-1];
	        
	    if(diff<=min)
	        min=diff;
	    else 
	        continue;
	}
	return min;
}





//https://www.codechef.com/viewsolution/39914960
int sol3(int n, int a[] )
{
	int min = 0;
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-1-i; j++){
			if(a[j] < a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	min = a[0] - a[1];
	for(int j=1; j<n-1; j++){
		int result = a[j] - a[j+1];
		if(min > result) min = result;
	}
	 return min;
}


//https://www.codechef.com/viewsolution/37777478
int sol4(int n, int a[])
{
	int i,j,pro,min=1000000000;
	for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            pro=abs(a[i]-a[j]);
            if(pro<min)
                min=pro;
        }
    }
    return min;
}


int main()
{
	int n;
	if((n<2||n>5000))
	{
    	return 0;
    }
	int m = (n > 0 ? n : 1);
	int x[m];
	int *a = (n > 0 ? x : NULL);
	__CPROVER_assert(sol1(n,a)==sol2(n,a),"sol1Vsol2");
  __CPROVER_assert(sol1(n,a)==sol3(n,a),"sol1Vsol3");
  __CPROVER_assert(sol1(n,a)==sol4(n,a),"sol1Vsol4");
  __CPROVER_assert(sol2(n,a)==sol3(n,a),"sol2Vsol3");
  __CPROVER_assert(sol2(n,a)==sol4(n,a),"sol2Vsol4");
  __CPROVER_assert(sol3(n,a)==sol4(n,a),"sol3Vsol4");
    return 0;
}
