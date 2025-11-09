#include <iostream>
#include <vector>
using namespace std;


class Solution {
  public:
    
    
    bool dfs(int node , int parent , int &timer , vector<int>&disc , vector <int>&low , 
    vector<vector<int>>&adj , vector<bool>&vis , int c , int d ){
        vis[node] = true;
        disc[node] = low[node] = timer++;
        
        for (auto nbr : adj[node]){
            if (nbr == parent) continue;
            
            if (!vis[nbr]){
                bool ans = dfs(nbr,node,timer,disc,low , adj , vis , c , d);
                if (ans) return true;
                low[node] = min(low[node], low[nbr]);
                
                //if bridge between nodes
                
                if (low[nbr] > disc[node]){
                    if ((nbr == c && node == d )|| nbr == d && node == c ){
                        return true;
                    }
                }
            }
            
            //visited
            else {
                low[node] = min(low[node], low[nbr]);
            }
            
        }
        
        return false;
        
        
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        
        vector<vector <int>> adj(V);
        for (int i = 0 ; i < edges.size() ; i++){
            
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        
        int timer = 0;
        
        vector<int>disc(V,0);
        vector<int>low(V,0);
        int parent;
        vector<bool>vis(V,false);
        
        
        for (int i = 0 ; i < V ; i++){
            if (!vis[i]){
                bool ans = dfs(i , parent , timer , disc , low , adj,vis , c, d);
                if (ans) return true;
            }
        }
        return false;
    }
};