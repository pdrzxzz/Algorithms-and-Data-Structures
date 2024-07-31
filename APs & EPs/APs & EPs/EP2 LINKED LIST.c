#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int element;
    struct node* next;
} Node;

typedef struct fila{
    int size;
    int max;
    Node* front;
    Node* rear;
} Fila;


Node* create_node(int it, Node* nextval){
    Node* n = (Node*) malloc(sizeof(Node));
    n->element = it;
    n->next = nextval;
    return n;
}

Node* create_node2(Node* nextval){
    Node* n = (Node*) malloc(sizeof(Node));
    n->next = nextval;
    return n;
}

Fila* create_queue(){
    Fila* q = (Fila*) malloc(sizeof(Fila));
    q->front = q->rear = create_node2(NULL);
    q->size = 0;
    return q;
}

int resolve(Fila* q){
    if(q->size == 0) exit(0);
    int it = q->front->next->element;
    q->front->next = q->front->next->next;
    if (q->front->next == NULL){
        q->rear = q->front;
    }
    q->size--;
    return it;
}

void add(Fila* q, int it){
    q->rear->next = create_node(it, NULL);
    q->rear = q->rear->next;
    q->size++;
    q->max++;
}

void print(Fila* q){
    Node* temp = q->front->next;
    if(q->size == 0){
            printf("x\n");
            return;
            }
    while(temp != NULL){
        if(temp->next != NULL){
            printf("%i ", temp->element);
        }
        else {
            printf("%i", temp->element);
        }
        temp = temp->next;
    }
    printf("\n");
}

void stats(Fila* q){
    printf("%i %i", q->max - q->size, q->size);
    printf("\n");
}




int main()
{
    Fila* F = create_queue();
    char operation[10];
    do{
        scanf("%s", operation);
        if(!strcmp(operation, "add")){
            int value;
            scanf("%i", &value);
            add(F, value);
        }
        else if(!strcmp(operation, "solve")){
            resolve(F);
        }
        else if(!strcmp(operation, "print")){
            print(F);
        }
        else if(!strcmp(operation, "stats")){
            stats(F);
        }
    } while(strcmp(operation, "end")); /*enquanto operacao for diferente de end*/
}
