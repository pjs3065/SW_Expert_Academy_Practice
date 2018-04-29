#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t, count = 1;
	scanf("%d", &t);

	while(count <= t)
	{
		//입력
		int n, m;
		scanf("%d %d",&n, &m);

		//2차원 filed 만들기 (n = 3 m = 2)
		vector< vector<bool> > field;
		for(int i = 0; i < m; i++)
		{
			vector<bool> element(n);
			field.push_back(element);
		}

		int number = 0;

		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(field[i][j] == true)
				{
					continue;
				}

				field[i][j] = true;
				number += 1;

				if(i-2 >=0 && j-2 >= 0)
				{
					field[i-2][j-2] = true;
					field[i][j-2] = true;
					field[i-2][j] = true;
				}
				else
				{
					if(i-2 >=0) field[i-2][j] = true;
					if(j-2 >=0) field[i][j-2] = true; 
				}

				if(i+2 < m && j+2 < n)
				{
					field[i+2][j+2] = true;
					field[i][j+2] = true;
					field[i+2][j] = true;
				}
				else
				{
					if(i+2 < m) field[i+2][j] = true;
					if(j+2 < n) field[i][j+2] = true; 
				}
			}
		}

		int ans = number;

		//출력
		printf("#%d %d\n",count++,ans);
	}
	return 0;
}