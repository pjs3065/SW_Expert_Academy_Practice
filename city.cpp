#include<stdio.h>
#include<vector>

using namespace std;

//방향이동하여 불모지 확인하려고 함 (x,y)의 증가량을 적어둔 거임
int way_x[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
int way_y[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

int main()
{
	//테스트케이스
	int t, count = 1;
	scanf("%d", &t);

	//지도 크기
	int n;

	while(count <= t)
	{
		scanf("%d", &n);

		//지도 넣을 2차원 배열 생성
		vector< vector<int> > map;

		for(int i = 0; i < n; i++)
		{
			vector<int> element(n);
			map.push_back(element);
		}

		//지도에 정보 넣기(불모지 : 0, 물 : 1, 산 : 2, 초원 : 3)
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%d",&map[i][j]);
			}
		}

		int city_count = 0; // 도시건설 가능 수

		//지도 탐색
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				//물과 산과 초원이 있는지 체크
				vector<int> check(4); 

				//현재 위치한 곳이 불모지일 경우 다른 위치로 이동
				if(map[i][j] == 0) continue;

				//불모지가 아닌 경우에 체크 반영
				else check[map[i][j]] = 1;

				//현재 위치에서 위치 이동하면서 체크하기
				for(int k = 0; k < 8; k++)
				{
					int d_x = i + way_x[k];
					int d_y = j + way_y[k];

					//범위를 벗어 나지 않는 한에서만 체크하기
					if(d_x >= 0 && d_x < n && d_y >= 0 && d_y < n)
					{
						int current_info = map[d_x][d_y]; //현재 이동했을때 그 위치의 정보 (불모지, 물, 산, 초원)

						if(current_info == 0)
						{
							check[current_info] = 1;
							break; // 불모지가  있을 경우에는 확인을 멈추고 다른 위치로 이동
						}

						else check[current_info] = 1; //있는지 여부 확인 값 넣기 (0은 없다. 1은 있다)
					}
				}

				//불모지가 하나라도 있으면 다음 위치로 이동
				if(check[0] == 1) continue;

				//물, 산, 초원이 모두 있는 지 확인하기
				int check_count = 0;

				for(int z = 1; z < 4; z++)
				{
					if(check[z] == 1)
					{
						check_count++;
					}
				}

				//세개다 모두 있을 경우 건설할 수 있다고 체크해준다.
				if(check_count == 3)
				{
					city_count++;
				}
			}
		}

		printf("#%d %d\n", count++, city_count);
	}
	return 0;
}