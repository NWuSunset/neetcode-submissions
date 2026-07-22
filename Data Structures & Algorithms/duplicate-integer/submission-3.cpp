class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seenNums;
        for (int num : nums) {
            if (seenNums.count(num)) {
                return true;
            }
            seenNums.insert(num);
        }
        return false;
    }
};