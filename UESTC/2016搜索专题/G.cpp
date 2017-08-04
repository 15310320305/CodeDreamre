#include<bits/stdc++.h>
using namespace std;

int vis[55][55][55];
char s[55][55][55];
int n,m,h;
int sx,sy,sz;
int tx,ty,tz;
int fx[4][2]={1,0,-1,0,0,1,0,-1};
struct nod
{
    int x,y,z;
    int len;
    nod()
    {
        len = 0;
    }
    nod(int x,int y,int z,int len):x(x),y(y),z(z),len(len){}
};
int bfs()
{
    queue<nod>q;
    q.push(nod(sx,sy,sz,0));
    vis[sx][sy][sz] = 1;
    while(!q.empty())
    {
        nod a = q.front();
        q.pop();

        if(s[a.z][a.x][a.y]=='D'&&s[a.z-1][a.x][a.y]!='x')
        {
            if(!vis[a.x][a.y][a.z-1])
            {
                vis[a.x][a.y][a.z-1] = 1;
                q.push(nod(a.x,a.y,a.z-1,a.len+1));
                if(a.x==tx&&a.y==ty&&a.z-1==tz)return a.len+1;
            }
        }
        else if(s[a.z][a.x][a.y]=='U'&&s[a.z+1][a.x][a.y]!='x')
        {
            if(!vis[a.x][a.y][a.z+1])
            {
                vis[a.x][a.y][a.z+1] = 1;
                q.push(nod(a.x,a.y,a.z+1,a.len+1));
                if(a.x==tx&&a.y==ty&&a.z+1==tz)return a.len+1;
            }
        }

        for(int i=0;i<4;i++)
        {
            int x = a.x+fx[i][0],y = a.y+fx[i][1],z = a.z;

            if(x>=0&&x<n&&y>=0&&y<m&&z>=0&&z<h&&!vis[x][y][z]&&s[z][x][y]!='x')
            {
                vis[x][y][z] = 1;
                q.push(nod(x,y,z,a.len+1));
                if(x==tx&&y==ty&&z==tz)return a.len+1;
            }
        }
    }
    return -1;
}

int main()
{
    while(~scanf("%d%d%d",&h,&n,&m))
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%s",s[i][j]);
                for(int l=0;l<m;l++)
                {
                    if(s[i][j][l]=='X')
                    {
                        sx = j,sy = l,sz = i;
                    }
                    if(s[i][j][l]=='Y')
                    {
                        tx = j,ty = l,tz = i;
                    }
                }
            }
        }
        int ans = bfs();
        printf("%d\n",ans);
    }

    return 0;
}
