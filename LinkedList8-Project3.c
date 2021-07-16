/*Distance education has become widespread today due to covid-19. Many schools, including primary and secondary schools, continue their education from home with distance education systems. 
With this project, I wrote a simple application for primary school teachers. It is both a game-playing and an instructive application. It randomly asks students for multiplication operations, 
giving 10 points to those who get it right and 0 points to those who answer incorrectly.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h> //This library is necessary to produce random number;

struct Node{
    int num;
    int puan;
    struct Node *next;
    
};
typedef struct Node node;
node *head=NULL;
node *root=NULL;
node *iter=NULL;
node *q=NULL;

node *creatlist(node *head,int x){
    if(head==NULL){
        head=(node*)malloc(sizeof(node));
        head->next=NULL;
        head->num=x;
        return (head);
    }
    if(head->num > x){
        q=(node*)malloc(sizeof(node));
        q->num = x;
        q->next=head;
        return q;
    }
    iter=head;
    while(iter->next!=NULL && iter->next->num < x){
       iter=iter->next;
    }
    q=(node*)malloc(sizeof(node));
    q->next=iter->next;
    iter->next=q;
    q->num=x;
    return (head);
}
void delete(int x){
    iter=head;
    if(iter->num==x){
        head=iter->next;
        free(iter);
    }
    else
    {
        while((iter!=NULL) && (iter->num!=x)){
            q=iter;
            iter=iter->next;
        }
         if((iter->num==x) && (iter->next!=NULL)){
            q->next=iter->next;
            free(iter);
        }
        else if((iter->num==x) && (iter->next==NULL)){
            free(iter);
            q->next=NULL;
        }
        
    }
}
int question(){
    srand(time(NULL)); //For random number ,it is used generally.
    int a,b,x,y;
    a=rand()%10; //This is prototype.
    b=rand()%20;
    x=a*b;
    printf("%d is a ; %d is b : x=a*b, what is value of x?\n\n",a,b);
    printf("Enter your answer!\n"); scanf("%d",&y);
    printf("correct answer is %d\n\n",x);
    if(x==y){
       return 10;
    }
    else
    {
        return 0;
    }
}
void find(int x){
    iter=head;
    if(iter->num==x){
        iter->puan=question();
        printf("\n%d is your score dear %d!!\n\n",iter->puan,iter->num);
    }
    else{
        while(iter->num!=x && iter->next!=NULL){
        iter=iter->next;
    }
        if (iter->num == x)
        {
        iter->puan=question();
        printf("%d is your score dear %d\n\n",iter->puan,iter->num);  
        }
        else{
            printf("There is no student who has this school number!!\n\n");
        }
    }
}
void print(node *head){
    iter=head;
    while(iter!=NULL){
        printf("number : %d\n",iter->num);
        iter=iter->next;
    }
    printf("\n");

}
void scores(int n){
    node*added=(node*)malloc(sizeof(node));
    added->num=n;
    added->next=root;
    root=added;
}
int main(){
    int i=0,n,no;
    printf("Please enter your number of students!!\n"); scanf("%d",&n);
    printf("Please enter your students school numbers!!\n");
    for(i=0; i<n; i++){
        scanf("%d",&no);
        head=creatlist(head,no);
        no=0;
    }
    print(head);
    printf("\n");
    for(i=0; i<n/2; i++){
        printf("Please enter a number!!\n\n"); 
        scanf("%d",&no);
        find(no);
        scores(no);
        delete(no);
        printf("\n");
        printf("Remaining Students");
        print(head);
    }
    printf("\nNext week student's numbers : \n\n");
    print(head);
    getch();
    return 0;
}
