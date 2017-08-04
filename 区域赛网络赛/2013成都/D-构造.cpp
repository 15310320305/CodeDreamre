#include<bits/stdc++.h>

using namespace std;
char ch[10] = {'a','a','b','a','b','b'};
int main()
{
    int t;cin>>t;int T = 1;
    while(t--)
    {
        int n,m;scanf("%d%d",&m,&n);
        printf("Case #%d: ",T++);
        if(m==1)
        {
            for(int i=1;i<=n;i++)
                printf("a");
            cout<<endl;
        }
        else if(m==2)
        {
            if(n==1)printf("a");
            else if(n==2)printf("ab");
            else if(n==3)printf("aab");
            else if(n==4)printf("aabb");
            else if(n==5)printf("aaaba");
            else if(n==6)printf("aaabab");
            else if(n==7)printf("aaababb");
            else if(n==8)printf("aaababbb");
            else
            {
                printf("aaaababb");
                n-=8;
                for(int i=0;i<n;i+=6)
                {
                    int j=0;
                    while(i+j<n&&j<6)
                    {
                        printf("%c",ch[j]);
                        j++;
                    }
                }
            }
            cout<<endl;
        }
        else
        {
            int i;
            for(i=0;i<n;i+=3)
            {
                for(int j=0;j<3&&i+j<n;j++)
                    printf("%c",'a'+j);
            }
            cout<<endl;
        }
    }
    return 0;
}
