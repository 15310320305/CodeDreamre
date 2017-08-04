#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int dis[50005],vis[50005],a[2005];
int n;

void spfa()
{
    for(int i=0;i<=50005;i++)
        dis[i] = inf,vis[i] = 0;
    dis[0] =0,vis[0] = 1;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int u  = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=2;i<=n;i++)
        {
            int v = (u+a[i])%a[1];
            if(dis[v]>dis[u]+a[i])
            {
                dis[v] = dis[u]+a[i];
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
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    spfa();
    int q;cin>>q;
    while(q--)
    {
        int x;scanf("%d",&x);
        puts(dis[x%a[1]]<=x?"YES":"NO");
    }
    return 0;
}
