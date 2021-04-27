#include <stdio.h>
#include<math.h>
#define ll long long int

/*
Please Like Me: https://www.codechef.com/problems/PLZLYKME

Constraints:
> 1 <= L, D, S, C <= 1000000000

*/

//https://www.codechef.com/viewsolution/17743720
char* sol1(ll L, ll D, ll S, ll C)
{
	ll nLikes,flag,i;
	 flag = 0;
        nLikes = S;
        for(i=0;i<=D-1;i++)
        {
            if(nLikes>=L)
            {
                flag=1;
                break;
            }
            
            nLikes = nLikes + nLikes*C;
        }
	if(flag==0)
	    return "DEAD AND ROTTING\n";
	else
	    return "ALIVE AND KICKING\n";
}


	    
//https://www.codechef.com/viewsolution/37987458
char* sol2(ll l, ll d, ll s, ll c)
{
	if(s*pow(c+1,d-1)<l)
	    return "DEAD AND ROTTING\n";
	else
	    return "ALIVE AND KICKING\n";
}


//https://www.codechef.com/viewsolution/19629541
char* sol3(ll l, ll d, ll s, ll c)
{
	long long int i;
	long long int p[d];
   int flag=0;
   p[0]=s;
   if(p[0]>=l)
    flag=1;
   else{
   for(i=1;i<d;i++)
  {
    p[i]=p[i-1]+c*p[i-1];
    if(p[i]>=l){
     flag=1;
     break;}
   }}
   if(flag==1)
    return "ALIVE AND KICKING\n";
   else
    return "DEAD AND ROTTING\n";
}


int main()
{
	ll l,d,s,c;
	if(l<1 || l>1000000000 || d<1 || d>1000000000 || s<1 || s> 1000000000 || c<1 || c>1000000000 )
		return 0;
	__CPROVER_assert(sol1(l,d,s,c)==sol2(l,d,s,c),"sol1Vsol2");
  __CPROVER_assert(sol1(l,d,s,c)==sol3(l,d,s,c),"sol1Vsol3");
  __CPROVER_assert(sol2(l,d,s,c)==sol3(l,d,s,c),"sol2Vsol3");
}
