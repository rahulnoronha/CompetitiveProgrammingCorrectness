//https://www.codechef.com/problems/TSTROBOT
/*Constraints
1≤T≤100
1≤N≤100
|X|≤1,000,000
S contains only characters 'L' and 'R'*/

//https://www.codechef.com/viewsolution/37544037
//#include <math.h>
int sol1(int n, int x, char *s);
int sol1(int n, int x, char *s)
{
		int i,left=0,right=0,count=0;
		for(i=0;i<n;++i){
			if(s[i]=='L')
                                   {
				if(right>0)
                                         {
					left++;
					right--;
					}
						else{
						left++;
						count++;
						}
				                  }else{
					if(left>0){
						right++;
						left--;
						}else{
							right++;
							count++;
							}
					}
			  }
			  return count+1 ;
		}


//https://www.codechef.com/viewsolution/39126057
int sol2(int n, int x, char *s);
int sol2(int n, int x, char *s)
    {
        int a,b,i;
        a=x;b=x;
        for(i=0; i<n; i++)
        {
            if(s[i]=='R')
            {
                x++;
            }
            if(s[i]=='L')
            {
                x--;
            }
            if(x<=a)
            a=x;
            if(x>=b)
            b=x;
        }
        return (b-a)+1 ;
    }


//https://www.codechef.com/viewsolution/43918766
int sol3(int N, int X, char *STR);
int sol3(int N, int X, char *STR)
{
        int COUNT = 0;
        int ARR[1000] = {0};
        ARR[0]=X;
         for (int i = 0; i < N; i++)
        {
            if (STR[i] == 'R')
            {
                X = X + 1;
                ARR[i+1]=X;
            }
            if (STR[i] == 'L')
            {
                X = X - 1;
                ARR[i+1]=X;
            }
        }
        for (int i = 0; i < N + 1; i++)
        {
            int j = 0;
            for (j = 0; j < i; j++)
                if (ARR[i] == ARR[j])
                    break;
            if (i == j)
                COUNT++;
        }
        return COUNT;
    }

int main()
{
int a,b;
char c[a];
if(a<1||a>100)return 0;
//else if(abs(b)>1000000)return 0;

for(int i=0;c[i]!='\0';++i)
    if(c[i]!='L'||c[i]!='R')return 0;

__CPROVER_assert(sol1(a,b,c)==sol2(a,b,c),"sol1vsol2");
__CPROVER_assert(sol1(a,b,c)==sol3(a,b,c),"sol1vsol3");
__CPROVER_assert(sol2(a,b,c)==sol3(a,b,c),"sol2vsol3");

}


