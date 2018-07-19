#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

//x�� y�� �������� (��, ��, ��, ��)
int m_x[4] = {-1, 1, 0, 0};
int m_y[4] = {0, 0, -1, 1};

int main()
{
	//�׽�Ʈ���̽�
	int t, count = 1;
	scanf("%d", &t);

	while(count <= t)
	{
		//�Է°���
		int n, m, r1, r2, c1, c2;
		scanf("%d %d %d %d %d %d",&n, &m, &r1, &r2, &c1, &c2);

		//������ ������ Ȯ�ο� �����
		vector< vector<int> > board;
		vector< vector<int> > check;

		for(int i = 0; i < n; i++)
		{
			vector<int> element(m);
			board.push_back(element);
			check.push_back(element);
		}

		//queue ���� ó�� ���� �ֱ�
		queue< pair<int,int> > q;
		q.push(make_pair(r1,r2));

		check[r1][r2] = 1; // �湮���� �� 1�� �־��ش�.

		//queue�� ��� ������� ������ ������.
		while(!q.empty())
		{
			//(x,y)�� �����´�.
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			// �����¿� �̵��ϱ�
			for(int i = 0; i < 4; i++)
			{
				int dx = x + m_x[i];
				int dy = y + m_y[i];

				//���� ���� ��� ó��
				if(dx < 0) dx = dx + n;
				else if(dx >= n) dx = dx - n;

				//���� ���� ��� ó��
				if(dy < 0) dy = dy + m;
				else if(dy >= m) dy = dy - m;

				//ó�� �湮 �ϴ� ���� ���� ��ġ�� �̵� �Ÿ����� 1 ����
				if(check[dx][dy] == 0)
				{
					board[dx][dy] =  board[x][y] + 1;
					check[dx][dy] = 1;
					q.push(make_pair(dx,dy));
				}
				// �ٽ� �湮 �ϴ� ���� ������ �湮�ߴ� �Ÿ����� ���� ��� ���� �ٲ��ش�.
				else
				{
					if(board[x][y] + 1 < board[dx][dy])
					{
						board[dx][dy] = board[x][y] + 1;
						q.push(make_pair(dx,dy));
					}
				}
			}

		}
		printf("#%d %d\n",count++, board[c1][c2]);
	}
	return 0;
}
