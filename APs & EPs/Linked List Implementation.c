#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int element;
    struct node* next;
} Node;

typedef struct llist{
    Node* head;
    Node* tail;
    Node* curr;
    int cnt;
} LList;

Node* create_link(int it, Node* nextval){
    Node* n = (Node*) malloc(sizeof(Node));
    n->element = it;
    n->next = nextval;
    return n;
}

Node* create_link2(Node* nextval){
    Node* n = (Node*) malloc(sizeof(Node));
    n->next = nextval;
    return n;
}

LList* create_list(){
    LList* l = (LList*) malloc(sizeof(LList));
    l->curr = l->tail = l->head = create_link2(NULL);
    l->cnt = 0;
    return l;
}

void insert(LList* l, int it){
    l->curr->next = create_link(it, l->curr->next);
    if(l->tail == l->curr){
        l->tail = l->curr->next;
    }
    l->cnt++;
    next(l);
}

void moveToStart(LList* l){
    l->curr = l->head;
}

void prev(LList* l){
    if(l->curr == l->head) return;
    Node* temp = l->head;
    while(temp->next != l->curr){
        temp = temp->next;
    }
    l->curr = temp;
}

void next(LList* l){
    if(l->curr != l->tail) l->curr = l->curr->next;
}

int remove_el(LList* l){
    if(l->curr->next == NULL) return NULL;
    int it = l->curr->next->element;
    if(l->tail == l->curr->next){
        l->tail = l->curr;
    }
    l->curr->next = l->curr->next->next;
    l->cnt--;
    return it;
}

int count(LList* l, int it){
    Node* temp = l->head->next;
    int counter = 0;
    while(temp != NULL){
        printf("\nelemento atual:%i\nvalor procurado:%i", temp->element, it);
        if(temp->element == it) counter++;
        temp = temp->next;
    }
    printf("%i", counter);
}

void main(){
    int num_cases;
    scanf("%i", &num_cases);
    for(int i=0; i<num_cases; i++){ //for each case
        printf("Caso %i:", i+1);
        int num_operations;
        scanf("%i", &num_operations);
        LList* L = create_list();
        for(int j=0; j<num_operations; j++){ //for each operation
            char opr[7];
            scanf("%s", opr);
                if(strcmp(opr, "insert") == 0) {
                    int it;
                    scanf("%i", &it);
                    insert(L, it);
                }
                else if(strcmp(opr, "count") == 0) {
                    int it;
                    scanf("%i", &it);
                    count(L, it);
                }
            else if(strcmp(opr, "remove") == 0) remove_el(L);
            else if(strcmp(opr, "prev") == 0) prev(L);
            else if(strcmp(opr, "next") == 0) next(L);
        }
    }
}
