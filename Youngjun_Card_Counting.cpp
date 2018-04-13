#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	//test case
	int t,count = 1, error;
	cin >> t;

	while(count <= t)
	{
		//card information
		string card_information;
		cin >> card_information;

		//card check
		vector<bool> card(1000);

		//convert shape -> number
		int len = card_information.length();

		error = 0;

		for(int i = 0; i< len; i++)
		{
			switch(card_information[i])
			{
			case 'S': card_information[i] = '0';
				break;

			case 'D': card_information[i] = '1';
				break;

			case 'H': card_information[i] = '2';
				break;

			case 'C': card_information[i] = '3';
			}
		}

		for(int i = 0; i < len/3; i++)
		{
			int sum = 0;

			for(int j = i * 3 ; j < (i * 3) + 3; j++)
			{
				int k = j % 3;
				int number = card_information[j] - '0';

				switch(k)
				{
				case 0:  sum += 100 * number;
					break;
				case 1:  sum += 10 *  number;
					break;
				case 2:  sum +=  number;
				}
			}

			if(card[sum] == true)
			{
				cout << "#" << count++ << ' ' << "ERROR" << '\n';
				error = 1;
				break;
			}

			card[sum] = true;
		}

		if(error != 1)
		{
			int s = 13, d = 13, h = 13, c = 13;

			for(int i = 1; i <= 13; i++)
			{
				if(card[i] == true)
					s--;
			}

			for(int i = 100; i <= 113; i++)
			{
				if(card[i] == true)
					d--;
			}
			for(int i = 200; i <= 213; i++)
			{
				if(card[i] == true)
					h--;
			}
			for(int i = 300; i <= 313; i++)
			{
				if(card[i] == true)
					c--;
			}

			cout << "#" << count++ << ' ' << s << ' ' <<  d << ' ' <<  h << ' ' << c << '\n';
		}
	}
	return 0;
}