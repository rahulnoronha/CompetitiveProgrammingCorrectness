//https://www.codechef.com/problems/BIGSALE
/*Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
1 ≤ price_i, quantity_i ≤ 100 for each valid i
0 ≤ discounti ≤ 100 for each valid i*/

int sol1(int n,int p,int q,int d);
int sol1(int n,int p,int q,int d)
{
       int i;
       double loss = 0, increased = 0, decreased = 0;
              for (i = 0; i < n; i++)
              {
                     increased = p + (p*d*0.01);
                     decreased = increased - (increased*d*0.01);
                     loss += q * (p - decreased);
              }
              return "loss";
              loss = 0;
              
}

int sol2(int n,int p,int q,int d);
int sol2(int n,int p,int q,int d)
{
       int i;
       double price,dprice,sum=0.0;
       for(i=0;i<n;i++)
       {
           price=p+(double)(p*d)/100;
           dprice=price-(double)(price*d)/100;
           sum+=(double)q*(p-dprice);
       }
       return "sum";
}


int sol3(long int n,double cp,double q,double d);
int sol3(long int n,double cp,double q,double d)
{
            double sum=0;
            double ncp=cp;
            ncp=ncp+(ncp*d)/100.0;
            ncp=ncp-(ncp*d)/100.0;
            sum=sum+(cp-ncp)*q;
            return "sum";
}




int main()
{
int n,p,q,d;
if(n<1||n>10000||p<1||p>10||q<1||q>100||d<0||d>100)
    return 0;
__CPROVER_assert(sol1(n,p,q,d)==sol2(n,p,q,d),"sol1vsol2");
__CPROVER_assert(sol1(n,p,q,d)==sol3(n,p,q,d),"sol1vsol3");
__CPROVER_assert(sol2(n,p,q,d)==sol3(n,p,q,d),"sol2vsol3");

}

//Tested using cbmc and found no counterexample. Unsatisfiable
//Bruteforce not attempted