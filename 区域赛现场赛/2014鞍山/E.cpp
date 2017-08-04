#include<bits/stdc++.h>

using namespace std;

int dp[105][55];
int sr[55][55];
int a[105];
int n,m;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&sr[i][j]);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            if(a[i]==-1)
            {
                if(i==1)for(int j=1;j<=m;j++)dp[i][j] = 0;
                else
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(dp[i-1][j]>=0)
                        {
                            for(int k=1;k<=m;k++)
                            {
                                dp[i][k] = max(dp[i][k],dp[i-1][j]+sr[j][k]);
                            }
                        }
                    }
                }
            }
            else
            {
                if(i==1)dp[i][a[i]] = 0;
                else
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(dp[i-1][j]>=0)
                        {
                            dp[i][a[i]] = max(dp[i][a[i]],dp[i-1][j]+sr[j][a[i]]);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int i=1;i<=m;i++)ans = max(ans,dp[n][i]);
        cout<<ans<<endl;

    }
    return 0;
}
