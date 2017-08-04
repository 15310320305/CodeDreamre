#include<bits/stdc++.h>
#define inf 1e18
using namespace std;
const int maxn = 1e6+1e5+100;
struct st
{
    int v,nex;
    long long w;
}edge[maxn<<1];
long long dis[2][maxn];
int hed[maxn];
bool vis[maxn];
int n,m,e;
void add(int u,int v,long long w)
{
    edge[e].v = v,edge[e].w = w,edge[e].nex = hed[u],hed[u] = e++;
}

void spfa(int u,int id)
{
    for(int i=1;i<=n;i++)
        dis[id][i] = inf,vis[i] = 0;
    vis[u] = 1;
    dis[id][u] = 0;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=hed[u];~i;i=edge[i].nex)
        {
            int v = edge[i].v;
            if(dis[id][v]>dis[id][u]+edge[i].w)
            {
                dis[id][v] = dis[id][u]+edge[i].w;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
int N;
int ans[100005];
int cnt = 0;
int main()
{
    int t;cin>>t;int T = 1;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        N = n;
        memset(hed,-1,sizeof(hed));
        e = 1;
        while(m--)
        {
            long long t;
            int s;
            scanf("%lld%d",&t,&s);
            ++n;
            while(s--)
            {
                int x;scanf("%d",&x);
                add(x,n,t);
                add(n,x,t);
            }
        }
        spfa(1,0);
        spfa(N,1);
        cnt = 0;
        long long Min = 2e18;
        for(int i=1;i<=N;i++)
        {
            long long Max = max(dis[0][i],dis[1][i]);
            if(Max!=inf)
            {
                if(cnt==0)
                {
                    Min = Max;
                    ans[cnt++] = i;
                }
                else
                {
                    if(Max==Min)
                    {
                        ans[cnt++] = i;
                    }else if(Min>Max)
                    {
                        Min = Max;
                        cnt = 0;
                        ans[cnt++] = i;
                    }
                }
            }
        }
        printf("Case #%d: ",T++);
        if(cnt==0)
        {
            printf("Evil John\n");
        }
        else
        {
            printf("%lld\n",Min/2ll);
            for(int i=0;i<cnt;i++)
            {
                printf("%d%c",ans[i],i==cnt-1?'\n':' ');
            }
        }
    }
    return 0;
}
