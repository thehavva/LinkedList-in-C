//This program makes a list by creating a node with adding to first element.

#include <stdio.h>
#include <stdlib.h> //for allocation from memory.
#include <string.h> 
#include <conio.h> //for getch function

struct Node{ // List generally is used with structs.
    int data;
    struct Node *next;
};
typedef struct Node node; //We shortened the name of the struct with typedef.
node *head;
node *iter;

node *createbegining(node *head,int value){   //This function create a list adding to first again.
    node *added=(node*)malloc(sizeof(node));
	added->data=value;
	added->next=NULL;
	if(added==NULL){     //This process is necessary to control allocation in our computer.
		printf("Bad allocate\n");
		exit(0);
	}
	if(head==NULL){ //This is valid to first node.
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
void display(node *head){
    iter=head;
    while(iter!=NULL){
        printf("%d\t",iter->data);
        iter=iter->next; //iteration
    }
    printf("\n");
}
int main(){
    int num;
    char answer[10];
    do{
        printf("Enter a number : ");
        scanf("%d",&num);
        head=createbegining(head,num); //We must make equal to returning result of creating function to a node because of the first eleman change continuously.
        printf("Do you want to continue,yes or no?");
        scanf("%s",answer);
    }while(strcmp(answer,"no")!=0);
    display(head);
    getch(); //This is necessary for Viual Stdio Code 
    return 0;
}