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

		//덤프 수 입력
		int dump = 0;
		scanf("%d", &dump);

		//최대값, 최솟값
		int max = -1;
		int min = 101;

		//입력 및 최대값 최솟값 탐색
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

		//상자 옮기기 작업
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

		//답 출력
		int ans = max - min;
		printf("#%d %d\n", count++, ans);
	}

	return 0;
}