#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int t, count = 1;
	

	while(count <= 10)
	{
		scanf("%d",&t);
		vector< vector<int> > map;

		for(int i = 0; i< 100; i++)
		{
			vector<int> element(100);
			map.push_back(element);
		}

		for(int i = 0; i < 100; i++)
		{
			for(int j = 0; j < 100; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		//행 기준 합계
		int max = -1;

		for(int i = 0; i < 100; i++)
		{
			int sum = 0;

			for(int j = 0; j < 100; j++)
			{
				sum += map[i][j];
			}

			if(max < sum)
			{
				max = sum;
			}
		}

		//열 기준 합계

		for(int j = 0; j < 100; j++)
		{
			int sum = 0;

			for(int i = 0; i < 100; i++)
			{
				sum += map[i][j];
			}

			if(max < sum)
			{
				max = sum;
			}
		}

		//대각 선 기준 합계
		int dig_sum1 = 0;
		int dig_sum2 = 0;

		for(int i = 0; i < 100; i++)
		{
			dig_sum1+= map[i][i];
			dig_sum2+= map[99-i][99-i];
		}

		if(max < dig_sum1)
		{
			max = dig_sum1;
		}

		if(max < dig_sum2)
		{
			max = dig_sum2;
		}

		printf("#%d %d\n",t, max);
		count++;
	}

	return 0;
}