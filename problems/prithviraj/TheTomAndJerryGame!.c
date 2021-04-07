//https://www.codechef.com/problems/EOEO

/*

1≤TS≤10^18
*/

//using cbmc


//https://www.codechef.com/viewsolution/44307705

long long int sol1(long long int n);
long long int sol1(long long int n)
{
    return n/((n&-n)<<1);
}


//https://www.codechef.com/viewsolution/42662902

void Divide( long long int *TS, long long int *JS)
{

    while(*TS%2==0 && *JS%2==0)
    {
        *TS/=2;
        *JS/=2;
    }
}

 long long int sol2( long long int T);
 long long int sol2( long long int T)
{
     long long int count=0;

        if(T%2!=0)
            count=T/2;
        else
        {
            while(T%2==0)
			{
				T/=2;
			}
			count=T/2;

        }
        return count;
}



//https://www.codechef.com/viewsolution/34440566

long long int sol3(long long int n);
long long int sol3(long long int n)
{
    long int i = 2;
	    while(n%i == 0){
	        i *= 2;
	    }
	    return n/i;
}


int main()
{
    //1≤TS≤10^18

    long long int TS;
    if(TS<1||TS>1000000000000000000)
        return 0;
    __CPROVER__assert(sol1(TS)==sol2(TS),"sol1vsol2");
    __CPROVER__assert(sol1(TS)==sol3(TS),"sol1vsol3");
    __CPROVER__assert(sol2(TS)==sol3(TS),"sol2vsol3");


}




