#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main()
{

    int t;cin>>t;
    for(int i=1;i<=t;i++)
    {
        scanf("%s",s);
        int len = strlen(s);
        int ans = 0;
        int c = 0;
        int flag = 1;
        for(int j=0;j<len;j++)
        {
            if(s[j]=='c')
            {
                flag = 0;
                int num = 0;
                j++;
                while(j<len&&s[j]=='f')
                {
                    j++;
                    num++;
                }
                j--;
                if(num<2&&j!=len-1||num<2&&num+c<2)
                {
                    ans = -1;
                    break;
                }

                ans++;
            }
            else if(s[j]=='f')
            {
                int num = 0;
                while(j<len&&s[j]=='f')
                {
                    c++;
                    j++;
                }
                j--;
            }
            else
            {
                flag = 0;
                ans = -1;
                break;
            }
        }
        if(flag)
        {
            ans = (c+1)/2;
        }
        printf("Case #%d: ",i);
        printf("%d\n",ans);
    }
    return 0;
}

