#include<bits/stdc++.h>
using namespace std;
int pre[100005],pre1[100005];
int f[25];
vector<int>G[100005];
int vis[100005];
int get(int x)
{
    if(x!=pre[x])return pre[x]=get(pre[x]);
    return pre[x];
}
int get1(int x)
{
    if(x!=pre1[x])return pre1[x]=get1(pre1[x]);
    return pre1[x];
}
int n,m,cnt;
void bfs()
{
    queue<int>q;
    q.push(1);
    vis[1] = 1;
    cnt++;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            if(!vis[v])
            {
                vis[v] = 1;
                q.push(v);
                cnt++;
            }
        }
    }
}
int main()
{

    f[1]  =1,f[2] = 2;
    for(int i=3;i<25;i++)
        f[i] = f[i-1]+f[i-2];
    int t;cin>>t;int T = 1;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            pre[i] = i,pre1[i]=i,vis[i]=0,G[i].clear();
        int W =0,B =0;
        while(m--)
        {
            int u,v,w;scanf("%d%d%d",&u,&v,&w);
            G[u].push_back(v);
            G[v].push_back(u);
          //  cout<<1<<endl;
            if(w==1)
            {
                W++;
                int uu = get1(u),vv = get1(v);
                if(uu!=vv)
                {
                    pre1[uu] = vv;
                }
                else
                {
                    W--;
                }
            }
            else
            {

                B++;
                int uu = get(u),vv = get(v);
               // cout<<uu<<" "<<vv<<endl;
                if(uu!=vv)
                {
                    pre[uu] = vv;
                }
                else
                {
                    B--;
                }
            }
        }
        cnt = 0;
        bfs();
        int flag = 0;
        if(cnt==n)
        for(int i=1;i<25;i++)
        {
            int w = f[i],b = n-1-f[i];
            if(w<=W&&w>=0&&b<=B&&b>=0)
            {
                flag = 1;
                break;
            }
        }
        printf("Case #%d: ",T++);
        if(flag)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
