#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdio>

using namespace std;

const int maxn = 1e4+20;
struct st{
    int v,w,nex;
}edge[maxn*10*2];

int n,m,e;
int dis[maxn],ans[maxn],hed[maxn],vis[maxn];
queue<int>q;

void add(int u,int v,int w){
    edge[e].v=v,edge[e].w=w,edge[e].nex=hed[u],hed[u]=e++;
}

void spfa(int s){
    for(int i=1;i<=maxn;i++){
        dis[i]=1e5;
    }
    dis[s]=1,vis[s]=1;
    if(ans[s]==-1)ans[s]=1;
    q.push(s);
    while(!q.empty()){
        int u = q.front();q.pop();vis[u]=0;
        for(int i=hed[u];~i;i=edge[i].nex){
            int v =edge[i].v;
            if(dis[v]>dis[u]+edge[i].w){
                dis[v]=dis[u]+edge[i].w;
                ans[v]=max(ans[v],dis[v]);
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }

    }
}

int main()
{
    int t;cin>>t;
    while(t--){
        scanf("%d%d",&n,&m);
        memset(hed,-1,sizeof(hed));
        memset(vis,0,sizeof(vis));
        memset(ans,-1,sizeof(ans));
        e=1;
        for(int i=1;i<=n;i++){
            int u,mu;scanf("%d%d",&u,&mu);
            for(int j=0;j<mu;j++){
                int v;scanf("%d",&v);
                add(u,v,1);
            }
        }
        while(m--){
            int nm;scanf("%d",&nm);
            while(nm--){
                int u;scanf("%d",&u);
                spfa(u);
            }

        }
        int id,Min=1e5;
        for(int i=1;i<maxn;i++){
            if(ans[i]!=-1){
                if(ans[i]<Min){
                    Min=ans[i],id=i;
                }
            }
        }
        printf("%d %d\n",Min,id);
    }

    return 0;
}
