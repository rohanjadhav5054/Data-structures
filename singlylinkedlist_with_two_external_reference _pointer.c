/*
Name:Rohan Dadasaheb Jadhav
Div:A
Roll No:2027
Batch:S2
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *start = NULL,*last = NULL,*p,*q;

void createatstart();
void createatend();
void traverse();
void createatgivenlocation();
void deleteatstart();
void deleteatend();
void deleteatgivenlocation();
int main(){
    int ch;
    do{
        printf("\nOperations on singly linkedlist with two external reference pointer\n1.Create at start\n2.Create at end\n3.Create at given location\n4.Delete at start\n5.Delete at end\n6.Delete at given location\n7.Traverse\n8.Exit");
        printf("\nEnter your choice:"),
        scanf("%d",&ch);

        switch(ch){
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
            case 8:printf("your code will be exitted");
                break;
            default:
                printf("\n your choice is invalid please again enter your choice");    
        }

    }while(ch != 8);
}
//create at start
void createatstart(){
    p = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter the data:");
    scanf("%d",&p -> data);

    if(start == NULL){
        p -> next = NULL;
        start = p;
        last = p;
    }
    else{
        p -> next = start;
        start = p;

    }
}
//create at end
void createatend(){
    p = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter data element:");
    scanf("%d",&p -> data);
    
    if(start == NULL){
        p -> next = NULL;
        start = p;
        last = p;
    }
    else{
        last -> next = p;
        p -> next = NULL;
        last = p;
    }
}
//create at given location
void createatgivenlocation(){
    int loc , i;
    p = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter the location:");
    scanf("%d",&loc);
    printf("\nEnter the Data:");
    scanf("\n%d",&p -> data);
    if(start == NULL){
        if(loc == 1){
            p -> next = NULL;
            start = p;
            last = p;
        }else{
            printf("\nyou entered the invalid location");
            free(p);
        }
    }else{
        if(loc == 1){
            p -> next = start;
            start = p;
        }else{
            i = 1;
            q = start;
            while(i < loc - 1 && q != NULL ){
                q = q -> next;
                i++;
            }
                if(q != NULL){
                    p -> next = q -> next;
                    q -> next = p;
                    if(p -> next == NULL){
                        last = p;
                    }
                }else{
                    printf("\nyou entered invalid location");
                    free(p);
                
            }
    
        }
    }

}
//delete at start
void deleteatstart(){
    if(start == NULL){
        printf("\nThere is no elements present in linked list so what do you want to delete ?");
    }
    else if(start -> next == NULL){
        start = p;
        printf("\n%d element will be deleted",p -> data);
        start = NULL;
        last = NULL;
        free(p);
    }else{
        p = start;
        start = start -> next;
        printf("\n%d element is deleted",p -> data);
        free(p);
    }
}
//delete at end
void deleteatend(){
    if(start == NULL){
        printf("\nIn the linked list there is no element present so what do you want to delete");
    }
    else if(start -> next == NULL){
        p = start;
        printf("\n%d data is deleted",p -> data);
        start = NULL;
        last = NULL;
        free(p);
    }else{
        p = last;
        q = start;
        while(q -> next != NULL){
            q = q -> next;
        }
        printf("\n%d data is deleted ",p -> data);
        last = q;
        q -> next = NULL; 
        free(p);
    }
}
//delete at given location
void deleteatgivenlocation(){
    int loc,i;
    printf("\nEnter the location of data:");
    scanf("%d",&loc);
    if(start == NULL){
        printf("\nyou have nothing to delete because linked list is empty");
        free(p);
    }else{
        if(loc == 1){
            start = p;
            start = start -> next;
            printf("\n%d element is deleted",p -> data);
            free(p);
        }else{
            i = 1;
            p = start;
            while(i < loc && p != NULL){
                q = p;
                p = p -> next;
                i++;
            }
            if(p != NULL){
                q -> next = p -> next;
                if( p -> next == NULL){
                    last = p;
                }
                printf("\n%d element is deleted",p -> data);
                free(p);

            }
            else{
                printf("\nyou entered the invalid location");
                free(p);
            }
        }
    }
}
//traverse
void traverse(){
    q = start;
    while(q != NULL){
        printf("\n%d",q -> data);
        q = q -> next;
    }
}