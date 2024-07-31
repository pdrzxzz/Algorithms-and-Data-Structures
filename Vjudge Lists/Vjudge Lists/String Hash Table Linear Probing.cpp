#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

class Dictionary{
    public:
    //--attributes--
    int m; //size of hash table
    int cnt; //num of elements in hash table
    vector<string> hashTable;

    //--constructor--
    Dictionary(int size);

    //--methods--
    void insert(string str);
    void remove(string str);
    int find(string str);
    int hashFunction(string str);
    int inDict(string str);
    void print_elements();

};;

int main()
{
    int num_cases; cin >> num_cases; cin.ignore();
    for(int i=0; i<num_cases; i++){
        Dictionary *d = new Dictionary(101);
        int num_operations; cin >> num_operations; cin.ignore();
        for(int j=0; j<num_operations; j++){
            string operation, str;
            getline(cin, operation, ':');
            getline(cin, str);
            if(operation == "ADD"){
                d->insert(str);
            }
            else{
                d->remove(str);
            }
            //d->print_elements();
        }

        // ---printing---
        cout << d->cnt << endl;
        for(int k=0; k<101; k++) {
            if(!d->hashTable[k].empty() && d->hashTable[k] != "NULL"){
            cout << k << ":" << d->hashTable[k] << endl;
            }
        }

    }
    return 0;
}

Dictionary::Dictionary(int size){
    cnt = 0;
    m = size;
    hashTable.resize(size);
}

int Dictionary::find(string str){
    int pos = hashFunction(str);
    int pos_inicial = pos;
    for(int j=1; j < 21; j++){
        if(this->hashTable[pos] == str){
            return pos;
        }
        pos = abs((pos_inicial + j*j + 23*j) % 101);
    }
    return -1;
}

void Dictionary::insert(string str){
    if(find(str) == -1 && this->cnt < this->m){ //if str not in dict and there's space in hashTable
    int pos = hashFunction(str);
    int pos_inicial = pos;
        for(int j=1; j< 21; j++){
            if(this->hashTable[pos].empty() || this->hashTable[pos] == "NULL"){
                this->hashTable[pos] = str;
                this->cnt++;
                return;
            }
            pos = abs((pos_inicial + j*j + 23*j) % 101);
        }
    }
}

void Dictionary::remove(string str){
    int pos = find(str);
    if(pos != -1){ //if str in dict
        this->hashTable[pos] = "NULL";
        this->cnt--;
    }
}

int Dictionary::hashFunction(string str){
    int sum = 0;
        for(int i=0; i<str.size(); i++){
        char letter = str[i];
        sum += letter*(i+1);
    }
    int result = abs((19 * sum)%101);
    return result;
}

void Dictionary::print_elements(){
    cout << endl;
    cout << "---HASHTABLE UPDATE---" << endl;
    for(int k=0; k<101; k++) {
        if(!this->hashTable[k].empty() && this->hashTable[k] != "NULL"){
            cout << k << ":" << this->hashTable[k] << endl;
        }
    }
}

