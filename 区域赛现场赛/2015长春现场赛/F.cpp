#include<bits/stdc++.h>

using namespace std;

int n;
int a[100005];
int b[100005];
int len,flag;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        flag = 1;
        len  = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i==0)b[len++] = a[i];
            else if(a[i]>=b[len-1])b[len++] = a[i];
            else
            {
                int x = upper_bound(b,b+len,a[i])-b;
                b[x] = a[i];
            }
        }
        if(len<n-1)flag = 0;
        if(flag==0)
        {
            len = 0;
            flag = 1;
            for(int i=n-1;i>=0;i--)
            {
                if(i==n-1)b[len++] = a[i];
                else if(a[i]>=b[len-1])b[len++] = a[i];
                else
                {
                    int x = upper_bound(b,b+len,a[i])-b;
                    b[x] = a[i];
                }
            }
            if(len<n-1)flag = 0;

        }

        if(flag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
