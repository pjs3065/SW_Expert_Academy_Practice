#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, count = 1;
	scanf("%d",&t);
	
	while(count <= t)
	{
		int n, k;
		vector<int> scores;
		scanf("%d %d",&n,&k);

		for(int i = 0; i < n; i++)
		{
			int score;
			scanf("%d",&score);
			scores.push_back(score);
		}

		sort(scores.rbegin(),scores.rend());

		int sum = 0;

		for(int i = 0; i < k; i++)
		{
			sum += scores[i];
		}

		printf("#%d %d\n", count++, sum);
	}
	return 0;
}