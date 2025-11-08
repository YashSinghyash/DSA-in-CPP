#include <iostream>
#include <vector>
using namespace std;

class Graph{
    int V;
    vector <vector<int>> adj;

public:
    Graph(int nodes){
        V = nodes;
        adj.resize(V);
    }

    void addEdge(int u , int v){
        adj[u].push_back(v);
    }

    void printGraph(){
        for (int i = 0 ; i < V ; i++){
            cout << i << "->";
            for (auto node : adj[i]) cout << node << ",";
            cout << endl;
        }
    }

    void BFS()
};


int main(){


    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(2,6);
    g.printGraph();
    return 0;

}



