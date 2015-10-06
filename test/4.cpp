#include <stdio.h>
#include <stdlib.h>

typedef struct ele {
    int key;
    struct ele *nxt;
}node;


void init(node **head) {
    *head = NULL;
    return;
}

void insrt(int ele,node **a) {
    node *one,*two,*three;
    if(*a == NULL) {
        one = (node *)malloc(sizeof(node));
        one->key = ele;
        one->nxt = NULL;
        *a = one;
        return;
    }
    if((*a)->nxt == NULL) {
        one = (node *)malloc(sizeof(node));
        one->key = ele;
        one->nxt = NULL;
        (*a)->nxt = one;
        return;
    }
    insrt(ele,&((*a)->nxt));
    return;
}


void traverse(node *a) {
    if(a == NULL) return;
    printf("%d->",a->key);
    traverse(a->nxt);
    return;
}


int main() 
{
    node *head;
    init(&head);
    int a;
    for (int i = 0; i < 10 ; ++i) {
        scanf("%d",&a);
        insrt(a,&head);
    }
    traverse(head);
}