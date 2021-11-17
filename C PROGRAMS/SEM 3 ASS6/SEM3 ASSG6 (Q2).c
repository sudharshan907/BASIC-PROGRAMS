#include<stdio.h>
#include<stdlib.h>
//assumes all values are unique
struct node{
int d;
struct node *p,*n;
};

struct doublelist{
struct node *h;
};

struct node *createnode(int k){
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->d=k;
    t->n=t->p=NULL;
    return t;
}

void insfrt(struct doublelist *l,struct node *t){
if(l->h==NULL){
    l->h=t;
}
else{
    t->n=l->h;
    t->n->p=t;
    l->h=t;
}
}

void instail(struct doublelist *l,struct node *t){
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
      t->p=y;
}
}
//if not present or empty returns NULL
struct node* listsearch(struct doublelist *l,int k){
    struct node* y=l->h;
    if(y==NULL)
        return NULL;
    while((y)&&(y->d!=k)){
        y=y->n;
    }
    return y;
}
//works only if y node is present in list
void listinsertafter(struct doublelist *l,struct node *x,struct node *y){
x->n=y->n;
x->p=y;
y->n=x;
x->n->p=x;
}
//works only if y noe is present in list
void listinsertbefore(struct doublelist *l,struct node *x,struct node *y){
if(l->h==y){
 y->p=x;
 x->n=y;
 x->p=NULL;
 l->h=x;
}
else{
     y=y->p;
     listinsertafter(l,x,y);
}
}

//works only if x node is present in list
struct node* listdelete(struct doublelist *l,struct node *x){
if(l->h==x){
    l->h=x->n;
l->h->p=NULL;
    return x;
}
else{
   x->p->n=x->n;
   if(x->n)
   x->n->p=x->p;
    return x;
}
}

struct node* deletefirst(struct doublelist *l){
    struct node *t=l->h;
    if(l->h==NULL)
        return NULL;
    l->h=l->h->n;
    l->h->p=NULL;
    return t;
}


struct node* deletelast(struct doublelist *l){
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
/* useful to print list to trace the bugs
void print(struct doublelist *l){
       struct node *u=l->h;
       while(u){
       printf("%d",u->d);
       if(u->p)
        printf("(%d)",u->p->d);
        else
            printf("()");
       if(u->n)
        printf("(%d) ",u->n->d);
         else
            printf("()  ");
         u=u->n;}
}

*/
void main(){
char c;
int k,k1;
struct node *t=NULL,*y=NULL;
struct doublelist l;
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
