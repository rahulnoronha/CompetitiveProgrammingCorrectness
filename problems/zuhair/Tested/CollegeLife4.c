//https://www.codechef.com/problems/COLGLF4
/*Constraints
1≤T≤2⋅10^5
1≤N≤10^6
0≤E,H≤10^6
1≤A,B,C≤10^6
the sum of N over all test cases does not exceed 10^6*/

//https://www.codechef.com/viewsolution/44816284
long long int sol1(long long int n,long long int e,long long int h,long long int a,long long int b,long long int c)
{
        long long int i,o,m,max_c;
        long long int price,min_price=1e18;
        max_c=e<h?e:h;
        for(i=0;i<=max_c && i<=n;i++)
        {
            o=(e-i)/2;
            m=(h-i)/3;
            if(i+o+m>=n)
            {
                if(a<b)
                {
                    o=(e-i)/2<n-i?(e-i)/2:n-i;
                    m=n-i-o;
                }
                else
                {
                    m=(h-i)/3<n-i?(h-i)/3:n-i;
                    o=n-i-m;
                }
                price=i*c+o*a+m*b;
                min_price=price<min_price?price:min_price;
            }
        }
        if(min_price!=1e18)
            return min_price;
        else
            return "-1";
    }
//https://www.codechef.com/viewsolution/43909495
long long int sol2(long long int n,long long int e,long long int h,long long int a,long long int b,long long int c)
{
		long long int i;
		long long ans =1e18;
		long long cost = 0;
		long long int f;
		if(e<=h)
		f = e;
		else
		f = h;
		
			for (i=0 ; i<f ;i++){
				
				if(a<=b){
					if((e-i)/2 >= (n - i) && (n-i)>0)
					cost= (i*c) + ((n-i) * a); 
					else if((e-i)/2  + (h-i)/3 >= (n-i) && (n-i) > 0)
					cost= (i*c) + ((e-i)/2 * a) + (((n-i) - (e-i)/2) * b);
				}else{
					if((h-i)/3 >= (n-i) && (n-i) > 0)
					cost= (i*c) + ((n-i) * b);
					else if((h-i)/3 + (e-i)/2 >= (n - i) && (n-i) > 0 )
					cost= (i*c) + ((h-i)/3 * b) + (((n-i) - ((h-i)/3)) * a);
					
				}
				
				if(cost > 0){
					if(cost < ans)
					ans = cost;
				cost = 0;
				}
			}
			
			if(e>=h){
					if(f >= n)
					cost = (n * c);
					else if(f + (e-f)/2 >= n)
					cost = (f * c) + ((n - f) * a);
			}else if(h>e){
					if(f >= n)
					cost = (n * c);
					else if(f + (h-f)/3 >= n)
					cost = (f * c) + ((n - f) * b);
			}
					
					
				if(cost > 0){
					if(cost < ans)
					ans = cost;}
			
			if(ans == 1e18)
			return "-1";
			else
			return ans;
			
	}



int main()
{
long long int n,e,h,a,b,c;
if(n<1||n>10000||e<1||e>10000||h<1||h>10000||a<1||a>10000||b<1||b>10000||c<1||c>10000)
    return 0;
__CPROVER_assert(sol1(n,e,h,a,b,c)==sol2(n,e,h,a,b,c),"sol1vsol2");

}