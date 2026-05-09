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
    void dijkstra(int src){
        vector<int> dist (V, INT16_MAX);
        priority_queue<
            pair<int,int>,          //type of value
            vector<pair<int,int>>,  //container
            greater<pair<int,int>>  //comparator
        > pq;
        dist[src] = 0;
        pq.push({0,src});
        while (!pq.empty())
        {
            int currentDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto nbr : l[node]){
                int adjNode = nbr.first;
                int weight = nbr.second;
                if(currentDist+weight<adjNode){
                    dist[adjNode] = currentDist+weight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
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
}