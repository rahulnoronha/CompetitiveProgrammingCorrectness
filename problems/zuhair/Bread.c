//https://www.codechef.com/problems/EGBOBRD

/*Constraints and Subtasks
1 ≤ T ≤ 10

Subtask 1: 15 points
1 ≤ N ≤ 100
1 ≤ K ≤ 100
1 ≤ Ai ≤ 100

Subtask 2: 25 points
1 ≤ N ≤ 10^5
1 ≤ K ≤ 10^6
1 ≤ Ai ≤ 10^6

Subtask 3: 60 points
1 ≤ N ≤ 10^5
1 ≤ K ≤ 10^11
1 ≤ Ai ≤ 10^6*/


//https://www.codechef.com/viewsolution/36051795
long long int sol1(long long int n,long long int k,char *a[n])
{
		long long int i;
		long long int a[n],x=0,count=1,y;
		for(i=0;i<n;i++)
		{
		x+=a[i];
		if(a[i]%k!=0 && i!=n-1 && x%k!=0)
		x++;
		}
		if(x%k==0)
		return x/k;
		else
		return x/k+1;
}



//https://www.codechef.com/viewsolution/19950377
#include<math.h>
long long int sol2(long long int n,long long int k,char *a[n])
{

        long long int i,sum=0,count=0;
        //long long int a[n];
        for(i=0;i<n-1;i++)
        {
            sum=sum+a[i];
            if((sum%k)!=0)
            {
                sum=sum+1;
            }
        }
        sum=sum+a[n-1];
        count=sum%k;
        sum=sum/k;
        if((count%k)==0)
        {
            return sum;
        }
        else
        {
            return sum+1;
        }

}



//https://www.codechef.com/viewsolution/38190680
typedef long long int ll;
long long int sol3(long long int n,long long int k,char *a[n])
{
    int i;
        ll *a,j,ans=0,q,res=0;
        a=(ll *)malloc(n*sizeof(ll));
        for(j=0;j<n;j++)
        {
            if(res==0)
            {
                q=a[j]/k;
                if(a[j]%k>0)
                {
                    q++;
                }
                res=k-(a[j]%k);
                if(a[j]%k==0)
                {
                    res=0;
                }
                ans+=q;
            }
            else
            {
                res--;
                if(a[j]-res>0)
                {
                    a[j]-=res;
                    q=a[j]/k;
                    if(a[j]%k>0)
                    {
                        q++;
                    }
                    res=k-(a[j]%k);
                    if(a[j]%k==0)
                    {
                        res=0;
                    }
                    ans+=q;
                }
                else
                {
                    res-=a[j];
                    a[j]=0;
                }
            }
        }
        return ans;
    }


int main()
{
	long long int n,k;
	char *a[n];
	if(n<1||n>100||k<1||k>100||a[n]<1||a[n]>100)
    		return 0;
		__CPROVER_assert(sol1(n,k,a[n])==sol2(n,k,a[n]),"sol1vsol2");
		__CPROVER_assert(sol1(n,k,a[n])==sol3(n,k,a[n]),"sol1vsol3");
		__CPROVER_assert(sol2(n,k,a[n])==sol3(n,k,a[n]),"sol2vsol3");

}


