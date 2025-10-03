#include <stack>
#include <iostream>
#include <list>
#include <vector>

using namespace std;


class Solution {
  public:
    void helper(int i , stack<int> &sta , list<int>*adj , vector<bool>&visited){
        visited[i] = true;
        
        for (auto v : adj[i]){
            if (!visited[v]){
                helper(v, sta , adj , visited);
                
            }
        }
        
        sta.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        list<int>*adj = new list<int>[V];
        for (int i = 0 ; i < edges.size() ; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            
            adj[a].push_back(b);
        }
        
        vector<bool> visited(V, false);
        stack <int> sta;
        
        for (int i = 0 ; i < V ; i++){
            if (!visited[i]){
                helper(i , sta , adj, visited);
            }
            
        }

        vector<int> ans;
        
        while (!sta.empty()){
            ans.push_back(sta.top());
            sta.pop();
            
        }
        
        return ans;
        
    }
};