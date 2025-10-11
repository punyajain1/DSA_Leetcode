class MyQueue {
public:
    stack<int> s , a;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s.empty()){
            a.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!a.empty()){
            s.push(a.top());
            a.pop();
        }
    }
    
    int pop() {
        int n=s.top();
        s.pop();
        return n;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */