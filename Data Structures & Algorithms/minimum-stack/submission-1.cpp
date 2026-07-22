class MinStack {
public:
    std::stack<int> stack;
    //int min = 0;
    std::stack<int> minStack;
    MinStack() {}
    
    void push(int val) {
        stack.push(val);
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            val = std::min(minStack.top(), val);
            minStack.push(val);
        }
        
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
