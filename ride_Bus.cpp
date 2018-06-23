#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;


int Answer;

int main(int argc, char** argv)
{
	setbuf(stdout, NULL);
	cin.sync_with_stdio(false);

	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;

		int n;
		long long k;

		//input case
		cin >> n;
		cin >> k;

		//input player information
		vector<int> player(n);
		vector<int> ischeck(n);
		for(int i = 0; i < n; i++)
		{
			cin >> player[i];
		}

		//ascending order
		sort(player.begin(),player.end());

		int n_count = 0;

		for(int i = 0; i < n; i++)
		{
			if(n_count == n)
			{
				break;
			}

			if(ischeck[i] == 1)
			{
				continue;
			}

			else
			{
				ischeck[i] = 1;
				int temp = i;
				int first = 0;
				n_count += 1;

				for(int j = i + 1; j < n; j++)
				{

					if(n_count == n)
					{
						break;
					}

					if(ischeck[j] == 1)
					{
						continue;
					}

					if(abs(player[temp] - player[j]) > k)
					{
						temp = j;
						ischeck[j] = 1;
						n_count += 1;
					}

					else if(abs(player[temp] - player[j]) <= k && first == 0)
					{
						first = 1;
						i = j - 1;
					}
				}
			}
			Answer += 1;
		}

		cout << "Case #" << test_case+1 << '\n';
		cout << Answer << '\n';
	}

	return 0;
}