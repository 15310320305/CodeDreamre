#include<bits/stdc++.h>
using namespace std;

int in[10005],vis[10005];
long long v[10005];
vector<int>G[10005];
int n,m;
int num;
long long ans,res;

void bfs(int u)
{

    queue<int>q;
    q.push(u);
    vis[u] = 1;
    num++;
    res+=v[u];
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int vv = G[u][i];
            if(vis[vv]==0)
            {
                vis[vv] = 1;
                res+=v[vv];
                num++;
                q.push(vv);
            }
        }
    }

}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        ans = 0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%lld",&v[i]),ans+=v[i],in[i] = 0,vis[i] = 0,G[i].clear();
        while(m--)
        {
            int u,v;scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
            in[u]++;
            in[v]++;
        }
        queue<int>q;
        for(int i=1;i<=n;i++)
        {
            if(in[i]==0)ans-=v[i],vis[i] = 1;
            else if(in[i]==1)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i=0;i<G[u].size();i++)
            {

                int vv = G[u][i];
                if(vis[vv]==0)
                {
                    in[vv]--;
                    if(in[vv]==1)
                    {
                        q.push(vv);
                        vis[vv] = 1;
                    }
                }
            }
        }
        ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                res = 0;
                num = 0;
                bfs(i);
                if(num%2==1)ans+=res;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
