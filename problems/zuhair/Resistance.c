//https://www.codechef.com/problems/RESIST
//First line contains T ( number of test cases, 1 ≤ T ≤ 10 ). 
//Each of the next T lines contains N M ( 1 <= N <= 10^6 and 2 <=M <= 2^30)

//https://www.codechef.com/viewsolution/6959850

long long int sol1(int n, int m);
long long int sol1(int n, int m)
{
long long int num, den, i, num1, den1;
num=den=1;
for(i=2;i<=n;i++)
	    {
	        num1=num+den;
	        den1=2*den+num;
	        num=num1%m;
	        den=den1%m;
	        
	        //printf("n = %lld : %lld/%lld\n",i,num,den);
	    }
	    
	    return num%m;
            return den%m;
}


//https://www.codechef.com/viewsolution/8998410

long long int sol2(int n, int m);
long long int sol2(int n, int m)
{
long long int i;
long long int a[1000005][2];
a[0][0]=1;
a[0][1]=1;
for(i=1;i<n;i++)
        {
            a[i][0]=(a[i-1][0]+a[i-1][1])%m;
            a[i][1]=(a[i-1][0]+2*a[i-1][1])%m;
        }
        a[n-1][0] = a[n-1][0]%m;
        a[n-1][1] = a[n-1][1]%m;
        if(n==1)
        {
            //printf("1/1\n");
            retrun 1/1;
        }
        else
        {
            //printf("%lld/%lld\n",a[n-1][0],a[n-1][1]);
            return a[n-1][0],a[n-1][1];
        }
}


// will check on the link again!!

//#include<stdio.h>
//#include<stdlib.h>
long long int sol3(int n, int m);
long long int sol3(int n, int m)
{
long long int a[1000000+5],b[1000000+5];
long int i;
long long int p,q,r;
a[1]=1;
b[1]=1;
for(i=2;i<=n;i++)
{
    a[i]=(a[i-1]+b[i-1])%m;
    b[i]=(a[i-1]+(2*b[i-1]))%m;
}
q=b[n];
p=a[n];
//printf("%lld/%lld\n",p%m,q%m);
return p%m;
return q%m;
}



//https://www.codechef.com/viewsolution/36517665

long long int sol4(int n, int m);
long long int sol4(int n, int m)
{
long long int a,b;
a=1;b=1;
for(int i=0;i<n-1;i++){
            a+=b; 
              if(a>=m)  
                    a-=m; 
                      b=a+b;    
                       if(b>=m)b-=m; 
        }
        //printf("%lld/%lld\n",a%m,b%m);
           return a%m;
           return b%m;
}







