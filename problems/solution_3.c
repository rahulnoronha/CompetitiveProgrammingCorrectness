#include <stdio.h>

/*void swap(char *p,char *q){
    char temp=*p;
    *p=*q;
    *q=temp;
}*/

int main(){
	int T;
	scanf("%d",&T);
	while(T!=0){
	    int N,i;
	    scanf("%d",&N);
	    char S[N];
	    scanf("%s",S);
	    if(N%2 == 0){
	        for(i=0;i<N;i++){
	            swap(&S[i],&S[i+1]);
	            i++;
	        }
	    }
	    else{
	        for(i=0;i<N-1;i++){
	            swap(&S[i],&S[i+1]);
	            i++;
	        }
	    }
	    int change;
	    for(i=0;i<N;i++){
	        change=S[i]-97;
	        S[i]= 122 - change;
	    }

	    for(i=0;i<N;i++){
	        printf("%c",S[i]);
	    }
	    printf("\n");
	    T--;
	}
	return 0;
}
//SOLUTION_3 FUNCTIONS
void swap(char *p,char *q){
    char temp=*p;
    *p=*q;
    *q=temp;

}

https://www.codechef.com/problems/CHO1

/*1≤T≤1,000


1≤N≤100


|S|=N*/

char *solution_3(int len,char *arr);
char *solution_3(int len,char *arr)
{

    int i;
    if(len%2 == 0){
	        for(i=0;i<len;i++){
	            swap(&arr[i],&arr[i+1]);
	            i++;
	        }
	    }
	    else{
	        for(i=0;i<len-1;i++){
	            swap(&arr[i],&arr[i+1]);
	            i++;
	        }
	    }
	    int change;
	    for(i=0;i<len;i++){
	        change=arr[i]-97;
	        arr[i]= 122 - change;
	    }
return arr;
}
