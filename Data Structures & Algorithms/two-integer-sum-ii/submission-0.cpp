class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //numbers is in 'increasing' order (non decreasing). 
        //we get two pointers, one on the left one on the right of the array.
        //Move each pointer via a condition
        

        int n = numbers.size();
        int r = n - 1; //right ppointer
        int l = 0; //left pointer

        int test =0;

        while (l < r) {
            int sum = numbers[r] + numbers[l];
            if (sum == target) { //if exceeding the target, then the right num is too big
                return {l+1, r+1}; //one indexed so just add one to result.
            } else if (sum > target) { //if less than the target we move the left pointer upward
                r--;
            } else { //if target is greater than sum, move up left pointer
                l++;
            }
        }
        return {};
    }
};
