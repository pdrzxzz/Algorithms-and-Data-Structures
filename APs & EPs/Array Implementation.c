#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct array{
    int maxSize;
    int listSize;
    int curr;
    int* listArray;
} Array;

Array* create_array(int size){
    Array* A = (Array*) malloc(sizeof(Array));
    A->maxSize = size;
    A->listSize = A->curr = 0;
    A->listArray = (int*) malloc(size * sizeof(int));
    return A;
}

void count(Array *A, int it){
    int counter = 0;
    for(int i=0; i<A->listSize; i++){
        if(A->listArray[i] == it) counter++;
        if (i==A->listSize-1) printf("\n%i", counter);
    }
}

void insert(Array *A, int it){
    if (A->listSize >= A->maxSize) exit(1);
    int i = A->listSize;
    while (i > A->curr){
        A->listArray[i] = A->listArray[i-1];
        i--;
    }
    A->listArray[A->curr] = it;
    A->listSize++;
}

void moveToStart(Array *A){
    A->curr = 0;
}

void moveToEnd(Array *A){
    A->curr = A->listSize;
}

void prev(Array *A){
    if (A->curr >= 0) A->curr--;
}

void next(Array *A){
    if (A->curr < A->listSize) A->curr++;
}

int remove_el(Array *A){
    if (A->curr < 0 && A->curr >= A->listSize) return NULL;
    int it = A->listArray[A->curr];
    int i = A->curr;
    while(i < A->listSize -1){
        A->listArray[i] = A->listArray[i+1];
        i++;
    }
    A->listSize--;
    return it;
}

void main(){
    int num_cases;
    scanf("%i", &num_cases);
    for(int i=0; i<num_cases; i++){ //for each case
        printf("Caso %i:", i+1);
        int num_operations;
        scanf("%i", &num_operations);
        Array* A = create_array(num_operations);
        for(int j=0; j<num_operations; j++){ //for each operation
            char opr[7];
            scanf("%s", opr);
                if(strcmp(opr, "insert") == 0) {
                    int it;
                    scanf("%i", &it);
                    insert(A, it);
                }
                else if(strcmp(opr, "count") == 0) {
                    int it;
                    scanf("%i", &it);
                    count(A, it);
                }
            else if(strcmp(opr, "remove") == 0) remove_el(A);
            else if(strcmp(opr, "prev") == 0) prev(A);
            else if(strcmp(opr, "next") == 0) next(A);
        }
    }
}
