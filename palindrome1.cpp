#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	int t = 10, count = 1;

	while(count <= t)
	{
		int n;
		scanf("%d", &n);

		char m[8][9];

		for(int i = 0; i < 8; i++)
		{ 
			for(int j = 0; j < 9; j++)
			{
				char c1 = getchar();
				m[i][j] = c1;
			}
		}

		int ans = 0;

		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{				
				if(j + n < 8)
				{
					int miss = 0;
					for(int k = 0; k < n/2; k++)
					{
						if(m[i][j+k] != m[i][j + (n -1) - k])
						{
							miss = 1;
							break;
						}
					}

					if(miss == 0)
					{
						ans += 1;
					}
				}

				if(i + n < 8)
				{
					int miss = 0;
					for(int k = 0; k < n/2; k++)
					{
						if(m[i+k][j] != m[i + (n - 1) - k][j])
						{
							miss = 1;
							break;
						}
					}

					if(miss == 0)
					{
						ans += 1;
					}
				}
			}
		}
	
		printf("#%d %d\n",count++,ans);
	}

	return 0;
}