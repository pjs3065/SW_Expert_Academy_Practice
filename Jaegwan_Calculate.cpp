#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;
int main()
{
	//input test case
	int t, count = 1;
	cin >> t;

	//repeat as test case
	while( count <= t )
	{
		//input number of item
		int n;
		cin >> n;

		//input item price
		vector<int> item_price(n);

		int total_price = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> item_price[i];
			total_price += item_price[i];
		}

		// sort for permutation
		sort(item_price.begin(), item_price.end(), greater<int>());

		int ans = total_price;

			int discount = 0;

			for(int i = 0; i < n / 3; i++)  // n = 3  n = 5 n = 7
			{
				int min_item = 100001;
				for(int j = i * 3; j < (i * 3) + 3; j++) // 0 ~ 2 //3 ~ 5
				{
					if(min_item > item_price[j])
					{
						min_item = item_price[j]; 
					}
				}
				discount += min_item;
			}

			int discount_price = total_price - discount;

			if(ans > discount_price)
			{
				ans = discount_price;
			}

		cout << "#" << count++ << ' ' << ans << '\n';
	}
	return 0;
}

