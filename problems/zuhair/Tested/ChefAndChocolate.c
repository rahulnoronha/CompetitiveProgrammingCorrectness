//https://www.codechef.com/problems/CHCHCL
/*
Constraints
1 ≤ T ≤ 100
1 ≤ n, m ≤ 10^9*/

//https://www.codechef.com/viewsolution/41354857
int sol1(int n,int m);
int sol1(int n,int m)
{
	    long long int p;
	    p=n*m;
	    if(p%2==0)
	    //printf("Yes\n");
            return 1;
	    else
	    //printf("No\n");
	    return 0;
	
	
}

//https://www.codechef.com/viewsolution/42934316
long long int sol2(long long int n,long long int m);
long long int sol2(long long int n,long long int m)
{
	int i;
	//for(i=0;i<t;i++)
	//{
	    long long int p;
	    p=n*m-1;
	    if(p%2==0)
            return 0;
	    //printf("No\n");
	    else
	    return 1;
	    //printf("Yes\n");
	//}
	
}


//https://www.codechef.com/viewsolution/44360290
int sol3(int n,int m);
int sol3(int n,int m)
{ 
   if(m*n%2==0)
   //printf("Yes\n");
   return 1;
   else
   return 0; 
   //printf("No\n");
}
	
int main()
{
    int n,m;
    if(n<1||n>1||m>10)
        return 0;


    __CPROVER_assert(sol1(n,m)==sol2(n,m),"sol1vsol2");
    __CPROVER_assert(sol1(n,m)==sol3(n,m),"sol1vsol3");
    __CPROVER_assert(sol2(n,m)==sol3(n,m),"sol2vsol3");


}

//Tested using cbmc it is unsatisfiable in this case
//Bruteforce approach not done

