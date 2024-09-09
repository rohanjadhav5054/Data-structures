#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node NODE;
  
NODE *start = NULL,*start1 = NULL,*p,*q;
void createatend();
void createatend1();
void traverse();
void traverse1();
bool find();
int main(){

    int ch;
   
    do
    {
       printf("\nMENU\n1.create at end in LL-1\n2.create at end in LL-2\n3.traverse LL-1\n4.traverse LL-2\n5.Find\n6.Exit\n");
       printf("\nEnter the choice:");
       scanf("%d",&ch);

        switch(ch)
        {
            case 1:createatend();
                   break;  
            case 2:createatend1();
                   break;
            case 3:traverse();
                   break;
            case 4:traverse1();
                   break;
            case 5:if (find()) {
                    printf("\nThere is a common element in both lists.\n");
                } else {
                    printf("\nNo common element found in both lists.\n");
                }
                   break;
            case 6:printf("\nexitting our code");
                   break; 
            default:printf("incorrect choice");
       
        }
    } while (ch!=6);
    
}
//create at end in linked list 1
void createatend(){
       p = (NODE*)malloc(sizeof(NODE));
       printf("\nEnter data of element:");
       scanf("%d",&p->data);
       if(start == NULL){
              p -> next = NULL;
              start = p;
       }else{
              q = start;
              while(q->next!=NULL){
                     q = q -> next;
              }
              q -> next = p;
              p -> next = NULL; 
       }
}
//create at end in linkedlist 2
void createatend1(){
       p = (NODE*)malloc(sizeof(NODE));
       printf("\nEnter data of element :");
       scanf("%d",&p->data);
       if(start1 == NULL){
              p -> next = NULL;
              start1 = p;
       }else{
              q = start1;
              while(q->next!=NULL){
                     q = q -> next;
              }
              q -> next = p;
              p -> next = NULL; 


       }
}
//traverse in linked list 1
void traverse(){
       if(start == NULL){
              printf("\nyour first linked list will be empty");
       }
       else{
              q = start;
              while(q != NULL){
                     printf("\n%d",q->data);
                     q=q->next;
              }
       }
}
//traverse in linkedlist 2
void traverse1(){
       if(start1 == NULL){
              printf("\nyour second linked list will be empty");
       }
       else{
              q = start1;
              while(q != NULL){
                     printf("\n%d",q->data);
                     q=q->next;
              }
       }
}
//finding first linkedlist in second
bool find(){
    p = start;
    while(p != NULL){
        q = start1; 
        while(q != NULL){
            if(p -> data == q -> data){
                return true;
            }
            q = q -> next;
        }
        p = p -> next;
    }
    return false;
}
