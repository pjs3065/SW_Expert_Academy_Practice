#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
	int t;
	int max;
	int count = 10;

	while(count--)
	{
		vector<int>view(1000);

		//test case number
		cin >> t;

		//input buildings
		vector<int>building(t);

		for(int i = 0; i < t; i++)
		{
			cin >> building[i];
		}

		for(int i = 2; i < t - 2; i++)
		{
			//����Ȯ��
			if(building[i] > building[i-1] && building[i] > building[i-2])
			{
				//������Ȯ��
				if(building[i] > building[i+1] && building[i] > building[i+2])
				{
					int left_max = building[i-1] < building[i-2] ? building[i-2]:building[i-1];
					int right_max = building[i+1] < building[i+2] ? building[i+2]:building[i+1];

					view[i] = left_max < right_max ? building[i] - right_max : building[i] - left_max;
				}
			}
		}

		int ans = 0;

		for(int i = 0; i < t; i++)
		{
			ans += view[i];
		}

		cout << "#" << 10 - count << ' ' << ans << '\n';
	}
	return 0;
}
