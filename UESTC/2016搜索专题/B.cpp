#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
int vis[maxn][maxn][4][2];
char mp[maxn][maxn];
int n,m;
int fx[4][2][2] = {0,1,1,0,-1,0,0,1,0,-1,-1,0,1,0,0,-1};

int dfs(int x,int y,int k,int f)
{
    int xx = x+fx[k][f][0],yy = y+fx[k][f][1];
    if(xx>=0&&xx<n&&yy>=0&&yy<m&&mp[xx][yy]=='1')
    {
        f^=1;
        if(vis[xx][yy][k][f]!=-1)
        {
            return 1+vis[xx][yy][k][f];
        }
        else
        {
            return (vis[xx][yy][k][f] = dfs(xx,yy,k,f))+1;
        }
    }
    else
    {
        return 1;
    }
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        memset(vis,-1,sizeof(vis));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",mp[i]);
        int Max = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum = 0;
                if(mp[i][j]=='1')
                {
                    for(int k=0;k<4;k++)
                    {
                        if(vis[i][j][k][0]!=-1)
                        {
                            sum+=vis[i][j][k][0];
                        }
                        else sum+=(vis[i][j][k][0]=dfs(i,j,k,0));
                    }
                    sum-=3;
                    Max = max(Max,sum);
                }
            }
        }
        printf("%d\n",Max);
    }
    return 0;
}
