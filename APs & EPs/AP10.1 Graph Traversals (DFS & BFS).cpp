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
    void delEdge(int i, int j);
    void setMark(int v, int w);
    int getMark(int v);
    void graphTraverse(int i, int t); //0 = BFS, 1 = DFS.
    void DFS(int v);
    void BFS(int start);
    void print_matrix();

};

int main()
{

    int num_nodes, num_operations;
    cin >> num_nodes >> num_operations;
    Graph graph{num_nodes};
    for(int i=0; i<num_operations; i++){
        string operation;
        cin >> operation;
        int k;
        cin >> k;
        if(operation == "add"){
            int j;
            cin >> j;
            graph.setEdge(k, j);
        }
        else if(operation == "DFS"){
            graph.graphTraverse(k, 1);
            cout << endl;
        }
        else if(operation == "BFS"){
            graph.graphTraverse(k, 0);
            cout << endl;
        }
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
        matrix[j][i] = 1;
    }
}

void Graph::delEdge(int i, int j){
    if(matrix[i][j] != 0){
        numEdge--;
        matrix[i][j] = 0;
        matrix[j][i] = 0;
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

void Graph::graphTraverse(int i, int t){ //0 = BFS, 1 = DFS.
    for(int v=0; v<numNode; v++){
        setMark(v, 0);
    }
    for(int v=i; v<numNode; v++){
        if(getMark(v) == 0){
            if(t == 1){
                DFS(v);
            }
            else if(t == 0){
                BFS(v);
            }
        }
    }
}

void Graph::DFS(int v){
    cout << v << " ";
    setMark(v, 1);
    int w = first(v);
    while(w < numNode){
        if(getMark(w) == 0){
            DFS(w);
        }
        w = next(v, w);
    }
}

void Graph::BFS(int start){
    queue<int> Q;
    Q.push(start);
    setMark(start, 1);
    while(Q.size() > 0){
        int v = Q.front();
        Q.pop();
        cout << v << " ";
        int w = first(v);
        while(w < numNode){
            if(getMark(w) == 0){
                setMark(w, 1);
                Q.push(w);
            }
            w = next(v, w);
        }
    }
}

