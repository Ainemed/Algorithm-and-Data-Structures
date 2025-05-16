#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj; // (dest, peso)
    vector<tuple<int, int, int>> edges; // per Bellman-Ford

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        edges.push_back({u, v, w});
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "\nDijkstra (from " << src << "):\n";
        for (int i = 0; i < V; ++i)
            cout << "To " << i << " : " << (dist[i] == INT_MAX ? -1 : dist[i]) << "\n";
    }

    void bellmanFord(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        for (int i = 1; i < V; ++i) {
            for (auto [u, v, w] : edges) {
                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }

        // check ciclo negativo
        for (auto [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                cout << "\nBellman-Ford: Negative cycle detected.\n";
                return;
            }
        }

        cout << "\nBellman-Ford (from " << src << "):\n";
        for (int i = 0; i < V; ++i)
            cout << "To " << i << " : " << (dist[i] == INT_MAX ? -1 : dist[i]) << "\n";
    }

    void floydWarshall() {
        vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

        for (int i = 0; i < V; ++i)
            dist[i][i] = 0;

        for (auto [u, v, w] : edges)
            dist[u][v] = w;

        for (int k = 0; k < V; ++k)
            for (int i = 0; i < V; ++i)
                for (int j = 0; j < V; ++j)
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        cout << "\nFloyd-Warshall (all pairs shortest paths):\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] == INT_MAX)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

// Esempio di utilizzo
int main() {
    Graph g(5);
    g.addEdge(0, 1, 6);
    g.addEdge(0, 3, 7);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, -4);
    g.addEdge(2, 1, -2);
    g.addEdge(3, 2, -3);
    g.addEdge(3, 4, 9);
    g.addEdge(4, 0, 2);
    g.addEdge(4, 2, 7);

    g.dijkstra(0);       // Non supporta negativi → risultati imprecisi qui
    g.bellmanFord(0);    // Corretto con pesi negativi
    g.floydWarshall();   // Tutti i cammini

    return 0;
}