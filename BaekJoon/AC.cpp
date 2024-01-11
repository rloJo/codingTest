#include <iostream>
#include <deque>
#include<algorithm>
#include <string>
/*
선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다.
AC는 정수 배열에 연산을 하기 위해 만든 언어이다.
이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.
함수 R은 배열에 있는 수의 순서를 뒤집는 함수이고, D는 첫 번째 수를 버리는 함수이다. 
배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.
함수는 조합해서 한 번에 사용할 수 있다. 
예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 
예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 수를 버리는 함수이다.
배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.
각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. 
p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.
다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)
다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 ≤ xi ≤ 100)
전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.

*/
using namespace std;


void arr(string& arr, deque<int>& dq, int n) {
	string tmp = "";
	if (n == 0)
		return;
	for (int i = 1; i < arr.length(); i++)
	{ 
		if (arr[i] != ',' && arr[i] != ']')
			tmp += arr[i];
		else
		{
			dq.push_back(stoi(tmp));
			tmp = "";
		}
		                                                                                
	}
}

void print(deque<int>& dq) {
	cout << "[";
	for (int i = 0; i < dq.size(); i++)
	{
		cout << dq[i];
		if (i + 1 != dq.size())
			cout << ",";
	}
	cout << "]" << "\n";

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T = 0, n;
	string p, x;
	cin >> T;
	while (T--) {
		deque<int> dq;
		int flag = false; //이것 때매 몇분을 잡아먹음 
		int error = false; // while문 안에 초기화 해야함
		cin >> p; 
		cin >> n;
		cin >> x;
		arr(x, dq, n);

		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') { //R이나오면 뒤집을 필요가 없고 앞뒤에서 만 뽑아주면 끝
				flag = !flag;
			}
			else if (p[i] == 'D') //D 나오면 덱이 비면 error 아니면 flag에 따라 앞에서 뽑을지 뒤에서 뽑을 지 판단
			{
				if (dq.empty()) {
					error = true;
					break;
				}
				else {
					if (!flag)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}

		if (error)
			cout << "error" << "\n";
		else {
			if (flag)
				reverse(dq.begin(), dq.end());
			print(dq);
		}
	}

	return 0;
}
