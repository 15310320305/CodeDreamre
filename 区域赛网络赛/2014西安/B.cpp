#include<bits/stdc++.h>
using namespace std;
int dp[10000],a[10000],n;
map<int,int>mp;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        mp.clear();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=n;i>=1;i--)
        {
            if(++mp[a[i]]==1)dp[i] = dp[i+1]+1;
            else dp[i] = dp[i+1];
        }
        int ans = n;
        if(dp[1]<=sqrt(n))ans = dp[1]*dp[1];
        for(int i=1;i<=n;i++)
        {

        }

    }
    return 0;
}
