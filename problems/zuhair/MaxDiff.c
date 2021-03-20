//https://www.codechef.com/problems/MAXDIFF
//CONSTRAINTS
//1 ≤ T ≤ 100
//1 ≤ K < N ≤ 100
//1 ≤ Wi ≤ 100000 (105)

//https://www.codechef.com/viewsolution/42405178
long int *sol1(int *a, int n);
long int *sol1(int *a, int n)
{
int i, j, k;
for(i=0;i<n;i++)
	    {
	     for(j=0;j<n;j++)
	     {
	       if(a[j]>a[j+1])
	       {
	         long long temp=a[j];
	          a[j]=a[j+1];
	          a[j+1]=temp;
	       }
	     }
	    }
long long sum1=0,sum2=0,ans;
		     for(int i=0;i<k;i++)
		        sum1=sum1+a[i];
		         for(int i=k;i<n;i++)
		            sum2=sum2+a[i];
		            ans=sum2-sum1;
                                return ans;
}


//https://www.codechef.com/viewsolution/42585219
long int *sol2(int *arr, int n);
long int *sol2(int *arr, int n)
{
int i,r,j,sum,sum1,temp;
for(i=0;i<n-1;i++)
{
	        for(j=0;j<n-1;j++){
	            if(arr[j]>arr[j+1]){
	                temp=arr[j];
	                arr[j]=arr[j+1];
	                arr[j+1]=temp;
	            }
	        }
	    }
	    sum=0;sum1=0;
	    for(i=0;i<r;i++){
	        sum=sum+arr[i];
	    }
	    for(i=r;i<n;i++){
	        sum1=sum1+arr[i];
	    }
return sum1-sum;
}
