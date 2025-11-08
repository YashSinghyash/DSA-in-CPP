#include <iostream>
#include <stack>
#include <vector>

class Solution {
  public:
    void helperDFS(int i , vector <vector<int>>&adj , vector <bool> &visited , stack <int>& sta){
        visited[i] = true;
        for (auto nei : adj[i]){
            if (!visited[nei]) helperDFS(nei,adj,visited, sta);
        }
        
        sta.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (int i = 0 ; i < edges.size() ; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            
            adj[a].push_back(b);
        }
        
        //adj list is completed
        stack <int> sta;
        vector<bool> visited(V,false);
        for (int i = 0 ; i < V ; i++){
            if (!visited[i]) helperDFS(i,adj,visited,sta);
        }
        
        
        vector <int> ans;
        
        while (!sta.empty()){
            
            ans.push_back(sta.top());
            sta.pop();
        }
        
        
        
        return ans;
    }
};