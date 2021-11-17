#include<stdio.h>
#include<stdlib.h>
//1)if array size is n ,then it's max capacity is n-1,so n++ after scanning
//2)queue contains f,r,n,pointer to array
//3)it contains elements from index (f+1)%n to r
struct queue{
int f,r,n;
int *b;
};

int dequeue(struct queue *q){
if(q->f==q->r)
    return -1;
else{
    q->f=(q->f+1)%(q->n);
    int d=q->b[q->f];
    return d;
} }

void enqueue(struct queue *q,int x){
q->r=(q->r+1)%(q->n);
if(q->f==q->r){
    printf("-1\n");
    if(q->r==0)
        q->r=q->n-1;
    else
        q->r=q->r-1;
    return ;
}
q->b[q->r]=x;
}


void main(){
int n,x;
scanf("%d",&n);
n++;
int *a=(int *)malloc(n*sizeof(int));
struct queue q;
q.n=n;
q.b=a;
q.f=q.r=0;
char c;
while(1){
    scanf("%c",&c);
    if(c=='i'){
            scanf("%d",&x);
     enqueue(&q,x);
    }
    else if(c=='d'){
   printf("%d\n",dequeue(&q));
    }
    else if(c=='e'){
       if(q.f==q.r)
        printf("-1\n");
       else
        printf("1\n");
    }
    else if(c=='f'){
        x=(q.r+1)%(q.n);
       if(q.f==x)
       printf("-1\n");
        else
            printf("1\n");
    }
    else if(c=='t'){
        break;
    } }}

