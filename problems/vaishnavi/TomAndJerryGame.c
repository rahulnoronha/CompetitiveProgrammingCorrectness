#include<stdio.h>

/*
The Tom and Jerry Game: https://www.codechef.com/problems/EOEO
1 <= TS <= 10^18
TS is also used as T, ts in sol 1 and sol2,3 respectively.
*/


//https://www.codechef.com/viewsolution/42662902
//I DO NOT KNOW WHY THEY USED OR WROTE THIS FUNCTION????v
void Divide(unsigned long long int *TS,unsigned long long int *JS)
{
    while(*TS%2==0 && *JS%2==0)
    {
        *TS/=2;
        *JS/=2;
    }    
}
long long int sol1(long long int T)
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


//https://www.codechef.com/viewsolution/38763375
long long int sol2(long long int ts)
{
	int c=0;
    if(ts%2!=0)
    {
        return ((ts-1)/2);
    }
    else
    {
        long long int n;
        n=ts;
        while(!(n & 1))
        {
            c++;
            n >>= 1;
        }
	    // printf("%d",c);
	    long long int y;
        y=pow(2,c);
		long long int l;
        l=y*2;
        long long int u=ts/l;
         return u;
    }
}


//https://www.codechef.com/viewsolution/35605165
long long int sol3(long long int ts)
{
	long long int j,count=0,tsc=0,power=0,js,tom=0, jerry=0;
	tsc=ts;
    while(ts%2==0)
    {
        power+=1;
        ts=ts/2;
    }
    tom++;
    jerry--;
    js=pow(2,(power+1));
    if (js<=tsc)
    	count=tsc/js;
    tom++;
    jerry--;         
    return count;
}


//https://www.codechef.com/viewsolution/35527372
long long int sol4(long long int TS;)
{
	while (TS % 2 == 0)
		TS = TS / 2;
	//printf("TS is %lld\n", TS);
	if (TS == 1)
		return 0;
	else
		return ((TS - 1) / 2);
}




