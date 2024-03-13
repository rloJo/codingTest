#include <iostream>
#include <string>

using namespace std;

int T, N; // 테스트 케이스, 명령어 개수
string instruction[1002]; // 명령어
//위(0,w) 아(1,y) 앞(2,r) 뒤(3,o) 왼(4,g) 오(5,b)
char cube[6][3][3];
char col[6] = { 'w','y','r','o','g','b' };
pair<int, int> d[6][4] // 6면에 대한 시계방향 회전시 측면 회전 (회전면, 해당 인덱스)
{					   // 마주볼때 방향 기준으로 인덱스 설정
	{{3,0},{5,0},{2,0},{4,0}}, //윗면 회전시 뒷면 0번 행 -> 오른쪽면 0번 행 -> ...
	{{2,2},{5,2},{3,2},{4,2}}, //아랫면 회전시 앞면 2번 행 -> 오른쪽면 2번 행 -> ...
	{{0,2},{5,0},{1,0},{4,2}}, //앞면 회전시 윗면 2번 행 -> 오른쪽면 0번 열 -> 아랫면 0번 행 -> 왼면 2번 열
	{{0,0},{4,0},{1,2},{5,2}}, //뒷면 회전시 윗면 0번 행 -> 왼쪽면 0번 열 -> 아랫면 2번 행 -> 왼면 2번 열
	{{0,0},{2,0},{1,0},{3,2}}, //왼쪽면 회전시 윗면 0번 열 -> 앞면 0번 열 -> 아랫면 0번 열 -> 뒷면 2번 열
	{{0,2},{3,0},{1,2},{2,2}}  //오른면 회전시 윗면 2번 열 -> 뒷면 0번 열 -> 아랫면 2번 열 -> 앞면 2번 열
};

void init_cube() { // 큐브 초기화
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				cube[i][j][k] = col[i];
		}
	}
}

void turn(int idx) {
	char tmp1[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tmp1[i][j] = cube[idx][i][j];

	// 돌려야하는 면 회전  적용
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cube[idx][i][j] = tmp1[3 - 1 - j][i];

	// 측면 회전할 값 추출
	char tmp2[4][3]; // 회전시 측면에 4면이 각 3블럭씩 회전 된다
	for (int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++){
			if (idx == 0 || idx == 1) // 윗면 또는 아랫면 회전시
				tmp2[i][j] = cube[d[idx][i].first][d[idx][i].second][j]; //d[idx][i].first면의 d[idx][i].second 행을 가져와야함			
			else if (idx == 2) // 앞면 회전시
			{
				if (i % 2 == 0) { // 인덱스가 짝수면 행 홀수면 열을 가져옴
					tmp2[i][j] = cube[d[idx][i].first][d[idx][i].second][j];
				}
				else { // 앞면을 돌릴때 왼면을 윗면이 받을 때, 오른면을 아랫면이 받을 때 인덱스가 교차
					  // 따라서 왼면 오르면 값을 반대로 받고 시작 -> 값을 넣을 때 그냥 넣으면 끝
					//if(d[idx][i].first == 4 || d[idx][i].first == 5)
						tmp2[i][3-1-j]= cube[d[idx][i].first][j][d[idx][i].second];
					//else 
						//tmp2[i][j] = cube[d[idx][i].first][j][d[idx][i].second];
				}
			}
			else if (idx == 3) // 뒷면 회전시
			{
				if (i % 2 == 0) { // 인덱스가 짝수면 행 홀수면 열을 가져옴			
						tmp2[i][3-1-j] = cube[d[idx][i].first][d[idx][i].second][j];
				}
				else {
						tmp2[i][j] = cube[d[idx][i].first][j][d[idx][i].second];
				}
			}

			else { // 왼면 오른면 회전시
				if (d[idx][i].first == 3) // 뒷면은 인덱스가 반대이므로 회전시 반대로 대입된다.
					tmp2[i][j] = cube[d[idx][i].first][3-1-j][d[idx][i].second];
				else
					tmp2[i][j] = cube[d[idx][i].first][j][d[idx][i].second]; //d[idx][i].first면의 d[idx][i].second 열을 가져와야함      
			}
		}
	}
	//측면 회전 값 삽입
	for (int i = 0; i < 4; i++) {
		for(int j=0;j<3;j++){
			if (idx == 0 || idx == 1) // 윗면 또는 아랫면 회전시
				cube[d[idx][i].first][d[idx][i].second][j] = tmp2[(i + 3) % 4][j];
				//0번 인덱스는 3번, 1번 인덱스는 0번, 2번 인덱스는 1번에서 값을 가져옴
			else if (idx == 2) { // 앞면
				if (i % 2 == 0)
					cube[d[idx][i].first][d[idx][i].second][j] = tmp2[(i + 3) % 4][j];
				else
					cube[d[idx][i].first][j][d[idx][i].second] = tmp2[(i + 3) % 4][j];
			}
			else if (idx == 3) { //뒷면
				if (i % 2 == 0)
					cube[d[idx][i].first][d[idx][i].second][j] = tmp2[(i + 3) % 4][j];
				else
					cube[d[idx][i].first][j][d[idx][i].second] = tmp2[(i + 3) % 4][j];
			}
			else {// 왼면 오른면 회전시
				if (d[idx][i].first == 3) // 뒷면은 인덱스가 반대이므로 대입도 반대로!
					cube[d[idx][i].first][j][d[idx][i].second] = tmp2[(i + 3) % 4][3-1-j];
				else
					cube[d[idx][i].first][j][d[idx][i].second] = tmp2[(i + 3) % 4][j];
			}
		}
	}
}

void start() {
	int dir = 0; int idx = 0;
	for (int i = 0; i < N; i++) {
		if (instruction[i][0] == 'U') idx = 0;
		else if (instruction[i][0] == 'D') idx = 1;
		else if (instruction[i][0] == 'F') idx = 2;
		else if (instruction[i][0] == 'B') idx = 3;
		else if (instruction[i][0] == 'L') idx = 4;
		else idx = 5;
		if (instruction[i][1] == '+') dir = 1; // +면 1번 실행 -면 3번 실행, 반시계 = 시계 3번
		else dir = 3;
		for (int j = 0; j < dir; j++)
			turn(idx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		init_cube();
		for (int i = 0; i < N; i++)
			cin >> instruction[i];
		start();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[0][i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
