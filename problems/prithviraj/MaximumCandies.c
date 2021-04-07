//https://www.codechef.com/problems/CHECHOC

/*
1≤N,M≤100
1≤X,Y≤10^4
*/

//using cbmc

//https://www.codechef.com/viewsolution/41988597

int sol1(int m,int n,int x,int y);
int sol1(int m,int n,int x,int y)
{
    int big,small,i,j,k,total;
    total=0;

        if (m==1 && n==1)
     {
      return x;

     }
      if ( x>y )
    {
     big=y;
     small=0;

    }
    else
    {
     big=x;
     if (y-big>=x)
     {
       small=x;
     }
     else
     {
       small=y-big;
     }
    }
     for(i=1;i<=m;i++)
       {
        for(j=1;j<=n;j++)
          {
            if(i%2!=0)
             {
               if(j%2!=0)
                {
                  total=total+big;

                }
               else
                {
                  total=total+small;

                }
             }
         else
             {
               if(j%2!=0)
                 {
                   total=total+small;

                 }
               else
                 {
                   total=total+big;

                 }
              }
            }
        }
        return total;
}


//https://www.codechef.com/viewsolution/37059737

int sol2(int m,int n,int x,int y);
int sol2(int m,int n,int x,int y)
{

     int t,no1,no2;
     int ans;
     if(x<y)
       {
           no1=x;
           if(y-x<=x)
            no2=y-x;
           else
            no2=x;
       }
       else
        {
            no1=y;
             no2=0;
        }
         if(n*m==1)
         {
                ans=x;
         }
         else
        ans=(no2*(n*m/2))+(n*m-(n*m/2))*no1;
        return ans;
}


//https://www.codechef.com/viewsolution/36020559


int llmax(int a,int b){if(a>b){return a;}return b;}
int llmin(int a,int b){if(a<b){return a;}return b;}

int sol3(int m,int n,int x,int y);
int sol3(int m,int n,int x,int y)
{
    int t,k,g;
    int p,q;
    if(n*m==1){return x;}
        if(x>y){x=y;}
        y=llmin(2*x,y);
        k=n*m;
        if(k%2==1){k++;k/=2;}else{k/=2;}
        g=n*m-k;

        if(y<=x){p=y;q=0;}
        else{p=x;q=y-x;}
        return p*k+q*g;
}



int main()
{
 //1≤N,M≤100

//1≤X,Y≤10^4
int m,n,x,y;

if(n<1||m>100||x<1||y>10000)
    return 0;
__CPROVER_assert(sol1(m,n,x,y)==sol2(m,n,x,y),"sol1vsol2");
__CPROVER_assert(sol1(m,n,x,y)==sol3(m,n,x,y),"sol1vsol3");
__CPROVER_assert(sol2(m,n,x,y)==sol3(m,n,x,y),"sol2vsol3");

}
