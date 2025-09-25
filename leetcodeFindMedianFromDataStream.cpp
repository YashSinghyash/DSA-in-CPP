#include <iostream>
#include <queue>
using namespace std;



class MedianFinder {
public:
    priority_queue<double> maxheap;
    priority_queue<double, vector<double>, greater<double>> minheap;
    double median = -1.0;

    MedianFinder() {}

    void addNum(int num) {
        double element = num;
        if (maxheap.empty() && minheap.empty()) {
            maxheap.push(element);
            median = element;
            return;
        }

        
        callMedian(element, maxheap, minheap, median);
    }

    int signum(int a, int b) {

        if (a == b)
            return 0;
        if (a > b)
            return 1;
        else return -1;
 
    }
    void
    callMedian(double element, priority_queue<double>& maxi,
               priority_queue<double, vector<double>, greater<double>>& mini,
               double& median) {
        switch (signum(maxi.size(), mini.size())) {
        case 0:
            if (element > median) {
                mini.push(element);
                median = mini.top();

            } else {
                maxi.push(element);
                median = maxi.top();
            }
            break;

        case 1:
            if (element > median) {
                mini.push(element);
                median = (mini.top() + maxi.top()) / 2;
            } else {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
                median = (mini.top() + maxi.top()) / 2;
            }
            break;

        case -1:
            if (element > median) {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
                median = (mini.top() + maxi.top()) / 2;

            } else {
                maxi.push(element);
                median = (mini.top() + maxi.top()) / 2;
            }
            break;
        }
    }
    double findMedian() { return median; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */