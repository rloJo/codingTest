#include <iostream>

/*
강을 가로지르는 하나의 차선으로 된 다리가 하나 있다. 이 다리를 n 개의 트럭이 건너가려고 한다. 
트럭의 순서는 바꿀 수 없으며, 트럭의 무게는 서로 같지 않을 수 있다. 
다리 위에는 단지 w 대의 트럭만 동시에 올라갈 수 있다.
다리의 길이는 w 단위길이(unit distance)이며, 각 트럭들은 하나의 단위시간(unit time)에 하나의 단위길이만큼만 이동할 수 있다고 가정한다.
동시에 다리 위에 올라가 있는 트럭들의 무게의 합은 다리의 최대하중인 L보다 작거나 같아야 한다. 
참고로, 다리 위에 완전히 올라가지 못한 트럭의 무게는 다리 위의 트럭들의 무게의 합을 계산할 때 포함하지 않는다고 가정한다.
다리의 길이와 다리의 최대하중, 그리고 다리를 건너려는 트럭들의 무게가 순서대로 주어졌을 때, 모든 트럭이 다리를 건너는 최단시간을 구하는 프로그램을 작성하라.

입력 데이터는 표준입력을 사용한다. 입력은 두 줄로 이루어진다. 
입력의 첫 번째 줄에는 세 개의 정수 n (1 ≤ n ≤ 1,000) , w (1 ≤ w ≤ 100) and L (10 ≤ L ≤ 1,000)이 주어지는데,
n은 다리를 건너는 트럭의 수, w는 다리의 길이, 그리고 L은 다리의 최대하중을 나타낸다. 
입력의 두 번째 줄에는 n개의 정수 a1, a2, ⋯ , an (1 ≤ ai ≤ 10)가 주어지는데, ai는 i번째 트럭의 무게를 나타낸다.
*/

using namespace std;

int n, w, L;  // 트럭 수, 다리 길이, 최대하중 
pair<int,int> truck[1002]; // 트럭 하중 및 트럭이 건너기 까지 남은길이
int ans = 0;

// 모든 트럭이 건너는 시간을 구하는 메소드
void cross() {
	bool flag = true; // 다리에 다음 트럭이 올라갈 수 있는지
	int idx = 0; // 다리에 올라간 트럭의 인덱스
	while (truck[n - 1].second > 0) //마지막 트럭이 건널때 까지
	{
		int weight = 0; // 다리에 가해진 하중 (올라간 트럭의 무게 합)
		ans++; // 시간 증가

		if (flag) { // 다음 트럭이 올라갈 수 있으면 
			for (int i = 0; i < n; i++) {
				truck[i].second--; //모든 트럭의 거리가 1 줄어듬
				if (truck[i].second == w) { // 만약 거리가 다리의 길이 만큼 남으면 다리에 올라간 것으로
					idx = i;				// 다리에 올라간 트럭의 인덱스를 변환
				}
			}
		}
		else { //다음 트럭이 못올라가면
			for (int i = 0; i <= idx; i++) 
				truck[i].second--; // 올라간 트럭의 거리만 1 줄어듬
		}

		for (int i = 0; i <= idx; i++) { //올라간 트럭의 하중을 구함
			if (truck[i].second > 1) weight += truck[i].first; // 남은 거리가 1이면 다음에 내려 가기 때문에 누적 x
		}

		if (weight + truck[idx + 1].first > L) // 현재 올라간 트럭과 대기중인 트럭의 합이 L 이상이면
			flag = false; 
		else // 다음 트럭이 올라갈수 있으면
			flag = true;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> w >> L;

	for (int i = 0; i < n; i++) {
		cin >> truck[i].first;
		truck[i].second = w + i + 1;
	}

	cross();
	cout << ans << "\n";
	return 0;
}
