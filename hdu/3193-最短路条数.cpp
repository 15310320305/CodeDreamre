#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 1e3+10;
const int inf = 1e9;

class Edge{
public:
    int v,w,nex;
};

class num_Shortpath{
public:
    int n,m,e;
    int dis[maxn][2], cnt[maxn][2],vis[maxn][2],hed[maxn];
    Edge edge[maxn*maxn];

    queue<pair<int,int> >q;

    void add(int u,int v,int w){
        edge[e].v=v,edge[e].w=w,edge[e].nex=hed[u],hed[u]=e++;
    }

    void init(){
        int s0,e0;
        while( ~scanf("%d%d%d%d",&n,&m,&s0,&e0)){
            s0++,e0++;
            for(int i=1;i<=n;i++)hed[i]=-1,vis[i][0]=vis[i][1]=0;e=1;
            for(int i=0;i<m;i++){
                 int u,v,w;scanf("%d%d%d",&u,&v,&w);
                 u++,v++;
                 add(u,v,w);
            }
            spfa(s0);
            printf("%d %d\n",dis[e0][1],cnt[e0][1]);
        }
    }

    void spfa(int u){
        for(int i=1;i<=n;i++){
            dis[i][0]=inf,cnt[i][1]=0;
            dis[i][1]=inf,cnt[i][1]=0;
            vis[i][0]=vis[i][1]=0;
        }
        dis[u][0]=0,cnt[u][0]=1;
        q.push(make_pair(u,0));
        while(!q.empty()){
            int to = q.front().first,flag = q.front().second;q.pop();
            if(vis[to][flag])continue;
            vis[to][flag]=1;
            for(int i=hed[to];~i;i=edge[i].nex){
                int j = edge[i].v;
                int tmp = dis[to][flag]+edge[i].w;
                if(dis[j][0]>tmp){
                    if(dis[j][0]!=inf){
                    dis[j][1]=dis[j][0];
                    cnt[j][1]=cnt[j][0];
                    q.push(make_pair(j,1));
                    }
                    dis[j][0]=tmp;
                    cnt[j][0]=cnt[to][flag];
                    q.push(make_pair(j,0));
                }
                else if(dis[j][0]==tmp){
                    cnt[j][0]+=cnt[to][flag];
                }
                else if(dis[j][1]>tmp){
                    dis[j][1]=tmp;
                    cnt[j][1]=cnt[to][flag];
                    q.push(make_pair(j,1));
                }
                else if(dis[j][1]==tmp){
                    cnt[j][1]+=cnt[to][flag];
                }
            }
        }
    }

}ns;

int main()
{
    ns.init();
    return 0;
}
