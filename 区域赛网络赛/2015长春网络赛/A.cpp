#include<bits/stdc++.h>
using namespace std;

int k,m,q;
struct st
{
    char s[203];
    int v;
    int id;
    bool operator<(const st&a)const
    {
        if(a.v==v)return a.id<id;
        return a.v>v;
    }

}s[150005];

struct nod
{
    int x,y;
    bool operator <(const nod &a)const
    {
        return a.x>x;
    }
}ss[150005];


int main()
{
    int t;cin>>t;
    while(t--)
    {
        scanf("%d%d%d",&k,&m,&q);
        map<int,string>ans;
        for(int i=1;i<=k;i++)
        {
            scanf("%s %d",s[i].s,&s[i].v);
            s[i].id = i;
        }
        map<string,int>flag;
        int cnt = 1;
        int xx=0;
        priority_queue<st>qmax;

        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&ss[i].x,&ss[i].y);
        }
        sort(ss+1,ss+m+1);
        for(int i=1;i<=m;i++)
        {
            int x = ss[i].x,y = ss[i].y;
            for(int i=xx+1;i<=x;i++)
            {
                qmax.push(s[i]);
            }
            while(y--&&!qmax.empty())
            {
                st a = qmax.top();
                qmax.pop();
                ans[cnt++] = a.s;
            }
            xx = x;
        }
        for(int i=xx+1;i<=k;i++)qmax.push(s[i]);
        while(!qmax.empty())
        {
            ans[cnt++] = qmax.top().s;
            qmax.pop();
        }
        while(q--)
        {
            int x;scanf("%d",&x);
            cout<<ans[x];
            if(q)printf(" ");
        }
        printf("\n");
    }
    return 0;
}
