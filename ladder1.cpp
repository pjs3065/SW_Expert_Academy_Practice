#include<stdio.h>
#include<vector>

using namespace std;

int mx[3] = {0,0,-1}; // �� �� ��
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

		int x;
		int y;

		//������ ��������
		for(int i = 0; i < 100; i++)
		{
			for(int j = 0; j < 100; j++)
			{
				scanf("%d",&map[i][j]);

				if(map[i][j] == 2)
				{
					x = i;
					y = j;
				}
			}
		}

		int option = 1; // 1 : ���� 2: �·� 3: ���

		//��ٸ� Ÿ��
		while(x != 0)
		{
			for(int i = 0; i < 3; i++)
			{
				int dx = x + mx[i];
				int dy = y + my[i];

				if(dy >= 0 && dy < 100)
				{
					if(map[dx][dy] == 1)
					{
						map[x][y] = 0;
						x = dx;
						y = dy;
					}
				}
			}
		}
		printf("#%d %d", count++, y);
	}



	return 0;
}