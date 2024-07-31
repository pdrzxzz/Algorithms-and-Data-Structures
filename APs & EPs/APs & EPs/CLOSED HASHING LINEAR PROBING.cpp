#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Dictionary{
    public:
    //  ---attributes---
        int m; //size of hashTable
        int cnt; //number of elements in hashTable
        vector<char*> hashTable;

    //  ---methods---
        int hash_function(char *k){
            int s = strlen(k);
            int sum = 0;
            for(int i=0; i<s; i++){
                sum += k[i];
            }
            return abs(sum) % m;
        }


        void insert(char *k){ //fold collision resolution
            if(this->cnt < this->m){
                int pos = hash_function(k);
                while(this->hashTable[pos] != nullptr){
                    pos = (pos+1)%this->m;
                }
                this->hashTable[pos] = k;
            }
        }

        int search(char *k){
            int pos = hash_function(k);
            while(true){
                if(this->hashTable[pos] == nullptr){ //key not found
                    return -1;
                }
                else if(this->hashTable[pos] == k){ //key find
                    return pos;
                }
                else{ //other key not k found
                    pos += 1;
                }
            }
        }


        void remove(char *k){
            int pos = search(k);
            if(pos != -1){ //if key in hashTable
                this->hashTable[pos] = "onceocuppied";
                this->cnt--;
            }
        }

};

Dictionary* create_dict(int size){
    Dictionary *d = new Dictionary;
    d->m = size;
    d->cnt = 0;
    d->hashTable.resize(size);
    return d;
}

int main()
{
    int size_of_hashTable;
    cin >> size_of_hashTable;
    Dictionary *d = create_dict(size_of_hashTable);
    char operation[4] = {};
    cin >> operation;
    while(strcmp(operation, "fim")){
        char word[50];
        cin >> word;
        if(!strcmp(operation, "add")){
            d->insert(word);
        }
        else if(!strcmp(operation, "rmv")){
            d->remove(word);
        }
        else if(!strcmp(operation, "sch")){
            int search_result = d->search(word);
            cout << word << " " << search_result;
        }
        cin >> operation;
    }
    return 0;
}
