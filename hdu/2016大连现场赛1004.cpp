    #include<iostream>
    #include<cstdio>
    #include<algorithm>
    #include<cmath>
    using namespace std;

    int gcd(int a,int b){
        if(b==0)return a;
        else return gcd(b,a%b);
    }

    int main()
    {
        long long a,b;
        while(~scanf("%lld%lld",&a,&b)){
           b*= __gcd(a,b);
           if(a*a-4*b>=0){
          long long dd =sqrt(a*a-4*b);
           if(dd*dd==a*a-4*b){
              long long x1 = (a-dd)/2;
              long long x2 = (a+dd)/2;
              if(x1*2==a-dd&&x1>0&&x1<a){
                printf("%lld %lld\n",min(x1,a-x1),max(x1,a-x1));
              }
              else if(x2*2==a+dd&&x2>0&&x2<a){
                 printf("%lld %lld\n",min(x2,a-x2),max(x2,a-x2));
              }
              else printf("No Solution\n");
           }
           else printf("No Solution\n");
           }
           else printf("No Solution\n");
        }
        return 0;
    }
