#include <cstdio>
#include <algorithm>
using namespace std;
int p[510000];
int r[510000];
int SUM[3100000];
void init(int n)
{
    for(int i=0;i<=n+10;i++)
    {
        p[i]=i;
        r[i]=1;
    }
}


struct node
{
    int u,v;
    int dis;
    int sum;
} e[101000];
int cmd(node X,node Y)
{
    return X.dis<Y.dis;
}
int Find(int x)
{
    if(x!=p[x])
        p[x]=Find(p[x]);
    return p[x];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        for(int i=0; i<m; i++)
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].dis);
        sort(e,e+m,cmd);
        init(n);
        int sum=0;
        for(int i=0; i<m;i++)
        {
            SUM[i] = e[i].dis;
            int XX=Find(e[i].u);
            int YY=Find(e[i].v);
            if(XX!=YY)
            {
                sum-=(r[XX]*(r[XX]-1));
                sum-=(r[YY]*(r[YY]-1));
                p[YY]=XX;
                r[XX]+=r[YY];

                sum+=(r[XX]*(r[XX]-1));
            }
           e[i].sum = sum;
        }
        while(q--)
        {
            int num;
            scanf("%d",&num);
            int x = upper_bound(SUM,SUM+m,num)-SUM-1;
            if(x>=0)
            printf("%d\n",e[x].sum);
            else printf("0\n");
        }
    }
    return 0;
}

