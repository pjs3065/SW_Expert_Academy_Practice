#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int t, count = 1;
	scanf("%d",&t);

	float a, b, c, d;
	float alice_rate, bob_rate;

	char s[3][10] = {"DRAW","ALICE","BOB"};

	while(count <= t)
	{
		scanf("%d %d %d %d",&a, &b, &c, &d);

		alice_rate = a/b;
		bob_rate = c/d;

		int output;

		if(alice_rate == bob_rate)
			output = 0;
		else if(alice_rate > bob_rate)
			output = 1;
		else
			output = 2;

		printf("#%d %s\n",count++,s[output]); 
	}
	return 0;
}