class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size()-1;i++){
            for(int j= i+1 ; j<nums.size();j++){
                if(nums[i]+nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

/* 위 코드는 이중 for문으로 작성된 것이라 배열의 크기가 커지면 느려지는 단점있다. 
더 개선해보자 */
