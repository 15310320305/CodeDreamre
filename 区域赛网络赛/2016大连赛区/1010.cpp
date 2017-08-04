
/** HDU5877   */

#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>

using namespace std;

#define lcr(a,b) memset(a,b,sizeof(a))
#define sfor(i,n) for(i=0;i<n;i++)
#define dfor(i,n) for(i=n-1;i>=0;i--)
#define sc(x) scanf("%d",&x)
#define pr(x) printf("%d\n",x)
#define ll long long
#define INF 1e18
#define esp 1e-8
const int maxn = 100500;
int n,e,q;
ll k,ans;
int a[maxn];
ll b[maxn];
int hed[maxn];
int vis[maxn];
int c[maxn<<1];
struct nood{
   int u,v,Next;
}nood[maxn<<1];
void addedge(int u,int v){
   nood[e].u=u,nood[e].v=v,nood[e].Next=hed[u],hed[u]=e++;
}

int lowbit(int x){return x&(-x);}
int getsum(int x){
    int res=0;
    while(x>0){
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
void updata(int x,int y){
     while(x<=q){
        c[x]+=y;
        x+=lowbit(x);
     }
}

void dfs(int v){
    ans+=(getsum(lower_bound(b,b+q,a[v]?k/a[v]:INF)-b+1));
    updata(lower_bound(b,b+q,a[v])-b+1,1);
    for(int i=hed[v];i!=-1;i=nood[i].Next)
        dfs(nood[i].v);
    updata(lower_bound(b,b+q,a[v])-b+1,-1);

}
int main()
{
     int t;cin>>t;
     while(t--){
        scanf("%d%I64d",&n,&k);
        q=0,e=1;
        ans=0;
        lcr(hed,-1);
        lcr(vis,0);
        lcr(c,0);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i])b[q++]=k/a[i];
            else b[q++]=INF;
        }
        sort(b,b+q);
        q=unique(b,b+q)-b;
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            vis[v]=1;
        }
        for(int i=1;i<=n;i++)
            if(!vis[i])dfs(i);
        printf("%I64d\n",ans);
     }
    return 0;
}
