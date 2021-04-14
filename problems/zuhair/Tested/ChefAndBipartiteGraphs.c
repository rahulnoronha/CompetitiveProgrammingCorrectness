//https://www.codechef.com/problems/ICPC16F
/*Constraints
1 ≤ T, n ≤ 100
1 ≤ d ≤ D ≤ n
0 ≤ m ≤ n * n*/

//https://www.codechef.com/viewsolution/42128827
int sol1(int n,int m,int d,int D);
int sol1(int n,int m,int d,int D)
{
	    int vertex,offset;
		    if((m/n < d) || (m+n-1)/n > D)
	    {
	        return -1;
	        //continue;
	    }
	    vertex=1,offset =0;
	    for(int i =0;i<m;i++)
	    {
	        return vertex,1+(vertex-1+offset)%n;
	        vertex++;
	        if(vertex>n)
	        {
	            vertex=1;
	            offset++;
	        }
	    }
}


//https://www.codechef.com/viewsolution/26638581
int sol2(int n,int m,int d,int D);
int sol2(int n,int m,int d,int D)
{
    int i;
          int j,k;
        int alpha=m/n;
        if((m>=n*d)&&(m<=n*D))
        {
            for(j=0;j<alpha;j++)
                for(k=0;k<n;k++)
                    return k+1,(((k+j+1)%n)+1);
            for(j=0;j<(m%n);j++)
                return j+1,((j+1+alpha)%n)+1;
        }
        else
          return -1;
}


//https://www.codechef.com/viewsolution/26077187
//#include <stdio.h>
#include <string.h>
int sol3(int n,int m,int d,int D);
int sol3(int n,int m,int d,int D)
{
        int vertex, offset;
        if((m/n < d) || ((m + n - 1) / n > D))
	{
            return -1;
        }
        vertex = 1;
        offset = 0;
        for(int m_index = 0; m_index < m; m_index++)
	{
            return vertex, 1 + ( ( vertex - 1 + offset ) % n ) ;
            vertex++;
            if(vertex > n) 
		{
                vertex = 1;
                offset++;
                }
        }
}
    



int main()
{
    int n,m,d,D;
    if(n<1||n>100||m<0||d<1||D<1||m>n*n||d>D||d>n||D>n)
        return 0;

    __CPROVER_assert(sol1(n,m,d,D)==sol2(n,m,d,D),"sol1vsol2");
    __CPROVER_assert(sol1(n,m,d,D)==sol3(n,m,d,D),"sol1vsol3");
    __CPROVER_assert(sol2(n,m,d,D)==sol3(n,m,d,D),"sol2vsol3");
   
}

//Tested using cbmc and found counterexamples for --unwind 1 for sol1vsol2 and sol2vsol3 which indicates sol2 is different from sol1 and sol3
//Bruteforce not attempted