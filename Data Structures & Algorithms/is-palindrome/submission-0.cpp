class Solution {
public:
    bool isPalindrome(string s) {
        // Walk from front and back of the string s
        int i = 0, j = s.length() - 1;

        while (i < j) {
            if (!std::isalnum(s[i])) { //ignore non alpha numeric 
                i++;
            } else if (!std::isalnum(s[j])) {
                j--; 
            }
            else if  (std::tolower(s[i]) == std::tolower(s[j])) {
                i++;
                j--;
            } else {
                return false; // not equal
            }
        } 
        return true;
    }
};
