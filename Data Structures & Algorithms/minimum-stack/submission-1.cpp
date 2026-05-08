class MinStack {
public:
    stack<int> stk;
    stack<int> stkmin;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(stkmin.empty()){
            stkmin.push(val);
        }
        else if(stkmin.top()>val){
            stkmin.push(val);
        }
        else{
            stkmin.push(stkmin.top());
        }
    }
    
    void pop() {
        stkmin.pop();
        stk.pop();
    }
    
    int top() {
      int ans=  stk.top();
    return ans;
    }
    
    int getMin() {
        int ans=stkmin.top();
        return ans;
    }
};
