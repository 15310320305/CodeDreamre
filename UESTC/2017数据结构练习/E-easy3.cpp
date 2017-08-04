/**
CDOJ 1597 Ïß¶ÎÊ÷
*/


#include<bits/stdc++.h>
using namespace std;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define ll long long
const int maxn = 1e5+100;
ll p;
int n;
ll Tree[maxn<<2],cadd[maxn<<2],cmul[maxn<<2];
void Build(int l,int r,int rt)
{
    cadd[rt] = 0;
    cmul[rt] = 1;

    if(l==r)
    {
        scanf("%lld",&Tree[rt]);
        return ;
    }
    int mid = (l+r)>>1;

    Build(lson);
    Build(rson);
    Tree[rt] = Tree[rt<<1]+Tree[rt<<1|1];
    Tree[rt]%=p;
}

void pushdown(int rt,ll m)
{

    //先让加的数组加上他要乘的倍数
    cadd[rt<<1]=(cadd[rt<<1]*cmul[rt]+cadd[rt])%p;
    cadd[rt<<1|1]=(cadd[rt<<1|1]*cmul[rt]+cadd[rt])%p;


    //先更新乘法
    cmul[rt<<1] *= cmul[rt];
    cmul[rt<<1|1] *= cmul[rt];

    cmul[rt<<1] %= p;
    cmul[rt<<1|1] %= p;

    //后更新加法
    Tree[rt<<1]=(Tree[rt<<1]*cmul[rt]+(m-m/2ll)*cadd[rt])%p;
    Tree[rt<<1|1]=(Tree[rt<<1|1]*cmul[rt]+(m/2ll)*cadd[rt])%p;

    cadd[rt] = 0;
    cmul[rt] = 1;

}

void updata(int L,int R,int l,int r,int rt ,ll c,int op)
{
    if(L<=l&&r<=R)
    {
        if(op==1)
        {
            cadd[rt] = cadd[rt]*c;
            cadd[rt]%=p;
            cmul[rt]*=c;
            cmul[rt]%=p;
            Tree[rt]*=c;
            Tree[rt]%=p;
        }
        else
        {
            cadd[rt]+=c;
            cadd[rt]%=p;
            Tree[rt]+=c*(r-l+1ll);
            Tree[rt]%=p;
        }

        return ;
    }

    pushdown(rt,r-l+1ll);

    int mid = (l+r)>>1;
    if(L<=mid)
    {
        updata(L,R,lson,c,op);
    }
    if(R>mid)
    {
        updata(L,R,rson,c,op);
    }

    Tree[rt] = (Tree[rt<<1]+Tree[rt<<1|1])%p;
}

ll quary(int L,int R,int l,int r,int rt)
{

    if(L<=l&&r<=R)return Tree[rt]%p;
    pushdown(rt,r-l+1ll);
    int mid = (l+r)>>1;
    ll res = 0;
    if(L<=mid)res+=quary(L,R,lson);
    if(R>mid)res+=quary(L,R,rson);
    return res%p;
}

int main()
{
    cin>>n>>p;
    Build(1,n,1);
    int m;
    cin>>m;
    while(m--)
    {
        int id,a,b;
        ll c;
        scanf("%d",&id);
        if(id==1)
        {
            scanf("%d%d%lld",&a,&b,&c);
            updata(a,b,1,n,1,c,1);
        }
        else if(id==2)
        {
            scanf("%d%d%lld",&a,&b,&c);
            updata(a,b,1,n,1,c,2);
        }
        else
        {
            scanf("%d%d",&a,&b);
            printf("%lld\n",quary(a,b,1,n,1));
        }
    }

    return 0;
}
