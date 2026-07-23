class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices; //mapping value to index

        for (int i = 0; i < nums.size(); i++) { // put everything in the map
            indices[nums[i]] = i; //key = actual val, value = index
        }

        for (int i = 0; i < nums.size(); i++) { //now loop through again and reference values in the map
            int diff = target - nums[i];
            //check if difference exists in hash map
            if (indices.count(diff) == 1 && indices[diff] != i) { //also check if i != j since that was a req
                return {i, indices[diff]}; //if it does we can return the pair
            }
        }
        return {};
    }
};
