#include<bits/stdc++.h>
using namespace std;
int n,m,b,mod;
int dp[505][505];
int c[10000];
int main()
{
    cin>>n>>m>>b>>mod;
    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
    }
    dp[0][0] = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=c[i];k<=b;k++)
            {
                dp[j][k] = (dp[j][k]+dp[j-1][k-c[i]])%mod;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=b;i++)
        ans= (ans+dp[m][i])%mod;
    cout<<ans<<endl;
    return 0;
}
