#include<bits/stdc++.h>
using namespace std;

int vis[40][40][40];
char s[40][40][40];
int n,m,h;
int sx,sy,sz;
int tx,ty,tz;
int fx[6][3]={1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};
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
        for(int i=0;i<6;i++)
        {
            int x = a.x+fx[i][0],y = a.y+fx[i][1],z = a.z+fx[i][2];

            if(x>=0&&x<n&&y>=0&&y<m&&z>=0&&z<h&&!vis[x][y][z]&&s[z][x][y]!='#')
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
    while(~scanf("%d%d%d",&h,&n,&m),n+m+h)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%s",s[i][j]);
                for(int l=0;l<m;l++)
                {
                    if(s[i][j][l]=='S')
                    {
                        sx = j,sy = l,sz = i;
                    }
                    if(s[i][j][l]=='E')
                    {
                        tx = j,ty = l,tz = i;
                    }
                }
            }
        }

        int ans = bfs();
        if(ans==-1)printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",ans);
    }

    return 0;
}


//#include<bits/stdc++.h>
//using namespace std;
//
//int vis[10][10];
//int ans[10000][10];
//int cnt;
//int n;
//
//bool check(int h,int l)
//{
//    for(int i=0;i<h;i++)
//        if(vis[i][l])return false;
//    for(int i=h-1,j = l+1;i>=0&&j<n;i--,j++)
//    {
//        if(vis[i][j])return false;
//    }
//    for(int i=h-1,j = l-1;i>=0&&j>=0;i--,j--)
//    {
//        if(vis[i][j])return false;
//    }
//    return true;
//}
//
//
//void dfs(int h)
//{
//    if(h==n)
//    {
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                if(vis[i][j])
//                {
//                    ans[cnt][i] = j+1;
//                    break;
//                }
//            }
//        }
//        cnt++;
//        return ;
//    }
//    for(int i=0;i<n;i++)
//    {
//        if(check(h,i))
//        {
//            vis[h][i] = 1;
//            dfs(h+1);
//            vis[h][i] = 0;
//        }
//    }
//
//}
//
//int main()
//{
//    cin>>n;
//    cnt = 0;
//    memset(vis,0,sizeof(vis));
//    dfs(0);
//
//    cout<<cnt<<endl;
//    for(int i=0;i<cnt;i++)
//    {
//        for(int j=0;j<n;j++)
//        {
//            printf("%d ",ans[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}

