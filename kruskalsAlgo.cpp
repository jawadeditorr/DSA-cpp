#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

class Graph{

    int V;

    list<pair<int,int>> *l;

    // Edge list for Kruskal
    vector<vector<int>> edges;

public:

    Graph(int V){

        this->V = V;

        l = new list<pair<int,int>>[V];
    }

    void addEdge(int edge1, int edge2, int weight){

        l[edge1].push_back({edge2, weight});

        l[edge2].push_back({edge1, weight});

        // store edges
        edges.push_back({weight, edge1, edge2});
    }

    // DSU Find
    int find(int x, vector<int> &parent){

        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x], parent);
    }

    // DSU Union
    void unionSet(int a, int b,
                  vector<int> &parent,
                  vector<int> &rank){

        a = find(a, parent);
        b = find(b, parent);

        if(a != b){

            if(rank[a] < rank[b])
                swap(a,b);

            parent[b] = a;

            if(rank[a] == rank[b])
                rank[a]++;
        }
    }

    void kruskals(){

        // Sort edges according to weight
        sort(edges.begin(), edges.end());

        vector<int> parent(V);
        vector<int> rank(V,0);

        for(int i = 0; i < V; i++)
            parent[i] = i;

        int totalCost = 0;

        cout << "\nEdges in MST:\n";

        for(auto edge : edges){

            int weight = edge[0];
            int u = edge[1];
            int v = edge[2];

            // check cycle
            if(find(u,parent) != find(v,parent)){

                unionSet(u,v,parent,rank);

                cout << u << " - "
                     << v << " : "
                     << weight << endl;

                totalCost += weight;
            }
        }

        cout << "\nMinimum Cost = "
             << totalCost << endl;
    }

    void display(){

        for(int i = 0; i < V; i++){

            cout << i << " : ";

            for(auto j : l[i]){

                cout << "(" << j.first
                     << "," << j.second << ") ";
            }

            cout << endl;
        }
    }

};

int main(){

    Graph g1(5);

    g1.addEdge(0,1,10);

    g1.addEdge(0,2,6);

    g1.addEdge(0,3,5);

    g1.addEdge(1,3,15);

    g1.addEdge(2,3,4);

    g1.display();

    g1.kruskals();
}