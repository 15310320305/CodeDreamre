#include<bits/stdc++.h>

using namespace std;

struct st
{
    int v;
    int w;
    int nex;
}edge[3000];
int n,m,e,f;
int dis[40],vis[40],hed[40];
int ans;

void add(int u,int v,int w)
{
    edge[e].v = v,edge[e].w = w,edge[e].nex = hed[u],hed[u] =e++;
}

int spfa()
{
    for(int i=1;i<=n;i++)dis[i] = 1e9,vis[i] = 0;
    dis[1] = 0,vis[1] = 1;
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = hed[u];~i;i=edge[i].nex)
        {
            int v = edge[i].v;
            if(v==f)continue;
            if(dis[v]>dis[u]+edge[i].w)
            {
                dis[v] = dis[u]+edge[i].w;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis[n];
}

int main()
{
    while(~scanf("%d%d",&n,&m),n+m)
    {
        memset(hed,-1,sizeof(hed));
        e = 0;
        for(int i=0;i<m;i++)
        {
            int u,v,w;scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        ans = 0;
        for(f=2;f<n;f++)
        {
            int x = spfa();
            ans = max(ans,x);
        }
        if(ans!=1e9)
        {
            printf("%d\n",ans);
        }
        else printf("Inf\n");
    }

    return 0;
}
