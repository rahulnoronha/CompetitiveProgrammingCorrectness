//https://www.codechef.com/problems/CHSQR
/* Constraints
Ki is odd.
Subtask #1 (10 points) :
1 ≤ T ≤ 50
1 ≤ Ki≤ 5
Subtask #1 (90 points) :
1 ≤ T ≤ 10
1 ≤ Ki < 400 */

//https://www.codechef.com/viewsolution/35420142

int sol1(int k);
int sol1(int k)
{
for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=k;j++)
		    {
		        int num = (i+j+k/2)%k;
		        if (num==0)
		            num = k;
		        return num;
		    }
      }
}


//https:www.codechef.com/viewsolution/24891053

int sol2(int k);
int sol2(int k)
{
    int i,j,c;
    c=(k+1)/2;
        for(i=k;i>0;i--)
        {
            for(j=0;j<k;j++)
            {
                return (c+j+i)%k+1;
            }
       }
}




//https:www.codechef.com/viewsolution/17895958

int sol3(int n);
int sol3(int n)
{
      int x;
      int i,j;
      for(i=0;i<n;i++)
      {
        	for(j=0;j<n;j++)
        		{
                  	  x=((n+1)/2+i+j)%n+1;
        	          return x;
        		}

      }

}




int main()
{
    /*Ki is odd.
Subtask #1 (10 points) :

1 ≤ Ki≤ 5
Subtask #1 (90 points) :

1 ≤ Ki < 400 */

int x;
if(x<1||x>=400||x%2==1)
    return 0;

    __CPROVER_assert(sol1(x)==sol2(x),"sol1vsol2");
    __CPROVER_assert(sol1(x)==sol3(x),"sol1vsol3");
    __CPROVER_assert(sol2(x)==sol3(x),"sol2vsol3");


}

//Tested using cbmc and found counterexample for sol1vsol2 and sol1vsol3 for --unwind 1
//Bruteforce not attempted

