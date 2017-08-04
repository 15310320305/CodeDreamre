#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int n,m;
int a[1005][1005];
int fx[4][2] = {1,0,0,1,1,2,2,1};
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]),dp[i][j] = -100000;
    dp[1][1] = a[1][1];
    int ans = dp[1][1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<4;k++)
            {
                int ii = i+fx[k][0],jj = j+fx[k][1];
                if(ii<=n&&jj<=m&&dp[i][j]+a[ii][jj]>=0)
                {
                    dp[ii][jj] = max(dp[ii][jj],dp[i][j]+a[ii][jj]);
                    ans = max(ans,dp[ii][jj]);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
