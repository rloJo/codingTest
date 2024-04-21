#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define name first
#define id second

using namespace std;

int p, m;
vector<pair<string, int>> lobby;
vector<pair<string, int>> room[302];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> p >> m;
	for (int i = 1; i <= p; i++){ 
		int l; string n;
		cin >> l >> n;
		lobby.push_back({ n,l });
	}
	
	for (int i = 0; i < lobby.size(); i++) {
		for (int j = 1; j <= 300 ; j++) {
			//방이 비었을 경우 해당방에 방장 넣기
			if (room[j].empty()) {
				room[j].push_back(lobby[i]);
				break;
			}
			// 총인원수 초과일 경우 다음방으로
			if (room[j].size() >= m) continue;

			// 레벨 비교해서 조건 충족시 해당 대기실 입장
			if (abs(room[j][0].id - lobby[i].id) <= 10)
			{
				room[j].push_back(lobby[i]);
				break;
			}
			// 레벨 조건 미 충족 시 다음 방 탐색
			else continue;
		}
	}

	for (int i = 1; i <= 300; i++) {
		if (room[i].empty()) break;
		if (room[i].size() == m) cout << "Started!" << "\n";
		else  cout << "Waiting!" << "\n";
		sort(room[i].begin(), room[i].end());
		for (auto c : room[i])
			cout << c.id << " " << c.name << "\n";
	}
}

