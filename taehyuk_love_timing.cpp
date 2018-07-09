#include<stdio.h>

const int time =  (11 * 24 * 60) + (11 * 60) + 11;

int main()
{
	int t, count = 1;
	scanf("%d", &t);

	while(count <= t)
	{
		int d, h, m;
		scanf("%d %d %d", &d, &h, &m);
		
		int t_time = (d * 24 * 60) + (h * 60) + m;
		int wait_time = t_time - time < 0 ? -1 : t_time - time;

		printf("#%d %d\n", count++, wait_time); 
	}
	return 0;
}