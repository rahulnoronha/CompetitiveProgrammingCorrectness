//https://www.codechef.com/problems/CHEFKEY
//Constraints
//1 ≤ T ≤ 100
//1 ≤ n, m ≤ 106
//1 ≤ c ≤ 106


//https://www.codechef.com/viewsolution/40304299
int sol1(int i, int j);
int sol1(int i, int j)
{
int count=0,n,m;
for(i=n;i>=1;i--)
                for(j=m;j>=1;j--)
                    if(i*j==c)
                        count++;
            return count;
}




// https://www.codechef.com/viewsolution/40304263
int sol2_buggy(int n, int m);
int sol2_buggy(int n, int m)
{
int count=0,i,j;
for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                    if(i*j==c)
                        count++;
}


//https://www.codechef.com/viewsolution/19415817
int sol3(int i, int c);
int sol3(int i, int c)
{
int ctr=0;
for(i=1;i<=c;i++)
		{
			if(i*(c/i)==c)
			if(i>0 && i<=n && c/i>0 && c/i<=m)
			ctr++;
		}
		return ctr;
}


//https://www.codechef.com/viewsolution/17126317
int sol4(int n, int m);
int sol4(int n, int m)
{
int i,j;
count=0;
for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
				if(i*j == c)
					count++;
		                              return count;
}
