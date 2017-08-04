#include<bits/stdc++.h>
using namespace std;

double dp[30005][2];
int n,m,k,p;
struct st
{
    int a,b;
}s[105];

bool cmp(st aa,st bb)
{
    if(aa.b==bb.b)return aa.a<bb.a;
    return aa.b<bb.b;
}

int main()
{
    cin>>m>>k>>n>>p;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<k;i++)
        scanf("%d%d",&s[i].a,&s[i].b);
    sort(s,s+k,cmp);
    dp[p][0] = 1.0;
    int f = 0,ii=0;
    double ans = 0;
    for(int i=0;i<=n;i++)
    {
        while(ii<k&&s[ii].b==i)dp[s[ii].a][f]=0,ii++;
        if(i==n)
        {
            for(int j=1;j<=m;j++)
            {
                ans+=dp[j][f];
            }
            break;
        }
        for(int j=1;j<=m;j++)
        {
            if(j==1&&m>1)dp[j][f^1]+=dp[j][f]/2.0,dp[j+1][f^1]+=dp[j][f]/2.0,dp[j][f] = 0;
            else if(j==m&&m>1)dp[j][f^1]+=dp[j][f]/2.0,dp[j-1][f^1]+=dp[j][f]/2.0,dp[j][f] = 0;
            else if(j!=1&&j!=m&&m>2)
            {
                dp[j][f^1]+=dp[j][f]/3.0,dp[j+1][f^1]+=dp[j][f]/3.0;
                dp[j-1][f^1]+=dp[j][f]/3.0,dp[j][f] = 0;
            }
            else
            {
                dp[j][f^1]+=dp[j][f];
                dp[j][f] = 0;
            }
        }
        f^=1;
    }
    printf("%.6lf\n",ans);

    return 0;
}
