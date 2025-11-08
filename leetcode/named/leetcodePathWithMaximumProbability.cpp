#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        priority_queue<pair<double,int>> pq;
        
        vector<vector <pair<int,double>>> adj(n);

        //create adj list
        for (int i = 0 ; i < edges.size() ; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            double c = succProb[i];

            adj[a].push_back({b,c});
            adj[b].push_back({a,c});

        }

        vector <double> maxPro(n,0);

        pq.push({1 , start_node});

        while (!pq.empty()){
            auto top = pq.top();
            int node = top.second;

            double prob = top.first;

            pq.pop();
            if (maxPro[node] > prob) continue;

            for(auto nei: adj[node]){
                if (maxPro[nei.first] < prob * nei.second){
                    maxPro[nei.first] = prob * nei.second;
                    pq.push({prob * nei.second , nei.first});
                }
            }
        }
        return maxPro[end_node];


    }
};