#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
vector<int>G[maxn];

int mp[maxn][maxn];
int dp[maxn],num[maxn];
int n,ans,s;
int cnt;
bool check(int deep,int x){
    for(int i=1;i<=deep;i++){
        if(!mp[x][num[i]])return false;
    }
    return true;
}

void dfs(int deep,int x,int id){

    if(deep==s)
    {
        cnt++;
        return ;
    }
    if(id>=G[x].size()||deep+G[x].size()-id<s)return ;

    if(check(deep,G[x][id]))
    {
        num[deep+1] = G[x][id];
        dfs(deep+1,x,id+1);
    }
    dfs(deep,x,id+1);
}

int main()
{

    int t;scanf("%d",&t);
    int m;
    while(t--){
        memset(G,0,sizeof(G));
        memset(mp,0,sizeof(mp));
        cnt = 0;
        scanf("%d%d%d",&n,&m,&s);
        while(m--)
        {
            int x,y;scanf("%d%d",&x,&y);
            mp[x][y] = mp[y][x] = 1;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        for(int i=1;i<=n-s+1;i++){
            num[1]=i;
            dfs(1,i,0);
            for(int j=1;j<=n;j++)
            {
                if(mp[i][j])mp[i][j] = mp[j][i] = 0;
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}

