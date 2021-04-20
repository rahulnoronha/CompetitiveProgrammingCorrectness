//https://www.codechef.com/problems/INLO21

/*Constraints
1 ≤ T ≤ <1000
1 ≤ m ≤ <100000
1 ≤ n ≤ <100000*/


//https://www.codechef.com/viewsolution/18021298
int sol1(int a,int b);
int sol1(int a,int b)
{
      
 return a*(a+1)*b*(b+1)/4;  
}
    
 
//https://www.codechef.com/viewsolution/26987657
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define mod 1000000007 
long long int sol2(long long int a,long long int b)
{
        long long ans=0;
        ans=(((a*(a+1))/2)*((b*(b+1))/2));
        ans=ans%mod;
        return ans;
}



//https://www.codechef.com/viewsolution/17827938
#define m 1000000007
long long int sol3(long long int a,long long int b)
{
long long int ans=((((a*(a+1))/2)%m)*(((b*(b+1))/2)%m))%m;
return ans;
}



	int main()
	{
		int a,b;
		if(a<1||a>100000||b<1||b>100000)
    		return 0;
		__CPROVER_assert(sol1(a,b)==sol2(a,b),"sol1vsol2");
		__CPROVER_assert(sol1(a,b)==sol3(a,b),"sol1vsol3");
		__CPROVER_assert(sol2(a,b)==sol3(a,b),"sol2vsol3");
	}

