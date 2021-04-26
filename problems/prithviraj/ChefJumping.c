//https://www.codechef.com/problems/OJUMPS

/*
0 ≤ a ≤ 10^18
*/

//Using CBMC

//https://www.codechef.com/viewsolution/45098086
char *sol1(long long int a);
char *sol1(long long int a)
{
    if(a%6==0||a%6==1||a%6==3)
	{
	    return "yes";
	}else
	{
	    return "no";
	}
}


//https://www.codechef.com/viewsolution/45031519
char *sol2(long long int a);
char *sol2(long long int a)
{
    int p;
	p=a%6;
	int flag=0;
	if(p==0)
	flag=1;
	else
	{
	    if(p==1||p==3)
	    flag=1;
	}
	if(flag==1)
	return "yes";
	else
	return "no";
}

//https://www.codechef.com/viewsolution/30337976
char *sol3(long long int a);
char *sol3(long long int a)
{
    long long int b, c;
	if (a >= 6) {
          b = a/6;
          a = a - b*6;
	}

	if (a == 0 || a == 1 || a == 3) {
          return "yes";
	}
	else {
          return "no";
	}
}

int main()
{
	long long int a;
	if(a<0||a>1000000000000000000)
        return 0;
        __CPROVER_assert(sol1(a)==sol2(a),"sol1vsol2");
        __CPROVER_assert(sol1(a)==sol3(a),"sol1vsol3");
        __CPROVER_assert(sol2(a)==sol3(a),"sol2vsol3");
        return 0;
}
