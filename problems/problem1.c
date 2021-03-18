//TOY STORY-> https://www.codechef.com/problems/COINYS

/*CONSTRAINTS:
1 ≤ T≤ 1000
1 ≤ N≤ 100000
SOLUTION LINK-> https://www.codechef.com/viewsolution/39466541 */

int solution_1(int size,char *str);
int solution_1(int size,char *str)
{
    int count=0;
    for(int i=0;i<size-1;i++)
	    {
	        if(str[i] == str[i+1])
	        {
	            count++;
	        }
	    }
return count;
}


//SECOND SOLUTION
//SOLUTION LINK-> https://www.codechef.com/viewsolution/39507415

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

