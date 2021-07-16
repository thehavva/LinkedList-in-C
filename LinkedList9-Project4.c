//In this project, let's list the values of the nodes in the list.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int num;
    struct Node *next;
};

typedef struct Node node;
node *head;
node *root;
node *iter;
node *q;

node *create(node **head,int data){
    node *add=(node*)malloc(sizeof(node));
    add->num=data;
    add->next=NULL;
    if(add==NULL){
        printf("\nBad Allocation\n");
        exit(0);
    }
    if(*head==NULL){
        *head=(node*)malloc(sizeof(node));
        *head=add;
        return (*head);
    }
    else{
        iter=*head;
        while(iter->next!=NULL){
            iter=iter->next;
        }
        iter->next=add;
        return (*head);
    }
}

void sort(node **head,int n){
    int i,j,temp;
    for(i=0; i<n-1; i++){
         iter=*head;
        for(j=1; j<n; j++){
            if(iter->num > iter->next->num){
                temp=iter->num;
                iter->num=iter->next->num;
                iter->next->num=temp;
            }
            iter=iter->next;
        }
    }
}
void display(node **head){
    iter=*head;
    while(iter!=NULL){
        printf("%d\t",iter->num);
        iter=iter->next;
    }
    printf("\n");
}
int main(){
    int count=0,num;
    char answer[20];
    do{
        printf("Number : ");
        scanf("%d",&num);
        create(&head,num);
        count++;
        printf("\nDo you want to continue?\n");
        scanf("%s",&answer);
        printf("\n");
    }while(strcmpi(answer,"no")!=0);
    printf("------------First Node-----------\n\n");
    display(&head);
    sort(&head,count);
    printf("\n\n------------Second Node-----------\n\n");
    display(&head);
    getch();
    return 0;
}
