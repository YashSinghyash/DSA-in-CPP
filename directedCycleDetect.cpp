#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
  public:
    bool helper(int i , vector<bool> &visited , vector<bool>&dfsvisited ,list <int> *adj ){
        visited[i] = true;
        dfsvisited[i] = true;
        
        for (auto m : adj[i]){
            if (visited[m] == false){
                bool isCycle = helper(m , visited , dfsvisited , adj);
                if (isCycle) return true;
            }
            
            else if (dfsvisited[m] == true){
                return true;
            }
            
            
            
        }
        
        dfsvisited[i] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        int n = edges.size();
        list<int> *adj = new list<int>[V];
        vector<bool> visited(V,false);
        vector<bool> dfsvisited(V,false);
        for (int i = 0 ; i < n ; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            
            adj[a].push_back(b);
        }
        
        
        for (int i = 0 ; i < V ; i++){
            if (visited[i] == false){
                bool isCycle = helper(i , visited , dfsvisited , adj);
                if (isCycle) return true;
            }
        }
        return false;
    }
};