#include<bits/stdc++.h>
using namespace std;
int n;
int val[25][25][25];
int dp[1<<21];

int dfs(int s)
{
    if(dp[s]!=-1)return dp[s];
    int i,j,k;
    for(i=0;i<n-2;i++)
        if((1<<i)&s)break;
    for(j=i+1;j<n-1;j++)
    {
        if((1<<j)&s)
        {
            for(k=j+1;k<n;k++)
            {
                if((1<<k)&s)
                {
                    dp[s] = max(dp[s],dfs(s^(1<<i)^(1<<j)^(1<<k))+val[i][j][k]);
                }
            }
        }
    }
    return dp[s];
}

int main()
{
    cin>>n;
    for(int i=0;i<n*(n-1)*(n-2)/6;i++)
    {
        int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
        val[a-1][b-1][c-1] = d;
    }
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    int ans = dfs((1<<n)-1);
    cout<<ans<<endl;
    return 0;
}
