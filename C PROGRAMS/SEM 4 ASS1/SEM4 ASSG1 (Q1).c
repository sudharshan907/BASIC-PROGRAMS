#include<stdio.h>
#include<stdlib.h>

struct node {
int key;
struct node *l,*r,*p,*q;
};

struct node * insert(struct node *h,int k);
void print(struct node *h);

void main(){
struct node *h=NULL;
int n1;
char c;

    while(1){
    scanf("%c",&c);
    if(c=='i'){
        scanf("%d",&n1);
            h=insert(h,n1);   }

           else if(c=='p')
                print(h);

            else if(c=='e')
                    break;}
}

struct node *insert(struct node *h,int k){

//step 1
   struct node *new=NULL,*f=NULL,*r=NULL,*temp=NULL;
new=(struct node *)malloc(sizeof(struct node));
new->key=k;
new->q=new->l=new->r=new->p=NULL;

//step 2
if(h==NULL){
    h=new;
    return h;
}
//step 3
    temp=h;
    while(temp!=NULL){

    //loop 1

        if(temp->l==NULL){
                temp->l=new;
        new->p=temp;
        return h;
    }
    //loop 2
else{

    if((f==NULL)&&(r==NULL)){
            f=temp->l;
            r=temp->l;}
else if(f->key==r->key){
        f->q=temp->l;
 r=temp->l;
        }
else{
       r->q=temp->l;
       r=temp->l;}
}
//loop 3
     if(temp->r==NULL){

    temp->r=new;
        new->p=temp;
        return h;}
        //loop 4
else{
        if((f==NULL)&&(r==NULL)){
            f=temp->r;
            r=temp->r;}
 else if(f->key==r->key){
        f->q=temp->r;
 r=temp->r;

        }
else{
       r->q=temp->r;
       r=temp->r;
    } }

    //loop 5
    struct node *d=NULL;
 if((f==NULL)&&(r==NULL))
    temp=NULL;
 else if(f->key==r->key){
    d=f;
 f=r=NULL;
  temp=d;;
        }
else{
    d=f;
    f=f->q;
    temp=d;
}}

}

void print(struct node *h){
if(h==NULL){
    printf("( )");
    return;
}
else{
    printf("( %d ",h->key);
    print(h->l);
    printf(" ");
    print(h->r);
    printf(" )");
}
return;
}




