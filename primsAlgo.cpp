#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

// Prim's Algorithm
void primsAlgorithm(int V, vector<vector<pii>> &adj) {
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<bool> visited(V, false);

    int totalCost = 0;

    // Start from node 0
    pq.push({0, 0}); // {weight, node}

    cout << "Edges in MST:\n";

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        totalCost += weight;

        // Traverse neighbors
        for (auto neighbor : adj[node]) {
            int adjNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (!visited[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    cout << "Total Minimum Cost: " << totalCost << endl;
}

int main() {

    int V = 5;

    vector<vector<pii>> adj(V);

    // Adding edges
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    primsAlgorithm(V, adj);

    return 0;
}