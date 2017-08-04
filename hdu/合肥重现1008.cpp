#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;



int main()
{
    int n,m,t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        int pre[105];
        pre[0]=0;
        for(int i=1;i<=n;i++){
           int x;scanf("%d",&x);
           pre[i]=pre[i-1]^x;
        }
        int cnt=0;
        int s[3000];
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
              int x;
              if(i==1)x=pre[j];
              else x = (pre[i-1])^pre[j];
              if(!s[x]){
                s[x]=j-i+1;
              }
              else s[x]=max(s[x],j-i+1);
            }
        }
        int ans[105];
        int ccnt=0;
        scanf("%d",&m);
        for(int j=1;j<=m;j++)
        {
          int x;scanf("%d",&x);
          int Min=100000;
          int L;
          for(int l=x,r=x;;l--,r++){
            if(l>=0){
                if(s[l]&&s[r]){
                    L=max(s[l],s[r]);
                    break;
                }
                if(s[l]){L=s[l];break;}
                if(s[r]){L=s[r];break;}
            }
            else {
                if(s[r]){L=s[r];break;}
            }
          }
          ans[ccnt++]=L;
        }
        for(int i=0;i<ccnt;i++)
            printf("%d\n",ans[i]);
        printf("\n");
    }

    return 0;
}
