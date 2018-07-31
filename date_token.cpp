#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int t, count = 1;
	scanf("%d", &t);

	while(count <= t)
	{
		string date;
		cin >> date;

		string y = date.substr(0,4);
		string m = date.substr(4,2);
		string d = date.substr(6,2);

		int mon = stoi(m);
		int day = stoi(d);

		if(mon > 0 && mon <= 12)
		{
			if(day > 0 && day <= month[mon])
			{
				cout << '#' << count++ << ' ';
				cout << y << '/' << m << '/' << d << '\n';
			}

			else
			{
				cout << '#' << count++ << ' ' << "-1" << '\n';
			}
		}

		else
		{
			cout << '#' << count++ << ' ' << "-1" << '\n';
		}
	}

	return 0;
}
