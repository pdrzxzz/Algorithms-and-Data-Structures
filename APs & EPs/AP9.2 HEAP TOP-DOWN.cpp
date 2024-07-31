#include <iostream>
#include <vector>

using namespace std;

//fix problem on getting input, maybe w cin.ignore()

class Heap{
    public:
    //--attributes--
    int max_size;
    int n; //num_of_elements
    vector<char> H;

    //--constructor--
    Heap(int msize);

    //--methods--
    void heapify(char c, int index);
    void insert(char c);
    void remove();
    void print_max();
    void print_all();
};


int main()
{
    int size, num_operations;
    cin >> size >> num_operations;
    Heap heap{size};
    for(int i=0; i<num_operations; i++){
        string operation;
        cin >> operation;
        if(operation == "insert"){
            char c;
            cin >> c;
            heap.insert(c);
        }
        else if(operation == "remove"){
            heap.remove();
        }
        else if(operation == "max"){
            heap.print_max();
        }
    }
}


Heap::Heap(int msize){
    H.resize(msize); //0-based
    max_size = msize;
    n = 0;
}

void Heap::heapify(char c, int index){
    int father_index = (index - 1)/2;
    while(H[father_index] < H[index]){ //if father is lower, then swap
        swap(H[index], H[father_index]);
        //--update indices for next iteration
        index = father_index;
        father_index = (father_index - 1)/2;
    }
}

void Heap::insert(char c){
    if(n < max_size){
        int index = n;
        n++;
        H[index] = c;
        heapify(c, index);
    }
    else{
        cout << "Tamanho máximo atingido!" << endl;
    }
}

void Heap::remove(){
    if(n == 0){
        cout << "Heap vazia." << endl;
        return;
    }
    H[0] = H[n-1]; //root receives last node
    n--;
    int k = 0;
    char v = H[k];
    bool heap = false;
    //--finding the proper place for the i-th node
    while(!heap && 2*k + 1 < n){
        int j = 2*k + 1; //position of the first child
        if(j < n-1){ //if has two children
            if(H[j] < H[j+1]) j++; //j points to the largest child
        }
        if(v >= H[j]){ //if the parent is greater than the children
            heap = true; //we have a max-heap
        }
        else{ //otherwise
            H[k] = H[j];
            k = j;
        }
    }
    H[k] = v;
}

void Heap::print_max(){
    if(n > 0) cout << H[0] << endl;
    else cout << "Não há elemento no topo." << endl;
}

void Heap::print_all(){
    for(int i=0; i<max_size; i++){
        cout << "INDEX " << i << ": " << H[i] << endl;
    }
}
