#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph{
    vector<vector<int>> matrix;
    int numNode;
    int numEdge;
    vector<int> Mark; //0 = unvisited, 1 = visited.


    public:
    Graph(int n);
    int first(int v);
    int next(int v, int w);
    void setEdge(int i, int j);
    void setMark(int v, int w);
    int getMark(int v);
    void graphTraverse(stack<int> & s);
    void toposort(int v, stack<int> & s);
    void print_matrix();

};

int main()
{

    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;
    Graph graph{num_nodes};
    for(int i=0; i<num_edges; i++){
        int u, v;
        cin >> u >> v;
        graph.setEdge(u, v);
    }
    stack<int> s;
    graph.graphTraverse(s);
    for(int i=0; i<num_nodes; i++){
        cout << s.top() << " ";
        s.pop();
    }
}

Graph::Graph(int n){
    Mark.resize(n, 0);
    matrix.resize(n, vector<int>(n, 0));
    numEdge = 0;
    numNode = n;
}

int Graph::first(int v){
    for(int i=0; i<numNode; i++){
        if(matrix[v][i] != 0) {
            return i;
        }
    }
    return numNode;
}

int Graph::next(int v, int w){
    for(int i=w+1; i<numNode; i++){
        if(matrix[v][i] != 0) {
            return i;
        }
    }
    return numNode;
}

void Graph::setEdge(int i, int j){
    if(matrix[i][j] == 0){
        numEdge++;
        matrix[i][j] = 1;
    }
}

void Graph::print_matrix(){
    for(int i=0; i<numNode; i++){
        for(int j=0; j<numNode; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::setMark(int v, int w){
    Mark[v] = w;
}

int Graph::getMark(int v){
    return Mark[v];
}

void Graph::graphTraverse(stack<int> & s){
    for(int v=0; v<numNode; v++){
        setMark(v, 0);
    }
    for(int v=0; v<numNode; v++){
        if(getMark(v) == 0){
            toposort(v, s);
        }
    }
}

void Graph::toposort(int v, stack<int> & s){
    setMark(v, 1);
    int w = first(v);
    while(w < numNode){
        if(getMark(w) == 0){
            toposort(w, s);
        }
        w = next(v, w);
    }
    s.push(v);
}



