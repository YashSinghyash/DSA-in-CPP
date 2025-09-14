#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<long long int> s;
    long long int minVal;

    MinStack() {
    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minVal = val;
        } else {
            if (val < minVal) {
                s.push((long long)2 * val - minVal);
                minVal = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.top() < minVal) {
            minVal = 2 * minVal - s.top();
            s.pop();
        } else {
            s.pop();
        }
    }

    int top() {
        if (s.top() < minVal) {
            return minVal;
        }
        return s.top();
    }

    int getMin() {
        return minVal;
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(3);
    obj->push(5);
    cout << "Top: " << obj->top() << endl;      // 5
    cout << "Min: " << obj->getMin() << endl;   // 3
    obj->push(2);
    obj->push(1);
    cout << "Min: " << obj->getMin() << endl;   // 1
    obj->pop();
    cout << "Min: " << obj->getMin() << endl;   // 2
    obj->pop();
    cout << "Top: " << obj->top() << endl;      // 5
    cout << "Min: " << obj->getMin() << endl;   // 3
    delete obj;
    return 0;
}
