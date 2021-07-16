//This is first project with LinkedList,which contain string variable and its application.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char name[20];
    int data;
    struct Node *next;
};
typedef struct Node node;
node *root=NULL;
node *iter=NULL;

node *insert(char name[20],int num,node **head){
    node *added=(node*)malloc(sizeof(node));
    added->data=num;
    strcpy(added->name, name);
    added->next=NULL;
    if(added==NULL){
        printf("\nBad Allocation\n");
        exit(0);
    }
    if(*head==NULL){
        *head=(node*)malloc(sizeof(node));
        *head=added;
    }
    else{
        iter=*head;
        while(iter->next!=NULL){
            iter=iter->next;
        }
        iter->next=added;
    }
    return (*head);
    free(head);
}
void display(node *head){
    iter=head;
    int i=1;
    while(iter!=NULL){
        printf("%d.number : name = %s data = %d\n",i,iter->name,iter->data);
        i++;
        iter=iter->next;
    }
    printf("\n");
}
void delete(node **head,int n){
    iter=*head;
    node *q;
   
    if(head==NULL){
        printf("This list is empty!\n");
        exit(0);
    }
    if(iter->data==n){
       q=iter;
       iter=iter->next;
       free(q);
    }
    else{
        while(iter!=NULL && iter->data!=n){
            q=iter;
            iter=iter->next;
        }
        if(iter==NULL){
            printf("Did not find!\n");
        }
        else{
            q->next=iter->next;
            free(iter);
        }

    }
}
node *add(node **head,int before){
    iter=*head;
    char ch[20];
    int num;
    node *q=(node*)malloc(sizeof(node));
    node *p;
    printf("Enter a new number and name!");
    scanf("%d %s",&num,&ch);
    q->data=num;
    q->next=NULL;
    strcpy(q->name,ch);    
    if(*head==NULL){
        printf("THis empty is empty!\n");
        q=*head;
        return (*head);
    }
    else if(iter->data == before){
        q->next=iter;
        iter=q;
        return (*head);
    }
    else{
        while(iter!=NULL && iter->data!=before){
            p=iter;
            iter=iter->next;
        }
        if(iter==NULL){
            printf("Did not find!\n");
        }
        else{
            p->next=q;
            q->next=iter;
            return (*head);
        }
    }
    free(q);
}
int main(){
    int num,temp,before;
    char name[20],answer[10];
    printf("Create your list\n\n");
    do{
        printf("Name : "); 
        scanf("%s",&name);
        printf("Number : "); 
        scanf("%d",&num);
        root=insert(name,num,&root);
        printf("\nDo you want to continue? "); 
        scanf("%s",&answer);
        printf("\n");
    }while(strcmpi(answer,"no")!=0);
    display(root);
    printf("which number to be deleted?\n");
    scanf("%d",&temp);
    delete(&root,temp);
    display(root);
    printf("Which number will be added before?\n");
    scanf("%d",&before);
    root=add(&root,before);
    display(root);
    getch();
    return 0;
   
}
