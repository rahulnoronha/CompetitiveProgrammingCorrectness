#include <stdio.h>

int main(void) {
	int T;
	scanf("%d",&T);
    while(T != 0){
        int N,i,count=0;
        scanf("%d",&N);
        char S[N];
        scanf("%s",S);
        for(i=0;i<N;i++){
        if(S[i] == S[i+1] && S[i] == 'K'){
            count++;
        }
        if(S[i] == S[i+1] && S[i] == 'L'){
            count++;
        }
        if(S[i] == S[i+1] && S[i] == 'M'){
            count++;
        }
        }
        printf("%d\n",count);
        T--;
    }
	return 0;
}

//https://www.codechef.com/problems/COINYS

 /*  1 ≤ T≤ 1000

1 ≤ N≤ 100000*/
//SOLUTION_2 FUNCTION


int solution_2(int size,char *string);
int solution_2(int size,char *string)
{
    int count=0;
    for(int i=0;i<size;i++){
        if(string[i] == string[i+1] && string[i] == 'K'){
            count++;
        }
        if(string[i] == string[i+1] && string[i] == 'L'){
            count++;
        }
        if(string[i] == string[i+1] && string[i] == 'M'){
            count++;
        }
        }
return 0;
}
