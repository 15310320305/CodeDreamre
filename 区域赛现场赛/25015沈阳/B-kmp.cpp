#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int Next[505][2005];
int vis[505];
int length[505];
char s[505][2005];
vector<int>v[505];
int n;

void getNext(int id,int len)
{
    Next[id][0] = -1;
    int i=-1,j=0;
    while(j<len)
    {
        if(i==-1||s[id][i]==s[id][j])
        {
            ++i,++j;
            Next[id][j] = i;
        }else i = Next[id][i];
    }
}
bool check(int x,int y)
{
    int i=0,j = 0;
    int lenx = length[x],leny = length[y];
    while(j<leny)
    {
        if(i==-1||s[x][i]==s[y][j])
        {
            ++i,++j;
        }else i = Next[x][i];
        if(i==lenx)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int t;cin>>t;
    int T = 1;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);

        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            length[i] = strlen(s[i]);
            getNext(i,length[i]);
        }
        int ans = -1;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(vis[j])continue;
               // cout<<i<<" "<<j<<endl;
                if(check(j,i))
                {
                   vis[j] = 1;
                }
                else
                {
                    ans = max(ans,i+1);
                    break;
                }

            }
           // cout<<v[i].size()<<endl;
        }
        printf("Case #%d: %d\n",T++,ans);
    }
    return 0;
}

