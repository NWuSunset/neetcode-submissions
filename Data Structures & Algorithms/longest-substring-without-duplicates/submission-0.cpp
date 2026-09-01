class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0; 
        unordered_set<char> c_set;
        int l = 0; // left index of array
        // use a variable sliding window and change size until condition met


        //r for right boundary expansion, l for left boundary contraction
        //r expands via the for loop
        for (int r =  0; r < s.length(); r++)
        {
            //while condition shink the window by moving the left size until we have no duplicates anymore
            while (c_set.contains(s[r])) { //while there is still a duplicate                
                //remove from hash set if removed from window
                c_set.erase(s[l]);
                //move the left 'pointer'
                l += 1;      
            }
            
            int w_len = (r - l) + 1;
            //update current window length if greater than previous
            if ( w_len > longest ) {
                longest = w_len;
            }

            //add the character to the set since it isn't a duplicate
            c_set.insert(s[r]);
        }
        return longest;
    }
};
