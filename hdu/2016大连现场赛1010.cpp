#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int n;int s[8]={0};
    int x=97,cnt=0;
    while(x){
        if(x%2==1)s[cnt++]=1;
        else s[cnt++]=0;
        x>>=1;
    }
    while(cin>>n){
        int ans = 0;
        while(n--){
            scanf("%d",&x);
            int num[32]={0};
            cnt=0;
            while(x){
                if(x%2==1)num[cnt++]=1;
                else num[cnt++]=0;
                x>>=1;
            }
            for(int i=0;i<4;i++){
                int flag=1;
                for(int j=0;j<8;j++){
                    if(num[8*i+j]!=s[j])flag=0;
                }
            if(flag)ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
