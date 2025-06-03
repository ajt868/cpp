#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};
    cout << nums.at(2) << endl;
    nums.push_back(100);
    cout << nums.back() << endl;
    nums.pop_back();
    cout << nums.back();
    
}


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        vector<int> nums_copy;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == val) {
                nums_copy.push_back(nums.at(i));
            }
        }
        nums = nums_copy;

        return nums.size();
    }

    int removeDuplicates(vector<int>& nums) {

    }
    
    // Input: nums = [2,7,11,15], target = 9
    // Output: [0,1]
    // Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

    vector<int> twoSum(vector<int>& nums, int target) {
        
    }
};
