#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N, K;
deque<int> con;
deque<bool> robot;
int stage = 0;

bool check() {
	int cnt = 0;
	for (int i = 0; i < con.size(); i++) {
		if (con[i] <= 0) cnt++;
	} 

	if (cnt >= K) return true;
	return false;
}

void out_robot(){
	if (robot[N - 1]) robot[N - 1] = false;
}

void move_robot() {
	for (int i = N - 2; i >= 0; i--) {
		if (con[i + 1] > 0 && !robot[i + 1] && robot[i]) {
			robot[i] = false;
			robot[i + 1] = true;
			con[i + 1]--;
		}
	}
	out_robot();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < 2*N; i++) {
		int d;
		cin >> d;
		con.push_back(d);
		robot.push_back(false);
	}

	while (!check()) {
		stage++;
		//과정 1 (로봇 및 컨테이너 회전)
		robot.push_front(robot.back());
		robot.pop_back();
		con.push_front(con.back());
		con.pop_back();
		out_robot();
		// 과정 2 (로봇 이동)
		move_robot();
		// 과정 3 (로봇 놓기)
		if (con[0] > 0) {
			robot[0] = true;
			con[0]--;
		}
	}

	cout << stage;

	return 0;
}

