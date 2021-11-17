#include<stdio.h>
#include<stdlib.h>
//assumes all values are unique
struct node{
int d;
struct node *n;
};

struct list{
struct node *h;
};

struct node *createnode(int k){
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->d=k;
    t->n=NULL;
    return t;
}

void insfrt(struct list *l,struct node *t){
if(l->h==NULL){
    l->h=t;
}
else{
    t->n=l->h;
    l->h=t;
}
}

void instail(struct list *l,struct node *t){
    struct node*y=NULL;
if(l->h==NULL){
    l->h=t;
}
else{
        y=l->h;
        while(y->n){
            y=y->n;
        }
      y->n=t;
}
}
//if not present or empty returns NULL
struct node* listsearch(struct list *l,int k){
    struct node* y=l->h;
    if(y==NULL)
        return NULL;
    while((y)&&(y->d!=k)){
        y=y->n;
    }
    return y;
}
//works only if y node is present in list
void listinsertafter(struct list *l,struct node *x,struct node *y){
x->n=y->n;
y->n=x;
}
//works only if y noe is present in list
void listinsertbefore(struct list *l,struct node *x,struct node *y){
    struct node *t1=NULL;
if(l->h==y){
    x->n=l->h;
    l->h=x;
}
else{
    t1=l->h;
    while(t1->n!=y){
        t1=t1->n;
    }
    x->n=t1->n;
    t1->n=x;
}
}

//works only if x node is present in list
struct node* listdelete(struct list *l,struct node *x){
    struct node *t=l->h;
if(l->h==x){
    l->h=x->n;
    return t;
}
else{
    while(t->n!=x){
        t=t->n;
    }
    t->n=t->n->n;
    return x;
}
}

struct node* deletefirst(struct list *l){
    if(l->h==NULL)
        return NULL;
    struct node *t=l->h;
    l->h=l->h->n;
    return t;
}


struct node* deletelast(struct list *l){
    if(l->h==NULL)
        return NULL;
    struct node *t=l->h,*t1=NULL;
    if(l->h->n==NULL){
        l->h=NULL;
        return t;
    }
    while( t->n->n){
        t=t->n;
    }
    t1=t->n;
    t->n=NULL;
    return t1;
}

void main(){
char c;
int k,k1;
struct node *t=NULL,*y=NULL;
struct list l;
l.h=NULL;
while(1){
    scanf("%c",&c);
    if(c=='f'){
         scanf(" %d",&k);
         t=createnode(k);
         insfrt(&l,t);
    }
   else if(c=='t'){
 scanf(" %d",&k);
         t=createnode(k);
         instail(&l,t);
   }
   else if(c=='a'){
     scanf(" %d %d ",&k,&k1);
       t=createnode(k);
       y=listsearch(&l,k1);
       listinsertafter(&l,t,y);
   }
    else if(c=='b'){
        scanf(" %d %d ",&k,&k1);
       t=createnode(k);
       y=listsearch(&l,k1);
       listinsertbefore(&l,t,y);
    }
   else if(c=='d'){
    scanf("%d",&k);
    t=listsearch(&l,k);
    if(t==NULL)
        printf("-1\n");
    else{
    t=listdelete(&l,t);
    printf("%d\n",t->d);
    }
   }
   else if(c=='i'){
    t=deletefirst(&l);
    if(t==NULL)
        printf("-1\n");
    else
        printf("%d\n",t->d);
   }
  else if(c=='l'){
   t=deletelast(&l);
    if(t==NULL)
        printf("-1\n");
    else
        printf("%d\n",t->d);
  }
  else if(c=='s'){
    scanf("%d",&k);
    t=listsearch(&l,k);
    if(t)
        printf("1\n");
    else
        printf("-1\n");
  }
  else if(c=='e'){
    break;
  }
}
}
