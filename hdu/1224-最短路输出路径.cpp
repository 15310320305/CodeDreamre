#include<iostream>
#include<cstdio>
#define min(x,y) (x<y?x:y)

using namespace std;

const int maxn = 105;
const int inf = 1e8;

class pathFloyd{
public:

    int n;
    int dis[maxn][maxn],path[maxn][maxn],w[maxn];

    void init(){
        int t;cin>>t;int T=1;
        while(t--){
            scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&w[i]);
            w[n+1]=0;
            int m;scanf("%d",&m);
            for(int i=1;i<=n+1;i++)
            for(int j=1;j<=n+1;j++){
                path[i][j]=j;
                dis[i][j]=-1;
            }
            while(m--){
                int u,v;scanf("%d%d",&u,&v);
                dis[u][v]=w[v];
            }
            floyd();
            if(T>1)printf("\n");
            cout<<"CASE "<<T++<<"#"<<endl;
            output(1,n+1);
        }
    }

    void floyd(){
        for(int k=1;k<=n+1;k++)
            for(int i=1;i<=n+1;i++)if(i!=k)
                for(int j=1;j<=n+1;j++)if(j!=i&&j!=k){
                    if(dis[i][j]<dis[i][k]+dis[k][j]&&dis[i][k]>=0&&dis[k][j]>=0){
                        dis[i][j]=dis[i][k]+dis[k][j];
                        path[i][j]=path[i][k];
                    }
                }

    }

    void output(int s,int t){
        printf("points : %d\ncircuit : %d",dis[s][t],s);
        int nex = path[s][t];
        while(nex!=t)printf("->%d",nex),nex = path[nex][t];
        printf("->1\n");
    }

}pf;

int main()
{
    pf.init();
    return 0;
}
