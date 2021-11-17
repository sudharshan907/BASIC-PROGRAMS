#include<stdio.h>
#include<stdlib.h>

struct node{
int d;
struct node *n;
};

struct stack{
struct node *s;
};


struct node* createnode(int k){
struct node *new=(struct node*)malloc(sizeof(struct node));
new->d=k;
new->n=NULL;
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

int isemp(struct stack *st){
if(st->s!=NULL)
    return 1;
return -1;
}


void main(){
struct node *temp=NULL;
//struct stack *st=(struct stack*)malloc(sizeof(struct stack));
struct stack st;
st.s=NULL;
char c;
int n;
while(1){
    scanf("%c",&c);
    if(c=='i'){
        scanf("%d",&n);
        temp=createnode(n);
        push(&st,temp);
    }
    else if(c=='d'){
        temp=pop(&st);
        if(temp)
            printf("%d\n",temp->d);
        else
            printf("-1\n");
    }
    else if(c=='e'){
    printf("%d\n",isemp(&st));
    }
    else if(c=='t'){
        break;
    }
}
}
