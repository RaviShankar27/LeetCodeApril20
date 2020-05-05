class MinStack {
    vector<int> data;
    int min;
    int curr_size;
    vector<int> minHeap;
public:
    /** initialize your data structure here. */
    MinStack() : min(INT_MIN), curr_size(0) {
    }
    
    void push(int x) {
        data.push_back(x);
        minHeap.push_back(x);
        heapify();
        ++curr_size;
        if (min == INT_MIN) {
            min = x;
        }
        else if (x < min){
            min = x;
        }
        return;
    }
    
    void heapify()  {
            
    }
    
    void pop() {
         if (data.empty()) return;
        //here if min element is popped, update min
        int next_min = min;
        /*
        if ((curr_size >= 0) && (min == data[curr_size-1])) {
            next_min = data[0];
            for (int i = 1; i < curr_size-1; ++i) {
                if (data[i] < next_min) {
                    next_min = data[i];
                }
            }
        }
        */
        //heapify
        minHeap.pop_back();
        heapify();
        data.pop_back();
        --curr_size;
        if (curr_size==0) {
            min = INT_MIN;
        }
        else {
            min=next_min;
        }
        
        //for getting minimum we can use heap DS
    }
    
    int top() {
        return !data.empty() ? data[curr_size-1]: -1;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */