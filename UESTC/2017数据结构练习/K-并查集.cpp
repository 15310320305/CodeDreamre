//#include<bits/stdc++.h>
//using namespace std;
//int pre[100005],rk[100005];
//int get(int x)
//{
//    if(x!=pre[x])
//    {
//        int tmp = pre[x];
//        pre[x] = get(pre[x]);
//        rk[x] = (rk[x]+rk[tmp])%2;
//    }
//    return pre[x];
//}
//
//int main()
//{
//    int n,m;
//    cin>>n>>m;
//    for(int i=1;i<=n;i++)pre[i] = i,rk[i] = 0;
//    int a,x,y;
//    int flag = 1;
//    while(m--)
//    {
//        scanf("%d%d%d",&a,&x,&y);
//        int xx = get(x);
//        int yy = get(y);
//        if(xx==yy)
//        {
//            if(a&&rk[x]!=rk[y]||!a&&rk[x]==rk[y])
//            {
//                flag = 0;
//                break;
//            }
//            continue;
//        }
//        rk[xx] = (a^1-rk[x]+rk[y]+2)%2;
//        pre[xx] = yy;
//    }
//    if(flag)printf("YES\n");
//    else printf("NO\n");
//    return 0;
//}

#include<bits/stdc++.h>
using namespace std;

map<string,int>mp;
int n,t;
int pre[200005],rk[200005];
int get(int x)
{
    if(x!=pre[x])
    {
        pre[x] = get(pre[x]);
    }
    return pre[x];

}
int main()
{
    while(cin>>t)
    {
        while(t--)
    {
        int cnt = 0;
        mp.clear();
        for(int i=1;i<=200000;i++)
            pre[i] = i,rk[i] = 1;
        scanf("%d",&n);
        while(n--)
        {
            char s1[30],s2[30];
            scanf("%s%s",s1,s2);
            int x,y;
            if(mp[s1]==0)
            {
                x = mp[s1] = ++cnt;
            }
            else x = mp[s1];

            if(mp[s2]==0)
            {
                y = mp[s2] = ++cnt;
            }
            else y = mp[s2];

            int xx = get(x);
            int yy = get(y);

            if(xx>yy)swap(xx,yy);
            if(xx!=yy)
            {
                pre[xx] = yy;
                rk[yy]+=rk[xx];
                printf("%d\n",rk[yy]);
            }
            else
            {
                printf("%d\n",rk[yy]);
            }

        }

    }

    }

    return 0;
}

