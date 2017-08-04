#include<bits/stdc++.h>

using namespace std;

map<string,int>mp;
int cnt;
int n,m;
const int maxn = 1e5+100;
const long long inf = 1e18;
struct st
{
    int v,nex;
    long long w;
}edge[maxn<<2];
int hed[maxn],e;
int vis[maxn];
long long dis[maxn];
void add(int u,int v,long long w)
{
    edge[e].v = v,edge[e].w = w,edge[e].nex = hed[u],hed[u] = e++;
}

long long spfa(int uu,int vv)
{
    queue<int>q;
    q.push(uu);
    for(int i=1;i<=cnt;i++)
        dis[i] = inf,vis[i] = 0;
    vis[uu] = 1,dis[uu] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=hed[u];~i;i = edge[i].nex)
        {
            int v = edge[i].v;
            if(dis[v]>dis[u]+edge[i].w)
            {
                dis[v] = dis[u] +edge[i].w;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }

    }
    if(dis[vv]==inf||dis[vv]==0)dis[vv] = -1;
    return dis[vv];

}

int main()
{
    cin>>n>>m;
    cnt = 0;
    memset(hed,-1,sizeof(hed));
    e = 1;
    while(m--)
    {
        char s1[30],s2[30];
        int u,v;
        long long w;
        scanf("%s%s%lld",s1,s2,&w);
        if(mp[s1])u = mp[s1];
        else u = ++cnt,mp[s1] = u;

        if(mp[s2])v = mp[s2];
        else v = ++cnt,mp[s2] = v;

        add(u,v,w);
    }
    string ss,tt;
    for(int i=0;i<n;i++)
        ss+='0',tt+='1';
    printf("%lld\n",spfa(mp[ss],mp[tt]));

    return 0;
}
