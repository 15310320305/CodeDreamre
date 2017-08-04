#include<bits/stdc++.h>

using namespace std;

struct Tree
{
    int nex[2],f;
    Tree()
    {
        nex[0]  =nex[1] = 0;
        f = 0;
    }
    void init()
    {
        nex[0]  =nex[1] = 0;
        f = 0;
    }
}tree[500005];

int Size,n;
int change[32];
void Build(int num[32])
{
    int now = 0;
    for(int i=30;i>=0;i--)
    {
        int id = num[i];
        if(tree[now].nex[id]==0)
        {
            tree[now].nex[id] = ++Size;
        }
        now = tree[now].nex[id];
        tree[now].f++;
    }
}
void Insert(int num[32])
{
    int now = 0;
    for(int i=30;i>=0;i--)
    {
        int id = num[i];
        now = tree[now].nex[id];
        tree[now].f++;
    }
}
int query(int num[32])
{
    int now = 0;
    int ans = 0;
    for(int i=30;i>=0;i--)
    {
        int id = num[i];
        if(tree[now].nex[id^1]&&tree[tree[now].nex[id^1]].f)
        {
            ans+=change[i];
            now = tree[now].nex[id^1];
        }
        else now = tree[now].nex[id];
    }
    return ans;
}
void delet(int num[32])
{
    int now = 0;
    for(int i=30;i>=0;i--)
    {
        int id = num[i];
        now = tree[now].nex[id];
        tree[now].f--;
    }
}
int a[1005];
int main()
{
    change[0] = 1;
    for(int i=1;i<=30;i++)
        change[i] = change[i-1]*2;
    int t;cin>>t;
    while(t--)
    {
        Size = 0;
        int num[32];
        int cnt = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            cnt = 0;
            memset(num,0,sizeof(num));
            int x = a[i];
            while(x)
            {
                num[cnt++] = x%2;
                x/=2;
            }
            Build(num);
        }
        int num1[32],num2[32];
        int cnt1,cnt2;
        int ans = 0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                cnt1 = cnt2 = cnt = 0;
                memset(num,0,sizeof(num));
                memset(num1,0,sizeof(num1));
                memset(num2,0,sizeof(num2));
                int x = a[i];
                while(x)
                {
                    num1[cnt1++] = x%2;
                    x/=2;
                }
                x = a[j];
                while(x)
                {
                    num2[cnt2++] = x%2;
                    x/=2;
                }
                x = a[j]+a[i];
                while(x)
                {
                    num[cnt++] = x%2;
                    x/=2;
                }
                delet(num1);
                delet(num2);
                int yy = query(num);
                ans = max(ans,yy);
                Insert(num1);
                Insert(num2);
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<=Size;i++)
            tree[i].init();
    }
    return 0;
}


/**
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005];

int main()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		int n, ma = 0;
		scanf("%d" ,&n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				for(int k = j + 1; k < n; k++)
				{
					ma = max(ma, (a[i] + a[j]) ^ a[k]);
					ma = max(ma, (a[i] + a[k]) ^ a[j]);
					ma = max(ma, (a[j] + a[k]) ^ a[i]);
				}
		printf("%d\n", ma);
	}
}


*/
