#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        for (int i = 0 ; i < edges.size() ; i++ ){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            
        }
        
        // create indegree
        
        vector <int> indegree(V , 0);
        for (int i = 0 ; i < V ; i++){
            for (auto a : adj[i]) indegree[a]++;
        }
        
        queue <int> q;
        for (int i = 0 ; i < V ; i++){
            if (indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while (!q.empty()){
            int a = q.front();
            ans.push_back(a);
            q.pop();
            for (auto nei : adj[a]){
                indegree[nei]--;
                if (indegree[nei]==0) q.push(nei);
                
            }
        }
        
        return ans;
    }
};