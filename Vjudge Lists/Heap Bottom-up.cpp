
#include <iostream>
#include <vector>

using namespace std;

class Heap{
    public:
    int n;
    vector<int> H;

    Heap(int);
    void HeapBottomUp();
    void insert(int key);
    void heapify(int index);
    int remove();
    void print_all();
};


int main()
{
    while(true){
        //get size and check if's not zero
        int size;
        cin >> size;
        if(size == 0) break;

        //create heap prototype
        Heap* heap = new Heap{size};

        //get and add nums
        for(int i=0; i<size; i++){
            int num;
            cin >> num;
            heap->H[i+1] = num;
        }

        //turn into a min-heap
        heap->HeapBottomUp();

        //calculate min cost
        int sumcost = 0;
        int a=0; int b=0;
        int n = heap->n;
        for(int i=0; i<n-1; i++){
            a = heap->remove();
            b = heap->remove();
            heap->insert(a+b);
            sumcost += a+b;
        }

        //print min cost
        cout << sumcost << endl;

        //deallocate memmory
        delete heap;
    }
}

Heap::Heap(int size){
    n = size;
    H.resize(size+1); //1-based
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

void Heap::insert(int key){
    n++;
    H[n] = key;
    heapify(n);
}

void Heap::heapify(int index){
    int father_index = (index)/2;
    while(H[father_index] > H[index]){ //if father is greater, then swap
        swap(H[index], H[father_index]);
        //--update indices for next iteration
        index = father_index;
        father_index = (father_index)/2;
    }
}

int Heap::remove(){ //n = size
    if(n <= 0) return 0;
    //remove process
    int removed = H[1];
    H[1] = H[n];
    n--;

    //heapify
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
    return removed;
}

void Heap::print_all(){
    for(int k=1; k<=n; k++){
        cout << H[k] << " ";
    }
    cout << endl;
}



