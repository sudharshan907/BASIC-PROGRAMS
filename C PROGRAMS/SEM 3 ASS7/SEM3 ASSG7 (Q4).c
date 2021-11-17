#include<stdio.h>
#include<stdlib.h>

struct node{
int d;
struct node *n;
};

struct queue{
struct node *h,*t;
};


struct node* createnode(int k){
struct node *new=(struct node*)malloc(sizeof(struct node));
new->d=k;
new->n=NULL;
return new;
}


void enqueue(struct queue *q,struct node *new){
    struct node *te;
if(q->h==NULL){
    q->h=q->t=new;   }
else{
   te=q->h;
   while(te->n){
    te=te->n;
   }
    te->n=new;
    q->t=new;         }}

struct node* dequeue(struct queue *q){
    struct node *te;
if(q->h==NULL){
    return NULL;
}
else{
    te=q->h;
    q->h=te->n;
    return te;
}
}

int isemp(struct queue *q){
if(q->h)
    return 1;
return -1;

}

void main(){
struct node *t=NULL;
struct queue q;
q.h=q.t=NULL;
char c;
int n;
while(1){
    scanf("%c",&c);
    if(c=='i'){
        scanf("%d",&n);
        t=createnode(n);
        enqueue(&q,t);
    }
    else if(c=='d'){
        t=dequeue(&q);
        if(t)
            printf("%d\n",t->d);
        else
            printf("-1\n");
    }
    else if(c=='e'){
    printf("%d\n",isemp(&q));
    }
    else if(c=='t'){
        break;
    }
}
}
