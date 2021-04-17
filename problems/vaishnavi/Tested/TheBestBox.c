#include<stdio.h>
#include<math.h>
/*
The Best Box: https://www.codechef.com/problems/J7
*/

//https://www.codechef.com/viewsolution/44396946
float sol1(int a, int b)
{
	int c;
    float f1,f2,f;
    c=a*a-4*6*b;
    f1=(a-sqrt(c))/12;
    f2=(a-8*f1)/4;
    f=f1*f1*f2;
    return f;
}

//https://www.codechef.com/viewsolution/37767103
float sol2(int p ,int s)
{
	double x,y;//s = surface, p = perimeter
	//scanf("%d",&n);
	x = (p - sqrt(p*p - 24*s))/12;
	return  x*x*((p-8*x)/4);
}

//https://www.codechef.com/viewsolution/18838761
float sol3(int p, int s)
{
	float l, v;
	l=(p/2 - sqrt(p*p/4 - 6*s))/6;
	v=l*l*l-l*l*p/4+l*s/2;
	return v;		
}

//
float sol4(int p, int s)
{
	double l,b,x,h;
    double a;
     b = (p/2.0-sqrt((p*p/4.0)-6*s))/6.0;
        x = (p/4.0-b)*(p/4.0-b)- 4*(b*b+s/2.0-p*b/4.0);
        h = (p/4.0-b+sqrt(x))/2;
        l = (p/4.0-b-sqrt(x))/2;
        a = l*b*h;
    return a;
}


int main()
{
	int n,a;
	if(n<1 || n>40000 || a<1 || a>20000)
	{
    	return 0;
    }
    __CPROVER_assert(sol1(n,a)==sol2(n,a),"sol1Vsol2");
    __CPROVER_assert(sol1(n,a)==sol3(n,a),"sol1Vsol3");
    __CPROVER_assert(sol1(n,a)==sol4(n,a),"sol1Vsol4");
    __CPROVER_assert(sol2(n,a)==sol3(n,a),"sol2Vsol3");
    __CPROVER_assert(sol2(n,a)==sol4(n,a),"sol2Vsol4");
    __CPROVER_assert(sol3(n,a)==sol4(n,a),"sol3Vsol4");
}

//Tested using cbmc and counterexample found for --uniwnd 1 for all the 6 assertions
//Bruteforce not attempted