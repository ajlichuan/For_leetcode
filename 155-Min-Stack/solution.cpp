class MinStack {
private:
    int min_data;
    bool is_get_min;
    vector<int> data;
    
public:
    /** initialize your data structure here. */
    MinStack() : is_get_min(false) {
        
    }
    
    void push(int x) {
        data.push_back(x);
        if(is_get_min && min_data > x)
            min_data = x;
    }
    
    void pop() {
        if(is_get_min && data.back() == min_data)
            is_get_min = false;
        data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        if(is_get_min) return min_data;
        
        int mind = data[0];
        
        for(auto it=data.begin()+1; it!=data.end(); ++it)
        {
            if(mind > *it)
                mind = *it;
        }
        
        min_data = mind;
        is_get_min = true;
        
        return mind;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */