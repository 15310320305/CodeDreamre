#include<bits/stdc++.h>

using namespace std;
int fx[4][2] = {1,0,-1,0,0,1,0,-1};
int vis[101][101][512];
char mp[101][101];
int ss[101][101];
int n,m;
int s1,t1,s2,t2;
struct st
{
    int now;
    int len;
    int x,y;
    int ss;
    st(int x,int y,int len,int now,int ss):x(x),y(y),len(len),now(now),ss(ss){}
    st(){}
    bool operator<(const st&a)const
    {
        return len>a.len;
    }
};

priority_queue<st>q;

int bfs()
{
    while(!q.empty())q.pop();
    q.push(st(s1,t1,0,0,0));
    while(!q.empty())
    {
        st a = q.top();
        q.pop();
        if(vis[a.x][a.y][a.now])continue;
        vis[a.x][a.y][a.now] = 1;
        //cout<<a.x<<" "<<a.y<<" "<<a.now<<" "<<a.len<<endl;
       // cout<<s2<<" "<<t2<<endl;
        if(a.x==s2&&a.y==t2&&a.now==((1<<m)-1))return a.len;

        for(int i=0;i<4;i++)
        {
            int xx = a.x+fx[i][0];
            int yy = a.y+fx[i][1];
            if(xx>=0&&xx<n&&yy>=0&&yy<n&&mp[xx][yy]!='#')
            {
                if(mp[xx][yy]>='1'&&mp[xx][yy]<='0'+m)
                {
                    int id = mp[xx][yy]-'1';
                    int flag = 1;
                    for(int j=0;j<id;j++)
                    {
                        if(((1<<j)&a.now)==0)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if((a.now&(1<<id))==0)
                    {
                        if(flag)
                            q.push(st(xx,yy,a.len+1,a.now|(1<<id),a.ss));
                        else
                            q.push(st(xx,yy,a.len+1,a.now,a.ss));
                    }
                    else q.push(st(xx,yy,a.len+1,a.now,a.ss));
                }
                else if(mp[xx][yy]=='S')
                {
                    int id = ss[xx][yy];
                    if((1<<id)&a.ss)
                    {
                        q.push(st(xx,yy,a.len+1,a.now,a.ss));
                    }
                    q.push(st(xx,yy,a.len+2,a.now,a.ss|(1<<id)));
                }
                else
                {
                    q.push(st(xx,yy,a.len+1,a.now,a.ss));
                }
            }
        }

    }
    return -1;

}

int main()
{
    while(~scanf("%d%d",&n,&m),n+m)
    {
        memset(vis,0,sizeof(vis));
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",mp[i]);
            for(int j=0;j<n;j++)
            {
                if(mp[i][j]=='K')s1 = i,t1 = j;
                if(mp[i][j]=='T')s2 = i,t2 = j;
                if(mp[i][j]=='S')
                {
                    ss[i][j]=cnt++;
                }
            }
        }
        int ans = bfs();
        if(ans!=-1)
            printf("%d\n",ans);
        else
            printf("impossible\n");
    }
    return 0;
}
