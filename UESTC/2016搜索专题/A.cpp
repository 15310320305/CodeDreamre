#include<bits/stdc++.h>
using namespace std;
int pp[11]
char s[12][12];
int ans[12];
int ff[27];
int cnt,n;
int res;
int num[29];
int vis[29];
int len[12];
int dig[11] = {0,1,2,3,4,5,6,7,8,9};
void dfs(int x)
{

    if(x==cnt)
    {
//        for(int i=0;i<cnt;i++)
//        {
//            printf("%d ",ans[i]);
//        }
//        printf("\n");
        long long xx = 0;
        for(int i=0;i<n;i++)
        {
            long long yy = 0;
            for(int j=0;j<len[i];j++)
            {
                yy = (long long)yy*10ll+(long long)ans[num[s[i][j]-'A']];
            }
            if(i!=n-1)
            xx+=yy;
            else
            {
                if(xx==yy)res++;
            }
        }


        return ;
    }

    for(int i=0;i<10;i++)
    {
        if(vis[i]==0&&(i!=0||ff[x]==0))
        {
            ans[x] = i;
            vis[i] = 1;
            dfs(x+1);
            vis[i] = 0;
        }
    }
}


int main()
{
    while(~scanf("%d",&n))
    {
        memset(num,0,sizeof(num));
        memset(vis,0,sizeof(vis));
        memset(ff,0,sizeof(ff));
        cnt = 0;
        res = 0;
        int Maxlen = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            len[i] = strlen(s[i]);
            if(i<n-1)Maxlen = max(Maxlen,len[i]);
            for(int j = 0;j<len[i];j++)
            {
                if(vis[s[i][j]-'A'])continue;
                if(j==0)ff[cnt]=1;
                num[s[i][j]-'A'] = cnt++;
                vis[s[i][j]-'A']= 1;
            }
        }
        memset(vis,0,sizeof(vis));
        int ans = 0;
        if(len[n-1]>=Maxlen)
        dfs(0);
        printf("%d\n",res);
    }
    return 0;
}
