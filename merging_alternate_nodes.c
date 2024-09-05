#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *start1 = NULL,*start2 = NULL,*start3 = NULL;

void createatend1();
void createatend2();
void createatend3(int value);
void traverse1();
void traverse2();
void traverse3();
void merge();

int main(){
    int ch;
    do{
        printf("\nMENU\n1.Create at end in LL-1\n2.Create at end in LL-2\n3.Traverse in LL-1\n4.Traverse in LL-2\n5.Traverse in LL-3\n6.Merge linkedlist 1 & 2\n7.Exit..\n");
        printf("\nEnter Your choice:");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:createatend1();
            break;
            case 2:createatend2();
            break;
            case 3:traverse1();
            break;
            case 4:traverse2();
            break;
            case 5:traverse3();
            break;
            case 6:merge();
            break;
            case 7:printf("\nExitted......");
            break;
            default:printf("\nYou Entered invalid location please reenter the location\n");
        }
    }while(ch != 7);
}
void createatend1(){
    NODE *p = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter the data:");
    scanf("%d",&p -> data);
    if(start1 == NULL){
        p -> next = NULL;
        start1 = p;
    }
    else{
        NODE *q = start1;
        while(q -> next != NULL){
            q = q -> next;
        }
        q -> next = p;
        p -> next = NULL;
    }
}
void createatend2(){
    NODE *p = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter the data:");
    scanf("%d",&p -> data);
    if(start2 == NULL){
        p -> next = NULL;
        start2 = p;
    }
    else{
        NODE *q = start2;
        while(q -> next != NULL){
            q = q -> next;
        }
        q -> next = p;
        p -> next = NULL;
    }
}
void createatend3(int value){
    NODE *p = (NODE*)malloc(sizeof(NODE));
    p -> data = value;
    if(start3 == NULL){
        p -> next = NULL;
        start3 = p;
    }
    else{
        NODE *q = start3;
        while(q -> next != NULL){
            q = q -> next;
        }
        q -> next = p;
        p -> next = NULL;
    }
}
void traverse1(){
    if(start1 == NULL){
        printf("\nLinked list 1 is empty\n");
    }
    else{
        NODE *q = start1;
        while(q != NULL){
            printf("\t%d",q -> data);
            q = q -> next;
        }
    }
}
void traverse2(){
    if(start2 == NULL){
        printf("\nLinked list 2 is empty\n");
    }
    else{
        NODE *q = start2;
        while(q != NULL){
            printf("\t%d",q -> data);
            q = q -> next;
        }
    }
}
void traverse3(){
    if(start3 == NULL){
        printf("\nLinked list 2 is empty\n");
    }
    else{
        NODE *q = start3;
        while(q != NULL){
            printf("\t%d",q -> data);
            q = q -> next;
        }
    }
}
void merge() {
    NODE *p = start1;
    NODE *q = start2;
    
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            createatend3(p->data);
            p = p->next;
        } else {
            createatend3(q->data);
            q = q->next;
        }
    }
    
    while (p != NULL) {
        createatend3(p->data);
        p = p->next;
    }
    
    while (q != NULL) {
        createatend3(q->data);
        q = q->next;
    }
}
