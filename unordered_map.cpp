#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;

        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            if (numToIndex.count(difference)) {
                return {numToIndex[difference], i};
            }
            numToIndex[nums[i]] = i;
        }

        return {};
    }
};
