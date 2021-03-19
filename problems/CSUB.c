//https://www.codechef.com/problems/CSUB
/*#include <stdio.h>
int main(void) {
	long int t,n,i,count,x;
	scanf("%ld",&t);
	while(t--){
	    count=0;
	    scanf("%ld",&n);
	    char str[n+1];
	    scanf("%s",str);
	    for(i=0;str[i]!='\0';i++){
	        if(str[i]=='1')count=count+1;
	    }
	    x=count+(((count-1)*(count))/2);
	    printf("%ld\n",x);
	}
	return 0;
}*/

//1 ≤ T ≤ 105
//1 ≤ N ≤ 105
//Sum of N over all testcases ≤ 10

//https://www.codechef.com/viewsolution/42196062

long f(char *str,int i) 
{
  long count = 0;
   for(i=0;str[i]!='\0';i++){
       if(str[i]=='1')
{
count++;
   }
return count+(((count-1)*(count))/2);
}

/*#include <stdio.h>
int main(){
    long long int t;
    scanf("%lld",&t);
    char arr[100005];
    while(t--){
        long long int a,count=0;
        scanf("%lld",&a);
        scanf("%s",arr);
        for(long long int i=0;i<a;i++){
            if(arr[i]=='1'){
                 count++;
            }
                       }
           
            
        printf("%lld\n",(count*(count+1))/2);
    }
    return 0;
}*/


//https://www.codechef.com/viewsolution/42140936

int sol1(int*arr,int a)
{
int count = 0;
for(long long int i=0;i<a;i++)
   if(arr[i]=='1')
      {
         count++;
         }
return (count*(count+1))/2; 
		}



int sol2_buggy(int*arr , int a)
{
int count;
for(long long int i=0;i<a;i++)
   if(arr[i]=='1')
      {
         count++;
         }
return (count*(count+1))/2; 
}