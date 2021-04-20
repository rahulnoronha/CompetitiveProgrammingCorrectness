//https://www.codechef.com/problems/DELSUM

/*Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 20
1 ≤ D ≤ N*/


//https://www.codechef.com/viewsolution/24484190

int sol1(int n,int d)
{
    	int a[20],i,j;
        int sum=0;
          for(j=0;j<i;j++)
            {
               
                if (a[i]<a[j])
                {
                    a[i]=a[i]+a[j];
                    a[j]=a[i]-a[j];
                    a[i]=a[i]-a[j];
                }
            }
               for (i=0;i<n-d;i++)
        {
            sum=sum+a[i];
        }
        return sum;
}



//https://www.codechef.com/viewsolution/37037011

int sol2(int n,int d)
{
	    int i,j,k,index,sum=0,max=0,temp=0;
	    int array[25];
	    for(k=0;k<n;k++)
	    {
	        //scanf("%d", &temp);
	        array[k]=temp;
	        
	    }
	    for(i=0;i<d;i++)
	    {
	        max=0;
	        for(j=0;j<n;j++)
	        {
	           if(array[j]>max)
	           {
	               max=array[j];
	               index=j;
	              
	           }
	        }
	        array[index]=0;
	    }
	    for(j=0;j<n;j++)
	        {
	           sum=sum + array[j];
	        }
	 return sum; 
	}

//https://www.codechef.com/viewsolution/28559272
int sol3(int n,int d)
{
	    int temps,sum,a[1000];
	    sum=0;
            for(int i=0;i<n-1;i++){
	        for(int j=0;j<n-1-i;j++){
	             if (a[j] > a[j + 1]) {  
                temps = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temps;
	        }
	    }
	   
	}
	for(int i=n-1;i>(n-1-d);i--){
	    a[i]=0;
	}
	for(int i=0;i<n;i++){
	        sum+=a[i];
	    }
	return sum;
	
}



int main()
	{
		int n,d;
		if(n<1||n>20||d<1||d>20)
    		return 0;
		__CPROVER_assert(sol1(n,d)==sol2(n,d),"sol1vsol2");
		__CPROVER_assert(sol1(n,d)==sol3(n,d),"sol1vsol3");
		__CPROVER_assert(sol2(n,d)==sol3(n,d),"sol2vsol3");
		
	}

//Tested and found counterexample for --unwind 3 . Satisfiable
//Bruteforce approach not tested
