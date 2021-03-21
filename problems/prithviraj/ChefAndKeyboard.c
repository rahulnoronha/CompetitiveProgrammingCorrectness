//https://www.codechef.com/problems/CHEFKEY
/*
1 ≤ T ≤ 100
1 ≤ n, m ≤ 10^6
1 ≤ c ≤ 10^6

*/

//TRY CBMC

//https://www.codechef.com/viewsolution/37911608

#include<math.h>

int sol1(int n,int m,int c);
int sol1(int n,int m,int c)
{
    int i,j,count,x,y;
	float limit;
	count=0;
		limit=sqrt(c);
		for(j=1;j<=limit;j++)
		       if(c%j==0)
		       {
				x=j;
				y=c/j;
				if(x<=n&&y<=m)
					count++;
				if(x!=y&&x<=m&&y<=n)
					count++;
		       }
return count;
}


//https://www.codechef.com/viewsolution/37831206

int sol2(int a,int b,int c);
int sol2(int a,int b,int c)
{
    int k=0;
    for(int i=1;i<=a;i++)
    {
        if(c%i==0 && c/i<=b)
            k++;
    }
return k;
}

//https://www.codechef.com/viewsolution/16731315


long long int sol3(long long int n,long long int m,long long int c);
long long int sol3(long long int n,long long int m,long long int c)
{
    long long int ans=0;
        for(int x = 1; x <= n; x++) {
            if(c % x  == 0) {
                int y = c / x;
                if(y <= m)
ans++;
            }
        }
return ans;
}





