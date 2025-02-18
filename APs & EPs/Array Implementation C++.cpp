#include <iostream>

using namespace std;

class Array {
public:
    int maxSize;
    int listSize;
    int curr;
    int* listArray;

    Array(int size){
        maxSize = size;
        listSize = 0;
        curr = 0;
        listArray = new int(size);
    }

    void insert(int it){
        if(listSize >= maxSize){
            cout << "error";
        }
        int i = listSize;
        while(i > curr){ //shift the elements on right of the curr to right
            listArray[i] = listArray[i - 1];
            i--;
        }
        listArray[curr] = it; //insert on curr
        listSize++;
    }

    int remove(){
        if(curr < 0 || curr > listSize){
            return NULL;
        }
        int it = listArray[curr]; //remove on curr
        int i = curr;
        while(i < listSize - 1){ //shift the elements on right of the curr to left
            listArray[i] = listArray[i+1];
            i++;
        }
        listSize--;
        return it;
    }

    int count(int it){
        int score = 0;
        for(int i=0; i<listSize; i++){
            if(listArray[i] == it){
                score++;
            }
        }
        cout << score << endl;
    }
    
    void moveToStart(){
        curr = 0;
    }

    void moveToEnd(){
        curr = listSize;
    }

    void prev(){
        if(curr != 0){
            curr--;
        }
    }

    void next(){
        if(curr < listSize){
            curr++;
        }
    }

    void exibir(){
        cout << "Lista: ";
        for(int i=0; i<listSize; i++){
            cout << listArray[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int num_cases;
    cout << "Number of cases: ";
    cin >> num_cases;
    for(int i=0; i<num_cases; i++){
        Array* a = new Array(10);
        int num_operations;
        cout << "Number of operations: ";
        cin >> num_operations;
        for(int j=0; j<num_operations; j++){
            string operation;
            a->exibir();
            cout << "Operation: ";
            cin >> operation;
            if(operation == "insert"){
                int num;
                cin >> num;
                cout << "inserting " << num << " in the list" << endl;
                a->insert(num);
            } else if(operation == "remove"){
                int num_removed = a->remove();
                cout << num_removed << " removed from the list" << endl;
            } else if(operation == "count") {
                int num;
                cin >> num;
                cout << "couting how many " << num << "s are on the list" << endl;
                a->count(num);
            } else if(operation == "prev"){
                cout << "moving cursor left" << endl;
                a->prev();
            } else if(operation == "next"){
                a->next();
                cout << "moving cursor right" << endl;
            }
        }
    }



    return 0;
}
