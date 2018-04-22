#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t, count = 1;

	//test case
	scanf("%d",&t);

	while(count <= t)
	{
		int day;
		scanf("%d",&day);

		int head = 0;
		int tail = day - 1;
		int discount = 0;
		int maximum = -1;
		int minimum = 10001;

		//input
		vector<int> price(day);

		for(int i = 0; i < day ; i++)
		{
			scanf("%d",&price[i]);
		}

		//discount check
		while(1)
		{
			if(head >= day) break;

			//initialize head, tail, maximum and minimum
			for(int i = head; i <= day - 1; i++)
			{
				if(maximum < price[i])
				{
					maximum = price[i];
					tail = i;
				}

				if(minimum > price[i])
				{
					minimum = price[i];
				}
			}

			if(maximum == minimum) break;
			if(head == tail) continue;
			
			int select = head - tail;
			int price_count = 0;

			for(int i = head; i < tail; i++)
			{
				price_count += price[i];
			}

			discount = discount + (select * price[tail] - price_count); 

			//next head
			head = tail + 1;
		}

		int ans = discount;

		//output
		cout << "#" << count++ << ' ' << ans << '\n';
	}

return 0;
}