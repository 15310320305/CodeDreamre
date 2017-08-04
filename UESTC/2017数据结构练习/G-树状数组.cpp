#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
int n;
int a[maxn];
int get(int x){return x&(-x);}
void updata(int x){while(x<=n){a[x]++,x+=get(x);}}
int sum(int x){int res = 0;while(x>0){res+=a[x],x-=get(x);}return res;}
int ss[maxn],tt[maxn],rk[maxn];
int main()
{
    long long ans = 0;
    memset(a,0,sizeof(a));
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&ss[i]);
    for(int i=1;i<=n;i++)scanf("%d",&tt[i]);
    for(int i=1;i<=n;i++)rk[tt[i]] = i;
    for(int i=1;i<=n;i++)tt[i] = rk[ss[i]];
    for(int i=1;i<=n;i++){ans+=(long long)(i-1-sum(tt[i]));updata(tt[i]);}
    cout<<ans<<endl;
    return 0;
}
