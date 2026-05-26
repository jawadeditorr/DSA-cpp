#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph{

    int V;

    list<pair<int,int>> *l;

public:

    Graph(int V){

        this->V = V;

        l = new list<pair<int,int>>[V];
    }

    void addEdge(int edge1, int edge2, int weight){

        l[edge1].push_back({edge2, weight});

        l[edge2].push_back({edge1, weight});
    }

    void prims(){

        // {weight, node, parent}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<bool> visited(V, false);

        int totalCost = 0;

        // Start from node 0
        pq.push({0, 0, -1});

        cout << "\nEdges in MST:\n";

        while(!pq.empty()){

            auto top = pq.top();
            pq.pop();

            int weight = top[0];
            int node = top[1];
            int parent = top[2];

            if(visited[node])
                continue;

            visited[node] = true;

            totalCost += weight;

            // Ignore first node
            if(parent != -1){

                cout << parent
                     << " - "
                     << node
                     << " : "
                     << weight
                     << endl;
            }

            for(auto neighbour : l[node]){

                int adjNode = neighbour.first;
                int edgeWeight = neighbour.second;

                if(!visited[adjNode]){

                    pq.push({
                        edgeWeight,
                        adjNode,
                        node
                    });
                }
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

    g1.addEdge(0,1,5);

    g1.addEdge(1,2,3);

    g1.addEdge(1,3,7);

    g1.addEdge(2,3,2);

    g1.addEdge(2,4,8);

    g1.display();

    g1.prims();
}