#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
    int visited;
    int visited_max;
    int total_num_squares;
    int numRows;
    int numCol;
    int num_unreachable;
    vector<vector<int>> matrix; //-1 -> not on board, 0 -> unreachable, 1 -> reachable

    Graph(int num_rows);
    void setRow(int row_index, int row_offset, int row_num_squares);
    void reach(int r, int c);
    void updateUnreachable();
    void print_matrix();

};

int main()
{
    int counter = 0;
    while(true){
        //-----------Building the Graph-----------
        int num_rows;
        cin >> num_rows;
        if(num_rows == 0) break;
        Graph graph{num_rows};
        for(int i=0; i<num_rows; i++){
            int offset, num_squares;
            cin >> offset >> num_squares;
            graph.total_num_squares += num_squares;
            graph.setRow(i, offset, num_squares);
        }

        graph.matrix[0][0] = 1;
        graph.reach(0, 0);

        graph.num_unreachable = graph.total_num_squares - graph.visited_max;

        if(graph.num_unreachable != 1){
        cout << "Case " << ++counter << ", " << graph.num_unreachable << " squares can not be reached." << endl;
        }
        else{
        cout << "Case " << ++counter << ", " << graph.num_unreachable << " square can not be reached." << endl;
        }
    }
    return 0;
}

Graph::Graph(int num_rows){
    visited = 1;
    visited_max = 1;
    total_num_squares = 0;
    numRows = num_rows;
    numCol = 10;
    matrix.resize(num_rows, vector<int>(numCol, -1)); //Building and filling matrix with zeros
    num_unreachable = INT_MAX;
}

void Graph::reach(int r, int c){
    vector<pair<int, int>> positions {{r-2, c-1}, {r-2, c+1}, {r-1, c-2}, {r-1, c+2}, {r+1, c-2}, {r+1, c+2}, {r+2, c-1}, {r+2, c+1}};
    for(auto pos:positions){
        if(pos.first >= 0 && pos.second >= 0 && pos.first < numRows && pos.second < numCol){ //If position on "frame"
            if(matrix[pos.first][pos.second] == 0){ //if position was not visited yet
                visited++;
                visited_max = max(visited, visited_max);
                matrix[pos.first][pos.second] = 1; //mark it as reachable
                reach(pos.first, pos.second); //go to the position
            }
        }
    }
    visited--;
    matrix[r][c] = 0; //go back
}

void Graph::setRow(int row_index, int row_offset, int row_num_squares){
    for(int i=0; i<row_num_squares; i++){
        matrix[row_index][row_offset + i] = 0;
    }
}

void Graph::print_matrix(){
    cout << "---MATRIX---" << endl;
    for(int i=0; i<numRows; i++){
        for(int j=0; j<numCol; j++){
            cout << matrix[i][j] << " ";
        }
    cout << endl;
    }
    cout << "----------" << endl;
}
