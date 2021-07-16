//This program is related to stack operation with array.
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max 100

struct Stack{
    int stack[max];
    int count;
};
typedef struct Stack stack;
stack s;

void create(stack *s){
    s->count=-1;
}
void push(stack *s,int data){
    if(s->count==(max-1)){
        printf("Stack is overflow\n");
        exit(0);
    }
    else{
        s->count++;
        s->stack[s->count]=data;
    }
}
int pop(stack *s){
    return (s->stack[s->count--]);
}
void isempty(stack *s){
    if(s->count==-1){
        printf("Stack is empty!\n");
    }
    else{
        printf("Stack is not empty!\n");
    }
}
void isfull(stack *s){
    if(s->count>=(max-1)){
        printf("Stack is full!\n");
    }
    else{
        printf("Stack is not full!\n");
    }
}

int main(){
    int data,choice;
    char answer[10];
    create(&s);
    do{
        printf("\n-----------MENU---------\n");
        printf("1-)Push\n2-)Pop\n3-)Is stack is full\n4-)Is stack is empty\n");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter data : ");
            scanf("%d",&data);
            push(&s,data);
        }
        else if(choice==2){
            printf("%d is popped!\n",pop(&s));
        }
        else if(choice==3){
            isfull(&s);
        }
        else if(choice==4){
            isempty(&s);
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