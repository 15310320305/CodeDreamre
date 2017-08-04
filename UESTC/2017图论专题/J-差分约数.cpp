#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct st
{
    int v,w,nex;
}edge[100000];
int n,p,q,s,t,e;
int dis[505],vis[505],cnt[505],hed[505];
void add(int u,int v,int w)
{
    edge[e].v = v,edge[e].w = w,edge[e].nex = hed[u],hed[u] = e++;
}

bool spfa()
{
    queue<int>q;
    for(int i=0;i<=n+1;i++)
        dis[i] = inf,vis[i] = 0,cnt[i] = 0;
    dis[n+1] = 0,vis[n+1] = cnt[n+1] = 1;
    q.push(n+1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=hed[u];~i;i=edge[i].nex)
        {
            int v = edge[i].v;
            if(dis[v]>dis[u]+edge[i].w)
            {
                dis[v] = dis[u] +edge[i].w;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                    cnt[v]++;
                    if(cnt[v]>n+1)return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
    cin>>n>>p>>q>>s>>t;
    e = 0;memset(hed,-1,sizeof(hed));
    for(int i=p;i<=n;i++)add(i,i-p,-s);
    for(int i=q;i<=n;i++)add(i-q,i,t);
    for(int i=0;i<=n;i++)add(n+1,i,0);
    if(!spfa())
    {
        printf("No\n");
        return 0;
    }
    int sum[505];
    for(int i=1;i<=n;i++)
        sum[i] = dis[i]-dis[0];
    puts("Yes");
    sum[0] = 0;
    for(int i=1;i<=n;i++)
    {
        printf("%d%c",sum[i]-sum[i-1],i==n?'\n':' ');
    }
    return 0;
}
