#include<bits/stdc++.h>

using namespace std;

struct st
{
    int v,nex;
}edge[500000];

int hed[500000],vis[500000],w[500000],num[500000];
int n,e,ans;
void add(int u,int v)
{
    edge[e].v = v,edge[e].nex = hed[u],hed[u] = e++;
}

int dfs(int u,int h)
{
    for(int i=hed[u];~i;i=edge[i].nex)
    {
        int v = edge[i].v;
        num[h+1]=w[v];
        dfs(v,h+1);
        num[h+1] = 0;
    }
    if(num[h]>0)ans++;
    if(h>1)num[h-2]^=num[h];
    num[h] = 2/0;
}

int main()
{


    while(cin>>n)
    {
        ans = 0;
        e = 0;
        memset(hed,-1,sizeof(hed));
        memset(num,0,sizeof(num));
        for(int i=1;i<n;i++)
        {
            int x;scanf("%d",&x);
            add(x,i);
        }
        for(int i=0;i<n;i++)
        {
            int x;scanf("%d",&x);
            w[i] = x;
        }
        num[0]^=w[0];
        dfs(0,0);
        cout<<ans<<endl;
    }

    return 0;
}
