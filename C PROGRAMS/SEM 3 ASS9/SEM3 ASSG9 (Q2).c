#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
int key;
int pr;
char s[100];
struct node *l,*r,*p;
};

struct node * createnode(int k,char *s,int pr);
struct node * insert(struct node *h,struct node *new);
struct node * delete(struct node *h,struct node *new);
struct node * search(struct node *h,int k);
void inorder(struct node *h);
struct node * mini(struct node *h);
void modify(struct node *h,int n,int p);

void main(){
struct node *h=NULL,*new=NULL;
int n,pr;
char c,s[100];
while(1){
    scanf("%c",&c);
    if(c=='a'){
            scanf("%d %s %d",&n,&s,&pr);
          //  printf("%d %s %d",)
            new=createnode(n,s,pr);
            h=insert(h,new);
        }

   else if(c=='d'){
        scanf("%d",&n);
        new=search(h,n);
        if(new==NULL){
            printf("-1\n");
        }
        else{
        printf("%d %s %d\n",new->key,new->s,new->pr);
        h=delete(h,new);
        }
    }
    else if(c=='s'){
            scanf("%d",&n);
        new=search(h,n);
        if(new)
            printf("%d %s %d\n",new->key,new->s,new->pr);
            else
                printf("-1\n");
        }

    else if(c=='i'){
        inorder(h);
        printf("\n");
    }
    else if(c=='m'){
     scanf("%d %d",&n,&pr);
     modify(h,n,pr);
    }
    else if(c=='e'){
        break;
    }
}
}

void modify(struct node *h,int n,int p){
struct node *temp=search(h,n);
temp->pr=p;
}
struct node * mini(struct node *h){
struct node *x=h;
while((x)&&(x->l))
    x=x->l;
return x;
}

struct node * createnode(int k,char *st,int pr){
struct node *new=NULL;
new=(struct node *)malloc(sizeof(struct node));
new->key=k;
strcpy(new->s,st);
new->pr=pr;
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
        printf("%d %s %d\n",h->key,h->s,h->pr);
        inorder(h->r);
}
}



