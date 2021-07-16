//Thanks to this program, we can add and delete elements from the middle to the list.
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
node *q=NULL;

node *createbetween(node *head,int num,int x){
	node *added=(node*)malloc(sizeof(node));
	added->data=num;
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
		while(iter->data!=x && iter!=NULL){
			q=iter;
			iter=iter->next;
		}
	    q->next=added;
	    added->next=iter;
	}
	return head;
}
node *createbegining(node *head,int value){
    node *added=(node*)malloc(sizeof(node));
	added->data=value;
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
		added->next=(head);
		head=added;
		return (head);
	}
}
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
void deletebetween(node *head,int num){
    iter=head;
    while(iter->data!=num &&iter!=NULL){
        q=iter;
        iter=iter->next;
    }
    q->next=iter->next;
    free(iter);
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
    int num,position,choice;
    char answer[10];
    do{
        printf("\n1-)Add First\n2-)Add Last\n3-)Add Between\n4-)Delete Between\n5-)Display\n\nChoice one of them : ");
        scanf("%d",&choice);
        if(choice==1){
            printf("\nEnter a number : ");
            scanf("%d",&num);
            head=createbegining(head,num);
        }
        else if(choice==2){
            printf("\nEnter a number : ");
            scanf("%d",&num);
            head=createlast(head,num);
        }
        else if(choice==3){
            printf("\nEnter a number : ");
            scanf("%d",&num);
            printf("\nWhich number should come before?");
            scanf("%d",&position);
            createbetween(head,num,position);
        }
        else if(choice==4){
            printf("\nEnter a number to delete : ");
            scanf("%d",&num);
            deletebetween(head,num);
        }
        else if(choice==5){
            if(head==NULL){
                printf("\nList is empty!");
            }
            display(head);
        }
        else{
            printf("\nUnvalid choice!\n");
        }
        printf("\nDo you want to continue,yes or no?");
        scanf("%s",answer);
    }while(strcmp(answer,"no")!=0);
    getch();
    return 0;
}