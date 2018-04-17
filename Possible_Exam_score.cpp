#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<bool> score_sum(10001);

void cal(vector<int> &score, int i, int sum)
{
	score_sum[sum] = true;
    printf("%d ", sum );

	if(i == n) return;

	cal(score, i + 1, sum);
	
	if(i != -1)
	{
		cal(score, i + 1, sum + score[i]);
	}
}

int main()
{
	int t, count = 1;

	scanf("%d",&t);

	while(count <= t)
	{
		cin >> n;

		vector<int> score;

		for(int i = 0; i < n; i++)
		{
			int temp;
			scanf("%d",&temp);

			score.push_back(temp);
		}

		sort(score.begin(), score.end());

		cal(score,-1,0);

		int ans = 0;

		for(int i = 0; i < 10000; i++)
		{
			if(score_sum[i] == true)
			{
				ans++;
				score_sum[i] = false; //다시 초기화 해주기 위해
			}
		}

		printf("#%d %d\n",count++,ans);
	}
}