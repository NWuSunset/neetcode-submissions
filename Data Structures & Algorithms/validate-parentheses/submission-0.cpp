class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        
        for (char c : s ) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stack.empty()) {
                    return false;
                }
                char top = stack.top();
                if (top != '(' && c == ')' || top != '{' && c == '}' || top != '[' && c == ']') {
                    return false;
                }
                
                stack.pop();
            }
        }
        

        return stack.empty();
    }
};
