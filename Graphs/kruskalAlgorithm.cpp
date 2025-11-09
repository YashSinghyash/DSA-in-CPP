#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp (vector<int>&a , vector<int>&b){
        return a[2] < b[2];
    }
class Solution {
  public:
    int findParent(vector<int>&parent, int node){
        if (parent[node]==node){
            return node;
        }
        return parent[node] = findParent(parent,parent[node]);
    }
    void unionSet(int u , int v, vector <int>&parent, vector <int>&rank){
        u = findParent(parent, u);
        v = findParent(parent, v);
        
        if (rank[u] < rank[v]){
            parent[u] = v;
        }
        else if (rank[u] > rank[v]){
            parent[v] = u;
        }
        
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    

    int spanningTree(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),  edges.end() , cmp);
        
        vector <int> parent(n);
        vector <int> rank(n,0);
        
        for (int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
        int ans = 0;
        for(int i = 0 ; i < edges.size () ; i++){
            
            int node1 = findParent(parent, edges[i][0]);
            int node2 = findParent(parent, edges[i][1]);
            int weight = edges[i][2];
            
            if (node1 != node2){
                ans += weight;
                unionSet(node1, node2 , parent,rank);
            }

        }
        return ans;
    }
};