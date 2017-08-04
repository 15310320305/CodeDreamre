


#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
for(int z=1;z<=n;z++)
	{
		int i,x;
		int nowstart=1,start=1,end=1,sum,max;
		scanf("%d%d",&i,&x);
		sum=max=x;
		for(int j=2;j<=i;j++)
		{
			scanf("%d",&x);
			if(sum+x<x)
			{
				sum=x;
				nowstart=j;
			}
			else
			sum=sum+x;


		  if (sum>max)
                {
                    max=sum;
                    start=nowstart;
                    end=j;
                }

	}
	 printf("Case %d:\n",z);
            printf("%d %d %d\n",max,start,end);
            if (z!=n)
            {
                printf("\n");
            }
}
}
