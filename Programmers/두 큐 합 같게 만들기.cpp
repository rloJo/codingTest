#include <string>
#include <queue>

typedef long long ll;
using namespace std;

ll queue1Sum = 0;
ll queue2Sum = 0; 

void setting(vector<int> queue1, vector<int> queue2, queue<ll> &Q1 , queue<ll> &Q2 ){
   for(ll num : queue1) {
       queue1Sum += num;
       Q1.push(num);
   }
    
   for(ll num : queue2) {
       queue2Sum += num;
       Q2.push(num);
   }
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<ll> Q1, Q2;
    int n = queue1.size();
    setting(queue1, queue2, Q1,Q2);
    if((queue1Sum+queue2Sum)%2) return -1;
    while(1){
        if(queue1Sum == queue2Sum) break;
        if(queue1Sum > queue2Sum) {
            while(!Q1.empty() && queue1Sum > queue2Sum) {
                int num = Q1.front(); Q1.pop();
                queue1Sum -= num;
                queue2Sum += num;
                Q2.push(num);
                answer ++;
            }
        }
        if(queue2Sum > queue1Sum){
            while(!Q2.empty() && queue2Sum > queue1Sum) {
                int num = Q2.front(); Q2.pop();
                queue2Sum -= num;
                queue1Sum += num;
                Q1.push(num);
                answer++;
            }
        }
        if(answer>(n*3)-3)return -1;
    }
    

    return answer;
}
