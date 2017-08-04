#include<bits/stdc++.h>

using namespace std;
int a[1000005];
int num[10005];
int ans[10005];
int cnt;
int main()
{
    int t;cin>>t;int T = 1;
    while(t--)
    {
        int n;scanf("%d",&n);
        memset(num,0,sizeof(num));
        cnt = 0;
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i] = 10000-(100-a[i])*(100-a[i]);
            num[a[i]]++;
        }
        int m=-1;
        for(int i=0;i<=10000;i++)
        {
            while(num[i]==0&&i<=10000)i++;
            if(m==-1)
            {
                ans[cnt++] = i;
                m = num[i];
            }
            else
            {
                if(num[i]>m)
                {
                    flag = 1;
                    cnt = 0;
                    ans[cnt++] = i;
                    m = num[i];
                }
                else if(num[i]==m)
                {
                    ans[cnt++] = i;
                }
                else if(num[i])
                {
                    flag = 1;
                }
            }
        }
        printf("Case #%d:\n",T++);
        if(flag==1||m==n)
        {
            for(int i=0;i<cnt;i++)
                printf("%d%c",ans[i],i==cnt-1?'\n':' ');
        }
        else
        {
            printf("Bad Mushroom\n");
        }

    }
    return 0;
}

