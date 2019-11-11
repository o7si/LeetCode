class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        
        data.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        
        cout << "pop" << endl;
        assert(!empty());
        int count = data.size() - 1;
        while (count --) {

            data.push(data.front());
            data.pop();
        }

        int result = data.front();
        data.pop();
        return result;
    }
    
    /** Get the top element. */
    int top() {
        cout << "top" << endl;
        assert(!empty());
        return data.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        
        return data.empty();
    }
private:
    queue<int> data;
};
