#include<bits/stdc++.h>
using namespace std;
vector<int>G[30];
char s[1005][205];
int n;
int mp[30][30];
int in[30],out[30];
priority_queue<int,vector<int>,greater<int> >q;
int ans[30];
int cnt;
bool topsort()
{
    for(int i=1;i<=26;i++)
        if(in[i]==0)q.push(i);
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        ans[++cnt] = u;
        for(int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            in[v]--;
            if(in[v]==0)
            {
                q.push(v);
            }
        }
    }
    if(cnt==26)return true;
    else return false;
}
int main()
{

    int flag = 0;
    for(int i=1;i<=26;i++)
        for(int j=1;j<=26;j++)
            mp[i][j] = 0;
    cin>>n;
    memset(G,0,sizeof(G));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        int len = strlen(s[i]);
        if(i)
        {
            int len1 = strlen(s[i-1]);
            int ff = 1;
            for(int j=0;j<len&&j<len1;j++)
            {
                if(s[i][j]!=s[i-1][j])
                {
                    int x = s[i][j]-'a'+1;
                    int y = s[i-1][j] - 'a'+1;
                    if(mp[y][x]==0)
                    {
                        G[y].push_back(x);
                        in[x]++;
                        out[y]++;
                    }
                    mp[y][x] = 1;
                    if(mp[x][y])flag = 1;
                    ff = 0;
                    break;
                }
            }
            if(ff&&len1>len)
            {
                flag = 1;
            }
        }
    }
    if(flag)
    {
        printf("-1\n");
        return 0;
    }
    cnt = 0;
    if(topsort())
    {
        for(int i=1;i<=26;i++)
            printf("%c",ans[i]-1+'a');
        printf("\n");
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
