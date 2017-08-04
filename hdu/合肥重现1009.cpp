#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    long long l,r;
    int t;cin>>t;
    while(t--){
        scanf("%lld%lld",&l,&r);
        int num[65]={0};
        int cnt=0;
        long long R=r;
        while(R){
            if(R%2==1)num[cnt++]=1;
            else num[cnt++]=0;
            R>>=1;
        }
        long long ans=r;
        for(int i=cnt-1;i>=0;i--){
            if(num[i]==0){
                if((l|((long long)1<<i))<=r){
                    l=(l|((long long)1<<i));
                    ans= ans|((long long)1<<i);
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
