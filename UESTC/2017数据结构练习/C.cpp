/**
CDOJ1593 线段树区间合并
*/

#include<bits/stdc++.h>
using namespace std;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define Max(a,b) (a)>(b)?(a):(b)
#define Min(a,b) (a)<(b)?(a):(b)
const int maxn = 1e5+100;
#define ll long long
struct ST
{
    ll lsum,rsum,summax,sum;
    int l,r;
}Tree[maxn<<2];

int n;

void push_up(int rt)
{
    if(Tree[rt<<1].lsum>=0)
    Tree[rt].lsum = Tree[rt<<1].lsum;
    else Tree[rt].lsum = 0;

    if(Tree[rt<<1|1].rsum>=0)
    Tree[rt].rsum = Tree[rt<<1|1].rsum;
    else Tree[rt].rsum = 0;
    if(Tree[rt].lsum==Tree[rt<<1].sum)Tree[rt].lsum+=Tree[rt<<1|1].lsum;
    if(Tree[rt].rsum==Tree[rt<<1|1].sum)Tree[rt].rsum+=Tree[rt<<1].rsum;
    Tree[rt].summax = max(Tree[rt<<1].rsum+Tree[rt<<1|1].lsum,max(Tree[rt<<1].summax,Tree[rt<<1|1].summax));
    Tree[rt].sum = Tree[rt<<1].sum+Tree[rt<<1|1].sum;
}

void Build(int l,int r,int rt)
{
    Tree[rt].l = l,Tree[rt].r = r;
    if(l==r)
    {
        ll x;scanf("%lld",&x);
        Tree[rt].lsum = Tree[rt].rsum = Tree[rt].summax = Tree[rt].sum = x;
        return ;
    }
    int mid = (l+r)>>1;
    Build(lson);
    Build(rson);
    push_up(rt);
}


void updata(int pos,int rt)
{
    if(Tree[rt].l==Tree[rt].r)
    {
        Tree[rt].lsum = Tree[rt].rsum = Tree[rt].summax =0;
        Tree[rt].sum = -1e18;
        return ;
    }
    int mid = (Tree[rt].r+Tree[rt].l)>>1;
    if(pos<=mid)updata(pos,rt<<1);
    else updata(pos,rt<<1|1);
    push_up(rt);
}

ll quary(int l,int r,int rt)
{
    if(l<=Tree[rt].l&&Tree[rt].r<=r)
    {
        return Tree[rt].summax;
    }
    int mid = (Tree[rt].r+Tree[rt].l)>>1;
    if(l>mid)return quary(l,r,rt<<1|1);
    else if(r<=mid)return quary(l,r,rt<<1);
    else
    {
        ll ans1 = quary(l,mid,rt<<1);
        ll ans2 = quary(mid+1,r,rt<<1|1);
        ll ans3=0;
        if(Tree[rt<<1].rsum<0)ans3+=0;
        else ans3+=Tree[rt<<1].rsum;
        if(Tree[rt<<1|1].lsum<0)ans3+=0;
        else ans3+=Tree[rt<<1|1].lsum;
        return max(max(ans1,ans2),ans3);
    }
}

int main()
{
    int m;
    cin>>n;
    Build(1,n,1);
    m = n;
    while(m--)
    {
        int id;
        scanf("%d",&id);
        updata(id,1);
        ll ans = quary(1,n,1);
        if(ans==-1e18)printf("0\n");
        else printf("%lld\n",ans);
    }

    return 0;
}
