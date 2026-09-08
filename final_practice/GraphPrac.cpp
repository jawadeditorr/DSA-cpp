#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V;
    list <int> *l;
public:
    Graph(int V){
        this->V=V;
        l = new list <int> [V];
    }
    void addEdge(int edge1,int edge2,int weight){
        l[edge1].push_back(edge2);
        l[edge2].push_back(edge1);
    }
};