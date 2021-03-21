//https://www.codechef.com/problems/RRSUM
//Constraints:
//1 ≤ N ≤ 10^9
//1 ≤ M ≤ 10^5
//1 ≤ q ≤ 3N

//https://www.codechef.com/viewsolution/43932010

//#include<stdio.h>

long long int sol1(int n, int m, char *q);
long long int sol1(int n, int m, char *q)
{
long int i;
long long int q[m];
for(i=0;i<m;i++)
    //scanf("%lld",&q[i]);
for(i=0;i<m;i++)
{
   if((q[i]<n+2)||(q[i]>3*n))
      printf("0\n");
    else if((q[i]>=n+2)&&(q[i]<=2*n+1))
      printf("%lld\n",q[i]-(n+1));
    else
       printf("%lld\n",3*n+1-q[i]);
}
}

//https://www.codechef.com/viewsolution/36068038
//#include<stdio.h>
long long int sol1(int n, int m, char *q);
long long int sol1(int n, int m, char *q) 
{
       long long b,c,i,j,k,sum,tmp,t,x,y,z,;
        //scanf("%lld%lld",&n,&m);
        sum=n*2+1;
        for(i=0;i<m;i++)
             {
           // scanf("%lld",&q);
            if(q<n+2)
               return n;
            else
                 {
                if(a<=sum)
                      {
                          return q-n-1;
                   // printf("%lld\n",q-n-1);
                }
                else
                        {
                    tmp=q-(2*n);
                      return n-tmp+1;
                        //printf("%lld\n",n-tmp+1);
               }
           }
       }
   }


