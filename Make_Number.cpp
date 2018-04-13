#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int main()
{
	//�׽�Ʈ���̽�
	int t;
	int count = 1;
	cin >> t;

	while(count <= t)
	{
		//������ ����
		int use_number;
		cin >> use_number;

		//���۷��̼ǿ� ���� �迭
		vector<int> op;

		for(int i = 0; i< 4; i++)
		{
			int n;
			cin >> n; 
			for(int j = 0; j < n ; j++)
			{
				op.push_back(i+1);
			}
		}

		vector<int> number(use_number);

		for(int i = 0 ; i < use_number; i++)
		{
			cin >> number[i];
		}

		int max = -1000000001;
		int min = 1000000001;

		//������ ������ ���� ���
		do{
			int sum = number[0];

			for(int i = 0; i < use_number - 1; i++)
			{
				switch (op[i])
				{
				case 1: sum = sum + number[i+1];
					break;
				case 2: sum = sum - number[i+1];
					break;
				case 3: sum = sum * number[i+1];
					break;
				case 4: sum = sum / number[i+1];
				}
			}


			if(max < sum)
				max = sum;

			if(min > sum)
				min = sum;

		}while(next_permutation(op.begin(), op.end()));

		int ans = max - min;
		cout << "#" << count++ << ' ' << ans << '\n';
	}
	return 0;
}