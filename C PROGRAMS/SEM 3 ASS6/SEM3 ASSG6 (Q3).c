#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//assumes all values are unique
struct node{
int d;
char s[15];
struct node *n;
};

struct pcblist{
struct node *h;
};

struct node *createnode(int k,char *st){
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->d=k;
    strcpy(t->s,st);
    t->n=NULL;
    return t;
}

void insfrt(struct pcblist *l,struct node *t){
if(l->h==NULL){
    l->h=t;
}
else{
    t->n=l->h;
    l->h=t;
} }

//if not present or empty returns NULL
struct node* listsearch(struct pcblist *l,int k){
    struct node* y=l->h;
    if(y==NULL)
        return NULL;
    while((y)&&(y->d!=k)){
        y=y->n;
    }
    return y;  }

//works only if x node is present in list
struct node* listdelete(struct pcblist *l,struct node *x){
    struct node *t=l->h;
if(l->h==x){
    l->h=x->n;
    return t;
}
else{
    while(t->n!=x){
        t=t->n; }
    t->n=t->n->n;
    return x;
}
}

void listwaiting(struct pcblist*l){
    struct node*f=l->h;
    int i=0;
while(f){
        i++;
        if(strcmp(f->s,"waiting")==0)
    printf("%d ",f->d);
    f=f->n;
}
if(i==0){
    printf("-1\n");
}
}

void main(){
char c;
int k;
char st[15];
struct node *t=NULL;
struct pcblist l;
l.h=NULL;
while(1){
    scanf("%c",&c);
    if(c=='i'){
         scanf(" %d %s ",&k,st);
         t=createnode(k,st);
         insfrt(&l,t);
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
  else if(c=='g'){
    scanf("%d",&k);
    t=listsearch(&l,k);
    if(t)
        printf("%s\n",t->s);
   else
    printf("-1\n");
  }
 else if(c=='l'){

    listwaiting(&l);
    printf("\n");
 }
 else if(c=='u'){
    scanf("%d %s ",&k,st);
    t=listsearch(&l,k);
    strcpy(t->s,st);
 }
  else if(c=='e'){
    break;
  }
}
}
