//https://www.codechef.com/problems/CHECHOC
/*Constraints
1≤T≤100
1≤N,M≤100
1≤X,Y≤10^4*/


//https://www.codechef.com/viewsolution/43041973
int sol1(int n,int m,int x,int y);
int sol1(int n,int m,int x,int y)
 {
	   int i;
	   long int res = 0;
	   if(n*m == 1)
	    res = x;
	    else
	    {
	        if(x <= y)
	        {
	            if(2*x <= y)
	            res = m*n*x;
	            else if(m*n % 2 == 0)
	            res = m*n*y/2;
	            else
	            res = (m*n/2 +1)*x + (m*n/2)*(y-x);
	        }
	        else
	        {
	            if(m*n % 2 == 0)
	            res = m*n*y/2;
	            else
	            res = (m*n/2 +1)*y;
	        }
	    }
	    
	    return res;
	}

//https://www.codechef.com/viewsolution/37116378
int sol2(int N,int M,int X,int Y);
int sol2(int N,int M,int X,int Y)
{
	    if(N==1 && M==1) 
            return X;
	    else
	    {
    	    if(Y > 2*X) Y=2*X;
    	    else if(X>Y) X=Y;
    	    if(N%2==0)
    	    {
    	        return (N/2)*M*Y;
    	    }
    	    else if(M%2==0)
    	    {
    	        return (M/2)*N*Y;
    	    }
    	    else
    	    {
    	        return ((M/2)*N*Y)+((N/2)*Y)+X;
    	    }
	    }
	    //printf(result);
}

//https://www.codechef.com/viewsolution/36100772
long long int sol3(long long int n,long long int m,long long int x,long long int y);
long long int sol3(long long int n,long long int m,long long int x,long long int y)
{
		long long int temp=0,temp1=0;
		if(n==1&&m==1)
		{
			return x;
		}
		else if(y>=x*2)
		{
			return n*m*x;
		}
		else if(n%2==0)
		{
			return n*m*y/2;
		}
		else if(m%2==0)
		{
			return n*m*y/2;
		}
		else
		{
		    if(x<y)
		    temp1=x;
		    else
		    temp1=y;
				temp=n-1;
				temp=temp*y/2;
				temp=temp*m;
				temp=temp+((m/2)*y)+temp1;
				return temp;
		}
		
	}


int main()
{
int m,n,x,y;
if(n<1||m>100||x<1||y>10000)
    return 0;
__CPROVER_assert(sol1(m,n,x,y)==sol2(m,n,x,y),"sol1vsol2");
__CPROVER_assert(sol1(m,n,x,y)==sol3(m,n,x,y),"sol1vsol3");
__CPROVER_assert(sol2(m,n,x,y)==sol3(m,n,x,y),"sol2vsol3");

}

