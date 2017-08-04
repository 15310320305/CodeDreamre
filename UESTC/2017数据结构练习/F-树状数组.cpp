#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+100;

struct nod
{
    int x,y;
}s[maxn];
bool cmp(nod a,nod b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int a[maxn];
int ans[maxn];
int n;
int get(int x){return x&(-x);}

void updata(int x)
{
    while(x<maxn)
    {
        a[x]++;
        x+=get(x);
    }
}

int sum(int x)
{
    int res = 0;
    while(x>0)
    {
        res+=a[x];
        x-=get(x);
    }
    return res;
}

int main()
{
    cin>>n;
    memset(a,0,sizeof(a));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++)scanf("%d%d",&s[i].x,&s[i].y);
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++)
    {
        int x = sum(s[i].y);
        ans[x]++;
        updata(s[i].y);
    }
    for(int i=0;i<n;i++)printf("%d\n",ans[i]);
    return 0;
}
