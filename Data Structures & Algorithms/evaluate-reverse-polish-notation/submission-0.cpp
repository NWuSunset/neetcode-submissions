class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //push numbers, if operator pop twice then eval
        std::stack<long long> stack;
        for (auto token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long right = stack.top();
                stack.pop();
                long long left = stack.top();
                stack.pop();
                long long res = 0;

                if (token == "+") {
                    res = left + right;
                } else if (token == "-") {
                    res = left - right;
                } else if (token == "*") {
                    res = left * right;
                } else if (token == "/") {
                    res = left / right;
                }
                stack.push(res);
            } else {
            stack.push(std::stoll(token));
          } 
        }
        return static_cast<int>(stack.top());
    }
};
