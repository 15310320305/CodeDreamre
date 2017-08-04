#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 1e5+10;

struct nod{
   int v,nex;
   long long w;
}edge[maxn<<1];

int n;
int hed[maxn],vis[maxn],e,dp[maxn];
long long ans;
void add(int u,int v,long long w){
   edge[e].v=v,edge[e].w=w,edge[e].nex = hed[u],hed[u]=e++;
}

void dfs(int u){
    dp[u]=1;
   for(int i=hed[u];~i;i=edge[i].nex){
        int v = edge[i].v;
        if(!vis[v]){
            vis[v]=1;
            dfs(v);
            dp[u]+=dp[v];
            ans+=(long long)min(dp[v],n-dp[v])*(edge[i].w*2ll);
        }
   }
}

int main()
{
    int t,T=1;cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            hed[i]=-1,vis[i]=0;
        e=1,ans=0;
        for(int i=0;i<n-1;i++){
            long long w;int u,v;scanf("%d%d%lld",&u,&v,&w);
            add(u,v,w);add(v,u,w);
        }
        vis[1]=1;
        dfs(1);
        printf("Case #%d: %lld\n",T++,ans);
    }

    return 0;
}
