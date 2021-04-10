//https://www.codechef.com/problems/DSTAPLS/
/* Constraints
1≤T≤250
1≤N,K≤1018
N is divisible by K*/
// N=apples , k=boxes.

//https://www.codechef.com/viewsolution/41919216

long long int sol1(long long int apples,long long int boxes);
long long int sol1(long long int apples,long long int boxes)
{
	    if(apples%(boxes*boxes)==0)
	    {
	        //in such case he will put k apples in one box upto k boxes therefore k sqaure apples,and such equal distribution matches first person
	        //same
	        return "NO";
	    }
	    else
	    return "YES";
}


//https://www.codechef.com/viewsolution/35836133
long int sol2(long int apples,long int boxes);
long int sol2(long int apples,long int boxes)
{
	    long int c;
	    c=apples/boxes;
	    if(c%boxes==0){
	        return "NO";
	    }
	    else{
	        return "YES";
	    }
	}


//https://www.codechef.com/viewsolution/31998111
int sol3(int apples,int boxes);
int sol3(int apples,int boxes)
{
		int d;
                d=0;
		while(apples>=boxes)
		{
			apples=apples-boxes;
			d++;
		}
		if(d%boxes==0)
		return "NO";
		else
		return "YES";
	
}

int main()
{
long long int apples,boxes;
if(apples<1||boxes>1000000000)
    return 0;
__CPROVER_assert(sol1(apples,boxes)==sol2(apples,boxes),"sol1vsol2");
__CPROVER_assert(sol1(apples,boxes)==sol3(apples,boxes),"sol1vsol3");
__CPROVER_assert(sol2(apples,boxes)==sol3(apples,boxes),"sol2vsol3");


}
