#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	int t, count = 1;
	scanf("%d", &t);

	while(count <= t)
	{
		string str;
		cin >> str;

		int len = str.length();

		printf("#%d ", count++); 

		for(int i = 0; i < len; i++)
		{
			if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') continue;
			printf("%c",str[i]);
		}
		
		printf("\n");
	}
	return 0;
}