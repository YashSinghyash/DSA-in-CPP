#include <iostream>
#include <vector>
#include <queue>

using namespace std;



class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector <vector <int>> adj(n);

        for (int i = 0 ; i < edges.size() ; i++){
            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        queue <int> q;
        vector<bool> visited(n);
        q.push(source);
        visited[source] = true;

        while (!q.empty()){
            int curr = q.front();
            
            if (curr == destination) return true;

            q.pop();

            for (auto a : adj[curr]){
                if (!visited[a]){
                    
                    
                        q.push(a);
                        visited[a] = true;}                
            }
        }

        return false;


    }
};