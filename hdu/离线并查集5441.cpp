/** 计算客 热身赛  离线并查集   杭电5441    */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
using namespace std;
const int N = 50005;
const int inf = 1000000000;
const int mod = 2009;
struct edge
{
    int a,b,d;
}e[50005];
bool cmp1(edge x,edge y)
{
    return x.d<y.d;
}
struct berserk
{
    int v,id;
}x[50005];

bool cmp2(berserk x,berserk y)
{
    return x.v<y.v;
}
int s[N],w[N],ans[50005];
int fun(int x)
{
	if(s[x]!=x)
		s[x]=fun(s[x]);
	return s[x];
}
int main()
{
    int t,n,m,q,i,j,a,b,d,c,u,v;
    while(~scanf("%d%d%d",&n,&m,&q))
    {

        for(i=1;i<=n;i++)
            s[i]=i,w[i]=1;
        for(i=0;i<m;i++)
            scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].d);
        sort(e,e+m,cmp1);
        for(i=0;i<q;i++)
        {
            scanf("%d",&x[i].v);
            x[i].id=i;
        }
        sort(x,x+q,cmp2);
        for(i=j=c=0;i<q;i++)
        {
            for(;j<m&&e[j].d<=x[i].v;j++)
            {
                u=fun(e[j].a);
                v=fun(e[j].b);
                if(u!=v)
                {
                    c-=w[u]*(w[u]-1)+w[v]*(w[v]-1);
                    w[v]+=w[u];
                    w[u]=0;
                    c+=w[v]*(w[v]-1);
                    s[u]=v;
                }
            }
            ans[x[i].id]=c;
        }
        for(i=0;i<q;i++)
            printf("%d\n",ans[i]/2);
    }
    return 0;
}
