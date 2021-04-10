//https://www.codechef.com/problems/CHFTIRED

/*
1≤a,b≤10^9
*/

//Using CBMC

//https://www.codechef.com/viewsolution/44616606

char *sol1(int a,int b);
char *sol1(int a,int b)
{
    return "YES";
}


//https://www.codechef.com/viewsolution/43787773

char *sol2(int a,int b);
char *sol2(int a,int b)
{

    int y=0;
    if(a<b)
	    {
	        while(a!=b)
	        {
	            a=a+1;
	        }y=1;
	    }
	    else
	    {
	        while(a!=b)
	        {
	            b=b+1;
	        }y=1;

	    }

	    if(y==1)
	    return "YES";
	    else
	    return "NO";


}


//https://www.codechef.com/viewsolution/31905395
char *sol3(int a,int b);
char *sol3(int a,int b)
{
    if(a>0&&b>0)
        {
            return "YES";
        }
        else
        {
            return "NO";
        }
}


int main(){

    int a,b;
    if(a<1||a>1000000000||b<1||b>1000000000)
        return 0;

    __CPROVER_assert(sol1(a,b)==sol2(a,b),"sol1vsol2");
    __CPROVER_assert(sol1(a,b)==sol3(a,b),"sol1vsol3");
    __CPROVER_assert(sol2(a,b)==sol3(a,b),"sol2vsol3");

}

//Tested with CBMC and found no counterexample. Unsatisfiable
//Did not create a brute force checker






