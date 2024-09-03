#include<stdio.h>

#define size 5

int a[size];
int top = -1;

void push();
void pop();
void topofstack();
void traverse();

int main(){
    int ch;
    do{
        printf("stack operations\n1.push\n2.pop\n3.top of stack\n4.traverse\n5.exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:topofstack();
            break;
            case 4:traverse();
            break;
            case 5:printf("\nYour program is exitted\n");
            break;
            default:
            printf("\ninvalid choice please enter your choice again\n");
        }
    }while(ch != 5);
}

void push(){
    
    printf("\nEnter your push data:");

    if(top == size - 1){
        printf("\nstack is overflow\n");
    }
    else{
        top = top + 1;
        scanf("%d",&a[top]);
    }
}

void pop(){
    if(top == -1){
        printf("\nstack is empty\n");
    }
    else{
        printf("\n%d is popped",a[top]);
        top = top - 1;
    }
}

void topofstack(){
    if(top == - 1){
        printf("\nStack is empty\n");
    }
    else{
        printf("\n%d\n",a[top]);
    }
}

void traverse(){
    if(top == -1){
        printf("\nstack is empty\n");        
    }
    else{
        for(int i = 0;i<= top;i++){
            printf("\n%d\n",a[i]);
        }
    }
}