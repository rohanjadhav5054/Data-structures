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
void createatgivenlocation();
void deleteatstart();
void deleteatend();
void deleteatgivenlocation();
void traverse();

int main(){
    int ch;
    do{
        printf("\nDoubly linked list\n1.Create at start\n2.Create at end\n3.Create at given location\n4.Delete at start\n5.Delete at end\n6.Delete at given location\n7.Traverse\n8.Exit");
        printf("\nEnter your choice:");
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
            case 8:printf("\nYour code is Exitted");
            break;
            default:printf("\nYou Entered the invalid choice"); 
        }
    }while(ch != 8);
    
}
void createatstart(){
    p = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter the data:");
    scanf("%d",&p -> data);

    if(start == NULL){
        p -> next = p;
        start = p;
        last = p;
    }
    else{
        p -> next = start;
        start = p;
        last -> next = start;
    }

}
void createatend(){
    p = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter the data:");
    scanf("%d",&p -> data);
    if(start == NULL){  
        p -> next = p;
        start = p;
        last = p;
    }
    else{
        last -> next = p;
        p -> next = start;
        p = last;
    }
}
void createatgivenlocation(){
    int i,loc;
    p =(NODE*)malloc(sizeof(NODE));
    printf("\nEnter the Data:");
    scanf("%d",&p -> data);
    printf("\nEnter the location you want to add data:");
    scanf("%d",&loc);

    if(start == NULL){
        if(loc == 1){
            p -> next = p;
            start = p;
            last = p;
        }
        else{
            printf("\nyour linked list is empty\n");
            free(p);
        }
    }
    else{
        if(loc == 1){
            p -> next = start;
            start = p;
            last -> next = p;
        }
        else{
            q = start;
            for(i = 1;i < loc - 1 && q -> next != start; i++){
                q = q -> next;
            }
            if(i == loc -1){
                p -> next = q -> next;
                q -> next =p;
                if(q == last){
                    last = p;
                }
            }
            else{
                printf("\nYou entered the invalid location\n");
                free(p);
            }            
        }
    }
}
void deleteatstart(){
    if(start == NULL){
        printf("\nYour linkedlist is empty\n");
    }
    else if(start -> next == start){
        p = start;
        start = NULL;
        last = NULL;
        printf("\n%d element is deleted\n",p -> data);
        free(p);
    }
    else{
        p = start;
        start = start -> next;
        last -> next = start;
        printf("\n%d Element is deleted\n",p -> data);
        free(p);
    }
}
void deleteatend(){
    if(start == NULL){
        printf("\nlinked list is empty\n");
    }
    else if(start -> next == start){
        p = start;
        start = NULL;
        last = NULL;
        printf("\n%d Element is deleted\n",p -> data);
        free(p);
    }
    else{
        p = last;
        q = start;
        while(q ->next != p){
            q = q -> next;
        } 
        last = q;
        q -> next = start;
        printf("\n%d element is deleted\n",p -> data);
        free(p);
    }
}
void deleteatgivenlocation(){
    int i,loc;
    printf("\nEnter the location you want to delete:");
    scanf("%d",&loc);
    if(start == NULL){
        printf("\nLinked list is empty\n");
    }
    else{
        if(loc == 1){
            if(start -> next == start){
                p = start;
                start = NULL;
                last = NULL;
                printf("\n%d element is deleted\n",p -> data);
                free(p);
            }
            else{
                p = start;
                start = start -> next;
                last -> next = start;
                printf("\n%d Element is deleted\n",p -> data);
                free(p);
            }
        }
        else{
            p = start;
            for(i = 1;i < loc && p -> next != start; i++){
                q = p;
                p = p -> next;
            }
            if(i == loc){
                q -> next = p -> next;
                while(p == last){
                    last = q;
                }
                printf("\n%d element is deleted\n",p -> data);
                free(p);
            }
            else{
                printf("\nyou entered the invalid location so please re enter the location\n");
            }           
        }    
    }
}
void traverse(){
    if(start == NULL){
        printf("\nYour linkedlist is empty\n");
    }
    else{
        q = start;
        do{
            printf("\n%d",q -> data);
            q = q -> next;
        }while(q != start);
    }
}