#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 2e5+100;

/** 邻接表部分  */

struct st
{
    int v,nex;
}edge[maxn<<1];

int head[maxn],e;

void add(int u,int v)
{
    edge[e].v = v,edge[e].nex = head[u],head[u]=e++;
}

/**  树链剖分部分   */

int fa[maxn],dep[maxn],siz[maxn],top[maxn],son[maxn],pos[maxn],rak[maxn],val[maxn];;
int tim;

void dfs(int u,int pr,int d)
{
    siz[u] = 1,dep[u]=d,fa[u] = pr;
    for(int i = head[u];~i;i=edge[i].nex)
    {
        int v = edge[i].v;
        if(v==pr)continue;
        dfs(v,u,d+1);
        siz[u]+=siz[v];
        if(son[u]==-1||siz[son[u]]<siz[v])
            son[u]=v;
    }
}

void create(int u,int tp)
{
    top[u] = tp;
    pos[u] = ++tim;
    rak[pos[u]] = u;
    if(son[u]==-1)return ;
    create(son[u],tp);
    for(int i=head[u];~i;i=edge[i].nex)
    {
        int v = edge[i].v;
        if(v != fa[u]&&v != son[u])create(v,v);
    }
}

/**  线段树部分  */

struct nod
{
    int l,r;
    int sum,c;
}node[maxn<<3];

void pushdown(int rt,int m)
{
    node[rt<<1].c+=node[rt].c;
    node[rt<<1|1].c+=node[rt].c;

    node[rt<<1].sum+=node[rt].c*(m-m/2);
    node[rt<<1|1].sum+=node[rt].c*(m/2);

    node[rt].c = 0;
}

void pushup(int rt)
{
    node[rt].sum = node[rt<<1].sum+node[rt<<1|1].sum;
}

void BuildTree(int l,int r,int rt)
{
    node[rt].l = l,node[rt].r = r,node[rt].c =0;
    if(l==r)
    {
        node[rt].sum = val[rak[l]];
        return ;
    }
    int mid = (l+r)>>1;
    BuildTree(l,mid,rt<<1);
    BuildTree(mid+1,r,rt<<1|1);
    pushup(rt);
}

void update(int l,int r,int rt,int w)
{
    if(l<=node[rt].l&&r>=node[rt].r)
    {
        node[rt].sum+=(node[rt].r-node[rt].l+1)*w;
        node[rt].c+=w;
        return ;
    }
    if(node[rt].c)pushdown(rt,node[rt].r-node[rt].l+1);
    int mid = (node[rt].l+node[rt].r)>>1;
    if(l<=mid)update(l,r,rt<<1,w);
    if(r>mid)update(l,r,rt<<1|1,w);
    pushup(rt);
}

int quary(int L,int R,int l,int r,int rt)
{
    if(r<L||l>R)return 0;
    if(L<=l&&R>=r)return node[rt].sum;
    int mid = (l+r)>>1;

    if(node[rt].c)pushdown(rt,r-l+1);
    return quary(L,R,l,mid,rt<<1)+quary(L,R,mid+1,r,rt<<1|1);

}

/**  运行部分   */
int n,m,p;
int len;
void change(int x,int y,int w)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        update(pos[top[x]],pos[x],1,w);
        x = fa[top[x]];

    }
    if(dep[x]>dep[y])swap(x,y);
    update(pos[x],pos[y],1,w);
}

int SUM(int x,int y)
{
    len = 0;
    int sum = 0;
    while(top[x]!=top[y])
    {

        if(dep[top[x]]<dep[top[y]])swap(x,y);
        sum+=quary(pos[top[x]],pos[x],1,n,1);
        len+=abs(dep[x]-dep[fa[top[x]]]);
        x = fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    len+=dep[y]-dep[x]+1;
    sum+=quary(pos[x],pos[y],1,n,1);
    return sum;

}

void init()
{
    tim = e = 0;
    memset(head,-1,sizeof(head));
    memset(son,-1,sizeof(son));
}

void sove()
{
    for(int i=1;i<=n;i++)val[i] = 1;
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1,1,1);
    create(1,1);
    BuildTree(1,n,1);
    while(p--)
    {
        int s;
        int x,y,w;
        scanf("%d",&s);
        if(s==1)
        {
            scanf("%d%d",&x,&y);
            int xx = SUM(x,y);
            if(xx==len)printf("YES\n");
            else printf("NO\n");
        }
        else if(s==2)
        {
            scanf("%d",&x);
            change(x,x,1);
        }
        else
        {
            scanf("%d",&x);
            change(x,x,-1);
        }
    }
}

int main()
{
    scanf("%d%d",&n,&p);
    init();
    sove();
    return 0;
}
