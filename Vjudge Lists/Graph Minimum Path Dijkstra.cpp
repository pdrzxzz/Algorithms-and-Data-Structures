#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>
using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adjList; // Lista de adjacência
    int numNode;
    vector<int> Mark; // 0 = não visitado, 1 = visitado
    vector<int> distance;

public:
    Graph(int n);
    void addEdge(int u, int v, int weight);
    void minpath(int start);
    int getDistance(int start, int destiny);
};

struct comparator {
    bool operator()(const tuple<int, int>& a, const tuple<int, int>& b) {
        return get<1>(a) > get<1>(b);
    }
};

Graph::Graph(int n) {
    numNode = n;
    adjList.resize(n);
    Mark.resize(n, 0);
    distance.resize(n, numeric_limits<int>::max());
}

void Graph::addEdge(int u, int v, int weight) {
    adjList[u].push_back(make_pair(v, weight));
    adjList[v].push_back(make_pair(u, weight));
}

void Graph::minpath(int start) {
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, comparator> pq;
    pq.push(make_tuple(start, 0));
    distance[start] = 0;

    while (!pq.empty()) {
        int u = get<0>(pq.top());
        pq.pop();

        if (Mark[u] == 1) continue;
        Mark[u] = 1;

        for (auto edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (Mark[v] == 0 && distance[v] > distance[u] + weight) {
                distance[v] = distance[u] + weight;
                pq.push(make_tuple(v, distance[v]));
            }
        }
    }
}

int Graph::getDistance(int start, int destiny) {
    minpath(start);
    return distance[destiny];
}

int main() {
    int num_cases;
    cin >> num_cases;
    for (int i = 0; i < num_cases; i++) {
        int num_nodes, num_edges, start, destiny;
        cin >> num_nodes >> num_edges >> start >> destiny;

        Graph graph(num_nodes);

        for (int j = 0; j < num_edges; j++) {
            int server1, server2, latency;
            cin >> server1 >> server2 >> latency;
            graph.addEdge(server1, server2, latency);
        }

        cout << "Case #" << i + 1 << ": ";
        int result = graph.getDistance(start, destiny);
        if (result < numeric_limits<int>::max()) {
            cout << result << endl;
        } else {
            cout << "unreachable" << endl;
        }
    }

    return 0;
}