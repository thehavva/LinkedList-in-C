//In this second project, we have added together the two lists created.
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

node *create(node **p,int n){
    node *add=(node*)malloc(sizeof(node));
    add->num=n;
    add->next=NULL;
    if(add==NULL){
        printf("\nBad Allocation\n");
    }
    if(*p==NULL){
        *p=(node*)malloc(sizeof(node));
        *p=add;
        return (*p);
    }
    else{
        add->next=(*p);
        *p=add;
        return (*p);
    }
}
void display(node *head){
    iter=head;
    while(iter!=NULL){
        printf("%d\t",iter->num);
        iter=iter->next;
    }
    printf("\n");
}
node * concatenate(node **r1,node **r2){
    iter=*r1;
    while(iter->next!=NULL){
        iter=iter->next;
    }
    iter->next=(*r2);
    return (*r1);

}
int main(){
    printf("create first list!\n\n");
    
    int number;
    char answ[20];
    do{
        printf("Number : ");
        scanf("%d",&number);
        head=create(&head,number);
        printf("Do you want to continue? ");
        scanf("%s",&answ);
        printf("\n");
    }while(strcmpi(answ,"no")!=0);

    printf("\ncreate second list!\n\n");
    do{
        printf("Number : ");
        scanf("%d",&number);
        root=create(&root,number);
        printf("Do you want to continue? ");
        scanf("%s",&answ);
        printf("\n");
    }while(strcmpi(answ,"no")!=0);
    
    printf("\n\nFirst list : "); 
    display(head);
    printf("\n\nSecond list : "); 
    display(root);
    head= concatenate(&head,&root);
    printf("\nConcatenatelist : ");
    display(head);
    getch();
    return 0;
}
