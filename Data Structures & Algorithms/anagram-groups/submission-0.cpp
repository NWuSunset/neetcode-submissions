class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //vector<unordered_map<char, int>> 
        unordered_map<string, vector<string>> result; //string is the key to the anagram list.

        for (auto& str : strs) { //go through all the strings
            int count[26] = {0}; //count array for each of the letters in the alphabet, keep track of how many for this string
            for (char c : str) { //go through all the characters in a string
                count[c - 'a']++; //increment value for each letter occurance 
            }
            
            string key = to_string(count[0]); // make the key for the result vector 
                                             // a string that represents the occurances of each character in the alphebet
            for (int i = 1; i < 26; i++) {
                key += ' ' + to_string(count[i]); //makes a list of occurances for letter of the alphebet as the key for the anagram vector spcae for easier debug
            }

            result[key].push_back(str); //put the string related to the key in the corresponding vector.
        }

        //now get the values out of the result map into a final solution list
        vector<vector<string>> final_res;
        
        //we already have the vector<string> list of anagrams from 'result' , just put those anagram lists into this new vector
        for (auto& result_pair : result) { //loop through all of the map pairs and put the anagram lists into the final one.
            final_res.push_back(result_pair.second); 
        }

        return final_res;
    }
};
