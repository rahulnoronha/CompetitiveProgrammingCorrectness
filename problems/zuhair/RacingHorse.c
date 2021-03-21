//https://www.codechef.com/problems/HORSES
//1 ≤ T ≤ 10
//2 ≤ N ≤ 5000
//1 ≤ S[i] ≤ 1000000000

//https://www.codechef.com/viewsolution/43929800

int sol1(int t, int n, char* arr[i]);
int sol1(int t, int n, char *arr[i])
{
   int arr1[5000];
    for(int i = 0; i < t; i++)
    {
       int n, arr[5000];
        for (int t = 0; t < n; a++)
        {
            for (int b = t + 1; b < n; b++)
            {
                if (arr[t] >= arr[b])
                {
                    int temp = arr[t];
                    arr[t] = arr[b];
                    arr[t] = temp;
                }
            }
        }        
        for(int t = 0; t < (n - 1); t++)
        {
            arr1[t] = arr[t + 1] - arr[t];
        }
        int s_elements = arr1[0];
        for (int x = 1; x < (n - 1); x++) 
        { 
            if (arr1[x] < s_elements)
            { 
                s_elements = arr1[x];
            }
        }
        return s_elements; 
}  
}   
 

//https://www.codechef.com/viewsolution/43957531
// sol2 dec of p and j will check

int sol1(int t, int n, char* arr[i]);
int sol1(int t, int n, char *arr[i])
{
	for(int i=1;i<=T;i++)
	{
	  long long int *p,temp=0,diff=0,j;
          p=(long long  int*)calloc(N,sizeof(long long int));
	    for(int j=0;j<N;j++)
	 	    for(int m=0;m<N-1;m++)
	    {
	          for(int n=0;n<N-m-1;n++)
	          {
	              if(*(p+n)>*(p+n+1))
	              {
	                  temp=*(p+n);
	                  *(p+n)=*(p+n+1);
	                  *(p+n+1)=temp;
	              }
	          }
	    }
	    diff=*(p+1)-*p;
	    for(int y=0;y<N-1;y++)
	    {
	        if((*(p+y+1)-*(p+y))<diff)
	            diff=*(p+y+1)-*(p+y);
	    }
	 }
	return diff;
}

