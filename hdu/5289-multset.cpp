#include<iostream>
#include<cstdio>
#include<queue>
#include<set>

using namespace std;

const int N = 1e5+10;
int num[N];
multiset<int>s;
multiset<int,greater<int> >ms;
int main()
{
    int n,m;
    int t;cin>>t;
    while(t--){
        scanf("%d%d",&n,&m);
        s.clear();
        ms.clear();
        int st=0;
        long long ans=0;
        multiset<int>::iterator it1,it2;
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
            s.insert(num[i]);
            ms.insert(num[i]);
             while(st<=i&&*ms.begin()-*s.begin()>=m){
                it1=s.find(num[st]);
                it2=ms.find(num[st++]);
                s.erase(it1);
                ms.erase(it2);
             }
             ans+=s.size();
        }
        printf("%lld\n",ans);
    }
    return 0;
}
