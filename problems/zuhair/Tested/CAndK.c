//https://www.codechef.com/problems/CHEFKEY
//Constraints
//1 ≤ T ≤ 100
//1 ≤ n, m ≤ 10^6
//1 ≤ c ≤ 10^6


//https://www.codechef.com/viewsolution/40304299
int sol1(int m, int n, int c);
int sol1(int m, int n, int c)
{
int i=0, j=0;
int count=0;
for(i=n;i>=1;i--)
                for(j=m;j>=1;j--)
                    if(i*j==c)
                        count++;
            return count;
}




// https://www.codechef.com/viewsolution/40304263
int sol2(int n, int m, int c);
int sol2(int n, int m, int c)
{
int count=0,i,j;
for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                    if(i*j==c)
                        count++;
}


//https://www.codechef.com/viewsolution/19415817
int sol3(int n, int m, int c);
int sol3(int n, int m, int c)
{
int ctr=0, i=0;
for(i=1;i<=c;i++)
		{
			if(i*(c/i)==c)
			if(i>0 && i<=n && c/i>0 && c/i<=m)
			ctr++;
		}
		return ctr;
}


//https://www.codechef.com/viewsolution/17126317
int sol4(int n, int m, int c);
int sol4(int n, int m, int c)
{
int i,j;
int count=0;
for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
				if(i*j == c)
					count++;
		                              return count;
}

int main()
{
       int m,n,c;
       if(n<1||m<1||c<1||n>1000000||m>1000000||c>1000000)
       {
            return 0;
       }
       __CPROVER_assert(sol1(m,n,c)==sol2(m,n,c),"sol1vsol2");
       __CPROVER_assert(sol1(m,n,c)==sol3(m,n,c),"sol1vsol3");
       __CPROVER_assert(sol1(m,n,c)==sol4(m,n,c),"sol1vsol4");
       __CPROVER_assert(sol2(m,n,c)==sol3(m,n,c),"sol2vsol3");
       __CPROVER_assert(sol2(m,n,c)==sol4(m,n,c),"sol2vsol4");
       __CPROVER_assert(sol3(m,n,c)==sol4(m,n,c),"sol3vsol4");
        
}

//Tested using CBMC and found that there were counterexamples for unwindings 2, 3 and so on 
//Here sol1!=sol2, sol2!=sol3, sol2!=sol4
//Brute Force Check not done


