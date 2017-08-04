#include<iostream>
#include<cstdio>
#define min(x,y) (x<y?x:y)

using std::cin;

const int maxn = 50;
const int inf = 1e8;

class pathFloyd{
public:

    int n;
    int dis[maxn][maxn],path[maxn][maxn],w[maxn];

    void init(){
        while(cin>>n,n){
            for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
                scanf("%d",&dis[i][j]);path[i][j]=j;
                if(dis[i][j]==-1)dis[i][j]=inf;
            }
            for(int i=1;i<=n;i++)scanf("%d",&w[i]);
            floyd();
            int u,v;while(cin>>u>>v,u!=-1)output(u,v);
        }
    }

    void floyd(){
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)if(i!=k)
                for(int j=1;j<=n;j++)if(j!=i&&j!=k){
                    if(dis[i][j]>dis[i][k]+dis[k][j]+w[k]){
                        dis[i][j]=dis[i][k]+dis[k][j]+w[k];
                        path[i][j]=path[i][k];
                    }else if(dis[i][j]==dis[i][k]+dis[k][j]+w[k]){
                        path[i][j]=min(path[i][j],path[i][k]);
                     }
                }

    }

    void output(int s,int t){
        printf("From %d to %d :\nPath: %d",s,t,s);int nex=s;
        while(s!=t){printf("-->%d",path[s][t]);s=path[s][t];}
        printf("\nTotal cost : %d\n\n",dis[nex][t]);
    }

}pf;

int main()
{
    pf.init();
    return 0;
}
