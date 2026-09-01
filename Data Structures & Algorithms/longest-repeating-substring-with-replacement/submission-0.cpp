class Solution {
public:
    int characterReplacement(string s, int k) {
        
        //use a variable size sliding window to break up the problem into substrings, 
        //finding the longest substring that is within k replacements


        int res = 0;
        int l = 0;
        int max_freq = 0;
        unordered_map<char, int> count; // a map to keep track of the frequency of each character in a substring

        //expand window on the right
        for (int r = 0; r < s.length(); r++) { 
            count[s[r]]++; //increment count of character when adding to the window

            //update the character with the highest frequency in the substring
            max_freq = max(max_freq, count[s[r]]);

            //(r - l + 1) - max_freq; is the number of replacements that needs to be made to the substring to have one character
            //We need to shrink the window length until we are within the k replacements (ensuring we can create a substring of one distinct character)
            while ((r - l + 1) - max_freq > k) {
                count[s[l]]--; //remove character once it leaves the window
                l++; //move left point
            }
            //Update the max substring length once we have a valid one that can have one distinct character within k replacements.
            res = max(res, r - l + 1);
        }
        return res;
    }
};

