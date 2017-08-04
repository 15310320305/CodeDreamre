#include<algorithm>
#include<cstdio>
#include<cstring>
#define abs(x) ((x)<0?-(x):(x))
#define min(a,b) ((a)<(b)?(a):(b))
using std::sort;
struct st{
    int a,c,l,r;
}s[1005];

bool cmp(st a,st b){
    return a.c<b.c;
}

int main()
{
    int n,ss;
    int sum = 0;
    scanf("%d%d",&n,&ss);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&s[i].a,&s[i].c,&s[i].l,&s[i].r);
        sum+=s[i].a;
    }
    sort(s,s+n,cmp);
    int ans=0,num =ss-sum;
    for(int i=0;i<n&&num!=0;i++){
        if(num>0){
            ans+=min(s[i].r-s[i].a,num)*s[i].c;
            num-=min(num,s[i].r-s[i].a);
        }else {
            ans+=min(s[i].a-s[i].l,-num)*s[i].c;
            num+=min(-num,s[i].a-s[i].l);
        }
    }
    if(num==0){
        printf("%d\n",ans);
    }else {
        printf("impossible\n");
    }
    return 0;
}
