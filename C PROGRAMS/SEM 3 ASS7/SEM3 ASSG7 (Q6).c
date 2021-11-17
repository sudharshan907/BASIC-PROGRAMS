#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
char id[10],fil[10];
int num;
float kb;
struct node *n;
};

struct queue{
struct node *h,*t;
};


struct node* createnode(char *i,char *file,int nu,float k){
struct node *new=(struct node*)malloc(sizeof(struct node));
strcpy(new->id,i);
strcpy(new->fil,file);
new->num=nu;
new->kb=k;
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
    q->t=new;}}

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

void list(struct queue *q){
struct node *t=q->h;
if(t==NULL){
    printf("-1\n");
}
while(t){
        printf("%s %s %d %.1f\n",t->id,t->fil,t->num,t->kb);
        t=t->n;
}
}

void main(){
struct node *t=NULL;
struct queue q;
q.h=q.t=NULL;
char c;
int num;
float kb;
char id[10],file[10];
while(1){
    scanf("%c",&c);
    if(c=='a'){
        scanf("%s %s %d %f",id,file,&num,&kb);
        t=createnode(id,file,num,kb);
        enqueue(&q,t);
    }
    else if(c=='e'){
        t=dequeue(&q);
        if(t)
            printf("%s\n",t->id);
        else
            printf("-1\n");
    }
    else if(c=='l'){
     list(&q);
    }
    else if(c=='t'){
        break;
    }
}
}
