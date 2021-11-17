#include<stdio.h>
#include<stdlib.h>

//1)every line of q and sample
struct node {
int key,ht,c;
struct node *l,*r,*p;
};

void ins(struct node *h,struct node *new);
struct node* insert(struct node *h,int k);
struct node* leftrot(struct node *t);
struct node* rightrot(struct node *t);
int getbal(struct node *n);
struct node* sea(struct node *h,int k);
void print(struct  node *h);
struct node* createnode(int k);
int max(int a,int b){
return a>b?a:b;
}
int height(struct node*n){
if(n==NULL)
return 0;
return (n->ht);}

void main(){
int a[200],n,i;
scanf("%d",&n);
for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}

struct node *h=NULL,*f=NULL;
for(i=0;i<n;i++){
    f=sea(h,a[i]);
    if(f==NULL)
        h=insert(h,a[i]);
    else{
        f->c=f->c+1;
    }
}
print(h);
}

struct node* createnode(int k){
struct node*new=(struct node *)malloc(sizeof(struct node));
new->key=k;
new->ht=new->c=1;
new->l=new->r=new->p=NULL;
return new;
};

void print(struct  node *h){
    int i;
    if(h==NULL)
        return ;
    else{
            print(h->l);
            for(i=0;i<h->c;i++)
        printf("%d ",h->key);
        print(h->r);
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


