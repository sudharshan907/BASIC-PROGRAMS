#include<stdio.h>
#include<stdlib.h>

struct node{
int key;
struct node *l,*r,*p;
};

struct node * createnode(int k);
struct node * insert(struct node *h,struct node *new);
//struct node * delete(struct node *h,int k);
struct node * delete(struct node *h,struct node *new);
struct node * search(struct node *h,int k);
void inorder(struct node *h);
void preorder(struct node *h);
void postorder(struct node *h);
struct node * mini(struct node *h);

void main(){
struct node *h=NULL,*new=NULL;
int n;
char c;
while(1){
    scanf("%c",&c);
    if(c=='a'){
            scanf("%d",&n);
            new=createnode(n);
            h=insert(h,new);
        }

   else if(c=='d'){
        scanf("%d",&n);
        new=search(h,n);
        if(new==NULL){
            printf("-1\n");
        }
        else{
        printf("%d\n",new->key);
        h=delete(h,new);
        }
    }
    else if(c=='s'){
            scanf("%d",&n);
        new=search(h,n);
        if(new)
            printf("1\n");
            else
                printf("-1\n");
        }

    else if(c=='i'){
        inorder(h);
        printf("\n");
    }
    else if(c=='p'){
        preorder(h);
        printf("\n");
    }
     else if(c=='t'){
        postorder(h);
        printf("\n");
    }
    else if(c=='e'){
        break;
    }
}
}


struct node * mini(struct node *h){
struct node *x=h;
while((x)&&(x->l))
    x=x->l;
return x;
}

struct node * createnode(int k){
struct node *new=NULL;
new=(struct node *)malloc(sizeof(struct node));
new->key=k;
new->l=new->r=new->p=NULL;
return new;
}

struct node * insert(struct node *h,struct node *new){
struct node *m=h,*n=NULL;
while(m){
    n=m;
    if(new->key<m->key)
        m=m->l;
    else
        m=m->r;
}
new->p=n;
if(!n)
    h=new;
else if (new->key<n->key)
    n->l=new;
else
    n->r=new;
return h;
}
/*
struct node * delete(struct node *h,int k){
|struct node *temp=NULL;
if(h==NULL)
    return h;
if(k<h->key)
    h->l=delete(h->l,k);
else if(k>h->key)
    h->r=delete(h->r,k);
else{
    if(h->l==NULL){
        temp=h->r;
    return temp; }
    else if (h->r==NULL){
        temp=h->l;
        return temp;
    }
    else{
        temp=maxi(h->l);
        h->key=temp->key;
        h->l=delete(h->l,temp->key);
    }}
    return h;
}
*/

struct node * delete(struct node *h,struct node *new){
    struct node *temp=NULL;

//leaf
if((new->l==NULL)&&(new->r==NULL)){
        if(new->p==NULL){      return NULL;      }
        if( new->p->l==new  ){  new->p->l=NULL;    return h;  }
       else if(new->p->r==new){    new->p->r=NULL;     return h;  }
}

//left child
if((new->l)&&(new->r==NULL)){
        if(new->p==NULL){    h=new->l;   h->p=NULL;    return h;    }
        if( new->p->l==new  ){  new->p->l=new->l;   }
       else if(new->p->r==new){     new->p->r=new->l;   }
    new->l->p=new->p;
    return h;
}

//right chikd
if((new->l==NULL)&&(new->r)){
        if(new->p==NULL){   h=new->r;   h->p=NULL;   return h;    }
        if( new->p->l==new  ){   new->p->l=new->r;  }
       else if(new->p->r==new){    new->p->r=new->r;     }
    new->r->p=new->p;
    return h;
}
//two child
if((new->l)&&(new->r)){
temp=mini(new->r);
new->key=temp->key;
new=temp;
if(new->r==NULL){
    if(new->p->r==new){   new->p->r=NULL;      }
    else if(new->p->l==new){    new->p->l=NULL;     }
    return h;
}
else{
     if( new->p->l==new  )     {      new->p->l=new->r;   }
       else if(new->p->r==new){  new->p->r=new->r;  }
       new->r->p=new->p;
    return h;
}  }}




struct node * search(struct node *h,int k){


   while((h!=NULL)&&(h->key!=k)){
    if(k<h->key)
        h=h->l;
    else
        h=h->r;
   }
    return h;
}


void inorder(struct node *h){
if(h){
    inorder(h->l);
        printf("%d ",h->key);
        inorder(h->r);
}
}

void preorder(struct node *h){
if(h){
        printf("%d ",h->key);
        preorder(h->l);
        preorder(h->r);
}
}

void postorder(struct node *h){
if(h){
        postorder(h->l);
        postorder(h->r);
        printf("%d ",h->key);
}
}

