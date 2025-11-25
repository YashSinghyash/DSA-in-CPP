#include <iostream>
#include <vector>
#include <climits>
#include <set>


using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector <vector <pair <int,int>>> adj(V);
        for (int i = 0 ; i < edges.size() ;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        
        
        
        vector <int > dist(V);
        for (int i = 0 ; i < V; i++){
            dist[i] = INT_MAX;
        }
        
        set <pair<int,int>>st;
        
        dist[src] = 0;
        st.insert({0,src});
        
        while(!st.empty()){
            auto top = *(st.begin());
            
            int nodeDistance = top.first;
            int node = top.second;
            
            st.erase(st.begin());
            
            for (auto nei: adj[node]){
                if(nodeDistance + nei.second < dist[nei.first]) {
                    
                    auto record = st.find({dist[nei.first] , nei.first });
                    
                    // if record found
                    
                    if (record!=st.end()) st.erase(record);
                    
                    // update distance
                    dist[nei.first] = nodeDistance + nei.second;
                    
                    // record push
                    
                    st.insert({nodeDistance + nei.second , nei.first});
                }
                
            }
            
            
            
        }
        
        for (int i = 0 ; i < V ; i++) if (dist[i] == INT_MAX) dist[i] = -1;
        return dist;
    }
    
    
};