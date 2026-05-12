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
    
    void AdjacencyMatrix(){

        int matrix[V][V];

        // Initialize matrix with 0
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                matrix[i][j] = 0;
            }
        }

        // Fill matrix
        for(int i = 0; i < V; i++){

            for(int neighbor : l[i]){
                matrix[i][neighbor] = 1;
            }
        }

        cout << "\nAdjacency Matrix:\n";

        for(int i = 0; i < V; i++){

            for(int j = 0; j < V; j++){
                cout << matrix[i][j] << " ";
            }

            cout << endl;
        }
    }

    void BFS(int start){

        bool *visited = new bool[V];

        for(int i = 0; i < V; i++){
            visited[i] = false;
        }

        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS Traversal: ";

        while(!q.empty()){

            int node = q.front();
            q.pop();

            cout << node << " ";

            for(int neighbor : l[node]){

                if(!visited[neighbor]){

                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
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