#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

//x와 y의 방향조정 (상, 하, 좌, 우)
int m_x[4] = {-1, 1, 0, 0};
int m_y[4] = {0, 0, -1, 1};

int main()
{
	//테스트케이스
	int t, count = 1;
	scanf("%d", &t);

	while(count <= t)
	{
		//입력값들
		int n, m, r1, r2, c1, c2;
		scanf("%d %d %d %d %d %d",&n, &m, &r1, &r2, &c1, &c2);

		//보드판 만들기과 확인용 만들기
		vector< vector<int> > board;
		vector< vector<int> > check;

		for(int i = 0; i < n; i++)
		{
			vector<int> element(m);
			board.push_back(element);
			check.push_back(element);
		}

		//queue 만들어서 처음 시작 넣기
		queue< pair<int,int> > q;
		q.push(make_pair(r1,r2));

		check[r1][r2] = 1; // 방문했을 시 1을 넣어준다.

		//queue가 모두 비어있을 경우까지 돌린다.
		while(!q.empty())
		{
			//(x,y)를 가져온다.
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			// 상하좌우 이동하기
			for(int i = 0; i < 4; i++)
			{
				int dx = x + m_x[i];
				int dy = y + m_y[i];

				//행을 넘을 경우 처리
				if(dx < 0) dx = dx + n;
				else if(dx >= n) dx = dx - n;

				//열을 넘을 경우 처리
				if(dy < 0) dy = dy + m;
				else if(dy >= m) dy = dy - m;

				//처음 방문 하는 것은 현재 위치의 이동 거리에서 1 더함
				if(check[dx][dy] == 0)
				{
					board[dx][dy] =  board[x][y] + 1;
					check[dx][dy] = 1;
					q.push(make_pair(dx,dy));
				}
				// 다시 방문 하는 곳은 그전에 방문했던 거리보다 작을 경우 값을 바꿔준다.
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
