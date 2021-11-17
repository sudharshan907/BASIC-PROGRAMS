#include<stdio.h>
#include<stdlib.h>

struct node {
int key,ht;
struct node *l,*r,*p;
};

struct node * mini(struct node *h);
void ins(struct node *h,struct node *new);
struct node* delete(struct node *h,int k);
struct node* insert(struct node *h,int k);
struct node* leftrot(struct node *t);
struct node* rightrot(struct node *t);
int getbal(struct node *n);
struct node* sea(struct node *h,int k);
void print(struct  node *h);
struct node* createnode(int k);
int max(int a,int b);
int height(struct node*n);

void main(){
char c;
int k;
struct node *h=NULL,*f=NULL;
while(1){
    scanf("%c",&c);
    if(c=='i'){
            scanf("%d",&k);
        h=insert(h,k);
    }
    else if(c=='d'){
        scanf("%d",&k);
        if(sea(h,k)==NULL)
            printf("FALSE\n");
        else{
        h=delete(h,k);
        printf("%d\n",k); }
    }
    else if(c=='s'){
            scanf("%d",&k);
        f=sea(h,k);
        if(sea(h,k)==NULL)
            printf("FALSE\n");
        else
            printf("TRUE\n");

    }
    else if(c=='b'){
        scanf("%d",&k);
        f=sea(h,k);
        if(f==NULL)
            printf("FALSE\n");
        else
        printf("%d\n",getbal(f));
    }
    else if(c=='p'){
        print(h);
        printf("\n");
    }
    else if(c=='e')
        break;
    }}
struct node* createnode(int k){
struct node*new=(struct node *)malloc(sizeof(struct node));
new->key=k;
new->ht=1;
new->l=new->r=new->p=NULL;
return new;
}

int max(int a,int b){
return a>b?a:b;
}
int height(struct node*n){
if(n==NULL)
return 0;
return (n->ht);}

struct node * mini(struct node *h){
struct node *x=h;
while((x)&&(x->l))
    x=x->l;
return x;
}

void print(struct  node *h){
    if(h==NULL)
        printf("( )");
    else{
        printf("( %d ",h->key);
        print(h->l);
        printf(" ");
        print(h->r);
        printf(" )");
    }
}
struct node * sea(struct node *h,int k){
while((h!=NULL)&&(h->key!=k)){
    if(k<h->key)
        h=h->l;
    else
        h=h->r;
   }
    return h;
}

int getbal(struct node *n){
if(n==NULL)
    return 0;
return((height(n->l))-(height(n->r)));
}

struct node* leftrot(struct node *t){
struct node *t1=NULL,*t2=NULL;
t1=t->r;
if(t1==NULL)
    t2= NULL;
else
t2=t1->l;
if(  (t->p!=NULL)&&(t->p->l)&&(t->p->l->key==t->key) )
    t->p->l=t1;
else if(  (t->p!=NULL)&&(t->p->r)&&(t->p->r->key==t->key))
    t->p->r=t1;
if(t1)
t1->p=t->p;
t->p=t1;
t->r=t2;
if(t2)
t2->p=t;
if(t1)
t1->l=t;
t->ht=1+max(height(t->l),height(t->r));
if(t1)
t1->ht=1+max(height(t1->l),height(t1->r));
return t1;
}

struct node* rightrot(struct node *t){
struct node *t1=NULL,*t2=NULL;
t1=t->l;
if(t1==NULL)
    t2=NULL;
else
t2=t1->r;
if(  (t->p!=NULL)&& (t->p->l)&&  (t->p->l->key==t->key)   ){
     t->p->l=t1;
}
else if(  (t->p!=NULL)&&(t->p->r)&&(t->p->r->key==t->key))
    t->p->r=t1;
    if(t1)
t1->p=t->p;
t->p=t1;
t->l=t2;
if(t2)
t2->p=t;
if(t1)
t1->r=t;
t->ht=1+max(height(t->l),height(t->r));
if(t1)
t1->ht=1+max(height(t1->l),height(t1->r));
return t1;
}

void ins(struct node *h,struct node *new){
struct node *m=h,*n=NULL;
while(m){
    n=m;
    if(new->key<m->key)
        m=m->l;
    else
        m=m->r;
}
new->p=n;
if (new->key<n->key)
    n->l=new;
else
    n->r=new;
}
struct node* insert(struct node *h,int k){
    if(h==NULL)
        return createnode(k);
struct node *new=createnode(k);
int bal;
ins(h,new);
struct node  *n=new;
n=n->p;

while(n!=NULL){
    n->ht=1+max(height(n->l),height(n->r));
    bal=getbal(n);
     if((bal<-1)&&(n->r)&&(k<n->r->key)){
    n->r=rightrot(n->r);
           n= leftrot(n);
           if(n->p==NULL)
                h=n;
}
    else if((bal>1)&&(n->l)&&(k>n->l->key)){
  n->l=  leftrot(n->l);
            n=rightrot(n);
            if(n->p==NULL)
                h=n;
}

else if((bal>1)&&(n->l)&&(k<n->l->key)){
    n=rightrot(n);
    if(n->p==NULL)
        h=n;
 }

else if((bal<-1)&&(n->r)&&(k>n->r->key)){
    n=leftrot(n);
    if(n->p==NULL)
        h=n;
  }
    n=n->p;
}
return h;
}

struct node* delete(struct node *h,int k){

struct node *x=NULL,*n=NULL,*suc=NULL;
x=sea(h,k);
n=x->p;
int bal;
//leaf
if( (x->l==NULL)&&(x->r==NULL) ){
        if(x->p==NULL)
        h=NULL;
   else if((x->p->l) &&(x->p->l->key==k)){
        x->p->l=NULL;
    }
    else if( (x->p->r) && (x->p->r->key==k)){
        x->p->r=NULL;
    }
}
//one child
else if(!( (x->l) && (x->r))){
if(x->l){
    if(x->p==NULL){
        h=x->l;
    }
    else{
        x->l->p=x->p;
           if((x->p->l) &&(x->p->l->key==k)){
        x->p->l=x->l;
    }
    else if( (x->p->r) && (x->p->r->key==k)){
        x->p->r=x->l;
    } } }

else if(x->r){
    if(x->p==NULL){
        h=x->r;
    }
    else{
        x->r->p=x->p;
           if((x->p->l) &&(x->p->l->key==k)){
        x->p->l=x->r;
    }
    else if( (x->p->r) && (x->p->r->key==k)){
        x->p->r=x->r;
    }
}
}   }

//two child
else if( (x->l)&&(x->r)){
    suc=mini(x->r);
    x->key=suc->key;
    n=suc->p;
//leaf
    if(suc->r==NULL){
        if((suc->p->l) &&(suc->p->l->key==suc->key)){
        suc->p->l=NULL;
    }
    else if( (suc->p->r) && (suc->p->r->key==suc->key)){
        suc->p->r=NULL;
    }
    }
//one child
else {
    suc->r->p=suc->p;
      if((suc->p->l) &&(suc->p->l->key==suc->key)){
        suc->p->l=suc->r;
    }
    else if( (suc->p->r) && (suc->p->r->key==suc->key)){
        suc->p->r=suc->r;
    }
}
}
while(n!=NULL){
    n->ht=1+max(height(n->l),height(n->r));
    bal=getbal(n);
     if((bal<-1)&&(n->r)&&(k<n->r->key)){
    n->r=rightrot(n->r);
           n= leftrot(n);
           if(n->p==NULL)
                h=n;
}
    else if((bal>1)&&(n->l)&&(k>n->l->key)){
  n->l=  leftrot(n->l);
            n=rightrot(n);
            if(n->p==NULL)
                h=n;
}
else if((bal>1)&&(n->l)&&(k<n->l->key)){
    n=rightrot(n);
    if(n->p==NULL)
        h=n;
 }
else if((bal<-1)&&(n->r)&&(k>n->r->key)){
    n=leftrot(n);
    if(n->p==NULL)
        h=n;
  }
    n=n->p;
}
return h;
}





