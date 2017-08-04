#include<bits/stdc++.h>
using namespace std;

int n;
struct st
{
    long long a,b;
}s[1000005];
bool cmp(st aa,st bb)
{
    if(aa.a==bb.a)return aa.b>bb.b;
    return aa.a<bb.a;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)scanf("%I64d%I64d",&s[i].a,&s[i].b);
    sort(s,s+n,cmp);
    long long ans = 0;
    long long num  = 0;
    for(int i=0;i<n;i++)
    {
       if(i==0)
       {
           ans+=s[i].a;
           num+=s[i].b;
       }
       else
       {
           if(num>=s[i].a)
           {
               num-=s[i].a;
               num+=s[i].b;
           }
           else
           {
               long long now = ans+s[i].a - num;
               long long now1 = s[i].a;
               if(s[i].b>=ans)
               {
                    if(now>=now1)
                    {
                        ans = now1;
                        num = s[i].b-ans+num;
                    }
                    else
                    {
                        ans = now;
                        num = s[i].b;
                    }
               }
               else
               {
                   now1+=ans-s[i].b;

                   if(now>now1)
                    {
                        ans = now1;
                        num = num;
                    }
                    else if(now==now1)
                    {
                        ans = now1;
                        num = max(num,s[i].b);
                    }
                    else
                    {
                        ans = now;
                        num = s[i].b;
                    }

               }

           }
       }
    }
    cout<<ans<<endl;
    return 0;
}
