#include <iostream>
#include <vector>
#include <list>
#include <queue>


using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        list<int> *adj = new list<int>[V];
        
        for (int a = 0 ; a < edges.size() ;a++){
            int u = edges[a][0];
            int v = edges[a][1];
            
            adj[u].push_back(v);
        }
        
        
        vector <int> indegree(V);
        
        for (int i = 0 ; i < V ; i++){
            for (auto j : adj[i]){
                indegree[j]++;
            }
        }
        
        queue <int> q;
        
        for (int i = 0 ; i < V ; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector <int> ans;
        
        while (!q.empty()){
            
            int a = q.front();
            q.pop();
            
            ans.push_back(a);
            
            for (auto i: adj[a]){
                indegree[i]--;
                if (indegree[i]== 0) q.push(i);
            }
        }
        
        return ans;
    }
};