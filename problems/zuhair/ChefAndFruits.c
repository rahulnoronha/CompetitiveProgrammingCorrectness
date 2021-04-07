//https://www.codechef.com/problems/FRUITS
/*Constraints
1 ≤ T ≤ 100
1 ≤ N, M, K ≤ 100*/

//https://www.codechef.com/viewsolution/44688545
//#include<math.h>
//#include<stdlib.h>
int sol1(int n,int m,int k);
int sol1(int n,int m,int k)
{
	    int i;
	    for(i=1;i<=k;i++)
	    {
	        if(n==m)
	        break;
	        else if(n>m)
	        {
	            n=n-1;
	        }
	        else if(m>n)
	        {
	            m=m-1;
	        }
	    }
	    return abs(m-n);
}


//https://www.codechef.com/viewsolution/44140068
//#include <stdio.h>
//#include <math.h>
int sol2(int n,int k,int c);
int sol2(int n,int k,int c)
{
    int diff;
    diff=abs(n-k);
    if(diff<=c) 
        {
            return 0;
        }
        else 
        {
            return diff-c;
        }
    
}


//https://www.codechef.com/viewsolution/44684656
int sol3(int n,int m,int k);
int sol3(int n,int m,int k)
{

	    if(n>m){
	        if(k>=(n-m)){
	            return 0;
	        }
	        else{
	            return n-m-k;
	        }
	    }
	    if(n<m){
	        if(k>=(m-n)){
	            return 0;
	        }
	        else{
	            return m-n-k;
	        }
	    }
	    if(n==m) return 0;
}
	
int main()
{
int n,m,k;
if(n<1||m>1||k>100)
    return 0;
__CPROVER_assert(sol1(n,m,k)==sol2(n,m,k),"sol1vsol2");
__CPROVER_assert(sol1(n,m,k)==sol3(n,m,k),"sol1vsol3");
__CPROVER_assert(sol2(n,m,k)==sol3(n,m,k),"sol2vsol3");

}

 
