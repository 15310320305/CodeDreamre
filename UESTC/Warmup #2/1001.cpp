#include<cstring>
#include<cstdio>
#define abs(x) ((x)<0?-(x):(x))

bool vis[12][12],ans[12][12];

void dfs(int a,int b,int cnt){
    if(a>10||b>10||cnt>10)return ;
    if(cnt<5){
        if(5-cnt<abs(a-b)){
            ans[a][b]=true;
            return ;
        }
    }else {
        if(abs(a-b)==1||abs(a-b)==2){
            ans[a][b]=true;
            return ;
        }else if(abs(a-b)!=0)return ;
    }
    dfs(a,b,cnt+1);
    dfs(a+1,b,cnt+1);
    dfs(a,b+1,cnt+1);
    dfs(a+1,b+1,cnt+1);
}

int main()
{
    memset(vis,false,sizeof(vis));
    memset(ans,false,sizeof(vis));
    dfs(0,0,0);

    int a,b;
    scanf("%d%d",&a,&b);
    if(ans[a][b])printf("Yes\n");
    else printf("No\n");
    return 0;
}
