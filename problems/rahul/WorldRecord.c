//Problem Link: https://www.codechef.com/problems/BOLT
/*
Constraints:
0<k1,k2<2
0<k3<=1
9<v<11
*/
#include <stdio.h>
#include<math.h>


int sol1(int a,int b,int c,int v)
{
        float a,b,c,v,x;
        x=100/(a*b*c*v);
        if ((round(x*100)/100) < 9.579)
            return 1;
        else
            return 0;
}

int main()
{
	int k1,k2,k3,v;
	if(k1<=0||k1>=2||k2<=0||k2>=2||k3<0||k3>1||v<=9||v>=11)
		return 0;