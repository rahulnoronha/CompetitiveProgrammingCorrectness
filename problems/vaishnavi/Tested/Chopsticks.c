#include <stdio.h>

/*
Chopsticks: https://www.codechef.com/problems/TACHSTCK
*/

//https://www.codechef.com/viewsolution/40485348
int partition1(int A[],int l,int r)
{
int key=A[r],temp,i,j;
i=l;
j=r;
j--;
while(1)
{
while(A[i]<key)
{

i++;
}
while(A[j]>key && j>i)
{
j--;
}
if(i<j)
{
temp=A[i];
A[i]=A[j];
A[j]=temp;
i++;
j--;
}
else
{
temp=A[i];
A[i]=A[r];
A[r]=temp;
break;
}
}

return i; 
}
int quickSort1(int A[],int l,int r)
{
if(l>=r)
   return 0;
int mid=partition1(A,l,r);
quickSort1(A,l,mid-1);
quickSort1(A,mid+1,r);

return 0;

}

int sol1(int n, int d, int data[])
{
	int key,j,match=0;
	quickSort1(data,0,n-1);
	for(int i=0;i<n-1;i++)
	{
	if(data[i+1]-data[i]<=d)
	{
	match++;
	i++;
	}
	}
    
    return match;
}






//https://www.codechef.com/viewsolution/39814100
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int sol2(int n, int d, int arr[])
{
	int count;
		mergeSort(arr, 0, n - 1);

	//printArray(arr, n);
	for(int q = 0; q<n-1; q++){
	    //printf("%d ", arr[q]);
	    if(arr[q+1] - arr[q] <= d){
	        ++count;
	        ++q;
	    }
	}
	return count;
}





//https://www.codechef.com/viewsolution/38160229
void swarag(int a[], int d, int j)
{
	int q,w,r,z;
	q=(d*2)+1;
	w=q+1;
	r=d;
	if(q<=j&&a[q]>a[r])
	r=q;
	if(w<=j&&a[w]>a[r])
	r=w;
	if(r!=d)
	{
	 z=a[d];
	 a[d]=a[r];
	 a[r]=z;
	 swarag(a,r,j);}
}
int sol3(int b, int c, int a[])
{
	int d,e,f,g,h,i,j,k=0;
	j=b-1;
	for(d=b/2;d>=0;d--)
	swarag(a,d,j);
	for(d=0;d<b;d++)
	{
	  h=a[0];
	  a[0]=a[j];
	  a[j]=h;
	  j=j-1;
	   swarag(a,0,j);}
	   for(d=0;d<b-1;d++)
	   {
	     j=a[d+1]-a[d];
	     if(j<=c)
	     {
	     k=k+1;
	     	d=d+1;}}
	     return k;
}




//https://www.codechef.com/viewsolution/33930012
int fun(const void * a,const void * b)
{
    return( *(int*)a - *(int*)b);
}
int sol4(int n, int d, int a[])
{
	int p=0,k;
	qsort(a,n,sizeof(int),fun);
	int count = 0;
    for(int i = 0;i<n-1;)
    {
        k = a[i+1] - a[i];
        if(k<=d)
        {
            i+=2;
            count++;
        }else{
            i++;
        }
    }
    return count;
}





int main()
{
	int n, d;
	if(n<1 || n>100000 || d<0 || d>1000000000)
		return 0;
	int m = (n > 0 ? n : 1);
	int x[m];
	int *a = (n > 0 ? x : NULL);
		__CPROVER_assert(sol1(n,d,a)==sol2(n,d,a),"sol1Vsol2");
    __CPROVER_assert(sol1(n,d,a)==sol3(n,d,a),"sol1Vsol3");
    __CPROVER_assert(sol1(n,d,a)==sol4(n,d,a),"sol1Vsol4");
    __CPROVER_assert(sol2(n,d,a)==sol3(n,d,a),"sol2Vsol3");
    __CPROVER_assert(sol2(n,d,a)==sol4(n,d,a),"sol2Vsol4");
    __CPROVER_assert(sol3(n,d,a)==sol4(n,d,a),"sol3Vsol4");
	
}

//Tested using cbmc and found no counterexample since time exceeded. Assume it is unsatisfiable.
//Bruteforce check not attempted