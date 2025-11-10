#include <iostream>
#include <vector>
#include <stack>


using namespace std;

class Solution {
  public:
    void dfs (int node , vector <bool> &vis , stack <int> &st , vector<vector<int>>&adj){
        vis[node] = true;
        for (auto nbr:adj[node]){
            if (!vis[nbr]){
                dfs(nbr , vis , st , adj);
            }
        }
        st.push(node);
    }
    
    void dfsTranspose(int node , vector <bool> &vis , vector<vector<int>>& transpose){
        vis[node] = true;
        for(auto nbr : transpose[node]){
            if(!vis[nbr]) dfsTranspose(nbr, vis , transpose);
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        stack <int>st;
        
        
        int n = adj.size();
        vector<bool> vis(n,false);
        for (int i = 0 ; i < n ; i++){
            if (!vis[i]){
                dfs(i , vis , st , adj);
            }
        }
        
        // transpose
        
        vector<vector<int>> transpose(n);
        
        for (int i = 0 ; i < n ;i++){
            vis[i] = false;
            for (auto nbr : adj[i]){
                transpose[nbr].push_back(i);
            }
        }
        
        // dfs using above;
        int count = 0;
        while (!st.empty()){
            int top = st.top();
            st.pop();
            
            if(!vis[top]){
                count++;
                dfsTranspose(top, vis, transpose);
            }
        }
        
        return count;
        
    }
};