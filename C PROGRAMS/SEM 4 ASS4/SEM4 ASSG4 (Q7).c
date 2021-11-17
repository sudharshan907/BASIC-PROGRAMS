#include<stdio.h>
#include<stdlib.h>

struct node {
int key,size;
struct node *p;
};
struct table{
struct node *t;
};

int f1,f2,f3,f4;

struct node* add(struct table T[500],int k);
struct node* find(struct node *x,int i);
struct node* findwipc(struct node *x,int i);
struct node* un(struct node *x,struct node *y,int i);
struct node* makeset(int k);
struct node* unrk(struct node *x,struct node *y,int i);

void main(){
    struct table T[500],TB[500],TC[500],TD[500];

    int i;
    struct node *temp=NULL,*temp1=NULL;
    for(i=0;i<500;i++){
        T[i].t=NULL;
        TB[i].t=TC[i].t=TD[i].t=NULL;  }
    char c;
    int k1,k2;
    while(1){
        scanf("%c",&c);
        if(c=='m'){
            scanf("%d",&k1);

            if(add(T,k1)!=NULL)
                printf("-1\n");
            else{
                printf("%d\n",k1);
                T[k1].t=makeset(k1);
                TB[k1].t=makeset(k1);
                TC[k1].t=makeset(k1);
                TD[k1].t=makeset(k1);
            }
        }

        else if(c=='f'){
            scanf("%d",&k1);
            temp=add(T,k1);
            if(temp==NULL)
            printf("-1 -1 -1 -1\n");
            else{
            temp=add(T,k1);
                //T
                temp=find(temp,1);
                printf("%d ",temp->key);
                //TB
                temp=add(TB,k1);
                temp=find(temp,2);
                printf("%d ",temp->key);
                //TC
                 temp=add(TC,k1);

                temp=findwipc(temp,3);
                printf("%d ",temp->key);
                //TD
                 temp=add(TD,k1);
                temp=findwipc(temp,4);
                printf("%d\n",temp->key);
            }

        }
         else if(c=='u'){
            scanf("%d %d",&k1,&k2);
            temp=add(T,k1);
            temp1=add(T,k2);
            if(!(   (temp)&&(temp1)          ))
                printf("-1 -1 -1 -1\n");
            else{

                //T
                temp=un(temp,temp1,1);
                printf("%d ",temp->key);
                //TB
                temp=add(TB,k1);
                temp1=add(TB,k2);

                temp=unrk(temp,temp1,2);
                printf("%d ",temp->key);
                //TC
                 temp=add(TC,k1);
                temp1=add(TC,k2);
                temp=un(temp,temp1,3);
                printf("%d ",temp->key);
                //TD
                 temp=add(TD,k1);
                temp1=add(TD,k2);
                temp=unrk(temp,temp1,4);
                printf("%d\n",temp->key);
            }
         }
            else if(c=='s'){

                printf("%d %d %d %d\n",f1,f2,f3,f4);
                break;}}}


struct node* makeset(int k){
struct node *temp=(struct node *)malloc(sizeof(struct node));
temp->key=k;
temp->size=0;
temp->p=temp;
return temp;
}

struct node* add(struct table T[500],int k){
int i=0;
for(i=0;i<500;i++){

    if((T[i].t)&&T[i].t->key==k)
        return (T[i].t);
}
return NULL;
};

struct node* find(struct node *x,int i){
    if(i==1)
    f1++;
    if(i==2)
        f2++;
        if(i==3)
            f3++;
            if(i==4)
                f4++;
while(1){
    if(x->p==x)
        return x;
    x=x->p;
    if(i==1)
    f1++;
    if(i==2)
        f2++;
        if(i==3)
           f3++;
           if(i==4)
            f4++;
}
}

struct node* findwipc(struct node *x,int i){
   if(i==3)
f3++;
if(i==4)
    f4++;
struct node *par=find(x,5),*u=NULL;
while(x->p!=x){
    u=x->p;
    x->p=par;
    x=u;
   if(i==3)
f3++;
if(i==4)
    f4++;
}
return par;
}

struct node* un(struct node *x,struct node *y,int i){

if((i==1)||(i==2)){
x=find(x,i);
y=find(y,i); }
if((i==3)||(i==4)){
x=findwipc(x,i);
y=findwipc(y,i);
}
y->p=x;
return x;
}


struct node* unrk(struct node *x,struct node *y,int i){
    if(i==2){
x=find(x,i);
y=find(y,i); }
if(i==4){
    x=findwipc(x,i);
y=findwipc(y,i);

}
if(y->size>x->size){
    x->p=y;
return y;}
else{
y->p=x;
if(x->size==y->size)
x->size=1+x->size;
return x; }
}













