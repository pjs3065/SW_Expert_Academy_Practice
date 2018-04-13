#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

queue<int> min_q;
queue<int> max_q;

int main()
{
	int t;
	scanf("%d",&t);

	int n, drop;
	scanf("%d %d",&n, &drop);

	int map[64];
	int min = 21;
	int max = 0;

	//�Է¹����鼭 ���� ���� �ִ�, �ּҰ� ���ϱ�
	for(int i = 0; i < n * n; i++)
	{
		scanf("%d",&map[i]);
		if(min > map[i]) min = map[i];
		if(max < map[i]) max = map[i];
	}

	//���������� �������� ã�� ����
	for(int i = 0; i < n * n; i++)
	{
		if(map[i] == max)
		{
			max_q.push(i);
		}

		if(map[i] == min)
		{
			min_q.push(i);
		}
	}

}