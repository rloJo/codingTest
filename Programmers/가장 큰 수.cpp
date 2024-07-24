#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	vector<string> nums;
	string answer = "";
	for (int num : numbers) nums.push_back(to_string(num));
	
	sort(nums.begin(), nums.end(), cmp);
	if (nums[0] == "0") return "0";
	for (string num : nums) answer += num;
	return answer;
}
