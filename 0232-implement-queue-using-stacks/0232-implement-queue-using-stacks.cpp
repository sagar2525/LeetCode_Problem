class MyQueue {
public:
stack<int> st;
stack<int> s;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        int temp = s.top();
        s.pop();
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        return temp;

    }
    
    int peek() {
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        int temp = s.top();
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        return temp;
    }
    
    bool empty() {
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
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