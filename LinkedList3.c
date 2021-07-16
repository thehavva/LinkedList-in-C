//This program makes a list by creating a node with adding to last element.
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

node *createlast(node *head,int n){  //Function create a list to last eleman
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

void display(node *head){
	iter=head;
	while(iter!=NULL){
		printf("%d ",iter->data);
		iter=iter->next;
	}
	printf("\n");
}
int main(){
    int num;
    char answer[10];
    do{
        printf("Enter a number : ");
        scanf("%d",&num);
        head=createlast(head,num);
        printf("Do you want to continue,yes or no?");
        scanf("%s",answer);
    }while(strcmp(answer,"no")!=0);
    display(head);
    getch();
    return 0;
}
