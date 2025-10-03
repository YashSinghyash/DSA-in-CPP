#include <iostream>

#include <vector>
#include <queue>
#include <list>
using namespace std;
class Solution {
  public:
    bool isCycleBFS(int i , vector <bool> &visited , list<int> *adj , int V){
        vector<int> parent(V,-1);
        parent[i] = -1;
        visited[i] = true;
        queue<int> q;
        q.push(i);
        while (!q.empty()){
            int front = q.front();
            q.pop();
            
            for (auto m : adj[front]){
                if (visited[m] == true && m != parent[front]){
                    return true;
                }
                
                else if(!visited[m]){
                    q.push(m);
                    visited[m] = true;
                    parent[m] = front;
                }
            }
            
        }
        
        return false;
    }
    
    
    bool isCycleDFS(int i , int parent , vector <bool> &visited , list <int> *adj){
        visited[i] = true;
        
        for (auto j : adj[i]){
            if (!visited[j]){
                bool cycleDetect = isCycleDFS(j , i , visited , adj);
                if (cycleDetect) return true;
            }
            
            else if (j != parent){
                return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        int a = edges.size();
        list<int> *adj = new list<int>[V];
        
        for (int i = 0 ; i < a ; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector <bool> visited(V,false);
        bool ans = false;
        for (int i = 0 ; i < V ; i++){
            if (visited[i] == false){
                ans = isCycleDFS(i , -1 , visited , adj);
                if(ans) return true;
            }
        }
        
        return ans;
        
        
    }
};