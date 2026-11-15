#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        peek();
        int front = s2.top();
        s2.pop();
        return front;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.peek() << endl;
    cout << "Pop: " << q.pop() << endl;
    cout << "Front after pop: " << q.peek() << endl;

    cout << "Is Empty? ";
    if (q.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}