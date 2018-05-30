#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int count = 1;

	while(count <= 100)
	{
		vector<int> box(101);

		//���� �� �Է�
		int dump = 0;
		scanf("%d", &dump);

		//�ִ밪, �ּڰ�
		int max = -1;
		int min = 101;

		//�Է� �� �ִ밪 �ּڰ� Ž��
		for(int i = 0; i < 100; i++)
		{
			int h;
			scanf("%d", &h);

			box[h]++;
			if(h > max)
			{
				max = h;
			}

			if(h < min)
			{
				min = h;
			}
		}

		//���� �ű�� �۾�
		while(dump != 0)
		{
			box[max]--;
			box[max - 1]++;

			box[min]--;
			box[min + 1]++;

			if(box[max] == 0)
			{
				max = max - 1;
			}

			if(box[min] == 0)
			{
				min = min + 1;
			}

			if(max - min <= 1)
			{
				break;
			}

			dump--;
		}

		//�� ���
		int ans = max - min;
		printf("#%d %d\n", count++, ans);
	}

	return 0;
}