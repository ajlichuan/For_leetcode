class Stack {
private:
    queue<int> data;
    int last;
    int cnt;
    
public:
    Stack(): cnt(0) {}
    
public:
    // Push element x onto stack.
    void push(int x) {
        last = x;
        data.push(x);
        cnt++;
    }

    // Removes the element on top of the stack.
    void pop() {
        for(int i=0; i< cnt-2; i++)
        {
            data.push(data.front());
            data.pop();
        }

        last = data.front();
        data.push(last);
        data.pop();

        data.pop();
        cnt--;
    }

    // Get the top element.
    int top() {
        return last;
    }

    // Return whether the stack is empty.
    bool empty() {
        return cnt == 0;
    }
};