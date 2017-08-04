#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int T = 1;
    cin>>t;
    while(t--)
    {
        char str[1005];
        scanf("%s",str);
        int len =strlen(str);
        int ans = 1e9;
        map<char ,int>mp;
        for(int i=0;i<len;i++)
        {
            if(mp[str[i]])
            {
                ans = min(ans,i+1-mp[str[i]]);
            }
            mp[str[i]] = i+1;
        }
        if(ans==1e9)ans = -1;
        printf("Case #%d: ",T++);
        cout<<ans<<endl;
    }
    return 0;
}
