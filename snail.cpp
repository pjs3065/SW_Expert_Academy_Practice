#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t, count = 1;
	int n;

	scanf("%d",&t);

	while(count <= t)
	{
		vector< vector<int> > matrix;
		scanf("%d",&n);

		//�迭 ����
		for(int i = 0; i < n; i++)
		{
			vector<int> element(n);
			matrix.push_back(element);
		}

		//�ݺ��� �� ����

		bool check1;
		bool check2;
		bool check3;
		bool check4;

		int i = 0;
		int j = 0;

		int number = 1;

		do{
			check1 = false;
			check2 = false;
			check3 = false;
			check4 = false;

			//����������

			while (j < n && matrix[i][j] == 0)
			{
				matrix[i][j] = number;
				number ++;
				j++;

				check1 = true;
			}

			j--;
			i++;

			//�Ʒ���
			while(i < n && matrix[i][j] == 0)
			{
				matrix[i][j] = number;
				number ++;
				i++;

				check2 = true;
			}

			i--;
			j--;

			//��������
			while(j >= 0 && matrix[i][j] == 0)
			{
				matrix[i][j] = number;
				number ++;
				j--;

				check3 = true;
			}

			j++;
			i--;

			//��������
			while(i >= 0 && matrix[i][j] == 0)
			{
				matrix[i][j] = number;
				number ++;
				i--;

				check4 = true;
			}

			i++;
			j++;

		}while(check1 == true || check2 == true || check3 == true || check4 == true);

		printf("#%d\n",count++);

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				printf("%d ",matrix[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}