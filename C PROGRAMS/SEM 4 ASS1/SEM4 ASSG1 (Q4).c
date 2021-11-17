#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *l,*r,*p;
};


struct node * getnode(int k);
struct node * ins(struct node *h,struct node *new);
struct node * del(struct node *h,int k);
struct node * sea(struct node *h,int k);
int vel(struct node *h,int k);
struct node * mini(struct node *h);
struct node * maxi(struct node *h);
struct node * pred(struct node *h,int k);
struct node * suc(struct node *h,int k);
void in(struct node *h);
void pr(struct node *h);
void po(struct node *h);


void main(){
struct node *h=NULL;
struct node *new=NULL;
struct node *temp=NULL;
char c;
int k;
while(1){
    scanf("%c",&c);
    if(c=='a'){
        scanf("%d",&k);
        new=getnode(k);
        h=ins(h,new);

    }
     if(c=='d'){
            scanf("%d",&k);
            temp=sea(h,k);
            if(!temp)
                printf("-1\n");
            else{
                printf("%d\n",k);
    h=del(h,k);}
    }
   else if(c=='s'){
     scanf("%d",&k);
     temp=sea(h,k);
     if(temp){
        printf("1\n");}
     else
        printf("-1\n");

   }
    else if (c=='l'){
            scanf("%d",&k);
        printf("%d\n",vel(h,k));

    }
    else if (c=='m'){
            temp=mini(h);
       printf("%d\n",temp->key);

    }
    else if (c=='x'){
temp=maxi(h);
printf("%d\n",temp->key);

    }
    else if(c=='r'){
scanf("%d",&k);
temp=pred(h,k);
if(!(temp))
    printf("-1\n");
else
    printf("%d\n",temp->key);

    }
    else if(c=='u'){

scanf("%d",&k);
temp=suc(h,k);
if(!(temp))
    printf("-1\n");
else
    printf("%d\n",temp->key);
    }
    else if (c=='i'){
      in(h);
      printf("\n");

    }
    else if (c=='p'){
   pr(h);
 printf("\n");
    }
    else if(c=='t'){
   po(h);
    printf("\n");
    }
    else if(c=='e')
        break;


}

}

struct node * getnode(int k){
struct node *new=NULL;
new=(struct node *)malloc(sizeof(struct node));
new->key=k;
new->l=new->r=new->p=NULL;
return new;
}

struct node * ins(struct node *h,struct node *new){
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

//this is a rec fn and will not use p pointer and will not update p pointers,if p pointers updation also required ,refer del fn in  program in sem3 ass9
/*
deletion algorithm:-
1)without parent pointer in every node
a)iterative is difficult(bcz we cannot access parents directly)
b)recursive is better
2)with parent pointer in every node
a)iterative is simpler(but lengthy code)
b)recursive is diffult which can update parent pointers after deletion
3)here recurive fn which will not update p pointers is used with nodes having p pointer
*/

struct node * del(struct node *h,int k){
struct node *temp=NULL;
if(h==NULL)
    return h;
if(k<h->key)
    h->l=del(h->l,k);
else if(k>h->key)
    h->r=del(h->r,k);
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
        h->l=del(h->l,temp->key);
    }}
    return h;
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



int vel(struct node *h,int k){

int lev=1;
struct node *temp=NULL;

temp=sea(h,k);


if(temp==NULL){
    return (-1);  }

    else{
while(  (h!=NULL)&&(h->key!=k)){
    if(k<h->key){
        h=h->l;
        lev=lev+1;}
    else{
        h=h->r;
        lev=lev+1;
    }
}
    }
return (lev);

}



struct node * mini(struct node *h){
struct node *x=h;
while((x)&&(x->l))
    x=x->l;
return x;
}


struct node * maxi(struct node *h){
struct node *x=h;
while((x)&&(x->r))
    x=x->r;
return x;
}



void in(struct node *h){
if(h){
    in(h->l);
        printf("%d ",h->key);
        in(h->r);
}
}

void pr(struct node *h){
if(h){
        printf("%d ",h->key);
        pr(h->l);
        pr(h->r);
}
}

void po(struct node *h){
if(h){
        po(h->l);
        po(h->r);
        printf("%d ",h->key);
}
}

struct node * pred(struct node *h,int k){
struct node *temp=NULL;
temp=sea(h,k);
if(temp==NULL)
    return NULL;
if(temp->l)
    return(maxi(temp->l));
    else{

        while(temp){
            if(  (temp->p)&&(temp->p->r)  &&(temp->p->r->key==temp->key)){
                return(temp->p);
            }
            temp=temp->p;}
    }
return NULL;
}

struct node * suc(struct node *h,int k){

struct node *temp=NULL;
temp=sea(h,k);
if(temp==NULL)
    return NULL;
if(temp->r){
    return(mini(temp->r)); }

    else{
            while(temp){

        if((temp->p)&& (temp->p->l) &&  (temp->p->l->key==temp->key))                {

                return(temp->p);}

            temp=temp->p;}
    }
return NULL;
}


