


#include<bits/stdc++.h>
using namespace std;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int maxn = 1e6;
struct st
{
    int sum,summax,lsum,rsum;
}Tree[maxn<<1];
void pushup(int rt)
{
    Tree[rt].lsum = max(Tree[rt<<1].lsum,Tree[rt<<1].sum+Tree[rt<<1|1].lsum);
    Tree[rt].rsum = max(Tree[rt<<1|1].rsum,Tree[rt<<1|1].sum+Tree[rt<<1].rsum);
    Tree[rt].sum = Tree[rt<<1].sum+Tree[rt<<1|1].sum;
    Tree[rt].summax = max(max(Tree[rt<<1].summax,Tree[rt<<1|1].summax),Tree[rt<<1].rsum+Tree[rt<<1|1].lsum);
}

void build(int l,int r,int rt)
{

    if(l==r)
    {
        int x;scanf("%d",&x);
        Tree[rt].lsum=Tree[rt].rsum= Tree[rt].sum = Tree[rt].summax = x;
        return ;
    }
    int mid = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

int lsum,rsum,sum,summax;

void quary(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        //在查找区间内不断更新，从左到右（性质）

        if(summax == 1e9)
        {
            summax = Tree[rt].summax;
            lsum = Tree[rt].lsum;
            rsum = Tree[rt].rsum;
            sum = Tree[rt].sum;
            return ;
        }

        summax = max(max(summax,Tree[rt].summax),rsum+Tree[rt].lsum);
        lsum = max(lsum,sum+Tree[rt].lsum);
        rsum = max(Tree[rt].rsum,Tree[rt].sum+rsum);
        sum = sum+Tree[rt].sum;

        return ;
    }
    int mid = (l+r)>>1;
    if(L<=mid)quary(L,R,lson);
    if(R>mid)quary(L,R,rson);
}

void updata(int l,int r,int rt,int pos,int v)
{
    if(l==r)
    {
        Tree[rt].lsum =v;
        Tree[rt].rsum=v;
        Tree[rt].sum=v;
        Tree[rt].summax=v;
        return ;
    }
    int mid = (l+r)>>1;
    if(pos<=mid)
    {
        updata(lson,pos,v);
    }
    else updata(rson,pos,v);
    pushup(rt);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,n,1);
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1)
        {
            lsum = rsum = sum = summax = 1e9;
            quary(b,c,1,n,1);
            printf("%d\n",summax);
        }
        else
        {
            updata(1,n,1,b,c);
        }
    }
    return 0;
}


