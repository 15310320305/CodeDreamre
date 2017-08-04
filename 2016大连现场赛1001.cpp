#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,m,x,y;
    while(~scanf("%d%d%d%d",&n,&m,&x,&y)){
        int s[1005]={0};
        for(int i=0;i<m;i++){
            int a,b;scanf("%d%d",&a,&b);
            s[a]=1;
            s[b]=1;
        }
        for(int i=0;i<x;i++){
            int a;scanf("%d",&a);
            s[a]=1;
        }
        for(int i=0;i<y;i++){
            int a;scanf("%d",&a);
            s[a]=1;
        }
        int flag=1;
        for(int i=1;i<=n;i++)
            if(s[i]==0)flag=0;
        if(flag)printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
