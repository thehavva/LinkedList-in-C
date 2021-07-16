//This program makes a list by creating a node with adding to last element and also deleting to last eleman.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Node{
	int data;
	struct Node *next;
};
typedef struct Node node;

node *head=NULL;
node *iter=NULL;

node *createlast(node *head,int n){
	node *added=(node*)malloc(sizeof(node));
	added->data=n;
	added->next=NULL;
	if(added==NULL){
			printf("bad allocate\n");
			exit(0);
	}
	if(head==NULL){
			head=(node*)malloc(sizeof(node));
			head=added;
			return (head);
	}
	else{
		iter=head;
		while(iter->next!=NULL){
			iter=iter->next;
		}
		iter->next=added;
	}
	return (head);
}
void lastdelete(node *head){
    iter=head;
    while(iter->next->next!=NULL){
        iter=iter->next;
    }
    free(iter->next);
    iter->next=NULL;
}
void display(node *head){
	iter=head;
	while(iter!=NULL){
		printf("%d ",iter->data);
		iter=iter->next;
	}
	printf("\n");
}
int main(){
    int num,choice;
    char answer[10];
    do{
        printf("1-)Create\n2-)Delete\n3-)Display\nChoice one option : ");
        scanf("%d",&choice);
        if(choice==1){
            printf("\nEnter a number : ");
            scanf("%d",&num);
            head=createlast(head,num);
        }
        else if(choice==2){
            if(head==NULL){
                printf("List is empty!");
            }
            else{
                lastdelete(head);
            }
            
        }
        else if(choice==3){
            if(head==NULL){
                printf("List is empty!");
            }
            display(head);
        }
        else{
            printf("Unvalid choice!\n");
        }
        printf("Do you want to continue,yes or no?\n");
        scanf("%s",answer);
        printf("\n\n");
    }while(strcmpi(answer,"no")!=0);
    getch();
    return 0;
}