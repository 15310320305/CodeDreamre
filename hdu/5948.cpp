#include<cstdio>
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(x<y)
        {
            int t = x;
            x = y;
            y = t;
        }
        printf("%d\n",x*2+y);
    }

    return 0;
}
