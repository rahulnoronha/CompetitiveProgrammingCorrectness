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


int sol3(int n,int m,int c);
int sol3(int n,int m,int c)
{
    int ans=0;
        for(int x = 1; x <= n; x++) {
            if(c % x  == 0) {
                int y = c / x;
                if(y <= m)
ans++;
            }
        }
return ans;
}

int main()
{
    int n,m,c;
    if((n<1||n>1000000)||(m<1||m>1000000)||(c<1||c>1000000))
        return 0;


    _CPROVER_assert(sol1(n,m,c)==sol2(n,m,c),"sol1vsol2");
    _CPROVER_assert(sol1(n,m,c)==sol3(n,m,c),"sol1vsol3");
    _CPROVER_assert(sol2(n,m,c)==sol3(n,m,c),"sol2vsol3");


}



