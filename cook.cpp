#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	//�׽�Ʈ ���̽��� ���� ���� �Է�
	int t,n, count = 1;
	scanf("%d",&t);

	while(count <= t)
	{
		scanf("%d",&n);

		vector< vector<int> > si;
		vector<int> order;

		//������ �ó��� �Է�
		for(int i = 0; i < n; i++)
		{
			vector<int> element(n);
			si.push_back(element);
		}

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%d",&si[i][j]);
			}
		}

		//���ĸ���� ���� �Է��ϱ� ���ؼ� 
		for(int i = 0; i < n; i++)
		{
			if(i < n/2)
				order.push_back(1);
			else
				order.push_back(2);
		}

		int ans = 9999999;

		do{
			int siA = 0;
			int siB = 0;

			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					if(i == j) continue;

					if(order[i] == 1 && order[j] == 1)
					{
						siA += si[i][j];
					}

					if(order[i] == 2 && order[j] == 2)
					{
						siB += si[i][j];
					}

				}
			}

			int result = siA-siB;
			result = result < 0 ? -result : result;

			if(ans > result)
			{
				ans = result;
			}

		}while(next_permutation(order.begin(), order.end()));

		printf("#%d %d\n",count++,ans);
	}
	return 0;
}