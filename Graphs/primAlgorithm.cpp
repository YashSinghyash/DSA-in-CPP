#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        // create adj list 
        
        vector <vector <pair<int,int> >> adj(V);
        for (int i = 0 ; i < edges.size() ; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
            
            
        }
        
        vector <int> key(V,INT_MAX);
        vector <int> parent(V,-1);
        vector <bool> mst(V,false);
        
        key[0] = 0;
        
        
        for (int i = 0; i < V; i++){
            int mini = INT_MAX;
            int u;
            
            for (int j = 0 ; j < V ; j++ ){
                if (mst[j] == false && key[j] < mini){
                    u = j;
                    mini = key[j];
                }
            }
            
            mst[u] = true;
            
            for (auto it : adj[u]){
                int node = it.first;
                int w = it.second;
                
                if (mst[node] == false && w < key[node]){
                    parent[node] = u;
                    key[node] = w;
                    
                }
            }
            
        }
        
        int ans =0;
        for (int i = 1 ; i < V ; i++){
            ans+=key[i];
        }
        
        return ans;
        
        
        
    } 
};