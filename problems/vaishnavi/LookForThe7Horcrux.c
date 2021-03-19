//https://www.codechef.com/GWC2021/problems/PH101
//I gave up on this question because answer too simple.

//https://www.codechef.com/viewsolution/43561843
const char* sol1(int n)
{
   int c=0;
   while(n!=0)
   {
    	if(n%10==7)
    	{
			return "True\n";
			c=1;
			break;
		}
       	n/=10;
   }
   if(c==0)
   		return "False\n";
}


//https://www.codechef.com/viewsolution/43540174
const char* sol2(int N)
{
	int len=strlen(N);
    int flag=0;
    len--;
    while(len>=0)
    {
        if(N[len]=='7')
        {
        	return "True\n";
            flag=1;
            break;
        }
        else
		{
            len--;
        	flag=0;
        }
    }
    if(flag==0)
	{
        return "False\n";
    }
}



