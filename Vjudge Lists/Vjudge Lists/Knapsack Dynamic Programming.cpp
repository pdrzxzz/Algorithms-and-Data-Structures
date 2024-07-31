#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> data;
vector<vector<int>> matrix;
int qtd_itens, capacidade;

void print_matrix(){
    for(int i=0; i<qtd_itens+1; i++){
        cout << data[i].first << "-" << data[i].second << ": ";
        for(int j=0; j<capacidade+1; j++){
            cout << matrix[i][j] << " ";
        }
    cout << endl;
    }
    cout << "-------------" << endl;
}

void dp(int linha, int coluna){
    if(matrix[linha][coluna] != -1) return;
    if(linha == 0 || coluna == 0){
        matrix[linha][coluna] = 0;
    }
    else{
        if(coluna - data[linha].first >= 0){ //se o item couber
            dp(linha-1, coluna);
            dp(linha-1, coluna - data[linha].first); //data[linha].first é o peso.
            matrix[linha][coluna] = max(matrix[linha-1][coluna], matrix[linha-1][coluna - data[linha].first] + data[linha].second);
        }
        else{ // se o item não couber
            dp(linha-1, coluna);
            matrix[linha][coluna] = matrix[linha-1][coluna];
        }
    }
}

int main()
{
    cin >> capacidade >> qtd_itens;

    matrix.resize(qtd_itens+1, vector<int>(capacidade+1, -1));

    data.push_back(make_pair(0,0));

    for(int i=0; i<qtd_itens; i++){
        int peso, valor;
        cin >> peso >> valor;
        data.push_back(make_pair(peso, valor));
    }

    dp(qtd_itens, capacidade);

    cout << matrix[qtd_itens][capacidade];

    return 0;
}
