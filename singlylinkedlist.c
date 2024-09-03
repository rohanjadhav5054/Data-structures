/*
Name : Rohan Dadasaheb Jadhav
Div : A
Roll No:2027
Batch:S2
*/
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node NODE;
  
NODE *start = NULL,*p,*q;
void createatstart();
void createatend();
void createatgivenlocation();
void deleteatstart();
void deleteatend();
void deleteatgivenlocation();
void traverse();

int main(){

    int ch;
   
    do
    {
       printf("\nMENU\n1.create at start\n2.create at end\n3.create at given location\n4.delete at start\n5.delete at end\n6.delete at given location\n7.traverse\n8.Exit\n");
       
       scanf("%d",&ch);

        switch(ch)

        {
            case 1:createatstart();
                   break;
            case 2:createatend();
                   break;
            case 3:createatgivenlocation();
                   break;
            case 4:deleteatstart();
                   break;  
            case 5:deleteatend();
                   break;
            case 6:deleteatgivenlocation();
                   break;  
            case 7:traverse();
                   break;
            case 8:printf("\nexitting our code");
                   break; 
            default:printf("incorrect choice");
       
        }
    } while (ch!=8);
    
}
//create at start
void  createatstart(){ 
       p = (NODE*)malloc(sizeof(NODE));
       printf("\nenter data of element:");
       scanf("\n%d",&p->data);
       if(start==NULL){
              p -> next = NULL;
              start = p;
       }else{
              p -> next = start;
              start = p;
       }
}
//create at end
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
//create at given location
void createatgivenlocation(){
       int loc,i;
       printf("\nEnter value of location:");
       scanf("%d",&loc);
       printf("\nEnter the value of data:");
       p = (NODE*)malloc(sizeof(NODE));
       scanf("%d",&p->data);
       if(start == NULL)
       {
              if(loc == 1){
                     p -> next = NULL;
                     start = p; 
              } 
              else{
                     printf("\ninvalid location");
              }

       }
       else
       {

       
              if(loc ==  1){
                     p -> next = start;
                     start = p;
              }
              else
              {
                 i = 1;
                 q = start;
              while(i<loc - 1 && q != NULL){
                           q = q -> next;
                           i++;
              }
                     if(q != NULL){
                           p -> next = q -> next;
                           q -> next = p;
                     }
                     else{
                            printf("you are written wrong location");
                            free(p);
                     }      
              }  
       }    
}
//delete at start
void deleteatstart(){
       if(start == NULL){
              printf("\nyour linked list is empty so you do not delete your element");
       }
       else{
              p = start;
              start = start -> next;
              printf("%d your element is deleted",p -> data);
              free(p);
       }
}
//delete at end
void deleteatend(){
       if(start == NULL){
              printf("\nyour linked list is empty so you can't delete the data");
       }
       else if(start -> next == NULL){
              p = start;
              start = NULL;
              printf("%d data is deleted",p -> data);
              free(p);
       }
       else{
              p = start;
              while(p -> next != NULL){
                     q = p;
                     p = p -> next;    
                     q -> next = NULL;
              }
              printf("%d element is deleted",p -> data);
              free(p);
              
       }
}
//delete at given location
void deleteatgivenlocation(){
       int i ,loc;
       printf("\nenter the number of deleting node");
       scanf("%d",&loc);
       if(start == NULL){
              printf("\nyour linked list is empty so nothing can be deleted");
       }else{      
              if(loc == 1){
                     p = start;
                     start = start -> next;
                     printf("\n%d element is deleted ",p -> data);
                     free(p);
              }else{
                     i = 1;       
                     while(i<loc && p != NULL){
                            q = p;
                     p = p -> next;
                     i++;
                     }
                     if(p != NULL){
                            q -> next = p -> next;
                            printf("%d element is deleted ",p -> data);
                            free(p);
                     }else{
                            printf("\nyou are entered wrong number of location");
                            free(p);
                     }
              }
       }                     
}
//traverse
void traverse(){
       if(start == NULL){
              printf("\nyour linked list will be empty");
       }
       else{
              q = start;
              while(q != NULL){
                     printf("\n%d",q->data);
                     q=q->next;
              }
       }
}
