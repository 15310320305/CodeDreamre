#include<bits/stdc++.h>

using namespace std;

int fx[8][2] = {1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
int ff[12][2] = {0,1,2,3,0,2,0,3,1,2,1,3,4,7,5,6,4,5,4,6,7,5,7,6};
int vis[101][101];
int point[102][102][8];
char mp[101][101];
int n,ans;
struct nod
{
    int f;
    int x,y;
    int len;
    nod(int x,int y,int len,int f):x(x),y(y),len(len),f(f){};
    nod(){};
};
queue<nod>q;

int dfs(int x,int y,int k)
{
    if(point[x][y][k])return point[x][y][k];

    int xx = x+fx[k][0];
    int yy = y+fx[k][1];
    if(xx>=0&&xx<n&&yy>=0&&yy<n&&mp[xx][yy]!='#')
    {
        return (point[xx][yy][k]=dfs(xx,yy,k))+1;
    }
    else return 1;

}

int main()
{
    while(~scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
            scanf("%s",mp[i]);
        memset(vis,0,sizeof(vis));
        memset(point,0,sizeof(point));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mp[i][j]!='#')
                for(int k=0;k<8;k++)
                {
                    if(point[i][j][k]==0)
                    {
                        point[i][j][k] = dfs(i,j,k);
                    }
                }
            }
        }
        ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mp[i][j]!='#')
                for(int k=0;k<12;k++)
                {
                    int ii = ff[k][0],jj = ff[k][1];
                    ans = max(ans,point[i][j][ii]+point[i][j][jj]-1);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


