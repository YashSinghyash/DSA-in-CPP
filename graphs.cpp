#include <iostream>
#include <unordered_map>
#include <list>


using namespace std;


class Graph{
public:
    unordered_map<int , list<int>>adj;

    void addEdge(int a , int b , bool direction){
        adj[a].push_back(b);

        if (direction == 0){
            adj[b].push_back(a);
        }

    }

    void printEdge(){
        for (auto i : adj){
            cout << i.first <<"->";
            for (auto j :i.second){
                cout << j << " ";
            }

            cout <<endl;
        }
    }
};

int main(){
    int n , m;

    cout << "Enter number of nodes (n)";
    cout << endl;
    cin >> n;

    cout << "Enter number of edges (m)";
    cout << endl;
    cin >> m;

    Graph g;

    for (int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        g.addEdge(u,v,0);
    }

    g.printEdge();

    return 0;

}