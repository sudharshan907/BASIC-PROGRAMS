#include<stdio.h>
#include<stdlib.h>

struct node{
char d;
struct node *n,*l,*r;
};

struct stack{
struct node *s;
};


struct node* createnode(int k){
struct node *new=(struct node*)malloc(sizeof(struct node));
new->d=k;
new->n=new->l=new->r=NULL;
return new;
}

void push(struct stack *st,struct node *temp){
temp->n=st->s;
st->s=temp;  }

struct node* pop(struct stack *st){
    struct node *t=NULL;
if(st->s==NULL){
return NULL;  }
else{
    t=st->s;
    st->s=t->n;
    return t;
}
}

//works only for alphabet operands
struct node* exptree(char *s){
struct stack st;
st.s=NULL;
int i;
struct node *t=NULL,*a=NULL,*b=NULL;
for(i=0;s[i];i++){
    if((s[i]>=97)&&(s[i]<=122)){
        t=createnode(s[i]);
        push(&st,t);
    }
    else{
        t=createnode(s[i]);
        a=pop(&st);
        b=pop(&st);
        t->r=a;
        t->l=b;
        push(&st,t);
    }
}
return st.s;}



void in(struct node *h){
if(h){
    in(h->l);
        printf("%c",h->d);
        in(h->r);
}
}

void pr(struct node *h){
if(h){
        printf("%c",h->d);
        pr(h->l);
        pr(h->r);
}
}

void po(struct node *h){
if(h){
        po(h->l);
        po(h->r);
        printf("%c",h->d);
}
}

void main(){
char c,s[100];
struct node *t=NULL;
while(1){
    scanf("%c",&c);
    if(c=='e'){
       scanf(" %[^\n]",s);
       t=exptree(s);
    }
    else if(c=='i'){
     in(t);
     printf("\n");
    }
    else if(c=='p'){
     pr(t);
     printf("\n");
    }
    else if(c=='s'){
     po(t);
     printf("\n");
    }
    else if(c=='t'){
        break;
    }
}
}
