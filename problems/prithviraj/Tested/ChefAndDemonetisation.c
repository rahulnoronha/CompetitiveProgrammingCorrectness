//https://www.codechef.com/problems/CHFMOT18
/*
1≤S≤10^9
2≤N≤10^9
N is even
*/

//Using CBMC

//https://www.codechef.com/viewsolution/44654463

int sol1(int s,int n);
int sol1(int s,int n)
{
    int i,a,quo,rem;
    if(s==1)
        {
            a=1;
        }
        if(s!=1 && s<=n)
        {
            if(s%2==0)
            a=1;
            if(s%2==1)
            a=2;
        }
        if(s>n)
        {
            a=0;
            quo=s/n;
            rem=s%n;
            if(rem==0)
            {
                a=a+quo;
            }
            else if(rem==1)
            {
                a=a+quo+1;
            }
            else
            {
                a=a+quo;
                if(rem%2==0)
                {
                    a=a+1;
                }
                if(rem%2==1)
                {
                    a=a+2;
                }
            }
        }

        return a;

}


//https://www.codechef.com/viewsolution/39278768

int sol2(int s,int n);
int sol2(int s,int n)
{
    int count;

    count = (s/n);
        s=s%n;
        if(s!=0)
        {
            if((s&1)==0 || s==1)
                count++;
            else
                count+=2;
        }
        return count;
    }


//https://www.codechef.com/viewsolution/37864434

int sol3(int s,int n);
int sol3(int s,int n)
{
    int coin=0;
if(s<=n)
{
if(s==1)
return 1;
else if(s%2==0)
return 1;
else
return 2;
}
else
{
coin=s/n;
s=s%n;
if(s==0)
return coin;
else if(s==1||s%2==0)
return coin+1;
else
return coin+2;
}
}




int main()
{
    int n,s;
    if(s<1||s>1000000000||n<2||n>1000000000||n%2!=0)
        return 0;

    __CPROVER_assert(sol1(n,s)==sol2(n,s),"sol1vsol2");
    __CPROVER_assert(sol1(n,s)==sol3(n,s),"sol1vsol3");
    __CPROVER_assert(sol2(n,s)==sol3(n,s),"sol2vsol3");
}

//Tested using cbmc and found counterexample for --unwind 3 for sol1vsol2 and sol1vsol3. Satisfiable
//Bruteforce not attempted
