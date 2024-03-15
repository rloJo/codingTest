#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class tree {
public:
	int x;			
	int y;
	int age;
};

int N, M, K; //땅, 묘목 수, K년 후
vector<int> map[12][12];
int A[12][12]; // 땅이 겨울에 받는 양분 기록
int manure[12][12]; // 거름이 되는 정도
int ground[12][12]; // 현재 땅의 양분
vector<tree> dead; //죽은 나무
int ans = 0; // 정답 변순

bool OOB(int x, int y) { // OutOfBounds
	return x < 0 || x >= N || y < 0 || y >= N;
}

void spring() { //봄
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			sort(map[i][j].begin(), map[i][j].end()); //나이순 정렬

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int ii = 0; ii < map[i][j].size(); ii++) {
				if (ground[i][j] >= map[i][j][ii]) { //영양분 섭취 가능인 경우
					ground[i][j] -= map[i][j][ii];
					map[i][j][ii]++;
				}
				else { //섭취 불가능인 경우
					dead.push_back({ i,j,map[i][j][ii] }); //죽은 나무 추가
					map[i][j].erase(map[i][j].begin() + ii); //해당 나무 삭제
					ii--;
				}
			}
		}
	}
}

void summer() { //여름
	for (int i = 0; i < dead.size(); i++) {
		ground[dead[i].x][dead[i].y] += (int)dead[i].age / 2; //죽은 나무의 양분 땅에 더함
	}
	dead.clear(); //dead배열 삭제
}

void fall() { //가을
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < map[i][j].size(); k++) {
				if (map[i][j][k] % 5 == 0 && map[i][j][k] >= 5) { //5의 배수인 경우
					for (int ii = -1; ii < 2; ii++) {
						for (int jj = -1; jj < 2; jj++) {//주변 8칸에 나무 심기
							if (ii == 0 && jj == 0) continue;
							if (OOB(i + ii, j + jj)) continue;
							map[i + ii][j + jj].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() { //겨울
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ground[i][j] += A[i][j];	  //S2D2 양분 추가
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K; 

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ground[i][j] = 5; // 시작할 때 땅의 양분은 5
			cin >> A[i][j];   // 매해 추가되는 양분 입력
		}
	}

	int x, y,z;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z; //x,y,age
		map[x - 1][y - 1].push_back(z);
	}

	while(K--)
	{
		spring();
		summer();
		fall();
		winter();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			ans += map[i][j].size();
	}

	cout << ans;
	return 0;
}
