
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Maxtrix{
   int ans[11][11];
};

int n,k;

Maxtrix mult(Maxtrix a,Maxtrix b){
   Maxtrix ans;
   for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
   {
       int sum=0;
       for(int k=0;k<n;k++){
           sum+=a.ans[i][k]*b.ans[k][j];
       }
       ans.ans[i][j]=sum%9973;
   }
   return ans;
}

void quickmuli(){
    Maxtrix ans,m;
    memset(ans.ans,0,sizeof(ans.ans));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&m.ans[i][j]);
    for(int i=0;i<n;i++)
        ans.ans[i][i]=1;
    while(k){
        if(k%2==1)
            ans=mult(ans,m);
        m=mult(m,m);
        k>>=1;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=ans.ans[i][i];
    }
    printf("%d\n",sum%9973);

}

int main()
{
    int t;cin>>t;
    while(t--){
        scanf("%d%d",&n,&k);
        quickmuli();
    }

    return 0;
}
