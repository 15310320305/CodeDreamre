#include<bits/stdc++.h>

using namespace std;
char str[100005];
int main()
{
    while(~scanf("%s",str))
    {
        if(strstr(str,"Apple")||strstr(str,"iPhone")||strstr(str,"iPod")||strstr(str,"iPad"))
        {
            printf("MAI MAI MAI!\n");
        }
        if(strstr(str,"Sony"))
        {
            printf("SONY DAFA IS GOOD!\n");
        }

    }
}
