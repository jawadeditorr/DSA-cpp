#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list <int> *l;
public:
    Graph(int V){
        this->V=V;
        l = new list <int> [V];
    }
    void addEdge(int edge1, int edge2){
        l[edge1].push_back(edge2);
        l[edge2].push_back(edge1);
    }
    void display(){
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            for(int j : l[i]){
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    g1.addEdge(2,3);
    g1.addEdge(2,4);

    g1.display();
}