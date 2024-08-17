#include<iostream>
#include <vector>
#include <set>
#define D first	
#define S second 
#define X first
#define Y second

using namespace std;

int N, M;
int A[52][52];
int	dx[9] = {0,0,-1,-1,-1,0,1,1,1};
int dy[9] = {0,-1,-1,0,1,1,1,0,-1};
vector<pair<int, int>> cloud;
vector<pair<int, int>> moveInfo;
set<pair<int, int>> isClouded;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;
		moveInfo.push_back({ d,s });
	}
	cloud.push_back({ N - 1,0 });
	cloud.push_back({ N - 1,1 });
	cloud.push_back({ N - 2,0 });
	cloud.push_back({ N - 2,1 });
}

void move(pair<int,int> info) {
	for (int i = 0; i < cloud.size(); i++) {
		for (int j = 0; j < info.S; j++) {
			cloud[i].X += dx[info.D];
			cloud[i].Y += dy[info.D];
			cloud[i].X = (cloud[i].X + N) % N;
			cloud[i].Y = (cloud[i].Y + N) % N;
		}
		A[cloud[i].X][cloud[i].Y]++;
		isClouded.insert({ cloud[i].X,cloud[i].Y });
	}
}

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= N;
}

void rain() {
	for (int i = 0; i < cloud.size(); i++) {
		int cnt = 0;
		for (int dir = 2; dir < 9; dir+=2) {
			int cx = cloud[i].X + dx[dir];
			int cy = cloud[i].Y + dy[dir];
			if (OOB(cx, cy)) continue;
			if (A[cx][cy] > 0) cnt++;
		}
		A[cloud[i].X][cloud[i].Y] += cnt;
	}
	cloud.clear();
}

void make_cloud() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isClouded.find({ i,j }) != isClouded.end()) continue;
			if (A[i][j] >= 2) {
				cloud.push_back({ i,j });
				A[i][j] -= 2;
			}
		}
	}

	isClouded.clear();
}

int calcWater() {
	int water = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			water += A[i][j];
		}
	}
	return water;
}

void solution() {
	for (int i = 0; i < moveInfo.size(); i++) {
		move(moveInfo[i]);
		rain();
		make_cloud();
	}
	cout << calcWater();
}

int main() {
	init();
	input();
	solution();
}
