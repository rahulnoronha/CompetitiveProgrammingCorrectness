#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
AndOperation: https://www.codechef.com/problems/TAAND
Constraints:
>	2 <= N <= 3 × 10^5
>	0 <= Ai <= 10^9
*/


//https://www.codechef.com/viewsolution/39740818
int sol1(int n, int a[])
{
	int i, j, k = 0, ans = 0;
	int x, b[n];
	for (i = 0; i < n; i++)
    {
        if (a[i] > ans)
        {
            for (j = 0; j < k; j++)
            {
                x = a[i] & b[j];
                if (ans < x)
                {
                    ans = x;
                }
            }
            b[k++] = a[i];
        }
    }
    return ans;
}



//https://www.codechef.com/viewsolution/36177040
int sol2(int n, int a[])
{
	unsigned int i=0,j=0,res=0,max=0;
	for(i=0;i<n;i++)
    {
    	for(j=i;j<n;j++)
    	{
			if(max<a[i])
    		{
    			if(i!=j)
    			{
    				res=(a[i])&(a[j]);
    				if(max<res)max=res;
    			}
			}
			else break;
    	}	
    }
    return max;
}





//https://www.codechef.com/viewsolution/36113392
int cmpfunc3(const void *a,const void* b)
{
    return (*(int*)b-*(int*)a);
}

int sol3(int n, int a[])
{
	int num,count,max=0,another;
	//int a[n],another;
	qsort(a,n,sizeof(int),cmpfunc3);
    for(int i=30;i>=0;i--)
    {
        num=pow(2,i),count=0;
        for(int j=0;j<n;j++) 
        {
            if(num&a[j])count++;
        }
        if(count>1) 
        {
            if(max==0)
            {
                max+=num;
            }
            else
            {
                another=0;
                for(int j=0;j<n;j++)
                {
                    if(((a[j]&num)==num)&((a[j]&max)==max))another++;
                }
                if(another>1)
                {
                    max+=num;
                }
            }
        }
    }
    return max;
}




//https://www.codechef.com/viewsolution/36102046
int cmpfunc4(const void *a,const void* b)
{
    return (*(int*)b-*(int*)a);
}
int sol4(int n, int a[])
{
	int biggest=0;
    //scanf("%d",&n);
    //int a[n];
    //for(int i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmpfunc4);
    for(int i=0;i<n-1;i++) biggest=(a[i]&a[i+1])>biggest?(a[i]&a[i+1]):biggest;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=biggest)
        continue;
        for(int j=i+1;j<n;j++)
        {
            if((a[i]&a[j])>biggest)
            biggest=(a[i]&a[j]);
        }
    }
    return biggest;
}



int main()
{
	int n;
	if(n<2 || n>3*100000)
		return 0;
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

//Tested using cbmc and found a counterexample for sol1vsol2 at --unwind 3 onwards.
//Bruteforce check not done
