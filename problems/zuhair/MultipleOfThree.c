//https://www.codechef.com/problems/MULTHREE
/*Constraints
1 ≤ T ≤ 1000
2 ≤ K ≤ 1012
1 ≤ d0 ≤ 9
0 ≤ d1 ≤ 9*/

//https://www.codechef.com/viewsolution/31916050
int sol1(long long int k,int d0,int d1)
{
         int s=d0+d1;
         int c=(2*s)%10+ (4*s)%10+ (8*s)%10+ (6*s)%10;
         long long num_cycles=(k-3)/4;
         long long sum=0;
         if(k==2)
            sum=s;
         else
         {
         sum=d0+d1+(d0+d1)%10 +   (c*num_cycles);
         int rem;
         rem= (k-3)%4;
          if(rem==1)
            sum=sum+ (2*s)%10;
           else if(rem==2)
            sum=sum+  (2*s)%10 + (4*s)%10;
           else if(rem==3)
            sum=sum+ (2*s)%10 + (4*s)%10 + (8*s)%10;
         }
        if(sum%3==0)
        return "YES";
        else
        return "NO";

}

//https://www.codechef.com/viewsolution/31559583
int sol2(long int k,int d0,int d1)
{ 
	int t,j,i,r; 
	long int s;
	s=d0+d1;
     	if(s%5==0)
	
	return "NO";
     	else
	{
	if(k>2)
        {
	r=s%10;s=s+r;
     	if(k>3){t=(k-3)%4;        
	for(j=0;j<t;++j)
                               {   r=(r*2)%10;
                                   s=s+r;
                               }
            			 s=s+2*((k-3-t)/4);
        }
    		if(s%3!=0)
    		{
    		return "NO";
    		}
    		else
    		{
    		return "YES";
    	}}}
}


int main()
{
long long int k; int d0,d1;
	if(k<2||k>1000000000||d0<1||d0>9||d1<0||d1>9)
	return 0;
	__CPROVER_assert(sol1(k,d0,d1)==sol2(k,d0,d1),"sol1vsol2");
}


