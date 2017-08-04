#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+50;
const int maxm = 1e6+100;
int x[maxm],y[maxm];
struct st
{
    int v,nex;
}edge[maxm],edge1[maxm];
int hed[maxn],vis[maxn],low[maxn],dfn[maxn],belon[maxn],Stack[maxn],size[maxn],dp1[maxn],dp2[maxn],hed1[maxn];
int n,m,e,e1,top,num,cnt;
void add(int u,int v)
{
    edge[e].v = v,edge[e].nex = hed[u],hed[u]= e++;
}
void add1(int u,int v)
{
    edge1[e1].v = v,edge1[e1].nex = hed1[u],hed1[u] =e1++;
}
void targan(int u)
{
    dfn[u] = low[u] = ++num;
    Stack[top++] = u;
    vis[u] = 1;
    for(int i=hed[u];~i;i=edge[i].nex)
    {
        int v = edge[i].v;
        if(!dfn[v])
        {
            targan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(vis[v])
        {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u])
    {
        cnt++;
        int x;
        do
        {
            x = Stack[--top];
            vis[x] = 0;
            belon[x] = cnt;
            size[cnt]++;
        }while(x!=u);
    }
}
queue<int>q;
void spfa()
{
    for(int i=1;i<=cnt;i++)
        dp1[i] = -1e9;
    int u = belon[1];
    dp1[u] = size[u];
    q.push(u);
    vis[u] = 1;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=hed[u];~i;i=edge[i].nex)
        {
            int v = edge[i].v;
            if(dp1[v]<dp1[u]+size[v])
            {
                dp1[v] = dp1[u]+size[v];
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
void spfa1()
{
    for(int i=1;i<=cnt;i++)
        dp2[i] = -1e9;
    int u = belon[1];
    dp2[u] = size[u];
    q.push(u);
    vis[u] = 1;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=hed1[u];~i;i=edge1[i].nex)
        {

            int v = edge1[i].v;
            if(dp2[v]<dp2[u]+size[v])
            {
                dp2[v] = dp2[u]+size[v];
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    memset(hed,-1,sizeof(hed));
    memset(hed1,-1,sizeof(hed1));
    memset(vis,0,sizeof(vis));
    memset(dfn,0,sizeof(dfn));
    memset(size,0,sizeof(size));
    top = num = cnt = e =e1= 0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        add(x[i],y[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])targan(i);
    }
    memset(hed,-1,sizeof(hed));
    memset(vis,0,sizeof(vis));
    e = 0;
    for(int i=0;i<m;i++)
    {
        int u = x[i],v = y[i];
        if(belon[u]!=belon[v])
        {
            add(belon[u],belon[v]);
            add1(belon[v],belon[u]);
        }
    }
    spfa();
    spfa1();
    int xx = size[belon[1]];
    int ans = xx;

    for(int i=0;i<m;i++)
    {
        int u = belon[x[i]],v = belon[y[i]];
        if(u!=v)
        {
            ans = max(ans,dp1[v]+dp2[u]-xx);
        }
    }
    cout<<ans<<endl;
    return 0;
}
