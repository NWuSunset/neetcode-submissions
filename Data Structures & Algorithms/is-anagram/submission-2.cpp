class Solution {
public:
    bool isAnagram(string s, string t) {
        //create 2 hash tables for each string then compare
        //hash table tracks the occurances for each letter?

        if (s.length() != t.length()) { //anagrams will be the same length
            return false;
        }

        unordered_map<char, int> sCount; //char = key, int = value
        unordered_map<char, int> tCount;

        for (int i = 0; i < s.length(); i++) { 
            //once we are at a character increment it's count in the map
            sCount[s[i]]++;
            tCount[t[i]]++;
        }

        //now check if maps are equal
        if (sCount == tCount) {
            return true;
        }

        return false;
    }
};
