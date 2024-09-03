#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
NODE *start  = NULL,*p,*q;

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
        printf("\n1.Create at start\n2.Create at end\n3.Create at given location\n4.Delete at start\n5.Delete at end\n6.Delete at given location\n7.Traverse\n8.Exit\n");
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
            case 8:printf("\nyour code is exitted");
            break;
            default:printf("\nyou entered invalid choice so please enter choice again");
        }
    }while(ch != 8);
}
//create at start.
void createatstart(){
    p = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter your data:");
    scanf("%d",&p -> data);

    if(start == NULL){
        p -> next = NULL;
        p -> prev = NULL;
        start = p;
    }
    else{
        p -> next = start;
        start -> prev = p;
        p -> prev = NULL;
        start = p;
    }
}
//Create at end.
void createatend(){
    p = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter the data:");
    scanf("%d",&p -> data);
    if(start == NULL){
        p -> next = NULL;
        p -> prev = NULL;
        start = p;
    }
    else{
        q = start;
        while(q -> next != NULL){
            q = q -> next;
        }
        q -> next = p;
        p -> prev = q;
        p -> next = NULL; 
    }
}
//Create at given location
void createatgivenlocation(){
    int loc,i;
    p = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter the data:");
    scanf("%d",&p -> data);
    printf("\nEnter the value of location:");
    scanf("%d",&loc);

    if(start==NULL){
        if(loc==1){
            p -> next = NULL;
            p -> prev = NULL;
            start = p;
        }else{
            printf("\nyou entered the invalid location");
            free(p);
        }
    }else{
        if(loc==1){
            p -> next = start;
            start -> prev = p;
            p -> prev = NULL;
            start = p;
        }else{
            i = 1;
            q = start;
            while(i < loc-1 && q != NULL){
                q = q -> next;
                i++;
            }
            if(q != NULL){
                p -> next = q -> next;
                if(q -> next != NULL){
                    q -> next -> prev = p;
                }
                p -> prev = q;
                q -> next = p;
            }
            else{
                printf("\nboss you entered the invalid location !");
                free(p);
            }
        }
    }
}
//Delete at start.
void deleteatstart(){
    if(start == NULL){
        printf("\nYour linked list is empty.");
    }
    else if(start -> next == NULL){
        p = start;
        start = NULL;
        printf("\n%d element is deleted\n",p -> data);
        free(p);
    }
    else{
        p = start;
        start = start -> next;
        start -> prev = NULL;
        printf("\n%d element is deleted\n",p -> data);
        free(p);
    }
}
//delete at end
void deleteatend(){
    if(start == NULL){
        printf("\nlinked list is empty\n");
    }
    else if(start -> next == NULL){
        p = start;
        start = NULL;
        printf("\n%d element is deleted\n",p -> data);
        free(p);
    }
    else{
        p = start;
        while(p -> next != NULL){
            q = p;
            p = p -> next;
        }
        q -> next = NULL;
        printf("\n%d element is deleted",p -> data);
        free(p);
    }
}
//Delete at given location
void deleteatgivenlocation(){
    int i,loc;
    printf("\nEnter the location you want to delete:");
    scanf("%d",&loc);
    if(start == NULL){
        printf("\nYour linked list is empty\n");
    }
    else{
        if(loc == 1){
            if(start -> next == NULL){
                p = start;
                start = NULL;
                printf("\n%d element is deleted\n",p -> data);
                free(p);
            }
            else{
                p = start;
                start = start -> next;
                start -> prev = NULL;
                printf("\n%d element is deleted\n",p -> data);
                free(p);
            }
        }
        else{
            i = 1;
            p = start;
            while(i < loc && p != NULL){ 
                q = p -> prev;
                p = p -> next;
                i++;
            }
            if(p != NULL){
                if(p -> next != NULL){
                    p -> next -> prev = p -> prev;
                }
                if(p -> next != NULL){
                    p -> prev -> next = p -> next;
                }
                if (p->next == NULL) {
                    q = start;
                    while (q->next != NULL) {
                        q = q->next;
                    }
                    q->next = NULL;
                }
                printf("\n%d element is deleted\n",p -> data);
                free(p);
            }
            else{
                printf("\nyou entered the invalid location so please enter the valid location\n");
                free(p);
            }
        }
    }
}
//Traverse
void traverse(){
    if(start == NULL){
        printf("\nyour linked list is empty\n");
    }
    else{
        q = start;
        while(q != NULL){
            printf("\n%d",q -> data);
            q = q -> next;
        }
    }
}