//https://www.codechef.com/problems/COOKMACH
/*
1 ≤ T ≤ 200
1 ≤ A ≤ 10^7
1 ≤ B ≤ 10^7, and B is an integer power of 2
*/
// TRY BRUTE FORCE

//https://www.codechef.com/viewsolution/42862022

int sol1(int a,int b);
int sol1(int a,int b)
{
    int temp=0;
    while(b%a!=0){
	        a=a/2;
	        temp++;
	    }
	    while(a!=b){
	        a=a*2;
	        temp++;
	    }
return temp;
}

//https://www.codechef.com/viewsolution/38158434

int sol2(int a,int b);
int sol2(int a,int b)
{
    int c=0;
    while ((a & -a) != a) a >>=1, ++c;
        while (a < b) a <<= 1, ++c;
        while (a > b) a>>= 1, ++c;
return c;
}

//https://www.codechef.com/viewsolution/36821000

int sol3(int a,int b);
int sol3(int a,int b)
{
    int c=0;
    while(b%a!=0)
    {
        a=a/2;c++;
    }
     while(a!=b)
    {
        a=a*2;c++;
    }
return c;
}

//https://www.codechef.com/viewsolution/9002347

int loga(int a)
{
	int going=1;
	while(2>1)
	{
		if(a<going)
			return -1;

		else if(a==going)
			return 0;

		going=going<<1;
	}
}

int sol4(int a,int b);
int sol4(int a,int b)
{
    int count=0;
    if(a<=b)
		{
			yes:while(2>1)
			{
				if(loga(a)==0)
				{
					while(a!=b)
					{
						count++;
						a*=2;
					}
					break;
				}
				else
				{
					if(a%2==0)
						a/=2;
					else
						a=(a-1)/2;
					count++;
				}
			}
		}
		else
		{
			while(a>=b)
			{
				if(a==b)
					break;
				count++;
				if(a%2==0)
					a/=2;
				else
					a=(a-1)/2;
			}
			if(a<b)
			{
				goto yes;
			}
		}
return count;


}

//https://www.codechef.com/viewsolution/8997758

int sol5(int in,int out);
int sol5(int in,int out)
{
    int flag=0;
    while(in!=out)
       {

        if(in>out)
           {
            in/=2;
            flag++;
           }
          else
           {
               out/=2;
               flag++;
           }
       }
return flag;
}


int main()
{
    int a,b;
    if((a<1||a>10000000)||(b<1||b>10000000))

    //code block to check if b is a 2's power integer
         while (b != 1)
  {
      if (b%2 != 0)
         return 0;
      b = b/2;
  }


  __CPROVER_assert(sol1(a,b)==sol2(a,b),"sol1vsol2");
  __CPROVER_assert(sol1(a,b)==sol3(a,b),"sol1vsol3");
  __CPROVER_assert(sol1(a,b)==sol4(a,b),"sol1vsol4");
  __CPROVER_assert(sol1(a,b)==sol5(a,b),"sol1vsol5");
  __CPROVER_assert(sol2(a,b)==sol3(a,b),"sol2vsol3");
  __CPROVER_assert(sol2(a,b)==sol4(a,b),"sol2vsol4");
  __CPROVER_assert(sol2(a,b)==sol5(a,b),"sol2vsol5");
  __CPROVER_assert(sol3(a,b)==sol4(a,b),"sol3vsol4");
  __CPROVER_assert(sol3(a,b)==sol5(a,b),"sol3vsol5");
  __CPROVER_assert(sol4(a,b)==sol5(a,b),"sol4vsol5");
}

//Tested using CBMC and found counterexample for unwind 3 sol2 is different from the rest and doesn't work
//Brute Force check not done
