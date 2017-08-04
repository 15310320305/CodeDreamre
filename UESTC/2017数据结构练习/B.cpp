/**
CDOJ1592 线段树区间合并模板题  HDU3911
*/


#include<bits/stdc++.h>
using namespace std;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define Max(a,b) (a)>(b)?(a):(b)
#define Min(a,b) (a)<(b)?(a):(b)
const int maxn = 1e5+100;

struct ST
{
    int lone,rone,lzero,rzero,sumone,sumzero;
    int cover;
    int l,r;
}Tree[maxn<<2];

int n;


//向上更新
void push_up(int rt)
{
    Tree[rt].lone = Tree[rt<<1].lone;
    Tree[rt].lzero = Tree[rt<<1].lzero;


    //子区间填满
    if(Tree[rt<<1].lone==Tree[rt<<1].r-Tree[rt<<1].l+1)Tree[rt].lone+=Tree[rt<<1|1].lone;
    if(Tree[rt<<1].lzero==Tree[rt<<1].r-Tree[rt<<1].l+1)Tree[rt].lzero+=Tree[rt<<1|1].lzero;

    Tree[rt].rone = Tree[rt<<1|1].rone;
    Tree[rt].rzero = Tree[rt<<1|1].rzero;

    if(Tree[rt<<1|1].rone==Tree[rt<<1|1].r-Tree[rt<<1|1].l+1)Tree[rt].rone+=Tree[rt<<1].rone;
    if(Tree[rt<<1|1].rzero==Tree[rt<<1|1].r-Tree[rt<<1|1].l+1)Tree[rt].rzero+=Tree[rt<<1].rzero;

    Tree[rt].sumone = max(Tree[rt<<1].rone+Tree[rt<<1|1].lone,max(Tree[rt<<1].sumone,Tree[rt<<1|1].sumone));
    Tree[rt].sumzero = max(Tree[rt<<1].rzero+Tree[rt<<1|1].lzero,max(Tree[rt<<1].sumzero,Tree[rt<<1|1].sumzero));
}

void Build(int l,int r,int rt)
{
    Tree[rt].l = l,Tree[rt].r = r,Tree[rt].cover = 0;
    if(l==r)
    {
        int x;scanf("%d",&x);
        Tree[rt].lone = Tree[rt].rone = Tree[rt].sumone = x;
        Tree[rt].lzero = Tree[rt].rzero = Tree[rt].sumzero = !x;
        return ;
    }
    int mid = (l+r)>>1;
    Build(lson);
    Build(rson);
    push_up(rt);
}

void pushdown(int rt)
{
    if(Tree[rt].cover)
    {
        Tree[rt<<1].cover^=1;
        Tree[rt<<1|1].cover^=1;
        Tree[rt].cover = 0;

        //0,1交换
        swap(Tree[rt<<1].lone,Tree[rt<<1].lzero);
        swap(Tree[rt<<1].sumone,Tree[rt<<1].sumzero);
        swap(Tree[rt<<1].rone,Tree[rt<<1].rzero);

        swap(Tree[rt<<1|1].lone,Tree[rt<<1|1].lzero);
        swap(Tree[rt<<1|1].sumone,Tree[rt<<1|1].sumzero);
        swap(Tree[rt<<1|1].rone,Tree[rt<<1|1].rzero);
    }
}

void updata(int l,int r,int rt)
{
    if(l<=Tree[rt].l&&Tree[rt].r<=r)
    {
        Tree[rt].cover^=1;
        swap(Tree[rt].lone,Tree[rt].lzero);
        swap(Tree[rt].sumone,Tree[rt].sumzero);
        swap(Tree[rt].rone,Tree[rt].rzero);
        return ;
    }
    pushdown(rt);
    int mid = (Tree[rt].r+Tree[rt].l)>>1;
    if(r<=mid)
    {
        updata(l,r,rt<<1);
    }
    else if(l>mid)
    {
       updata(l,r,rt<<1|1);
    }
    else
    {
        updata(l,mid,rt<<1);
        updata(mid+1,r,rt<<1|1);
    }
    push_up(rt);
}

int quary(int l,int r,int rt)
{
    if(l<=Tree[rt].l&&Tree[rt].r<=r)
    {
        return Tree[rt].sumone;
    }
    pushdown(rt);
    int mid = (Tree[rt].r+Tree[rt].l)>>1;
    if(l>mid)return quary(l,r,rt<<1|1);
    else if(r<=mid)return quary(l,r,rt<<1);
    else
    {
        int ans1 = quary(l,mid,rt<<1);
        int ans2 = quary(mid+1,r,rt<<1|1);
        return max(min(mid-l+1,Tree[rt<<1].rone)+min(r-mid,Tree[rt<<1|1].lone),max(ans1,ans2));
    }
}

int main()
{
    int m;
    while(cin>>n)
    {
        Build(1,n,1);
        cin>>m;
        while(m--)
        {
            int id,x,y;
            scanf("%d%d%d",&id,&x,&y);
            if(id)
            {
                updata(x,y,1);
            }
            else
            {
                printf("%d\n",quary(x,y,1));
            }
        }
    }

    return 0;
}
