#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int inf = 1e8;
int dis[205][205],ans[205];
int n,m;
int s,e;

void dij(){
    int vis[205];
    for(int i=1;i<=n;i++)
        ans[i]=inf,vis[i]=0;
    vis[s]=1;
    ans[s]=0;
    for(int i=1;i<=n;i++){
        int to=s,v=inf;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&v>ans[j]){
                v=ans[j];
                to=j;
            }
        }
        vis[to]=1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&ans[j]>dis[to][j]+ans[to]){
                ans[j]=dis[to][j]+ans[to];
            }
        }

    }

}

int main()
{
    while(cin>>n&&n){
        scanf("%d%d",&s,&e);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
              if(i!=j)dis[i][j]=inf;
              else dis[i][j]=0;
        int k[205];
        for(int i=1;i<=n;i++)scanf("%d",&k[i]);
        for(int i=1;i<=n;i++){
            if(i+k[i]<=n&&k[i])dis[i][i+k[i]]=1;
            if(i-k[i]>=1&&k[i])dis[i][i-k[i]]=1;
        }
        dij();
        if(ans[e]==inf)cout<<-1<<endl;
        else cout<<ans[e]<<endl;
    }

    return 0;
}
