//#include<bits/stdc++.h>
//
//using namespace std;
//char s[2000005];
//int Next[2000005];
//int n;
//void getNext()
//{
//
//    Next[0] = -1;
//    int i = -1,j = 0;
//    while(j<n)
//    {
//        if(i==-1||s[i]==s[j])
//        {
//            ++i,++j;
//            Next[j] = i;
//        }
//        else i = Next[i];
//    }
//
//}
//int main()
//{
//    int t;cin>>t;int T = 1;
//    while(t--)
//    {
//        scanf("%s",s);
//        n = strlen(s);
//
//        getNext();
//        for(int i=0;i<=n;i++)
//            cout<<Next[i]<<" ";
//        cout<<endl;
//        map<char ,int>mp;
//        printf("Case #%d:\n",T++);
//        int k ,t;
//        for(int i=0;i<n;i++)
//        {
//            if(mp[s[i]]==0)
//            {
//                printf("-1 %d\n",s[i]);
//                k = 0;
//                t = n;
//                mp[s[i]] = 1;
//            }
//            else
//            {
//                while(i<n&&mp[s[i]]&&Next[i]!=-1)
//                {
//                    k++;
//                    i++;
//                    t = min(Next[i+1],t);
//                }
//                printf("%d %d\n",k,t);
//                i--;
//            }
//
//        }
//
//    }
//    return 0;
//


