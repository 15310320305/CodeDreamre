/** 杭电3938 离线并查集   */

#pragma comment(linker, "/STACK:1024000000,1024000000")
#include"stdio.h"
#include"string.h"
#include"iostream"
#include"map"
#include"string"
#include"queue"
#include"stdlib.h"
#include"math.h"
#include"algorithm"
#include"vector"
#define M 100009
#define eps 1e-10
#define inf 1000000000
#define mod 1000000000
#define INF 1000000000
using namespace std;
struct node
{
    int u,v,w;
}e[M*5],q[M];
int f[M],h[M];
__int64 sum,ans[M];
int cmp(node a,node b)
{
    return a.w<b.w;
}
int finde(int x)
{
    if(x!=f[x])
        f[x]=finde(f[x]);
    return f[x];
}
void make(int a,int b)
{
    int x=finde(a);
    int y=finde(b);
    if(x==y)return;
    else if(x>y)
    {
        f[x]=y;
        int tt=h[y];
        h[y]+=h[x];
        sum+=h[y]*(h[y]-1)/2-h[x]*(h[x]-1)/2-tt*(tt-1)/2;
    }
    else
    {
        f[y]=x;
        int tt=h[x];
        h[x]+=h[y];
        sum+=h[x]*(h[x]-1)/2-h[y]*(h[y]-1)/2-tt*(tt-1)/2;
    }
}
int main()
{
    int n,m,k,i;
    while(scanf("%d%d%d",&n,&m,&k)!=-1)
    {
        for(i=0;i<m;i++)
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        sort(e,e+m,cmp);
        for(i=0;i<k;i++)
        {
            scanf("%d",&q[i].w);
            q[i].u=i;
        }
        sort(q,q+k,cmp);
        for(i=1;i<=n;i++)
        {
            f[i]=i;h[i]=1;
        }
        sum=0;
        int j=0;
        for(i=0;i<k;i++)
        {
            while(j<m&&e[j].w<=q[i].w)
            {
                make(e[j].u,e[j].v);
                j++;
            }
            ans[q[i].u]=sum;
        }
        for(i=0;i<k;i++)
            printf("%I64d\n",ans[i]);
    }
    return 0;
}
