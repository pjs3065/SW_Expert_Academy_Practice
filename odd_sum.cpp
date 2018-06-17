#include<stdio.h>
int main()
{
	int t; 
	scanf("%d",&t);

	while(t--)
	{
		int n;
		int sum = 0;

		for(int i = 0; i< 10; i++)
		{
			scanf("%d",&n);
			if(n % 2)
			{
				sum+= n;
			}
		}

		printf("#%d %d\n",3 - t, sum);
	}
	return 0;
}