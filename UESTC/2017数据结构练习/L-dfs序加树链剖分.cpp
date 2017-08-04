#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5+100;

int n,m,T;
int val[maxn];
//邻接表
struct st
{
    int v,nex;
}edge[maxn<<2];

int hed[maxn],e;

void add(int u,int v)
{
    edge[e].v = v,edge[e].nex = hed[u],hed[u] = e++;
}

//树链剖分

int Deep[maxn],Size[maxn],fa[maxn],Son[maxn],top[maxn],in[maxn],out[maxn],rk[maxn];
int tid;

void dfs1(int u,int f,int d)
{
    Deep[u] = d;
    fa[u] = f;
    Size[u] = 1;
    for(int i=hed[u];~i;i=edge[i].nex)
    {
        int v = edge[i].v;
        if(v!=f)
        {
            dfs1(v,u,d+1);
            Size[u]+=Size[v];
            if(Son[u]==-1||Size[v]>Size[Son[u]])
            {
                Son[u] = v;
            }
        }
    }
}


void dfs2(int u,int t)
{
    top[u] = t;
    in[u] = ++tid;  //开始的时间戳
    rk[tid] = u;
    if(Son[u]!=-1)
    {
        dfs2(Son[u],t);
        for(int i=hed[u];~i;i=edge[i].nex)
        {
            int v = edge[i].v;
            if(v!=Son[u]&&v!=fa[u])
                dfs2(v,v);
        }

    }
    out[u] = tid;   //结束的时间戳
}

//线段树
int Tree[maxn<<2],c[maxn<<2];

void Build(int l,int r,int rt)
{
    c[rt] = 0;
    if(l==r)
    {
        Tree[rt] = 0;
        return ;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    Tree[rt] = Tree[rt<<1]=Tree[rt<<1|1];
}

void pushdown(int rt,int m)
{
    if(c[rt])
    {
        c[rt<<1]+=c[rt];
        c[rt<<1|1]+=c[rt];
        Tree[rt<<1]+=(m-m/2)*c[rt];
        Tree[rt<<1|1]+=(m/2)*c[rt];
        c[rt] = 0;
    }

}

void updata(int L,int R,int l,int r,int rt,int v)
{
    if(L<=l&&r<=R)
    {
        c[rt]+=v;
        Tree[rt]+=(r-l+1)*v;

        return ;
    }
    pushdown(rt,r-l+1);
    int mid = (l+r)>>1;
    if(L<=mid)updata(L,R,l,mid,rt<<1,v);
    if(R>mid)updata(L,R,mid+1,r,rt<<1|1,v);
    Tree[rt] = Tree[rt<<1]+Tree[rt<<1|1];
}

int quary(int l,int r,int rt,int pos)
{
   if(l==r)
   {
       return Tree[rt];
   }
   pushdown(rt,r-l+1);
   int mid = (l+r)>>1;
   if(pos<=mid)return quary(l,mid,rt<<1,pos);
   else return quary(mid+1,r,rt<<1|1,pos);
}



//运行


void change(int x,int y,int v)
{
    while(top[x]!=top[y])
    {
        if(Deep[top[x]]<Deep[top[y]])swap(x,y);
        updata(in[top[x]],in[x],1,n,1,v);
        x = fa[top[x]];
    }
    if(Deep[x]>Deep[y])swap(x,y);
    updata(in[x],in[y],1,n,1,v);

}

void init()
{
    tid = e = 0;
    memset(hed,-1,sizeof(hed));
    memset(Son,-1,sizeof(Son));
}

int main()
{
    init();
    cin>>n>>m>>T;
    for(int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs1(T,T,1);
    dfs2(T,T);
    Build(1,n,1);
    while(m--)
    {
        int k;scanf("%d",&k);
        int a,b,c;
        if(k==1)
        {
            scanf("%d%d",&a,&b);
            updata(in[a],out[a],1,n,1,b);
        }
        else if(k==2)
        {
            scanf("%d%d%d",&a,&b,&c);
            change(a,b,c);
        }
        else
        {
            scanf("%d",&a);
            printf("%d\n",quary(1,n,1,in[a]));
        }
    }
    return 0;
}
