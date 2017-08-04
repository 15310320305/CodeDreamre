#include<stdio.h>
int main()
{
    int y,m,d;

    while(~scanf("%d",&m))
    {
        int num=0;
        switch(m-1)
        {
        default : printf("111111\n");
        case 11 :
            num+=30;
        case 10 :
            num+=31;
        case 9 :
            num+=30;

        }
        printf("%d\n",num);
    }
    return 0;
}
