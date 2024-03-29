#include <iostream>
#include <vector>
#include <deque>

/*
총 8개의 톱니를 가지고 있는 톱니바퀴 4개가 아래 그림과 같이 일렬로 놓여져 있다. 
또, 톱니는 N극 또는 S극 중 하나를 나타내고 있다.
톱니바퀴에는 번호가 매겨져 있는데, 가장 왼쪽 톱니바퀴가 1번, 그 오른쪽은 2번, 그 오른쪽은 3번, 가장 오른쪽 톱니바퀴는 4번이다.
이때, 톱니바퀴를 총 K번 회전시키려고 한다. 
톱니바퀴의 회전은 한 칸을 기준으로 한다. 
회전은 시계 방향과 반시계 방향이 있고, 아래 그림과 같이 회전한다.

톱니바퀴를 회전시키려면, 회전시킬 톱니바퀴와 회전시킬 방향을 결정해야 한다.
톱니바퀴가 회전할 때, 서로 맞닿은 극에 따라서 옆에 있는 톱니바퀴를 회전시킬 수도 있고, 회전시키지 않을 수도 있다. 
톱니바퀴 A를 회전할 때, 그 옆에 있는 톱니바퀴 B와 서로 맞닿은 톱니의 극이 다르다면, B는 A가 회전한 방향과 반대방향으로 회전하게 된다. 

두 톱니바퀴의 맞닿은 부분은 초록색 점선으로 묶여있는 부분이다. 
여기서, 3번 톱니바퀴를 반시계 방향으로 회전했다면, 4번 톱니바퀴는 시계 방향으로 회전하게 된다.
2번 톱니바퀴는 맞닿은 부분이 S극으로 서로 같기 때문에, 회전하지 않게 되고, 
1번 톱니바퀴는 2번이 회전하지 않았기 때문에, 회전하지 않게 된다.


위와 같은 상태에서 1번 톱니바퀴를 시계 방향으로 회전시키면, 
2번 톱니바퀴가 반시계 방향으로 회전하게 되고, 2번이 회전하기 때문에, 
3번도 동시에 시계 방향으로 회전하게 된다. 4번은 3번이 회전하지만, 맞닿은 극이 같기 때문에 회전하지 않는다.

톱니바퀴의 초기 상태와 톱니바퀴를 회전시킨 방법이 주어졌을 때, 최종 톱니바퀴의 상태를 구하는 프로그램을 작성하시오.

첫째 줄에 1번 톱니바퀴의 상태, 둘째 줄에 2번 톱니바퀴의 상태, 셋째 줄에 3번 톱니바퀴의 상태, 넷째 줄에 4번 톱니바퀴의 상태가 주어진다. 상태는 8개의 정수로 이루어져 있고, 12시방향부터 시계방향 순서대로 주어진다.
N극은 0, S극은 1로 나타나있다.

다섯째 줄에는 회전 횟수 K(1 ≤ K ≤ 100)가 주어진다. 
다음 K개 줄에는 회전시킨 방법이 순서대로 주어진다.
각 방법은 두 개의 정수로 이루어져 있고, 첫 번째 정수는 회전시킨 톱니바퀴의 번호, 두 번째 정수는 방향이다. 
방향이 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향이다.
*/

using namespace std;

vector<deque<int>> gear(4); //1~4 톱니바퀴의 상태를 저장하는 변수
int instruction = 0; // 명령어 개수 저장하는 변수
int ans = 0; //정답을 저장하는 변수

void turn_right(int index) { // 오른쪽 회전 (시계 방향)
	gear[index].push_front(gear[index].back());
	gear[index].pop_back();
}

void turn_left(int index) { // 왼쪽 회전 (반시계 방향)
	gear[index].push_back(gear[index].front());
	gear[index].pop_front();
}

void turn(int index, int dir){
	int cur_l,cur_r; //왼쪽 , 오른쪽 index 커서 
	int dir_r = dir, dir_l = dir; //기어가 왼쪽 오른쪽으로 나아갈 때 방향 변수
	pair<bool, int> flag[4]; // 4기어의 회전을 판단
	flag[index].first = true; // 처음 명령어로 회전한 기어는 무조건 돈다
	flag[index].second = dir; // 방향 설정
	cur_l = index-1; // 왼쪽 커서
	cur_r = index+1; // 오른쪽 커서
	while(1) {
		if (cur_l < 0 && cur_r > 3) // while 문 탈출 조건 
			break;
	
		if (cur_r < 4) { //오른쪽 커서가 4 미만일 때 즉 0~3 까지 
			if (gear[cur_r - 1][2] != gear[cur_r][6]) { //해당 톱니 검사
				dir_r *= -1; // 방향은 앞선 톱니 회전의 반대 방향
				flag[cur_r].first = true; 
				flag[cur_r].second = dir_r;
			}
			else {
				flag[cur_r].first = false;
				cur_r = 4; //해당 톱니가 안돌면 오른쪽으로 뻗을 이유가 없음
			}
		}

		if (cur_l >= 0) { // 왼쪽 커서가 0이상일 때 즉 0~3 까지
			if (gear[cur_l + 1][6] != gear[cur_l][2]) { // 해당 톱니 검사
				dir_l *= -1; 
				flag[cur_l].first = true;
				flag[cur_l].second = dir_l;
			}
			else {
				flag[cur_l].first = false;
				cur_l = -1;
			}
		}

		cur_l--; cur_r++;; //왼쪽커서 -- 오른쪽 커서 ++
	} 

	// flag로 검사한 톱니 회전 
	for (int i = 0; i < 4; i++) {
		if (flag[i].first) {
			if (flag[i].second == -1)
				turn_left(i);
			else turn_right(i);
		}
	}
}

void check() { //점수 계산
	for (int i = 0; i < 4; i++)
	{
		if (gear[i].front() == 1) {
			if (i == 0) ans += 1;
			if (i == 1) ans += 2;
			if (i == 2) ans += 4;
			if (i == 3) ans += 8;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string tmp;
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++)
			gear[i].push_back(tmp[j]-'0');
		//  1번 톱니 2번 , 2번 톱니 2번 6번, 2번 톱니 2번 6번, 4번 톱니 6번
	}

	cin >> instruction;

	while (instruction--) {
		int num; int dir;
		cin >> num >> dir;
		turn(num-1, dir);
	}
	check();
	cout << ans << '\n'; 
	return 0;
}
