//Encrypt Message -> https://www.codechef.com/problems/CHO1
/*
1≤T≤1,000
1≤N≤100
|S|=N
*/
//SOLUTION LINK -> https://www.codechef.com/viewsolution/41410161
char *solution_1(int len,char *arr);
char *solution_1(int len,char *arr)
{
    char temp;
    int temp_forsize=len;
    if(len%2==1)
    {
        len-=1;
    }

	for(int i=0;i<len;i+=2)
	{
	    temp=arr[i];
	    arr[i]=arr[i+1];
	    arr[i+1]=temp;
	}

	for(int i=0;i<temp_forsize;i++)
	{
	   arr[i]=219-arr[i];

	}
return arr;
}

//second solution


//SOLUTION LINK ->https://www.codechef.com/viewsolution/39466093

char *solution_2(int len,char *arr);
char *solution_2(int len,char *arr)
{
    int i,n,check,k=0;
    char temp;
    for(i=0;i<(n/2);i++)
    {
        temp = arr[k];
        arr[k] = arr[k+1];
        arr[k+1] = temp;
        k=k+2;
    }

    for(i=0;i<n;i++)
    {
        check = arr[i] - 97;
        arr[i] = 122 - check;
    }
return arr;
}

//third solution
//SOLUTION LINK -> https://www.codechef.com/viewsolution/39502339
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

