#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int second_comes_queue;
    int second_leaves_queue;
    struct node* next;
} Node;

typedef struct fila{
    int size;
    int max;
    Node* front;
    Node* rear;
} Fila;


Node* create_node(int second_comes, int second_leaves, Node* nextval){
    Node* n = (Node*) malloc(sizeof(Node));
    n->second_comes_queue = second_comes;
    n->second_leaves_queue = second_leaves;
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

void move(Fila* q, int *timer){
    Node* next_student = q->front->next;
    while(*timer < next_student->second_comes_queue){
        *timer = *timer + 1;
    }
    if(next_student->second_leaves_queue < *timer){
        printf("0 ");
    }
    else{
        printf("%i ", *timer);
        *timer = *timer + 1;
    }
    q->size--;
    q->front->next = q->front->next->next;
}

void add(Fila* q, int second_comes, int second_leaves){
    q->rear->next = create_node(second_comes, second_leaves, NULL);
    q->rear = q->rear->next;
    q->size++;
    q->max++;
}

void clear(Fila* q){
    for(int i=0; i<q->size; i++){
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

int main()
{
    int num_cases;
    scanf("%i", &num_cases);
    for(int i=0; i<num_cases; i++){ //for each case
        Fila* q = create_queue();
        int num_students;
        scanf("%i", &num_students);
        for(int j=0; j<num_students; j++){ //for each student
            int second_comes_queue, second_leaves_queue;
            scanf("%i %i", &second_comes_queue, &second_leaves_queue);
            add(q, second_comes_queue, second_leaves_queue); //add student to queue
        }
        int timer = 1;
        for(int y=0; y<num_students; y++){
            move(q, &timer);
        }
        printf("\n");
        clear(q);
    }
    return 0;
}
