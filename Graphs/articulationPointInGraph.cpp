#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
void dfs(int node, int parent, vector<int>&disc, vector<int>&low , vector<bool>&vis ,vector<int> adj[] , vector <int> &ap , int &timer ){
    
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;
    for (auto nbr : adj[node]){
        if (nbr == parent) continue;
        
        if (!vis[nbr]) {
            
            dfs(nbr , node , disc , low , vis , adj , ap , timer );
            low[node] = min(low[node], low[nbr]);
            
            // check ap
            
            if (low[nbr] >= disc[node] && parent !=-1) ap.push_back(node);
            child++;
        }
        
        else {
            low[node] = min(low[node], disc[nbr]);
        }
        
        
    }
    
    if (parent == -1 && child > 1) ap.push_back(node);
}

class Solution {
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        
        
        int timer = 0;
        vector<int>disc(V,-1);
        vector<int>low(V,-1);
        vector<bool>vis(V,false);
        vector <int> ap;
        
        
        
        for (int i = 0 ; i < V ; i++){
            if (!vis[i]) dfs(i,-1,disc,low,vis,adj,ap,timer);
        }
        
        
        if (ap.size()==0) ap.push_back(-1);
        sort(ap.begin(), ap.end());
        vector<int> ans;
        if (!ap.empty()) {
            sort(ap.begin(), ap.end());
            ans.push_back(ap[0]);
            for (int i = 1; i < ap.size(); i++) {
                if (ap[i] != ap[i-1]) ans.push_back(ap[i]);
            }
        }

        
        return ans;
    }
};