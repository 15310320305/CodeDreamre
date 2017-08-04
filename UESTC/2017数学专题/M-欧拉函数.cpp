/**
我们假设gcd(n,i) = k，则gcd(n/k,i/k) = 1。即假设gcd(n/k, x ) = 1，则gcd(n,x*k) = k。gcd(n,i) = k,
k的取值是确定的，即n的所有因子，所以，满足gcd(n/k,x) = 1个x的个数乘以k即为所有满足gcd(n,i) = k 的和。
因此就转化为n/k的欧拉函数的值乘以k的所有的和。
举个例子12来说，12的因子为1，2，3，4，6，12，
则和为12/1的欧拉函数值*1 + 12/2的欧拉函数值 * 2 + 12/3的欧拉函数值 * 3 + 12/4的欧拉函数值 * 4 + 12/6的欧拉函数值*6 + 12/12 的欧拉函数值 * 12。

*/


#include<bits/stdc++.h>
using namespace std;

const int M = 1e6+10;
int vis[M+10],prime[M+10],phi[M+10];
int cnt;
int n;

void PHI()  //即可以求出素数，还可以求出欧拉函数的值！ 模板。
{
    memset(vis,0,sizeof(vis));
    cnt=0;
    phi[1] = 1;
    for(int i=2;i<M;i++){
    if(vis[i]==0){
        prime[cnt++]=i;
        phi[i]=i-1;     //i如果是素数，那么前面i-1个都与它互质。
    }
     for(int j=0;j<cnt&&prime[j]*i<M;j++){
       vis[i*prime[j]]=1;
       if(i%prime[j]==0){
            phi[i*prime[j]]=phi[i]*prime[j];
            break;
       }
       else phi[i*prime[j]]=phi[i]*phi[prime[j]];
     }
    }
}

int main()
{
    PHI();
    cin>>n;
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        int a;scanf("%d",&a);
        int b = sqrt(a);
        if(b*b==a)
        {
            ans+=(long long)b*phi[b];
            b--;
        }
        for(int j=1;j<=b;j++)
        {
            if(a%j==0)
            {
                ans+=(long long)a/j*phi[j];
                ans+=(long long)j*phi[a/j];
            }
        }
        ans-=a;
    }

    cout<<ans<<endl;
    return 0;
}
