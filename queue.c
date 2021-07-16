//In this program, some of the notes in our intermediate programming language course are queued.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE  100
typedef struct{
	char name[30];
}_ELEMENT;

typedef struct{
	_ELEMENT q_elem[MAX_SIZE];
	int rear;
	int front;
	int full, empty;
}_QUEUE;

void init_queue(_QUEUE *q){
	q->rear= q->front= 0;
	q->full=0; 
	q->empty=1;
}

int IsFull(_QUEUE *q){
	return(q->full);
}

int IsEmpty(_QUEUE *q){
	return(q->empty);
}

void AddQ(_QUEUE *q, _ELEMENT ob){
	if(IsFull(q)){
		printf("Queue is Full \n");
		return;
	}
	q->rear=(q->rear+1)%(MAX_SIZE);
	q->q_elem[q->rear]=ob;
	if(q->front==q->rear)
		q->full=1;
	else
		q->full=0;
	q->empty=0;
	return;
}

_ELEMENT  DeleteQ(_QUEUE *q){
	_ELEMENT temp;
	temp.name[0]='\0';
	if(IsEmpty(q)){
		printf("Queue is EMPTY\n");
		return(temp);
	}
	q->front=(q->front+1)%(MAX_SIZE);
	temp=q->q_elem[q->front];
	if(q->rear==q->front) 
		q->empty=1;
	else
		q->empty=0;
	q->full=0;
	return temp;
}

int main(){
	char command[40];
	_ELEMENT ob;
	_QUEUE A;
	init_queue(&A);
	command[0]='\0';
	printf("For adding a name use 'add [name]'\n");
	printf("For deleting  use 'delete' \n");
	printf("To end the session use 'bye' \n");
	while (strcmp(command,"bye")!=0){
		scanf("%s",command);
		if(strcmp(command,"add")==0){
			scanf("%s",ob.name);
			if(IsFull(&A))
				printf("No more insertion!\n");
			else{
				AddQ(&A,ob);
				printf("inserted: %s \n",ob.name);
			}
		}
		if(strcmp(command,"delete")==0){
			if(IsEmpty(&A))
				printf("Queue is empty \n");
			else{
				ob=DeleteQ(&A);
				printf("deleted %s \n",ob.name);
			}

		}
	}/* End of while */
	printf("End session \n");
    return 0;
}