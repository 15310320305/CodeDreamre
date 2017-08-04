/** HDU5875  */

#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define lcr(a,b) memset(a,b,sizeof(a))
#define sfor(i,n) for(i=0;i<n;i++)
#define dfor(i,n) for(i=n-1;i>=0;i--)
#define sc(x) scanf("%d",&x)
#define pr(x) printf("%d\n",x)
#define ll long long
#define INF 0x7fffffff
#define esp 1e-8

const int maxn = 1e5+100;

int i,j,k;
int n,m;

int stak[maxn];
int Next[maxn];
int a[maxn];

int main()
{
   int t;cin>>t;
   while(t--){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int id=1;
    a[n+1]=0;
    stak[id]=n+1;
    for(int i=n;i>=1;i--){
        while(a[i]<=a[stak[id]])id--;
        Next[i]=stak[id];
        stak[++id]=i;
    }
    scanf("%d",&m);
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=a[l];
        while(Next[l]<=r&&ans){
            ans%=a[Next[l]];
            l=Next[l];
        }
        printf("%d\n",ans);
    }
   }
    return 0;
}

