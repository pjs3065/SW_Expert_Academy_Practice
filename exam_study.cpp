#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	//테스트케이스
	int t, count = 1;
	scanf("%d", &t);

	while(count <= t)
	{
		//입력
		int n, s, j, k; // n: 전체, s : 시작, j : 건너뛸, k : 쉬어가는 페이지수
		scanf("%d %d %d %d", &n, &s, &j, &k);

		//건너뛸 페이지 정보 입력
		vector<int> k_page(n + 1);

		for(int i = 0; i < k; i++)
		{
			int info;
			scanf("%d", &info);
			k_page[info] = 1;
		}

		int page_count = 0;

		for(int i = 0; s + ((j + 1) * i) <= n; i++)
		{
			int current_page = s + ((j + 1) * i);
			if(k_page[current_page] == 1)
			{
				page_count++;
			}
		}

		printf("#%d %d\n", count++, page_count);
	}
	return 0;
}