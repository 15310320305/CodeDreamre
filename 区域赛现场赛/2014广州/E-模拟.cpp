#include<bits/stdc++.h>

using namespace std;

struct st
{
    char name[55];
    int len;
    int x,y;
    void init()
    {
        x = y = 1;
    }
}s[205];
map<string,int>mp;
bool cmp(st a,st b)
{
    if(a.len==b.len)return strcmp(a.name,b.name)<0;
    else return a.len>b.len;
}
int n;
int main()
{
    while(cin>>n,n)
    {
        for(int i=0;i<n;i++)
        {
            s[i].init();
        }
        mp.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%s%d",s[i].name,&s[i].len);
        }
        sort(s,s+n,cmp);
        for(int i=0;i<n;i++)
        {
            mp[s[i].name] = i;
            if(i==0)continue;
            if(s[i].len==s[i-1].len)
            {
                s[i].y = s[i-1].y+1;
                s[i].x=s[i-1].x;
            }
            else
            {
                s[i].x = s[i-1].x+1+s[i-1].y-1;
            }
        }
        for(int i=0;i<n;i++)
        {
            printf("%s %d\n",s[i].name,s[i].len);
        }
        int m;cin>>m;
        while(m--)
        {
            char str[55];
            scanf("%s",str);
            int id = mp[str];
            if(s[id].y!=1)
            {
                printf("%d %d\n",s[id].x,s[id].y);
            }
            else printf("%d\n",s[id].x);
        }
    }

    return 0;
}
