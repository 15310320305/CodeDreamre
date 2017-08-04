#include<bits/stdc++.h>

using namespace std;
map<string,int>mp;
char num[55];
int cnt = 0;
struct st
{
    int val,v;
    int id;
}s[55];

bool cmp1(st a,st b){return a.val<b.val;}
bool cmp2(st a,st b){return a.id<b.id;}

struct nod
{
    int l,r;
    int v;
    void init()
    {
        l = r = -1;
    }
}Tree[55];

int n,k;
int head;

void Build(int u,int x)
{
    if(x>Tree[u].v)
    {
        if(Tree[u].r==-1)
        {
            Tree[u].r = x;
            Tree[x].v = x;
        }
        else Build(Tree[u].r,x);
    }
    else
    {
         if(Tree[u].l==-1)
        {
            Tree[u].l = x;
            Tree[x].v = x;
        }
        else Build(Tree[u].l,x);
    }
}

void quary(int u)
{
    num[cnt++] = Tree[u].v+'a';
    if(Tree[u].l!=-1)
    {
        quary(Tree[u].l);
    }
    if(Tree[u].r!=-1)
    {
        quary(Tree[u].r);
    }
}

int main()
{
    int ans = 0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            scanf("%d",&s[j].val);
            s[j].id = j;
            Tree[j].init();
        }
        sort(s,s+k,cmp1);
        for(int j=0;j<k;j++)
        {
            s[j].v = j;
        }
        sort(s,s+k,cmp2);
        for(int j=0;j<k;j++)
        {
            if(j==0)
            {
                head = s[j].v;
                Tree[head].v = s[j].v;
            }
            else Build(head,s[j].v);
        }
        cnt = 0;
        quary(head);
        num[cnt] = '\0';
        mp[num]++;
        if(mp[num]==1)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
