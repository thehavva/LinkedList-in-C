//This program is related to stack operation with linkedlist.
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max 100

struct Stack{
    int data;
    struct Stack *next;
};
typedef struct Stack stack;
stack *s;

void push(stack **top,int value){
    stack *temp=(stack*)malloc(sizeof(stack));
    if(temp==NULL){
        printf("\nStack is full\n");
        exit(0);
    }
    temp->data=value;
    temp->next=(*top);
    *top=temp;
}
int pop(stack **top){
    int add;
    stack *q;
    if((*top)==NULL){
        printf("\nStack is empty\n");
        exit(-1);
    }
    else{
        add=(*top)->data;
        q=(*top);
        *top=(*top)->next;
        free(q);
        return add;
    }
}
int main(){
    int data,choice;
    char answer[10];
    
    do{
        printf("\n-----------MENU---------\n");
        printf("1-)Push\n2-)Pop\n");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter data : ");
            scanf("%d",&data);
            push(&s,data);
        }
        else if(choice==2){
            printf("%d is popped!\n",pop(&s));
        }
        else{
            printf("Unvalid choice!\n");
        }
        printf("Do you want to continue? Yes or No?");
        scanf("%s",answer);
    }while(strcmp(answer,"no")!=0);
    
    getch();
    return 0;
}
