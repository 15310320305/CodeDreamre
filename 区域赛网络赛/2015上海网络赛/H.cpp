#include<bits/stdc++.h>
using namespace std;
long long Tree[5000000];
long long M;
int n;

void updata(int l,int r,int rt,int pos,long long w)
{
    if(l==r)
    {
        Tree[rt] = w%M;
        return ;
    }
    int mid = (l+r)>>1;
    if(pos<=mid)
    {
        updata(l,mid,rt<<1,pos,w);
    }
    else updata(mid+1,r,rt<<1|1,pos,w);
    Tree[rt] = Tree[rt<<1]*Tree[rt<<1|1]%M;
}

void Build(int l,int r,int rt)
{
    if(l==r)
    {
        Tree[rt] = 1ll;
        return ;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    Tree[rt] = Tree[rt<<1]*Tree[rt<<1|1];
}

int main()
{
    int t;cin>>t;
    int T = 1;
    while(t--)
    {
        scanf("%d%lld",&n,&M);
        printf("Case #%d:\n",T++);
        Build(1,n,1);
        for(int i=1;i<=n;i++)
        {
            int a;
            int b;scanf("%d%d",&a,&b);
            if(a==1)
            {
                updata(1,n,1,i,(long long)b);
                printf("%lld\n",Tree[1]);
            }
            else
            {
                updata(1,n,1,b,(long long)1);
                updata(1,n,1,i,(long long)1);
                printf("%lld\n",Tree[1]);
            }
        }
    }
    return 0;
}
