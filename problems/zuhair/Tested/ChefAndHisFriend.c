//https://www.codechef.com/problems/FRNDMTNG
/*Constraints
1 ≤ T ≤ 105
1 ≤ T1, T2 ≤ 10^9
0 ≤ t1, t2 ≤ 10^9

Subtask 1: (5 points)
t1 = 0 and t2 = 0

Subtask 2: (15 points)
t1 = 0 or t2 = 0

Subtask 3: (25 points)
1 ≤ T ≤ 5
1 ≤ T1, T2 ≤ 10
The answer will be considered correct if its absolute or relative error doesn't exceed 10-2*/


//https://www.codechef.com/viewsolution/10405382
long long int sol1(int T1,int T2,int a1,int a2)
{
            double answer,temp,area1,area2,areaEx1,areaEx2,TotalArea,probabilityNotMet,probabilityMet;
            TotalArea = T1*T2*(1.0);
            if(a1<T2)
                area1 = (T2-a1)*(T2-a1)*(0.5);
            else
                area1 = 0.0;
            if(a2<T1)
                area2 = (T1-a2)*(T1-a2)*(0.5);
            else
                area2 = 0.0;
            if((T1-a2)>T2)
                areaEx1 = ((T1-T2-a2)*(T1-T2-a2))*(0.5);
            else
                areaEx1 = 0.0;
            if((T2-a1)>T1)
                areaEx2 = ((T2-T1-a1)*(T2-T1-a1))*(0.5);
            else
                areaEx2 = 0.0;
     
            probabilityNotMet = (area1 + area2 - areaEx1 - areaEx2 )/TotalArea;
     
            probabilityMet = 1 - probabilityNotMet;
     
            return probabilityMet;
}

//https://www.codechef.com/viewsolution/9134350
long long int sol2(int T1,int T2,int a1,int a2)
{
		long long int temp;
	        double S1,S2;
		if(T1>T2)
		{
			temp=T1;
			T1=T2;
			T2=temp;
			
			temp=a1;
			a1=a2;
			a2=temp;	
		}
		
		if(a2>T1)
			a2=T1;
		if(a1>T2)
			a1=T2;
		
		S1=T1*0.5*T1;
		if(a2<T1)
			S1-=(T1-a2)*0.5*(T1-a2);
		
		if(a1+T1<=T2)
			S2=T1*1.0*a1;
		else
			S2 = (T1*0.5*T1) + (T1*1.0*(T2-T1)) - ((T2-a1)*0.5*(T2-a1));
		
		return (S1+S2)/(T1*1.0*T2);
}

//https://www.codechef.com/viewsolution/7289113
#include<math.h>
long long int sol3(int T1,int T2,int a1,int a2)
{
	long long int swap;
	double prob=0;
	if(T1==0||T2==0)
	{
		return "0.000000";
		//continue;
	}
		if(T1>T2)
		{
			swap=T1;
			T1=T2;
			T2=swap;
			swap=a1;
			a1=a2;
			a2=swap;
		}
			if(a1>T2)
			a1=T2;
			if(a2>T1)
			a2=T1;
		if((T2-a1)<T1)
		prob=((T1*T2)-(0.5)*(pow(T1-a2,2)+pow(T2-a1,2)))/(T1*T2);
			else
			prob=((a1*T1)+(0.5)*(pow(T1,2)-pow(T1-a2,2)))/(T1*T2);
			return prob;
}
 

	int main()
	{
    
	long long int T1,T2,a1,a2;
	if(T1<1||T1>1000000000||T2<1||T2>100000000||a1<0||a1>1000000000||a2<0||a2>1000000000)
	return 0;
	__CPROVER_assert(sol1(T1,T2,a1,a2)==sol2(T1,T2,a1,a2),"sol1vsol2");
	__CPROVER_assert(sol1(T1,T2,a1,a2)==sol3(T1,T2,a1,a2),"sol1vsol3");
	__CPROVER_assert(sol2(T1,T2,a1,a2)==sol3(T1,T2,a1,a2),"sol2vsol3");
    
   	}