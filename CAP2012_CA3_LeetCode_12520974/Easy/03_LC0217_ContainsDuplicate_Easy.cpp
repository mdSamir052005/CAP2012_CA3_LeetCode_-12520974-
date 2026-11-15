
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }

            s.insert(nums[i]);
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3, 1};

    cout << (obj.containsDuplicate(nums) ? "true" : "false");

    return 0;
}
