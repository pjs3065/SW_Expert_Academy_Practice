#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int t, count = 1;
	scanf("%d", &t);

	long long n;

	while(count <= t)
	{
		scanf("%lld", &n);

		vector<int> project;

		for(int i = 0; i < n; i++)
		{
			long long price;
			scanf("%lld", &price);

			project.push_back(price);
		}

		long long total = 0;
		long long start = 0;
		long long index = 0;

		while(start < n)
		{
			int high = -1;

			//ÃÖ´ë°ª »Ì±â
			for(int i = start; i < n; i++)
			{
				if(high < project[i])
				{
					high = project[i];
					index = i;
				}
			}

			//ÀÌµæ ÇÕÇÏ±â
			for(int i = start; i < index; i++)
			{
				total += high - project[i];
			}

			start = index + 1;
		}

		printf("#%d %lld\n",count++, total);
	}
	return 0;
}