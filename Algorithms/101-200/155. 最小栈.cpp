class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        
        data.push(x);

        if (helper.empty() || x <= helper.top())
            helper.push(x);
    }
    
    void pop() {
        
        if (data.empty())
            return;

        int value = data.top();
        data.pop();

        if (value == helper.top())
            helper.pop();
    }
    
    int top() {
        
        return data.top();
    }
    
    int getMin() {
        
        return helper.top();
    }
private:
    stack<int> data;
    stack<int> helper;
};
