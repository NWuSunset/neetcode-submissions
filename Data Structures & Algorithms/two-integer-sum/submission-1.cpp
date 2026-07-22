class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size(); //get unique things

        //get a hash map to lookup stuff efficiently
        unordered_map<int, int> map;

        for (int i = 0; i < size; i++) {
            int difference = target - nums[i]; //now find the resulting target
            if(map.find(difference) != map.end()) {
                return {map[difference], i}; //return pair of the index of difference and val of i
            }
            map.insert({nums[i], i}); //insert index and value pair
        }
        return {};
    }
};
