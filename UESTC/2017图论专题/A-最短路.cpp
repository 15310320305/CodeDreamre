#include<bits/stdc++.h>
using namespace std;
const int maxn = 2010;
struct st
{
    int v,w,nex;
}edge[10000];
int hed[maxn],vis[maxn],dis1[maxn],dis2[maxn],w[maxn];
int n,m,e;
void add(int u,int v,int ww)
{
    edge[e].v= v,edge[e].w = ww,edge[e].nex = hed[u],hed[u] = e++;
}

bool check(int Min,int Max)
{
    queue<int>q;
    for(int i=1;i<=n;i++)vis[i] = 0;
    q.push(1);
    vis[1] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=hed[u];~i;i=edge[i].nex)
        {
            int v = edge[i].v;
            if(!vis[v]&&edge[i].w>=Min&&edge[i].w<=Max)
            {
                q.push(v);
                if(v==n)return true;
                vis[v] = 1;
            }
        }
    }
    return false;
}

int main()
{
    memset(hed,-1,sizeof(hed));
    e = 1;
    cin>>n>>m;
    int mm = 0;
    while(m--)
    {
        int u,v,ww;scanf("%d%d%d",&u,&v,&ww);
        w[++mm] = ww;
        add(u,v,ww);
        add(v,u,ww);
    }
    sort(w+1,w+mm+1);
    int Min = 1e9;
    for(int i=mm;i>=1;i--)
    {
       int l = 1,r = i,mid,ans=0;
       while(l<=r)
       {
           mid = (l+r)>>1;
           if(check(w[mid],w[i]))
           {
               ans = mid;
               l = mid+1;
           }
           else r = mid-1;
       }
       if(ans)
       {
            Min = min(Min,w[i]-w[ans]);
       }
    }
    if(Min == 1e9)Min = 0;
    printf("%d\n",Min);

    return 0;
}



