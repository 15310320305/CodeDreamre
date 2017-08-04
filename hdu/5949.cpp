#include<cstdio>
#include<cstring>
int main()
{
    char s[20];
    int t;scanf("%d",&t);
    while(t--)
    {
        int ans = 0;
        scanf("%s",s);
        int n =strlen(s);
        for(int i=0;i<n;i++)
            {
                if(s[i]=='H')ans+=1;
                if(s[i]=='C')ans+=12;
                if(s[i]=='O')ans+=16;
            }
        printf("%d\n",ans);
    }

    return 0;
}
