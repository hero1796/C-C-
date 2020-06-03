#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); ++i) {
    	auto it = m.find(target - nums[i]);
    	if (it != m.end()) {
    		return {it->second, i};
    	} else {
    		m[nums[i]] = i;
    	}
    }
}

int main() {
	vector<int> v = {2,7,11,15};
	twoSum(v, 9);
	return 0;
}
