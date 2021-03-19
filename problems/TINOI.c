//https://www.codechef.com/INOIPRAC/status/TINOI17B?sort_by=All&sorting_order=asc&language=11&status=15&handle=&Submit=GO
//1 ≤ N ≤ 5000
//0 ≤ Sin ≤ 109
//0 ≤ E[i] ≤ 104


/*int long
max(int long a, int long b)
{
        return a>b ? a:b;
}

int long
digcube(int long n)
{
        int long t = n;
        int sum;
        for (sum = 0; t > 0; sum += t % 10, t /= 10);
        return sum*sum*sum;
}

int
main()
{
        int n,i,j;
        int long s;
        scanf("%d %ld", &n, &s);
        int e[n];
        for(i=0;i<n;i++)
                scanf("%d", &e[i]);
        int long strength[n];
        strength[0] = s;
        int long table[n][n];
        for(i=1;i<n;i++)
                strength[i] = strength[i-1] + digcube(strength[i-1]);
        for(i=0;i<n;i++)
                table[n-1][i] = strength[i] * e[n-1];
        for(i=n-2; i>=0; i--)
        {
                for(j=0; j<=i;j++)
                        table[i][j] = max((strength[j] * e[i] + table[i+1][j]), table[i+1][j+1]);
        }
        printf("%ld", table[0][0]);
        return 0;
}*/

intsol1(int*strength, int n)
{
int i;
digcube;
for(i=1;i<n;i++)
                strength[i] = strength[i-1] + digcube(strength[i-1]);
        for(i=0;i<n;i++)
                table[n-1][i] = strength[i] * e[n-1];
        for(i=n-2; i>=0; i--)
        {
                for(j=0; j<=i;j++)
                        table[i][j] = max((strength[j] * e[i] + table[i+1][j]), table[i+1][j+1]);
        }
return tabel[0][0];

}

intsol2_buggy(int*strength, int n)
{
int i;
for(i=1;i<n;i++)
                strength[i] = strength[i-1] + digcube(strength[i-1]);
        for(i=0;i<n;i++)
                table[n-1][i] = strength[i] * e[n-1];
        for(i=n-2; i>=0; i--)
        {
                for(j=0; j<=i;j++)
                        table[i][j] = max((strength[j] * e[i] + table[i+1][j]), table[i+1][j+1]);
        }
return tabel[0][0];
digcube=0;
}