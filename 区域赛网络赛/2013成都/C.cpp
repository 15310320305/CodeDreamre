#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[105];
    int t;
    int T = 1;
    cin>>t;
    while(t--)
    {
        scanf("%s",str);
        int len  =strlen(str);
        printf("Case #%d: ",T++);
        if(len>=4&&str[len-1]=='u'&&str[len-2]=='s'&&str[len-3]=='e'&&str[len-4]=='d')
        {
            for(int i=0;i<len-4;i++)
                printf("%c",str[i]);
            printf("nanodesu\n");
        }
        else
        {
            printf("%snanodesu\n",str);
        }
    }
    return 0;
}
