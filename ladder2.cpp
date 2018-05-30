#include<stdio.h>
#include<vector>

using namespace std;

int mx[3] = {0,0,1}; // 좌 우 하
int my[3] = {-1,1,0};

int main()
{
	int count = 1;

	while(count <= 10)
	{
		int t;
		scanf("%d",&t);

		vector < vector<int> > map;

		for(int i = 0; i < 100; i++)
		{
			vector<int> element(100);
			map.push_back(element);
		}

		vector<int> start_y;

		//시작점 가져오기
		for(int i = 0; i < 100; i++)
		{
			for(int j = 0; j < 100; j++)
			{
				scanf("%d",&map[i][j]);

				if(i == 0 && map[0][j] == 1)
				{
					start_y.push_back(j);
				}
			}
		}

		int length = start_y.size();
		int option = -1;
		int ans = 0;
		int min = 999999;

		//모든 사다리 구하기
		for(int j = 0; j < length; j++)
		{
			int x = 0;
			int y = start_y[j];
			int d = 0;
			

			while(x != 99)
			{
				for(int i = 0; i < 3; i++)
				{
					if(i == option)
					{
						continue;
					}

					int dx = x + mx[i];
					int dy = y + my[i];

					if(dy >= 0 && dy < 100)
					{
						if(map[dx][dy] == 1)
						{
							x = dx;
							y = dy;

							switch(i)
							{
							case 0 : option = 1; break;
							case 1 : option = 0; break;
							case 2 : option = -1; break;
							}

							d++;
							break;
						}
					}
				}
			}

			if(d < min)
			{
				min = d;
				ans = start_y[j];
			}
		}
		printf("#%d %d\n", count++, ans);
	}

	return 0;
}