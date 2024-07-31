#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char element;
    struct node* next;
} Node;

typedef struct llist{
    Node* head;
    Node* tail;
    Node* curr;
    int cnt;
} LList;

Node* create_link(char it, Node* nextval){
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

void insert(LList* l, char it){
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

void moveToEnd(LList* l){
    l->curr = l->tail;
}

void print_all_elements(LList* l){
    l->curr = l->head;
    for(int i=0; i<l->cnt; i++){
        printf("%c", l->curr->next->element);
        l->curr = l->curr->next;
    }
}

int main(){
    LList* l = create_list();
    char letter;
    while((letter = getchar()) != EOF){
        if(letter == '['){
            moveToStart(l);
        }
        else if(letter == ']'){
            moveToEnd(l);
        }
        else if(letter == '\n'){
            print_all_elements(l);
            printf("\n");
            l = create_list();
        }
        else{
            insert(l, letter);
        }
    }
    print_all_elements(l);
    return 0;
}
