#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

struct st{
 int v,a;
}s[10005];

bool cmp(st a,st b){
    if(a.v==b.v)return a.a>b.a;
    return a.v<b.v;
}

int n;
bool check(int mid){
    for(int i=0;i<n;i++){
        if(mid<s[i].v)return false;
        mid+=s[i].a;
    }
    return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&s[i].v,&s[i].a);
    sort(s,s+n,cmp);
    int l = 0,r = 1e9,ans,mid;
    while(l<=r){
        mid = (l+r)>>1;
        if(check(mid)){
            ans= mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
