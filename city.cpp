#include<stdio.h>
#include<vector>

using namespace std;

//�����̵��Ͽ� �Ҹ��� Ȯ���Ϸ��� �� (x,y)�� �������� ����� ����
int way_x[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
int way_y[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

int main()
{
	//�׽�Ʈ���̽�
	int t, count = 1;
	scanf("%d", &t);

	//���� ũ��
	int n;

	while(count <= t)
	{
		scanf("%d", &n);

		//���� ���� 2���� �迭 ����
		vector< vector<int> > map;

		for(int i = 0; i < n; i++)
		{
			vector<int> element(n);
			map.push_back(element);
		}

		//������ ���� �ֱ�(�Ҹ��� : 0, �� : 1, �� : 2, �ʿ� : 3)
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%d",&map[i][j]);
			}
		}

		int city_count = 0; // ���ðǼ� ���� ��

		//���� Ž��
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				//���� ��� �ʿ��� �ִ��� üũ
				vector<int> check(4); 

				//���� ��ġ�� ���� �Ҹ����� ��� �ٸ� ��ġ�� �̵�
				if(map[i][j] == 0) continue;

				//�Ҹ����� �ƴ� ��쿡 üũ �ݿ�
				else check[map[i][j]] = 1;

				//���� ��ġ���� ��ġ �̵��ϸ鼭 üũ�ϱ�
				for(int k = 0; k < 8; k++)
				{
					int d_x = i + way_x[k];
					int d_y = j + way_y[k];

					//������ ���� ���� �ʴ� �ѿ����� üũ�ϱ�
					if(d_x >= 0 && d_x < n && d_y >= 0 && d_y < n)
					{
						int current_info = map[d_x][d_y]; //���� �̵������� �� ��ġ�� ���� (�Ҹ���, ��, ��, �ʿ�)

						if(current_info == 0)
						{
							check[current_info] = 1;
							break; // �Ҹ�����  ���� ��쿡�� Ȯ���� ���߰� �ٸ� ��ġ�� �̵�
						}

						else check[current_info] = 1; //�ִ��� ���� Ȯ�� �� �ֱ� (0�� ����. 1�� �ִ�)
					}
				}

				//�Ҹ����� �ϳ��� ������ ���� ��ġ�� �̵�
				if(check[0] == 1) continue;

				//��, ��, �ʿ��� ��� �ִ� �� Ȯ���ϱ�
				int check_count = 0;

				for(int z = 1; z < 4; z++)
				{
					if(check[z] == 1)
					{
						check_count++;
					}
				}

				//������ ��� ���� ��� �Ǽ��� �� �ִٰ� üũ���ش�.
				if(check_count == 3)
				{
					city_count++;
				}
			}
		}

		printf("#%d %d\n", count++, city_count);
	}
	return 0;
}