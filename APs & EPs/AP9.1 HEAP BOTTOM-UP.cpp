#include <iostream>
#include <vector>

using namespace std;

class Heap{
    public:
    int n;
    int n_removed;
    vector<int> H;
    vector<int> removed;

    Heap(int);
    void HeapBottomUp();
    void remove();
    void print_all();
    void print_all_removed();
};


int main()
{
    //--receiving input
    short num_cases;
    cin >> num_cases;
    for(int i=0; i<num_cases; i++){
        int size;
        cin >> size;
        Heap heap{size};
        for(int j=1; j<size+1; j++){ //filling array
            int num;
            cin >> num;
            heap.H[j] = num;
        }

        //turn into a heap
        heap.HeapBottomUp();

        //printing
        for(int j=0; j<size; j++){
            heap.print_all();
            heap.remove();
        }
        heap.print_all_removed();
    }
}

void Heap::print_all(){
    for(int k=1; k<=n; k++){
        cout << H[k] << " ";
    }
    cout << endl;
}

void Heap::print_all_removed(){
    for(int k=0; k<n_removed; k++){
        cout << removed[k] << " ";
    }
    cout << endl;
}

void Heap::HeapBottomUp(){
    for(int i = n/2; i >= 1; i--){
        int k = i; //--current position of the i-th node
        int v = H[k]; //--value of the i-th node
        bool heap = false;
        //--finding the proper place for the i-th node
        while(!heap && 2*k <= n){
            int j = 2*k; //position of the first child
            if(j < n){ //if has two children
                if(H[j] > H[j+1]) j++; //j points to the lowest child
            }
            if(v <= H[j]){ //if the parent is lower than the children
                heap = true; //we have a min-heap
            }
            else{ //otherwise
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}

Heap::Heap(int size){
    n = size;
    H.resize(size+1); //1-based
    removed.resize(size); //0-based
}

void Heap::remove(){ //n = size
    removed[n_removed] = H[1];
    n_removed++;
    H[1] = H[n];
    n--;
    int k = 1;
    int v = H[k];
    bool heap = false;
    //--finding the proper place for the i-th node
    while(!heap && 2*k <= n){
        int j = 2*k; //position of the first child
        if(j < n){ //if has two children
            if(H[j] > H[j+1]) j++; //j points to the lowest child
        }
        if(v <= H[j]){ //if the parent is lower than the children
            heap = true; //we have a min-heap
        }
        else{ //otherwise
            H[k] = H[j];
            k = j;
        }
    }
    H[k] = v;
}


