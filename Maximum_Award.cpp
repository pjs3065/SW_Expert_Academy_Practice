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

	//�׽�Ʈ ���̽� �� �Է�
	cin >> t;


	while(count <= t){

		//���ڿ� �ݺ�Ƚ�� �Է�
		cin >> number >> c;

		//������ ����
		len = number.length();

		//�ִ밪 ������ ������ �� ���� �迭�� �����
		temp_max = number;
		sort(temp_max.begin(), temp_max.end(),greater<int>());

		vector<int> temp_number(len);
		for(int i = 0; i < len; i++)
		{
			temp_number[i] = temp_max[i] - '0';
		}

		//�ݺ� Ƚ���� ���� ī��Ʈ 0
		int n = 0;

		for(int i = 0; i < len; i++)
		{
			//�ݺ�Ƚ���� ������ break �Ѵ�
			if(n == c)break;

			//��ü ������ �ǵ� 2���� ������ 2���θ� ������
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