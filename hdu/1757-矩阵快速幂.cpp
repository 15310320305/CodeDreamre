#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
struct Matrix{
   int ans[10][10];
};

int n,m,a[10];

Matrix multi(Matrix a,Matrix b){
    Matrix ans;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            int sum=0;
            for(int k=0;k<10;k++){
                sum+=a.ans[i][k]*b.ans[k][j];
            }
            ans.ans[i][j]=sum%m;
        }
    return ans;
}

void quickmulti(int t){
    Matrix ans,m;
    memset(ans.ans,0,sizeof(ans.ans));
    memset(m.ans,0,sizeof(m.ans));
    for(int i=0;i<10;i++)
        ans.ans[i][0]=9-i;
    for(int i=0;i<10;i++)
        m.ans[0][i]=a[i];
    for(int i=1;i<10;i++)
        m.ans[i][i-1]=1;
    while(t){
        if(t%2==1)
            ans=multi(m,ans);
        m=multi(m,m);
        t>>=1;
    }
    printf("%d\n",ans.ans[0][0]);

}

int main()
{

   while(~scanf("%d%d",&n,&m)){
      for(int i=0;i<10;i++)
        scanf("%d",&a[i]);
      if(n<10){
        printf("%d\n",n);
        continue;
      }
      quickmulti(n-9);
   }
    return 0;
}

