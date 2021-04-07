//https://www.codechef.com/problems/PCJ18B
//Constraints
//1≤T≤100
//1≤N≤1000

//https://www.codechef.com/viewsolution/44381342
int sol1(int n);
int sol1(int n)
{

	    int sum = 0;
	    for(int i = 1 ; i <= n ; i = i + 2)
	    {
	        sum = sum + (n - i + 1)*(n - i + 1);
	    }
	    return sum;


}

//https://www.codechef.com/viewsolution/44616196
int sol2(int num);
int sol2(int num)
{
	    int c=0,i;
	    for(i=num;i>=1;i-=2)
            {
	        c+=(i*i);
	    }
	    return c;
}


//https://www.codechef.com/viewsolution/44092014
int sol3(int n);
int sol3(int n)
{
        int a[n];
        a[1]=1;
        a[2]=4;
        for(int i=3;i<=n;i++)
        {
            a[i]=i*i+a[i-2];

        }
        return a[n];

    }


int main()
{
    int n;
    if(n<1||n>1000)
        return 0;


    __CPROVER_assert(sol1(n)==sol2(n),"sol1vsol2");
    __CPROVER_assert(sol1(n)==sol3(n),"sol1vsol3");
    __CPROVER_assert(sol2(n)==sol3(n),"sol2vsol3");


}


//Tested using cbmc and found no counterexamples. Unsatisfiable
//Bruteforce not attempted

