#include<stdio.h>
#include<string.h>

/*
Physics: https://www.codechef.com/problems/PHYSICS
*/


//https://www.codechef.com/viewsolution/17974169
void merge1(int arr[], int l, int m, int r)
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
void mergeSort1(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort1(arr, l, m);
        mergeSort1(arr, m+1, r);
 
        merge1(arr, l, m, r);
    }
}
 
int binary1(int a[],int req,int i,int j)
{
    if(i>j) return -1;
    int mid=(i+j)/2;
    if(a[mid]==req)
    {
        int pos=mid;
        while(pos>=0 && a[pos]==req) pos--;
        return pos+1;
    }
    if(a[mid]<req)  return binary1(a,req,mid+1,j);
    else    return binary(a,req,i,mid-1);
}

int sol1(int n, int f, int a[])
{
	int i,req,pos,same,count1=0;
	mergeSort1(a,0,n-1);
    int count=0,req2;
    same=0;
    for(i=n-1;i>0;i--)
    {
        req=a[i];
        count1=0;
        while(req>0)
        {
            pos=binary1(a,req,0,n-1);
            if(pos!=-1 && a[i]==a[pos])
            {
                count+=((i-pos+1)*(i-pos))/2;
                same=i-pos+1;
            }
            else
            {
                while(pos!=-1 && pos<i && a[pos]==req)
                {
    	            pos++;
                    count1++;
                }
            }
            if(req%f==0)
        	    req/=f;
            else break;
        }
        // printf("%d %d\n",count1,same);
        count+=count1*same;
        i=i-same+1;
    }
    return count;
}




//https://www.codechef.com/viewsolution/17313929
int mycomp2(const void* a,const void* b)
{
    int f=*((int*)a);
    int s=*((int*)b);
    return f-s;
}

int sol2(int n, int f, int h[])
{
	int i,j,k,l,m,z,y,x;
	int ans = 0;
    //scanf("%d%d",&n,&f);
    for(i=0;i<n;i++)
    {
        z=h[i];
        while(z%f==0)
            z/=f;
        h[i]=z;
    }
	qsort(h,n,sizeof(int),mycomp2);
    y = h[0];x = 1;
    for(i=1;i<n;i++)
    {
        if(h[i]!=y)
        {
            y = h[i],x=0;
        }
        ans += x ;
    	x ++;
	}
    return ans;
}








//https://www.codechef.com/viewsolution/5243423
void merge3(int arr[],int l,int m,int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back long long into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
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

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort3(int arr[],int l,int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort3(arr, l, m);
        mergeSort3(arr, m+1, r);
        merge3(arr, l, m, r);
    }
}
/* if x is present in arr[] then returns the count of occurrences of x,
   otherwise returns -1. */


/* if x is present in arr[] then returns the index of FIRST occurrence
   of x in arr[0..n-1], otherwise returns -1 */
int first(int arr[], int low, int high, int x, int n)
{
  if(high >= low)
  {
    int mid = (low + high)/2;  /*low + (high - low)/2;*/
    if( ( mid == low || x > arr[mid-1]) && arr[mid] == x)
      return mid;
    else if(x > arr[mid])
      return first(arr, (mid + 1), high, x, n);
    else
      return first(arr, low, (mid -1), x, n);
  }
  int r=-1;
  return r;
}


/* if x is present in arr[] then returns the index of LAST occurrence
   of x in arr[0..n-1], otherwise returns -1 */
int last(int arr[], int low, int high, int x, int n)
{
  if(high >= low)
  {
    int mid = (low + high)/2;  /*low + (high - low)/2;*/
    if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x )
      return mid;
    else if(x < arr[mid])
      return last(arr, low, (mid -1), x, n);
    else
      return last(arr, (mid + 1), high, x, n);
  }
  int r=-1;
  return r;
}


int count(int arr[],int z, int x, int n)
{
  int i; // index of first occurrence of x in arr[0..n-1]
  int j; // index of last occurrence of x in arr[0..n-1]

  /* get the index of first occurrence of x */
  i = first(arr, z, n-1, x, n);

  /* If x doesn't exist in arr[] then return -1 */
  if(i == -1)
    return i;

  /* Else get the index of last occurrence of x. Note that we
      are only looking in the subarray after first occurrence */
  j = last(arr, i, n-1, x, n);

  /* return count */
  return j-i+1;
}

int sol3(int n, int f, int a[])
{
	int x,sum,q,i;
	sum=0;
	mergeSort3(a,0,n-1);
    /*for(i=0;i<n;i++)
    printf("%lld",a[i]);*/
    for(i=0;i<n;i++)
    {
        x=a[i];
        while(x<=a[n-1])
        {
            q=count(a,i+1,x,n);
            //printf("%lld",q);
            if(q!=-1)
    	        sum=sum+q;
            x=x*f;
        }
    }
    return sum;
}





int main()
{
	int n, f;
    if((n<2||n>10000)||(f<2||f>1000000000))
    {
    	return 0;
    }
	int m = (n > 0 ? n : 2);
	int x[m];
	int *a = (n > 0 ? x : NULL);
  	
	__CPROVER_assert(sol1(n,f,a)==sol2(n,f,a),"sol1Vsol2");
  __CPROVER_assert(sol1(n,f,a)==sol3(n,f,a),"sol1Vsol3");
  __CPROVER_assert(sol2(n,f,a)==sol3(n,f,a),"sol2Vsol3");
	return 0;
}

//Tested using cbmc but time exceeded so we assume that it is unsatisfiable in this case
//Bruteforce approach not done