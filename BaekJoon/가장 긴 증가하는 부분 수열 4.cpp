#include <iostream>
#include <stack>
using namespace std;

int N, idx =1;
int A[1002];
int dp[1002]; // dp 배열 [N]번째 까지 가장 긴 수열 길이
int cur[1002]; //역 추적을 위한 배열
stack<int> st;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> A[i];
	}

	cur[1] = 1;

	for (int i = 1; i <= N; i++) {
		dp[i] = 1; //모든 수는 자기 자신부터 시작할 수 있어 1로 초기화
		cur[i] = i; //마찬가지로 커서를 자기 자신으로 초기화
	} 

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++){
			if (A[j] < A[i]) { //
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					cur[i] = j;
				}
			}
			if (dp[idx] < dp[i]) {
				idx = i;
			}
		}
	}

	int tmp = idx;
	while (idx != cur[idx]) { //자기 자신을 가리키기 전까지
		st.push(A[cur[idx]]); //stack에 값 넣기
		idx = cur[idx]; // idx 변경
	}
	
	cout << dp[tmp] << "\n"; //최장 길이 출력
	
	while (!st.empty()) {
		cout << st.top() << " "; // 뽑아 내면서 출력
		st.pop();
	}
	cout << A[tmp] << " "; // 마지막 수 출력

	return 0;
}
