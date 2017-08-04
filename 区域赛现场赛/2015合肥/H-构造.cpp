#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin>>t;int T = 1;
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        printf("Case #%d:\n",T++);
        if(m>n)
        {
            printf("Impossible\n");
        }
        else if(k==1)
        {
            if(n!=m)
            {
                printf("Impossible\n");
            }
            else
            {
                for(int i=0;i<n;i++)
                    printf("A");
                printf("\n");
            }
        }
        else if(k==2)
        {
            if(n<=7&&m!=n)
            {
                printf("Impossible\n");
            }
            else if(n<=7)
            {
                for(int i=0;i<n;i++)
                    printf("A");
                printf("\n");
            }
            else
            {
                if(n==8&&m<7||n>8&&m<8)
                    printf("Impossible\n");
                else if(n==m)
                {
                    for(int i=0;i<n;i++)
                        printf("A");
                    printf("\n");
                }
                else
                {
                    if(n==8)
                    {
                        printf("AABBABAA\n");
                    }
                    else
                    {
                        int x = m-8;
                        for(int i=0;i<x;i++)
                            printf("A");
                        printf("AABB");
                        n-=x;
                        n-=4;
                        int i;
                        for(i=0;i+6<n;i+=6)
                        {
                            printf("ABAABB");
                        }

                        char s[10]= {'A','B','A','A','B','B'};
                        for(int j=0;i<n;i++,j++)
                            printf("%c",s[j]);
                        printf("\n");
                    }
                }
            }
        }
        else
        {
            if(m<min(n,3))printf("Impossible\n");
            else
            {
                if(m<3)
                {
                    for(int i=0;i<n;i++)
                        printf("A");
                    printf("\n");
                }
                else
                {
                    int x = m-3;
                    for(int i=0;i<n-x;i++)
                    {
                        if(i%3==0)printf("A");
                        else if(i%3==1)printf("B");
                        else printf("C");
                    }
                    for(int i=0;i<x;i++)
                    {
                        if((n-x-1)%3==0)printf("A");
                        else if((n-x-1)%3==1)printf("B");
                        else printf("C");
                    }
                    printf("\n");

                }

            }
        }
    }
    return 0;
}


//#include<bits/stdc++.h>
//
//using namespace std;
//char str[30];
//int ans[30];map<int,int>mp1;
//void dfs(int x)
//{
//    if(x==16)
//    {
//        map<string,int>mp;
//
//        str[x] = '\0';
//        int cnt = 0;
//        //cout<<str<<endl;
//        for(int i=0;i<x;i++)
//        {
//            for(int j=i;j<x;j++)
//            {
//                int f = 1;
//                for(int k=i,l=0;k<=(i+j)/2;k++,l++)
//                {
//                    if(str[k]!=str[j-l])
//                    {
//                        f = 0;
//                        break;
//                    }
//                }
//
//                if(f==1)
//                {
//                    string x;
//                    for(int ii=i;ii<=j;ii++)
//                        x+=str[ii];
//                    mp[x]++;
//                    if(mp[x]==1)
//                        cnt++;
//                }
//            }
//        }
//       // cout<<cnt<<endl;
//        if(cnt<x&&cnt==9)
//        {
//             mp1[cnt]++;
//            printf("%s\n",str);
//            cout<<cnt<<endl;
//        }
//        return ;
//    }
//
//    str[x] = 'A';
//    dfs(x+1);
//    str[x] = 'B';
//    dfs(x+1);
//}
//
//int main()
//{
//    dfs(0);
//    return 0;
//}


