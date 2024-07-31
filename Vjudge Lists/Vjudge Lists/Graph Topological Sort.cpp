#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;

void addEdge(int x, int y) { adj[x].push_back(y); }

void topologicalSort()
{
    int V = adj.size();
    vector<int> in_degree(V, 0);

    for (int u = 0; u < V; u++) {
        for (auto x : adj[u])
            in_degree[x]++;
    }

    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            pq.push(i);
            
    int cnt = 0;

    vector<int> top_order;

    while (!pq.empty()) {

        int u = pq.top();
        pq.pop();
        top_order.push_back(u);

        for (auto x : adj[u])
            if (--in_degree[x] == 0)
                pq.push(x);

        cnt++;
    }

    // Check if there is a cycle
    if (cnt != V) {
        cout << "Sandro fails.";
        return;
    }

    // Print topological order
    for (int i = 0; i < top_order.size(); i++)
        cout << top_order[i]+1 << " ";
}



int main()
{
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;
    
    adj.resize(num_nodes);
    
    for(int i=0; i<num_edges; i++){
        int x, y;
        cin >> x >> y;
        addEdge(x-1, y-1);
    }

    topologicalSort();
    
    return 0;
}


