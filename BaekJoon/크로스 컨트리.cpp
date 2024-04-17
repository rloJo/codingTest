#include <iostream>
using namespace std;

class team {
public:
	int num = 0; // 팀 수
	int score = 0; // 점수
	int fifth = 0; //5번째 선수 등수 
	int idx = 0;
};

int T, N;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;

		int order[1002]; //등수 저장
		team t[202]; // 팀 정보 저장

		for (int i = 1; i <= N; i++) {
			cin >> order[i];
			t[order[i]].num++; // order[i] 번째 팀 인원 증가
			if (t[order[i]].num == 5) t[order[i]].fifth = i;
			// 5번째 인원이면 등수 설정 i 가 등수
		}

		for (int i = 1, s=1; i <= N; i++) {
			if (t[order[i]].num < 6) continue;
			if (t[order[i]].idx < 4) {
				t[order[i]].score += s;
				t[order[i]].idx++;
			}
			s++;
		}

		// 최대 점수값은 대략 4000이므로 비교값 10000으로 설정
		int mn = 10000; int f = 10000;
		for (int i = 1; i <= 200; i++) { // 모든 팀의 점수 확인
			if (mn > t[i].score && t[i].num == 6) { // 최소값이 해당 팀값 보다 크면 값 교체 (팀의 점수가 0이면 pass)
				mn = t[i].score;
				f = t[i].fifth; //5등 등수 갱신
				ans = i; // 1등 수정
			}
			// 점수가 동률이면 5번째 등수가 낮은 팀이 우승
			else if (mn == t[i].score && t[i].num == 6 && f > t[i].fifth) {
				f = t[i].fifth;
				ans = i;
			}
		}
		cout << ans << "\n";
	}
}
