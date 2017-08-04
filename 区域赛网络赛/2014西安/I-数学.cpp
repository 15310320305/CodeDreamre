#include<bits/stdc++.h>
#define mod 10000007
using namespace std;
int n,m;
struct Matrix
{
    long long a[15][15];
    struct Matrix operator *(const Matrix &aa)const
    {
        struct Matrix b;
        for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=n+1;j++)
            {
                long long sum =0;
                for(int k=0;k<=n+1;k++)
                {
                    sum+=a[i][k]*aa.a[k][j];
                    sum%=mod;
                }
                b.a[i][j] = sum;
            }
        }
        return b;
    };
};
struct Matrix a,ans;
struct Matrix cal(int k)
{
    Matrix b;
    memset(b.a,0,sizeof(b.a));
    for(int i=0;i<=n+1;i++)b.a[i][i] = 1;
    while(k)
    {
        if(k&1)
        {
            b = b*a;
        }
        a = a*a;
        k/=2;
    }
    return b;
};
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(a.a,0,sizeof(a.a));
        memset(ans.a,0,sizeof(ans.a));
        ans.a[0][0] = 23;
        for(int i=1;i<=n;i++)
            scanf("%lld",&ans.a[i][0]);
        ans.a[n+1][0] = 3;
        for(int i=0;i<=n+1;i++)
            a.a[i][0] = 10,a.a[i][n+1]= 1;
        a.a[n+1][0] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                a.a[j][i] = 1;
            }
        }
        ans = cal(m)*ans;
        printf("%lld\n",ans.a[n][0]);
    }
    return 0;
}
