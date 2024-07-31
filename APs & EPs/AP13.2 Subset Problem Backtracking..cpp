#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int qtd, soma_desejada;
vector<int> nums_vec;
vector<int> nums_in;

void print(vector<int> v){
    for(auto n:v){
        cout << n << " ";
    }
    cout << endl;
}

int soma_restante(int i){
    int soma;
    for(int k=i; k<qtd; k++){
        soma += nums_vec[k];
    }
    return soma;
}

bool backtrack(int soma, int index){
    if(soma == soma_desejada){
        return true;
    }
    else if(soma > soma_desejada){
        return false;
    }
    else if(soma + soma_restante(index) < soma_desejada){
        return false;
    }

    for(int i=index; i<qtd; i++){
        soma += nums_vec[i];
        nums_in.push_back(nums_vec[i]);
        if(backtrack(soma, i+1)){
            return true;
        }
        else{
            soma -= nums_vec[i];
            nums_in.pop_back();
        }
    }
    return false;

}

int main()
{
    //input
    cin >> qtd >> soma_desejada;
    for(int i=0; i<qtd; i++){
        int num;
        cin >> num;
        nums_vec.push_back(num);
    }

    //sort nums
    sort(nums_vec.begin(), nums_vec.end());

    //algorithm
    backtrack(0, 0);

    //print result
    print(nums_in);

    return 0;
}


