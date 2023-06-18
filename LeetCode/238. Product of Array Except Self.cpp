class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum =1;
            for(int j=0;j<nums.size();j++){
                if(i!=j){
                    sum*=nums[j];
                }
            }
            answer.push_back(sum);
        }
        return answer;
    }
};
// 단순하게 풀었을 때 위와 같음
// 하지만 문제 조건이 O(n)으로 끝내기 및 나누기 사용 금지
