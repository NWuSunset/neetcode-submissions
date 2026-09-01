class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //perhaps use a sldiing window to move through the days and find the best time to buy and sell stock

        int max_profit = 0;
        int l = 0;
        //iterate through the array for selling price the right pointer will be one ahead of the left pointer to start
        for (int r = 1; r < prices.size(); r++) {

            //now get the buying price, want the lowest value on the left

            if (prices[r] > prices[l]) { //if this day is profitable
                int profit = prices[r] - prices[l];
                max_profit = max(max_profit, profit);
            } else { //if no profit
            //update the position of the left pointer to that of the right pointer, sincve this means there is a cheaper buy price
                l = r; 
            }
        }
        return max_profit;
    }
};
