#include<bits/stdc++.h>
using namespace std;
char s1[100005],s2[100005];
int len1,len2;
int Next[100005];

void getnext()
{
    int i = -1,j = 0;
    Next[0] = -1;
    while(j<len2)
    {
        if(i==-1||s2[i]==s2[j])
        {
            i++,j++;
            Next[j] = i;
        }
        else i = Next[i];
    }
}

int KMP()
{
    int i =0, j = 0,ans = 0;
    while(j<len1)
    {
        if(i==-1||s1[j]==s2[i])
        {
            i++,j++;
        }
        else i = Next[i];
        if(i==len2)
        {
            ans++;
            i = 0;
        }
    }
    return ans;
}

int main()
{
    scanf("%s%s",s1,s2);
    len1 = strlen(s1);
    len2 = strlen(s2);

    getnext();
    printf("%d\n",KMP());
    return 0;
}
