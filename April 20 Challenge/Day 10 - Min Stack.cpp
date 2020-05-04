/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.
*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<long double> s;
    long double min;
    
	MinStack() {}
    
    void push(long double x) {
        if(s.empty()){
           s.push(x);
           min = x;
        }
        else {
           if(x < min) {
               s.push(2 * x - min);
               min = x ;
           } else {
              s.push(x);
           }
        }
    }
    
    void pop() {
        if(!s.empty()) {
            if(s.top() > min){
                s.pop();
            } else {
                min = 2 * min - s.top() ;
                s.pop() ;
            }
        }
    }
    
    int top() {
        return (s.top() > min) ? s.top() : min;
    }
    
    int getMin() {
        return min;
    }
};

/*
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
*/