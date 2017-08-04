#include<bits/stdc++.h>
using namespace std;
struct nod
{
    int l,r;
    int v;
    void init()
    {
        l = r = -1;
    }
}Tree[2000];
int head;
int n;

void Insert(int u,int x)
{
    if(x>Tree[u].v)
    {
        if(Tree[u].l==-1)
        {
            Tree[u].l = x;
            Tree[x].v = x;
        }
        else Insert(Tree[u].l,x);
    }
    else
    {
        if(Tree[u].r==-1)
        {
            Tree[u].r = x;
            Tree[x].v = x;
        }
        else Insert(Tree[u].r,x);
    }
}

void quary(int u,int x)
{
    if(x==u)
    {
        printf("\n");
        return;
    }

    if(Tree[u].v>x)
    {
        printf("E");
        quary(Tree[u].r,x);
    }
    else
    {
        printf("W");
        quary(Tree[u].l,x);
    }

}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)Tree[i].init();
        for(int i=0;i<n;i++)
        {
            int x;scanf("%d",&x);
            if(i==0)
            {
                head = x;
                Tree[x].v = x;
            }
            else Insert(head,x);
        }
        int q;scanf("%d",&q);
        while(q--)
        {
            int x;scanf("%d",&x);
            quary(head,x);
        }

    }
    return 0;
}
