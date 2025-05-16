#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

class Graph {
    int V; // Numero di vertici
    vector<tuple<int, int, int>> edges; // archi (peso, u, v)
    vector<vector<pair<int, int>>> adjList; // lista di adiacenza per Prim

public:
    Graph(int V) : V(V) {
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back({weight, u, v});
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    // Kruskal - Union-Find helpers
    int find(vector<int>& parent, int i) {
        if (parent[i] != i)
            parent[i] = find(parent, parent[i]);
        return parent[i];
    }

    void unionSet(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);
        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end()); // ordina per peso
        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; ++i)
            parent[i] = i;

        cout << "\nKruskal MST:\n";
        int mstWeight = 0;
        for (auto [weight, u, v] : edges) {
            int set_u = find(parent, u);
            int set_v = find(parent, v);
            if (set_u != set_v) {
                cout << u << " - " << v << " : " << weight << "\n";
                mstWeight += weight;
                unionSet(parent, rank, set_u, set_v);
            }
        }
        cout << "Total weight: " << mstWeight << "\n";
    }

    void primMST() {
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);
        key[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0}); // (peso, nodo)

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (auto [v, weight] : adjList[u]) {
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        cout << "\nPrim MST:\n";
        int totalWeight = 0;
        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << " : " << key[i] << "\n";
            totalWeight += key[i];
        }
        cout << "Total weight: " << totalWeight << "\n";
    }
};

// Esempio di utilizzo
int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.kruskalMST();
    g.primMST();

    return 0;
}