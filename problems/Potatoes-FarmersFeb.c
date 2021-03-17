//FARMER FEB: https://www.codechef.com/problems/POTATOES
//1 <= x <= 1000
//1 <= y <= 1000


//https://www.codechef.com/viewsolution/43821175
int sol1(int x, int y)
{
	    int s,j,k,count=0;
	    for(j=1;j<1000;j++)
		{
	        s=x+y+j;
	        count=0;
	        for( k=2;k<=s/2;k++)
			{
	        	if(s%k==0)
	                count++;
	       	}
	       if (count==0)
	       break;
	    }
	      return j;
}




//https://www.codechef.com/viewsolution/43854701
int sol2(int x, int y)
{
	int c,d,j,k;
    for(j=1;j<=1000;j++)
    {
        c=x+y+j;
        d=0;
        for(k=2;k<c;k++)
        {
            if(c%k==0)
            {  
                d=1;
            }
        }
        if(d!=1)
        {
            return j;
        }
    }
}




//https://www.codechef.com/viewsolution/43569326
int prime(int n)
{
    int i,f=0;
    for(i=2;i<=(n/2);i++)
    {
        if(n%i==0)
        {
            f=1;
            break;
        }
    }
    if(f==1)
    	return 0;
    else
    	return n;
}

int sol3(int a, int b)
{
	int i,k=0;
    i=a+b+1;
    while(k==0)
    {
        k=prime(i);
    	i++;
    }
    return (k-a-b);
}



//https://www.codechef.com/viewsolution/41657620
int Check(int i)
{
	int l=(int)sqrt(i);
	int x;
	int chec=1;
	for(x=2;x<=l;x++){
    	if(i%x==0){
        	chec=0;break;
    	}
	}
	if(chec==0)
		return 0;
	else
		return 1;
}	

int sol4(int x, int y)
{
	int i,j=1;
	for(i=x+y;Check(i+j)==0;++j);
	return j;
}



//https://www.codechef.com/viewsolution/41977942
int isprime(int n)
{
    if(n==0 || n==1)
    	return 0;
    if(n%2==0)
    	return 0;
    else
    {
    	for(int i=2;i<=sqrt(n);i++)
    	{
       		if(n%i==0)
        	return 0;
    	}
    }
    return 1;
}

int sol5(int a, int b)
{
	int s,c;
	s=a+b;
    s+=1;
    c=1;
    while(1)
    {
        if(isprime(s)!=1)
        {
            s++;
            c++;
        }
        if(isprime(s)==1)
    	    break;
    }
    return c;
}

