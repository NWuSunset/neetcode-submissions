class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //matrix is sorted in increasing order if read top to bottom left to right.

        //the goal is O(log(m*n)) time, a binary serach applied to each row then each column

        //matrix[row][column]

        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int top = 0; //top row
        int bot = ROWS - 1; //bottom row

        int row = 0; // the target row

        while (top <= bot) {
            row = top + (bot - top) / 2;
            if (target > matrix[row][COLS - 1]) { //the target is bigger than the last element of the row, top row (lowest index row) is moved
                top  = row + 1;
            } else if (target < matrix[row][0]) { //target less than the first value in the row
                bot = row - 1; 
            } else { //the target must be in the current row
                break; 
            }
        }

        if (!(top <= bot)) {
            return false; //if the loop wasn't broken via the else statment there isn't a valid row
        }


        int left = 0;
        int right = COLS - 1;

        //now do a binary serach on the columsn
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};
