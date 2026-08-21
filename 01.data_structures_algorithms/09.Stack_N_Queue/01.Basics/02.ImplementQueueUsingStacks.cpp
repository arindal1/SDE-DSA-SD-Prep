class MyQueue {
private:
    stack<int> s1, s2;
public:
    MyQueue() { }
    
    void push(int x) {
        while (s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while (s2.size()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int top = s1.top();
        s1.pop();
        return top;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
