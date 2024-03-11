#include <iostream>
#include <vector>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

int M = 100; //보드 최대 크기
int N;
bool board[102][102] = { 0 };
vector<vector<pair<int,int>>> curve(13);

inline bool OOB(int x, int y) { //Out Of Bounds 검사
	return x < 0 || x >= M + 1 || y < 0 || y >= M+1;
}

int check() {
	int ans = 0;
	for (int i = 0; i <  M ; i++) {
		for (int j = 0; j < M ; j++ ) {
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i+1][j + 1])
				ans++;
		}
	}
	return ans;
}

void turn(vector<pair<int, int>>& c , int d) {
	if (d == 0) return;
	double offset = d * 90 * M_PI/180.0;
	for (int i = 1; i < c.size(); i++) { //시작점 0,0 빼고 회전
		pair<int, int> t = c[i];
		c[i].first =(int) (t.first * (int) cos(offset) -  t.second * (int) sin(offset));
		c[i].second =(int) (t.first * (int) sin(offset) + t.second * (int)cos(offset));
		//각 점을 원점에 대해 회전이동
	}
}

void dragon_curve(int x, int y, int d, int g) {
	vector<pair<int, int>> tmp = curve[g];

	turn(tmp,-d); //반시계 방향이므로 - 

	for (int i = 0; i < tmp.size(); i++) {
		if(OOB(x+tmp[i].second, y+tmp[i].first)) continue;
		board[x+tmp[i].second][y+tmp[i].first] = true; // x y좌표가 반대이므로 second를 x에 대입
	} 

}

void make_curve() { // 방향 0인 N 세대 드래곤 커브 생성기
	curve[0].push_back({ 0,0 }); // 0 세대는 직접 입력
	curve[0].push_back({ 1,0 });
	for (int i = 1; i <= 10; i++) { // 1~10 세대 입력
		for (int j = 0; j < curve[i - 1].size(); j++) {
			curve[i].push_back(curve[i - 1][j]); //N세대 좌표에 N-1 세대 좌표 입력
		}
		pair<int, int> std = curve[i].back(); //기준이 되는 끝점
		for (int j = curve[i-1].size()-2; j >=0; j--) { // 끝점을 벡터의 맨뒤로 보내기 위해 반대로 수행
			pair<int, int>tmp; // 끝점으로 부터의 해당점의 벡터 구하기
			tmp.first = std.first - curve[i-1][j].first; 
			tmp.second = std.second - curve[i-1][j].second;
			swap(tmp.first, tmp.second);
			tmp.second *= -1; //해당 벡터를 반시계 방향으로 90도 회전 후 끝점에서 평행이동하면 해당 점의 위치 탄생 
			curve[i].push_back({std.first+tmp.first,std.second+tmp.second});
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	make_curve();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		dragon_curve(x, y, d, g );
	}

	cout << check();

	return 0;
}
