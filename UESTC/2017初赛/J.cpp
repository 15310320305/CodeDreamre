#include<cstdio>
#include<map>
using std::map;
int main()
{
    int n,k;
    map<int,int>mp;
    int cnt = 0;
    scanf("%d%d",&n,&k);
    int num[100005];
    int l= 1,r = n;
    int flag = 0;
    for(int i=1;i<=k;i++){
        if(i%2==1){
            num[i]=l;
            l++;
            flag = 1;
        }else {
            num[i]=r;
            r--;
            flag = 2;
        }
    }
    if(flag== 1){
        for(int i=k+1;i<=n;i++,l++){
            num[i]=l;
        }
    }else {
        for(int i=k+1;i<=n;i++,r--)
            num[i]=r;
    }
    for(int i=1;i<n;i++)
        printf("%d ",num[i]);
    printf("%d\n",num[n]);
    return 0;
}
