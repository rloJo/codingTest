class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit =0;
        for(int i=0;i<prices.size()-1;i++){
            for(int j=i+1;j<prices.size();j++){
                if(prices[j] - prices[i] > maxProfit)
                    maxProfit =  prices[j] - prices[i];
            }
        }
        return maxProfit;
    }
};

// 단순하게 풀었을 때 2중 for문으로 구현이 가능 
// 하지만 시간 초과 문제 발생

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxProfit = 0; // 최고 이익 변수
       int price = prices[0]; // 최저점 가격
       for(int i=1;i<prices.size();i++){
           int profit = prices[i] - price; // 현재 얻는 수익
           maxProfit = max(profit, maxProfit); // 최대 이익 갱신
           price = min(price,prices[i]); // 최저점 가격 갱신
       }
        return maxProfit;
    }
};
