#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int n;
vector<vector<vector<int>>> results_vec;
vector<vector<int>> M;
bool valid(vector<vector<int>> M, int l, int i);

void print(vector<vector<int>> M){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << M[i][j] << " ";
        }
    cout << endl;
    }
}

bool qns(int l, vector<vector<int>> & M){
    if(l == n){
        results_vec.push_back(M);
    }
    for(int i=0; i<n; i++){
        if(valid(M, l, i)){
            M[l][i] = 1;
            qns(l+1, M);
            M[l][i] = 0;
        }
    }
    return false;
}

bool valid(vector<vector<int>> M, int l, int i){
    for(int k=l-1; k>=0; k--){ //check collumns
        if(M[k][i] == 1){
            return false;
        }
    }

    for(int k=1; k<l+1; k++){ //check diagonals
        if(i-k >= 0){ //left confer
            if(M[l-k][i-k] == 1){
                return false;
            }
        }

        if(i + k < n){ //right confer
            if(M[l-k][i+k] == 1){
                return false;
            }
        }
    }


    return true;
}

int main()
{
    cin >> n;

    M.resize(n, vector<int>(n, 0));

    qns(0, M);

    int i=0;
    for(auto result:results_vec){
        cout << "Sol. " << ++i << ":" << endl;
        print(result);
    }

    return 0;
}


