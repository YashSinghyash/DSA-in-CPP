#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph{
    int v;
    list <int> *l;

public:
    Graph(int a){
        v =a;
        l = new list<int>[v];
    }

    void addEdge(int a , int b){
        l[a].push_back(b);
        l[b].push_back(a);
    }

    void bfd(){
        queue <int> q;
        vector <bool> vis(v, false);

        q.push(0);

        vis[0] = true;

        while (!q.empty()){
            int a = q.front();
            q.pop();
            cout << a;

            for (int b : l[a]){
                if (vis[b] == false)
                {q.push(b);
                vis[b] = true;}
            }
        }



    }

};


int main(){


    return 0;


}