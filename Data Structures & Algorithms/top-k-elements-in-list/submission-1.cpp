class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //return k most frequent. ie: 2 most frequent elements, or 3 most frequent elements

        // map frequency to element
        //group numbers based on frequencies from 1 to the max 

        unordered_map<int, int> count; //map to keep track of count/frequency of each number

      ///  vector<int> buckets[nums.size()]; //max frequency is the lenght of the list
        vector<vector<int>>  frequencies(nums.size() + 1); //store a list of frequency groups (each individual group storing the numbers that appear x times)
        //frequencies[i] = numbers appearing i times

        //first fill up the count map
        for (int n : nums) {
            count[n] = 1 + count[n]; //increment the count of the number if it shows up
        }

        //now fill up the frequencies so that frequencies[i] = numbers appearing i times
        for (const auto & pairs : count) {
            frequencies[pairs.second].push_back(pairs.first);
        }

        //loop from highest to lowest frequency (one) and add to final list stop when k numbers in result
        vector<int> result;

        for (int i = frequencies.size() - 1; i >= 1; i--) {
            //loop through the ith frequency group and put numbers in the list
            for (int n : frequencies[i]) {
                result.push_back(n);
                if (result.size() == k) {
                    return result;
                } 
            }
        }
        return result;
    }
};
