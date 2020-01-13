class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        
        data.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {

        assert(!empty());
        stack<int> tmp;
        while (!data.empty()) {

            tmp.push(data.top());
            data.pop();
        }

        int result = tmp.top();
        tmp.pop();
        while (!tmp.empty()) {

            data.push(tmp.top());
            tmp.pop();
        }
        return result;        
    }
    
    /** Get the front element. */
    int peek() {

        assert(!empty());
        stack<int> tmp;
        while (!data.empty()) {

            tmp.push(data.top());
            data.pop();
        }

        int result = tmp.top();
        while (!tmp.empty()) {

            data.push(tmp.top());
            tmp.pop();
        }
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        
        return data.empty();
    }
private:
    stack<int> data;
};
