class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }


        //use a fixed size sliding window (since we a permutation of s1 it will be size of s1)
        //Check for the frequency of characters within the window if it matches the s1 then it's a permutation

        unordered_map<char, int> freq_s2;
        unordered_map<char, int> freq_s1; 

        int l = 0; //left pointer of window

        //catalog the first window
        for (int r = 0; r < s1.length(); r++) {
            freq_s2[s2[r]]++; //update the frequency of the character in the maps
            freq_s1[s1[r]]++; 
        }

        //move the window along
        for (int r = s1.length(); r <= s2.length(); r++) {
            //if we found a permutation
            if (freq_s2 == freq_s1) {
                return true;
            }

            //Add the new character in the winodw to the map and remove the old character 
            freq_s2[s2[r]]++;
            freq_s2[s2[l]]--;

            //remove from map if frequency hits 0
            if (freq_s2[s2[l]] == 0) {
                freq_s2.erase(s2[l]);
            }

            l++; //update the left pointer position            
        }
        return false;        
    }
};
