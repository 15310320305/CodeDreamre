/**
���Ǽ���gcd(n,i) = k����gcd(n/k,i/k) = 1��������gcd(n/k, x ) = 1����gcd(n,x*k) = k��gcd(n,i) = k,
k��ȡֵ��ȷ���ģ���n���������ӣ����ԣ�����gcd(n/k,x) = 1��x�ĸ�������k��Ϊ��������gcd(n,i) = k �ĺ͡�
��˾�ת��Ϊn/k��ŷ��������ֵ����k�����еĺ͡�
�ٸ�����12��˵��12������Ϊ1��2��3��4��6��12��
���Ϊ12/1��ŷ������ֵ*1 + 12/2��ŷ������ֵ * 2 + 12/3��ŷ������ֵ * 3 + 12/4��ŷ������ֵ * 4 + 12/6��ŷ������ֵ*6 + 12/12 ��ŷ������ֵ * 12��

*/


#include<bits/stdc++.h>
using namespace std;

const int M = 1e6+10;
int vis[M+10],prime[M+10],phi[M+10];
int cnt;
int n;

void PHI()  //������������������������ŷ��������ֵ�� ģ�塣
{
    memset(vis,0,sizeof(vis));
    cnt=0;
    phi[1] = 1;
    for(int i=2;i<M;i++){
    if(vis[i]==0){
        prime[cnt++]=i;
        phi[i]=i-1;     //i�������������ôǰ��i-1�����������ʡ�
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
