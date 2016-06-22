class Queue {
private:
    int front;
    int cnt;
    stack<int> data;

public:
    Queue() : cnt(0) {}
public:
    // Push element x to the back of queue.
    void push(int x) {
        if(cnt == 0)
            front = x;
        data.push(x);
        cnt ++;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> tmp;
        for(int i=0; i<cnt-1; i++)
        {
            tmp.push(data.top());
            data.pop();
        }
        cnt--;
        if(cnt > 0) front = tmp.top();
        for(int i=0; i<cnt; i++)
        {
            data.push(tmp.top());
            tmp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        return front;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return cnt == 0;
    }
};