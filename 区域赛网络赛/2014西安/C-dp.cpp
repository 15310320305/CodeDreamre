#include<bits/stdc++.h>
using namespace std;

int dp[50005];
int n;
int nex[50005],pre[50005];
map<int,int>mp;
int a[50005];
int main()
{
    while(cin>>n)
    {
        mp.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            nex[i] = i+1;
            pre[i] = i-1;
        }
        pre[0] = -1;
        memset(dp,0x3f,sizeof(dp));
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            if(mp[a[i]]==0)
            {
                mp[a[i]] = i;
            }
            else
            {
                int id = mp[a[i]];
                nex[pre[id]] = nex[id];
                pre[nex[id]] = pre[id];
                mp[a[i]] = i;
            }
            int num = 0;
            for(int j=pre[i];j!=-1;j=pre[j])
            {
                num++;
                dp[i] = min(dp[i],dp[j]+num*num);
                if(num*num>i)break;
            }

        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
