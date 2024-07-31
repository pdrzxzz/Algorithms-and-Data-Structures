#include <iostream>
#include <vector>

using namespace std;

class Dictionary{
    public:
    //  ------attributes------
        int m;
        int cnt;
        vector<vector<int>> hashTable;

    //  ------constructor------
        Dictionary(int size);

    //  ------methods------
        int hash_function(int);
        int find(int);
        void insert(int);
        void print_elements();
};


int main()
{
    //input
    int qtd_elements;
    cin >> qtd_elements;
    Dictionary* d = new Dictionary(10);
    for(int i=0; i<qtd_elements; i++){ //get and insert elements
        int element;
        cin >> element;
        d->insert(element);
    }
    //output
    d->print_elements();
    return 0;
}

Dictionary::Dictionary(int size=10){
    this->m = size;
    this->cnt = 0;
    this->hashTable.resize(size);
}

int Dictionary::hash_function(int k){
    return abs(k % 10);
}

int Dictionary::find(int k){
    int pos = hash_function(k);
    int hash_table_size = this->hashTable[pos].size();
    for(int i=0; i<hash_table_size; i++){
        int element = this->hashTable[pos][i];
        if(element == k){
            return 1;
        }
    }
    return 0;
}

void Dictionary::insert(int k){
    if (!this->find(k)){ //if key not in dict
        int pos = hash_function(k);
        this->hashTable[pos].push_back(k); //append key
        this->cnt++;
    }
}
void Dictionary::print_elements(){
    cout << endl << "---OUTPUT---" << endl; //start to print output
    for(int i=0; i<this->hashTable.size(); i++){ //for each subvector
        cout << i; //print subvector index
        for(int j=0; j<this->hashTable[i].size(); j++){ //for value num in subvector
            cout << " " << this->hashTable[i][j]; //print value
        }
    cout << endl; //end line
    }
}
