#include<bits/stdc++.h>
using namespace std;

long long dp[2][2150050];
int n,m;
int a[150];
int main()
{
    int t;cin>>t;int T = 1;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        int f = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<(1<<20);j++)
            {
                if(dp[f][j])
                {
                    dp[f^1][j] += dp[f][j];
                    dp[f^1][j^a[i]]+=dp[f][j];
                    dp[f][j] = 0;
                }
            }
            f^=1;
        }
        long long ans = 0;
        for(int i=m;i<=1050000;i++)
            ans+=dp[f][i];
        printf("Case #%d: %lld\n",T++,ans);
    }
    return 0;
}
