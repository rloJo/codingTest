#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; // 시간 초
    int idx = 0; // 현재 건너야하는 트럭의 인덱스
    int sum = 0; // 다리 위의 트럭 무게 합
    queue<int> Q;
    while (1) {
        if (idx == truck_weights.size()) { // 마지막 트럭이 들어갔다면
            answer += bridge_length; // 현재 시간에 남은 길이 추가하고 종료
            break;
        }

        answer++; // 시간 증가

        //차가 다리를 다 건넜을 경우
        if (Q.size() == bridge_length) {
            sum -= Q.front(); // 건넌 차량 무게 빼기
            Q.pop();
        }

        // 다리에 무게 이상의 차가 있는 경우 시간계산용 0 push;
        if (sum + truck_weights[idx] > weight) Q.push(0);
        else {
            sum += truck_weights[idx];
            Q.push(truck_weights[idx++]);
        }

    }
   
    return answer;
}
