//Problem Link: https://www.codechef.com/problems/BOLT
/*
Constraints:
0<k1,k2<2
0<k3<=1
9<v<11
*/
#include <stdio.h>
#include<math.h>

//Solution Link: https://www.codechef.com/viewsolution/45330827
int sol1(int a,int b,int c,int v)
{
        float a,b,c,v,x;
        x=100/(a*b*c*v);
        if ((round(x*100)/100) < 9.579)
            return 1;
        else
            return 0;
}

//Solution Link:https://www.codechef.com/viewsolution/45126275
int sol2(int x,int y,int z,int a)
{
	float res=100/(x*y*z*a);
	float res1=res+0.005;
	if(res1<9.58){
		return 1;
	}
	else{
		return 0;
	}
	

}

//Solution Link: https://www.codechef.com/viewsolution/45093176
int sol3(int k1,int k2, int k3, int v)
{
    float w,z,c;
    c=(k1*k2*k3*v);
    w=100/c;
	z = (int) 100*w + 0.5;
	z = (float) z/100;
    if(z<9.58)
    	return 1;
    else
    	return 0;
}

int main()
{
	int k1,k2,k3,v;
	if(k1<=0||k1>=2||k2<=0||k2>=2||k3<0||k3>1||v<=9||v>=11)
		return 0;

	__CPROVER_assert(sol1(k1,k2,k3,v)==sol2(k1,k2,k3,v),"sol1vsol2");
	__CPROVER_assert(sol1(k1,k2,k3,v)==sol3(k1,k2,k3,v),"sol1vsol3");
	__CPROVER_assert(sol2(k1,k2,k3,v)==sol3(k1,k2,k3,v),"sol2vsol3");
}

//Tested using cbmc, fails for --unwind 1 Satisfiable
//Bruteforce check not done