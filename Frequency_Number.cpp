#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t, n, count = 10;

	while(count--)
	{
		cin >> t;

		vector<int> frequency(101);

		for(int i = 0; i < 1000; i++)
		{
			cin >> n;
			frequency[n] += 1;
		}

		int max = 0;
		int ans;

		for(int i = 0; i < 101; i++)
		{
			if(max <= frequency[i])
			{
				max = frequency[i];
				ans = i;
			}
		}

		cout << "#" << t << ' ' << ans << '\n';
	}
	return 0;
}
