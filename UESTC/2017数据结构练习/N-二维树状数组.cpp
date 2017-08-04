#include<bits/stdc++.h>
using namespace std;

int a[1005][1005];

int get(int x){return x&(-x);}

void add(int x,int y,int v)
{
    for(;x<=1000;x+=get(x))
    {
        for(int i=y;i<=1000;i+=get(i))
        {
            a[x][i]+=v;
        }
    }
}

int sum(int x,int y)
{
    int res= 0;
    for(;x>0;x-=get(x))
    {
        for(int i=y;i>0;i-=get(i))
        {
            res+=a[x][i];
        }
    }
    return res;
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int q;scanf("%d",&q);
        memset(a,0,sizeof(a));
        while(q--)
        {
            char ch[5];
            int a,b,c,d;
            scanf("%s",ch);
            if(ch[0]=='C')
            {
                scanf("%d%d%d%d",&a,&b,&c,&d);
                add(a,b,1);
                add(c+1,d+1,1);
                add(a,d+1,-1);
                add(c+1,b,-1);
            }
            else
            {
                scanf("%d%d",&a,&b);
                int ans = sum(a,b);
                printf("%d\n",ans%2);

            }
        }
    }
    return 0;
}
