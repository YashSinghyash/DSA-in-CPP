#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution {
  public:
    
    void dfs(int node, vector<bool> &vis , stack <int> &s , vector<vector<pair<int,int>>>&adj){
        vis[node] = true;
        
        for (auto nei : adj[node]){
            if (!vis[nei.first]){
                dfs(nei.first,vis,s,adj);
            }
        }
        
        s.push(node);
        
    }
    
    void getShortest(int src , vector <int> &dist , stack<int>&s ,vector<vector<pair<int,int>>>&adj ){
        dist[src] = 0;
        
        
        while (!s.empty()){
            int top = s.top();
            s.pop();
            
            if (dist[top]!=INT_MAX){
                for (auto nei : adj[top]){
                    if(dist[top]+nei.second < dist[nei.first]) dist[nei.first] = dist[top]+nei.second;
                }
            }
        }
        
        
        
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(V);
        
        for (int i = 0 ; i < edges.size() ; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            
            adj[a].push_back({b,c});
        }

    
        vector <bool> visited(V, false);
        stack <int> s;
        for (int i = 0 ; i < V ; i++){
            if (!visited[i]){
                dfs(i,visited,s,adj);
            }
        }
        
        int src = 0;
        vector <int> distance(V);
        
        for (int i = 0 ; i < V ; i++ ){
            distance[i] = INT_MAX;
        }
        
        
        
        getShortest(src, distance, s,adj);
        
        for (int i = 0 ; i < V ; i++){
            if (distance[i]==INT_MAX) distance[i] = -1;
        }
        return distance;
    }
};
