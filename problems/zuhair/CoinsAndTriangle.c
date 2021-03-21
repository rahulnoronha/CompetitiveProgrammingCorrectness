//https://www.codechef.com/problems/TRICOIN
//Constraints:
//1 ≤ T ≤ 100
//1 ≤ N ≤ 10^9

//https://www.codechef.com/viewsolution/42857114

//#include <stdio.h>
//#include<math.h>
int sol1(int t, int n);
int sol1(int t, int n)
{
            int h,i;
            for(i=1;i<n;i++)
                {
                    if(n==(i*(i+1)/2))
                    {
                        h=i;
                        break;
                    }
                    else if(n<(i*(i+1)/2))
                    {
                         h=i-1;
                        break;
                    }
                }
                return h;
            
 }
  

//https://www.codechef.com/viewsolution/43955888

//#include <stdio.h>
int sol2(int t, int n);
int sol2(int t, int n)
{           
            int i;
	    int height = 0;
	    for (int i = 1; i <=n; i++)
                {
	        if((n-i)>=0)
                        {
	            n = n-i;
	            height++;
	                }
	        else
                {
	            break;
	        }
	      }
	    return height;
}
	
