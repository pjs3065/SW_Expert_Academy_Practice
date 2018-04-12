#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;

int main()
{
	int t,c;
	int count = 1;
	int len;

	string number;
	string temp_max;

	//테스트 케이스 수 입력
	cin >> t;


	while(count <= t){

		//숫자와 반복횟수 입력
		cin >> number >> c;

		//숫자의 길이
		len = number.length();

		//최대값 순으로 정렬한 후 숫자 배열로 만들기
		temp_max = number;
		sort(temp_max.begin(), temp_max.end(),greater<int>());

		vector<int> temp_number(len);
		for(int i = 0; i < len; i++)
		{
			temp_number[i] = temp_max[i] - '0';
		}

		//반복 횟수는 현재 카운트 0
		int n = 0;

		for(int i = 0; i < len; i++)
		{
			//반복횟수가 맞으면 break 한다
			if(n == c)break;

			//전체 숫자중 맨뒤 2개만 빼놓고 2개로만 돌리기
			if(len - i <= 2)
			{
				swap(number[i],number[i+1]);
				i = i - 1;
				n = n + 1;
				continue;
			}

			if(number[i] - '0' == temp_number[i]) continue;

			int max = number[i] - '0';
			int max_point = i;

			for(int j = len - 1; j >= i + 1; j--)
			{
				if(max < number[j] - '0')
				{
					max = number[j] - '0';
					max_point = j;
				}
			}

			if(max != number[i] - '0' && max_point != i)
			{
				swap(number[i],number[max_point]);
				n = n + 1;
			}
		}

		//print output
		cout << "#" << count++ << ' ' << number << '\n';
	}

	return 0;
}