#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn = 805;

int n,m,e;

struct nod{
  int id,dj;
}ans[maxn];

int hed[maxn],pnt[maxn],nex[maxn],num[maxn];

void addedge(int u,int v){
    pnt[e]=v,nex[e]=hed[u],hed[u]=e++;
}

bool cmp(nod a,nod b){return a.dj<b.dj;}

void topsort(){
    priority_queue<int,vector<int> ,greater<int> >q;
    for(int i=1;i<=n;i++)
        if(!num[i])q.push(i);
    int x=0;
    while(!q.empty()){
        int u=q.top();
        q.pop();
        ans[x].id=u;
        ans[x].dj=++x;
        for(int i=hed[u];~i;i=nex[i]){
            int v=pnt[i];
            if(--num[v]==0){
                q.push(v);
            }
        }
    }
    sort(ans,ans+x,cmp);
}

int main()
{
    while(cin>>n>>m){
        memset(num,0,sizeof(num));
        memset(hed,-1,sizeof(hed));
        e=0;
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            num[v]++;
        }
        topsort();
        for(int i=0;i<n-1;i++)
            printf("%d ",ans[i].id);
        printf("%d\n",ans[n-1].id);
    }
    return 0;
}
