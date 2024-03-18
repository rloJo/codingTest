#include <iostream>
#include <vector>
#include <queue>

#define X first 
#define Y second 

using namespace std;

int N;
int space[22][22]; //공간 정보
int Time = 0; //시간초 저장
pair<int, int> shark; // 상어의 현재 좌표 변수
int s_size = 2; //상어의 크기
int ate = 0;
vector<pair<int, int>> fish; //물고기 벡터 

int dx[4]{ -1,0,1,0 };
int dy[4]{ 0,-1,0,1 };

bool OOB(int x, int y) { // Out Of Bounds
	return x < 0 || x >= N || y < 0 || y >= N;
}

bool root() {
	bool help = true;
	int idx = 0;         // 해당 물고기 인덱스 저장
	int t = 10000;       // 거리 저장
	for (int i = 0; i < fish.size(); i++) { //모든 물고기에 대해
		if (s_size <= space[fish[i].X][fish[i].Y]) continue; // 상어의 크기가 물고기보다 작거나 같으면
		queue<pair<int, int>> Q;
		int vis[22][22] = { 0 };
		Q.push({ shark.X,shark.Y }); // 현재 상어의 위치 Q에 삽입
		vis[shark.X][shark.Y] = 1; // 방문 배열 설정
		while (!Q.empty()) {
			pair<int, int> cur = Q.front(); Q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir]; // 4방위에 대하여
				int ny = cur.Y + dy[dir];
				if (OOB(nx, ny) || vis[nx][ny] != 0) continue; // OOB이거나 방문한 점이면 continue
				if (space[nx][ny] > s_size) continue; // 해당 공간의 물고기 크기보다 상어의 크기가 작으면 continue
				vis[nx][ny] = vis[cur.X][cur.Y] + 1; //위에 모두 통과시 방문 
				Q.push({ nx,ny });
				if (nx == fish[i].X && ny == fish[i].Y) { // 목적지에 도달시
					if (t > vis[cur.X][cur.Y] + 1) { // 거리가 더 작은 지점이면 (q에 0,0 부터 들어가기 때문에 순서는 고려x)
						help = false; // 도움 필요없음
						t = vis[cur.X][cur.Y] + 1; // 거리 갱신
						idx = i; // 인덱스 저장
						break;
					}
				}
			}
		}
	}

	if (!help) { //먹은 물고기가 있으면
		ate++; // 먹은 물고기 1증가
		Time += (t-1); //시간 증가
		shark = fish[idx]; //상어의 좌표 먹은 물고기 좌표로 변경
		fish.erase(fish.begin() + idx); // 해당 물고기 삭제
		space[shark.X][shark.Y] = 0; // 공간 수정
	}

	return help;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> space[i][j];
			if (space[i][j] <= 6 && space[i][j] >= 1) //물고기 이면
				fish.push_back({ i,j }); //물고기 벡터에 해당 물고기 입력
			if (space[i][j] == 9) 
			{
				shark = { i,j }; //현재 상어 좌표 입력
				space[i][j] = 0; //해당 칸 0으로 변경
			}
		}
	}

	while (!root()) {
		if (ate == s_size) { //먹은 물고기가 상어의 크기이면
			ate = 0; // 먹은 물고기 0
			s_size++;// 상어 크기 증가
		}
	}
	
	cout << Time << " ";
	return 0;
}
