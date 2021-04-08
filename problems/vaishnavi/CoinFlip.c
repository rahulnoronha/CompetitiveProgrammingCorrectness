/*
Coin Flip: https://www.codechef.com/problems/CONFLIP
Constraints:
>	1 <= N <= 10
>	1 <= I <= 2
>	1 <= Q <= 2
*/

//https://www.codechef.com/viewsolution/39114252
int sol1(int i, int n, int q)
{
	if(n%2==0||i==q)
        return n/2;
    else
		return (n/2)+1;
}


//https://www.codechef.com/viewsolution/31889163
int sol2(int i, int n, int q)
{
	int l;
    l=n/2+n%2;
    if(i==q)
    	return n-l;
    else
    	return l;	
}


//https://www.codechef.com/viewsolution/44755460
int sol3(int i, int n, int q)
{
	int he,ta;
	if(i==1)
	{
	    he=n/2;
	    ta=n-he;
	}
	else
	{
		ta=n/2;
	    he=n-ta;
	}
	if(q==1)
	{
	    return he;
	}
    else
	{
		return ta;
	}
}


//https://www.codechef.com/viewsolution/44753900
int sol4(int i, int n, int q)
{
	if (n%2==0) return n/2;
    else if (n%2==1 && i==q) return n/2;
    else if (n%2==1 && i!=q) return n/2+1;
}



int main()
{
	int i, n, q;
	if(n<1 || n>10 || i<1 || i>2 || q<1 || q>2)
		return 0;
	__CPROVER_assert(sol1(i,n,q)==sol2(i,n,q),"sol1Vsol2");
  __CPROVER_assert(sol1(i,n,q)==sol3(i,n,q),"sol1Vsol3");
  __CPROVER_assert(sol1(i,n,q)==sol4(i,n,q),"sol1Vsol4");
  __CPROVER_assert(sol2(i,n,q)==sol3(i,n,q),"sol2Vsol3");
  __CPROVER_assert(sol2(i,n,q)==sol4(i,n,q),"sol2Vsol4");
  __CPROVER_assert(sol3(i,n,q)==sol4(i,n,q),"sol3Vsol4");
	return 0;
}
