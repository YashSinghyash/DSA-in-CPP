#include <iostream>
#include <queue>

using namespace std;


class Node{
public:
    int data;
    int i;
    int j;
    
    Node(int data , int i , int j){
        this->data = data;
        this->i = i;
        this->j = j;
    }
    
};

class compare{
public:
    bool operator()(Node* a, Node*b){
        return a->data > b->data;
    }
};



class Solution {
  public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    priority_queue<Node* , vector <Node*> , compare> minheap;
        for (int i = 0 ; i < K ; i++){
            Node* temp = new Node(arr[i][0] , i , 0);
            minheap.push(temp);
        }
        
        vector <int> ans;
        while (minheap.size()> 0){
            Node* tmp = minheap.top();
            minheap.pop();
            
            ans.push_back(tmp->data);
            int i = tmp->i;
            int j = tmp->j;
            
            if (j+ 1 < arr[i].size()){
                Node *nxt = new Node(arr[i][j+1] , i , j+1);
                minheap.push(nxt);
            }
            
            
            
        }
        return ans;
    }
};