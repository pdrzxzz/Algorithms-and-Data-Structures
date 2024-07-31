#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Função para adicionar uma aresta no grafo
void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].emplace_back(make_pair(v, weight));
    adj[v].emplace_back(make_pair(u, weight));
}

// Função para encontrar a MST usando o algoritmo de Prim
int primMST(vector<pair<int, int>> adj[], int n) {
    // Inicialização
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int start = 0;
    pq.push(make_pair(0, start));
    key[start] = 0;

    int maxEdgeWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Ignorar o vértice se ele já está na MST
        if (inMST[u]) continue;

        inMST[u] = true;

        // Atualizar as chaves dos vértices adjacentes
        for (auto &[v, weight] : adj[u]) {
            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
            }
        }

        // Atualizar o peso máximo da aresta na MST
        maxEdgeWeight = max(maxEdgeWeight, key[u]);
    }

    // Verificar se todos os vértices estão na MST (grafo conectado)
    for (bool connected : inMST) {
        if (!connected) return -1; // "IMPOSSIBLE"
    }

    return maxEdgeWeight;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        vector<pair<int, int>> adj[n];
        for (int i = 0; i < m; ++i) {
            int u, v, weight;
            cin >> u >> v >> weight;
            addEdge(adj, u, v, weight);
        }

        int result = primMST(adj, n);
        if (result == -1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << result << endl;
        }
    }
    return 0;
}
