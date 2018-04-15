#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int t, k;
	int turn[20][2];

	int p[4] = {0,0,0,0};
	int detch[4] = {2,6,2,6};
	int gear[4][8];

	int sum = 0;

	//test
	scanf("%d", &t);
	
	//repeat number
	scanf("%d", &k);

	for(int i = 0; i< 4; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			scanf("%d",&gear[i][j]);
		}
	}

	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			scanf("%d",&turn[i][j]);
		}
	}

	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			bool check1 = false;
			bool check2 = false;
			bool check3 = false;

		}
	}




	return 0;
}