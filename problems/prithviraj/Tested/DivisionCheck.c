//https://www.codechef.com/problems/DIVCHK

/*
0 <= A <= 10^5
0 <= B <= 10^5
*/

//Using CBMC

//https://www.codechef.com/viewsolution/37368401

char *sol1(long int m,long int n);
char *sol1(long int m,long int n)
{
    int arr[10000],i=0;
    if(n==0)
    arr[i]=0;
    else if(m%n==0)
    arr[i]=1;
    else if(m%n!=0)
    arr[i]=0;


    if(arr[i]==0)
    {
      return "crash";
    }
    else
    {
      return "safe";
    }

}

//https://www.codechef.com/viewsolution/37328969

char *sol2(long int a,long int b);
char *sol2(long int a,long int b)
{
    if(b==0)
	      return "crash";


	   else if(a%b==0)
	      return "safe";

	    else
	      return "crash";
}

//https://www.codechef.com/viewsolution/24211577

char *sol3(long int A,long int B);
char *sol3(long int A,long int B)
{
    if((A>=0 && A<=100000)&& (B>=0 && B<=100000))
        {
        long int d=(A/B);
        if(d==(A/B))
        return "safe";
    	else
    	return "crash";
        }
}





int main() {
    /*
0 <= A <= 10^5
0 <= B <= 10^5
*/
long int a,b;

if(a<0||b<0||a>100000||b>100000)
    return 0;

    __CPROVER_assert(sol1(a,b)==sol2(a,b),"sol1vsol2");
    __CPROVER_assert(sol1(a,b)==sol3(a,b),"sol1vsol3");
    __CPROVER_assert(sol2(a,b)==sol3(a,b),"sol2vsol3");


  return 0;

}

//Tested using cbmc and found no counterexample. Unsatisfiable by time exceeded
//Bruteforce not done
