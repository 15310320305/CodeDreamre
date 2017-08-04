#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 5e2+10;

const int inf = 1e9;

int mp[maxn][maxn],dp[maxn][maxn];
int n,m,s0,e0,s1,e1;

void floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(mp[i][j]>mp[i][k]+mp[k][j]){
                    mp[i][j]=mp[i][k]+mp[k][j];
                    dp[i][j]=dp[i][k]+dp[k][j]-1;
                }else if(mp[i][j]==mp[i][k]+mp[k][j]&&dp[i][j]<dp[i][k]+dp[k][j]){
                    dp[i][j]=dp[i][k]+dp[k][j]-1;
                }
            }
}

void sove(){
    int ans = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(mp[s0][i]+mp[i][j]+mp[j][e0]==mp[s0][e0]&&mp[s1][i]+mp[i][j]+mp[j][e1]==mp[s1][e1])
                ans=max(dp[i][j],ans);
        }
    printf("%d\n",ans);
}

int main()
{
    while(scanf("%d%d",&n,&m),n+m){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j)mp[i][j]=inf,dp[i][j]=2;
                else mp[i][j]=0,dp[j][j]=1;
        while(m--){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            mp[u][v]=mp[v][u]=min(mp[u][v],w);
        }
        scanf("%d%d%d%d",&s0,&e0,&s1,&e1);
        floyd();
        sove();
    }

    return 0;
}
