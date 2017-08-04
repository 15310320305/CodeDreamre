#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define lcr(a,b) memset(a,b,sizeof(a))
#define sfor(i,n) for(i=1;i<=n;i++)
#define dfor(i,n) for(i=n-1;i>=0;i--)
#define sc(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define ll long long
#define INF 0x7fffffff
#define esp 1e-8


int main()
{
    char s[550];
    map<pair<string ,string > ,int>mp;
    pair<string ,string>p,p1;
    char str1[505];
    while(gets(s)){
        if(s[0]=='#'){
            cout<<p.first<<" "<<p.second<<":"<<mp[p]<<endl;
            mp.clear();
            p.first="";
            p.second="";
            p1=p;
        }
        else {
             int len=strlen(s);
             s[len]='.';
             s[++len]='\0';
             int cnt=0;
             for(int i=0;i<len;i++){
                 if(s[i]>='a'&&s[i]<='z'){
                    str1[cnt++]=s[i];
                 }
                 else {
                        str1[cnt]='\0';
                        if(p1.first.size()){
                                p1.second=str1;
                                mp[p1]++;
                                if(p.first.size()==0){
                                    p=p1;
                                }
                                else {
                                    if(mp[p1]>mp[p]){
                                        p=p1;
                                    }
                                    else if(mp[p1]==mp[p]){
                                        if(p1.first<p.first||p1.first==p.first&&p1.second<p.second){
                                            p=p1;
                                        }
                                    }
                                }
                                p1.first=p1.second;
                        }
                        else {
                            p1.first=str1;
                        }
                    while(i<len&&!(s[i]>='a'&&s[i]<='z')){
                              if(s[i]==','||s[i]=='.'){
                                p1.first="";

                              }
                              i++;
                    }
                    i--;
                    cnt=0;
                 }
             }
        }
    }
    return 0;
}
