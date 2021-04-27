#include<stdio.h>
#include<math.h>
float expect(int);
float e[3002];

/*
Player: https://www.codechef.com/problems/RRPLAYER
*/

//https://www.codechef.com/viewsolution/41288200
float sol1(int n)
{
	int i;
    float ans,n_tmp;
    ans=0;
    n_tmp=n;
    for(i=1;i<=n;i++){
        ans=ans+n_tmp/i;
    }
    return ans;
}




//https://www.codechef.com/viewsolution/33205125
float sol2(int n)
{
	float ans=0,aux=n;
    for(int j=1;j<=n;j++){
    	ans+=aux/j;
    }
    return ans;
}





//https://www.codechef.com/viewsolution/5642853
float expect(int n)
{
	if(e[n]!=0.0)
		return e[n];
	else
		e[n]=(expect(n-1)/(n-1.0))*(n)+1.0;
	return e[n];
}

float sol3(int n)
{
	e[1]=1.0;
	int i;
	for(i=2;i<=3000;i++)
	e[i]=0.0;
	return expect(n);
}



//https://www.codechef.com/viewsolution/27557114
float sol4(int N)
{
	int i;
	float sum;
	sum=0;
    for(i = 0; i < N; i++)
    {
        sum+=(float)N/(i+1);
    }
	return sum;
}



int main()
{
	int n;
	if((n<2||n>3000))
    {
    	return 0;
    }
	__CPROVER_assert(sol1(n)==sol2(n),"sol1Vsol2");
  __CPROVER_assert(sol1(n)==sol3(n),"sol1Vsol3");
  __CPROVER_assert(sol1(n)==sol4(n),"sol1Vsol4");
  __CPROVER_assert(sol2(n)==sol3(n),"sol2Vsol3");
  __CPROVER_assert(sol2(n)==sol4(n),"sol2Vsol4");
  __CPROVER_assert(sol3(n)==sol4(n),"sol3Vsol4");
}

//Tested using cbmc but time exceeded so we assume that it is unsatisfiable in this case
//Bruteforce approach not done
