#include<bits/stdc++.h>

using namespace std;
int ch[26];
int main()
{
    ch['B'-'A'] = 0,ch['K'-'A']=1,ch['M'-'A'] = 2;
    ch['G'-'A'] = 3,ch['T'-'A']=4,ch['P'-'A'] = 5;
    ch['E'-'A'] = 6,ch['Z'-'A']=7,ch['Y'-'A'] = 8;
    int t;cin>>t;int T  =1;
    while(t--)
    {
        char str[100];
        scanf("%s",str);
        int len = strlen(str);
        int i= 0;
        int ans = 0;
        while(str[i]!='[')
        {
            ans+=ans*10+str[i]-'0';
            i++;
        }
        int x = ch[str[i+1]-'A'];
        double a = ans,b = ans;
        while(x)
        {
            a*=1024.0;
            b*=1000.0;
            x--;
        }
        printf("Case #%d: %.2lf",T++,(1.0-b/a)*100.0);
        puts("%");
    }
    return 0;
}
