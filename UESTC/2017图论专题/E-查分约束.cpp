#include<bits/stdc++.h>
using namespace std;
struct st
{
    int v,w,nex;
}edge[1100100],edge1[1100100];
int n,m,e,e1;
int vis[100005],hed[100005],hed1[100005],cnt[100005];
int ansMin[100005],ansMax[100005];
void add(int u,int v,int w)
{
    edge[e].v = v,edge[e].w = w,edge[e].nex = hed[u],hed[u] = e++;
}
void add1(int u,int v,int w)
{
    edge1[e1].v = v,edge1[e1].w = w,edge1[e1].nex = hed1[u],hed1[u] = e1++;
}

bool spfa()
{
    for(int i=0;i<=n;i++)
    {
        ansMin[i] = -1e9,vis[i] = 0,cnt[i] = 0;
    }
    ansMin[0] = 0;
    vis[0] = cnt[0]=1;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=hed[u];~i;i=edge[i].nex)
        {
            int v= edge[i].v;
            if(ansMin[v]<ansMin[u]+edge[i].w)
            {
                ansMin[v] = ansMin[u]+edge[i].w;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                    if(++cnt[v]>n)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
bool spfa1()
{
    for(int i=0;i<=n;i++)
    {
        ansMax[i] = 1e9,vis[i] = 0,cnt[i] = 0;
    }
    ansMax[0] = 0;
    vis[0] = cnt[0]=1;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=hed1[u];~i;i=edge1[i].nex)
        {
            int v= edge1[i].v;
            if(ansMax[v]>ansMax[u]+edge1[i].w)
            {
                ansMax[v] = ansMax[u]+edge1[i].w;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                    if(++cnt[v]>n)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    cin>>n>>m;
    memset(hed,-1,sizeof(hed));
    memset(hed1,-1,sizeof(hed1));
    e =e1 = 0;
    while(m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(v,u,w);
        add1(u,v,-w);
    }
    for(int i=1;i<=n;i++)
    {
        add(0,i,0);
        add1(0,i,100);
    }

    if(spfa())
    {
        if(spfa1())
        {
            for(int i=1;i<=n;i++)
            {
                printf("%d %d\n",ansMin[i],ansMax[i]);
            }
            return 0;
        }
    }
    cout<<-1<<endl;

    return 0;
}
