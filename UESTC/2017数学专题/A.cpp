/**
SG
*/

#include<bits/stdc++.h>
using namespace std;

int sg[10005],vis[10005];
int s[100005];
int k,m;
int get_sg(int num)
{
    if(sg[num]!=-1)return sg[num];
    bool vis[110];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<k;i++)
    {
        if(num>=s[i])
        {
            get_sg(num-s[i]);
            vis[sg[num-s[i]]] = 1;
        }
    }
    int e = 1;
    for(;vis[e]==1;)
    {
        e++;
    }
    return sg[num] = e;
}

int main()
{
    memset(sg,-1,sizeof(sg));
    cin>>k;
    for(int i=0;i<k;i++)
    {
        scanf("%d",&s[i]);
    }
    cin>>m;
    while(m--)
    {
        int t;scanf("%d",&t);
        int ans = 0;
        while(t--)
        {
            int num;scanf("%d",&num);
            ans^=get_sg(num);
        }
        if(ans==0)printf("lose!\n");
        else printf("win!\n");
    }
    return 0;
}
