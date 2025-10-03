#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int k = numCourses;
        vector<vector<int>> adj(k);

        for (int i = 0 ; i < pre.size() ; i++){
            int a = pre[i][0];
            int b = pre[i][1];

            adj[b].push_back(a);
        }

        vector <int> indegree(numCourses);
        for (int i = 0 ; i < numCourses ; i++){
            for (auto j : adj[i]){
                indegree[j]++;
            }
        }
        
        queue <int> q;
        for (int i = 0 ; i < numCourses ; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }

        while (!q.empty()){
            int front = q.front();
            q.pop();

            for (auto a : adj[front]){
                if (indegree[a]!=0){
                    indegree[a]--;
                }

                if (indegree[a]== 0) q.push(a);
            }


        }


        for (int i = 0 ; i < k ; i++){
            if (indegree[i] > 0) return false;
        }

        return true;


    }
};