#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> camera;



int main()
{
	int t, n, k;
	queue<pair<int,int>> q;
	
	//input
	cin >> t >> n >> k;

	for(int i = 0; i < n; i++)
	{ 
		cin >> camera[i];
	}

	vector<bool> check(1000000);

	//order
	sort(camera.begin(), camera.end());

	//push into queue
	q.push(make_pair(0,1));

	while(!q.empty())
	{
		int first = q.front().first;
		int second = q.front().second;

		for(int i = first; i <= second; i++)
		{
			if(check[i] == false)
			{
				check[i] = true;
			}
			else
				break;
		}

		if(check[second] == true)
		{

		}



	}




}