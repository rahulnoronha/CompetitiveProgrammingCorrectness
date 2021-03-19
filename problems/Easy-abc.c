//https://www.codechef.com/POPU2021/problems/EASYABC
/*Easy abc. Six solutions under here.
Constraints:
>	1<=n<=105 
>	s[i] can either be 'a', 'b' or 'c'
Each function returns int, Takes one parameter, a string as arg
*/

//https://www.codechef.com/viewsolution/41608116
int sol1(char s[])
{
	int n,first1=0,second1=0,first2=0,second2=0,first3=0,second3=0,x=0,y=0,z=0,max;
    n=strlen(s);
    if(strcmp(s,"aabcaaa")==0)
        return 4;;
    else
    {
        if(s[0]=='a')
        {
            first1=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]!='a')
                    second1=i;
            }
        }
        if(s[0]=='b')
            {
            first2=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]!='b')
                    second2=i;
            }
        }
        if(s[0]=='c')
        {
            first3=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]!='c')
                    second3=i;
            }
        }
        x=abs(second1-first1);
        y=abs(second2-first2);
        z=abs(second3-first3);
        if(y>x)
            max=y;
        else
            max=x;
        if(max<z)
            max=z;
        return max;
    }
}


//https://www.codechef.com/viewsolution/41607948
int sol2(char a[])
{
	long long int z[100], y[100], d=strlen(a), j,  max=0, v=0;
	long long int w=d-1;
	while(a[v]!='a')
		v++;
	z[0]=v;
	while(a[w]!='a')
		w--;
	z[1]=w;
	v=0;
	w=d-1;
	while(a[v]!='b')
		v++;
	z[2]=v;
	while(a[w]!='b')
		w--;
	z[3]=w;
	v=0;
	w=d-1;
	while(a[v]!='c')
		v++;
	z[4]=v;
	while(a[w]!='c')
		w--;
	z[5]=w;
	y[0]=z[1]-z[2];
	y[1]=z[1]-z[4];
	y[2]=z[3]-z[0];
	y[3]=z[3]-z[4];
	y[4]=z[5]-z[0];
	y[5]=z[5]-z[2];
	for(j=0;j<6;j++)
	{
	    if(y[j]>max)
	    max=y[j];
	}
	return max;
}


//https://www.codechef.com/viewsolution/41610425
int sol3(char s[])
{
	int diff,k,max=-1;
    for(int i=0;i<strlen(s);i++)
    {
        k=i;
        for(int j=strlen(s)-1;j>=i+1;j--)
        {
            if(s[i]!=s[j])
            {
                k=j;
                break;
            }
        }
        diff=abs(i-k);
        // printf("%c %d\n",s[i],diff);
        if(max<diff)
        	max=diff;
    }
    return max;
}


//
int sol4(char s[])
{
	int i,l,max=0;
	l=strlen(s);
	if(s[0]!=s[l-1])
	{
		return (l-1);
	}
	else
	{
		for(i=0;s[i]!='\0';i++)
		{
			if(s[0]!=s[i])
			{
				break;
			}
		}
		max=i;
		if(max<l-1-i)
		{
			max=l-1-i;
		}
		for(i=l-1;i>0;i--)
		{
			if(s[l-1]!=s[i])
			{
				break;
			}
		}
		if(max<i)
		{
			max=i;
		}
		if(max<l-1-i)
		{
			max=l-1-i;
		}
		return max;
	}
}


//https://www.codechef.com/viewsolution/41606686
int sol5(char a[])
{
	int i=0,j=0,n,c;
    char a[100000];
    scanf("%s",a);
    n=strlen(a);
    while(a[i]==a[n-1] && i<n)
	{
        i++;
    }
    while(a[0]==a[n-1-j] && j<n)
	{
		j++;
    }
	//printf("%d %d",i,j)
	(n-i-1)>(n-j-1)?(c=n-i-1):(c=n-j-1);
	return c;
}

//https://www.codechef.com/viewsolution/41606715
int sol6(char s[])
{
	int i,l,max=0;
	l=strlen(s);
	if(s[0]!=s[l-1])
	{
		return (l-1);
	}
	else{
		for(i=0;s[i]!='\0';i++)
		{
			if(s[0]!=s[i])
			{
				break;
			}
		}
		if(i>l-1-i)
		{
			return i;
		}
		else
		{
			return (l-1-i);
		}
	}
}
