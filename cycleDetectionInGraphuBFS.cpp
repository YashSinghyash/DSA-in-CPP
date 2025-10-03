#include <iostream>
#include <queue>
#include <stack>
#include <list>

using namespace std;
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        list<int> *adj = new list<int>[V];
        
        for (int i = 0 ; i < edges.size() ; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            
            adj[a].push_back(b);
        }
        
        
        vector <int> visited(V,0);
        for (int i = 0 ; i < V ; i++ ){
            for (auto a : adj[i]){
                visited[a]++;
            }
        }
        
        int count = 0;
        
        queue <int> q;
        
        for (int i = 0 ; i < visited.size() ; i++ ){
            if (visited[i] == 0 ){
                q.push(i);
            }
        }
        
        while (!q.empty()){
            
            int a = q.front();
            q.pop();
            count ++;
            for (auto i : adj[a]){
                visited[i]--;
                if (visited[i] == 0) q.push(i);
            }
        }
        
        if (count == V) return false;
        
        else return true;
    }
};