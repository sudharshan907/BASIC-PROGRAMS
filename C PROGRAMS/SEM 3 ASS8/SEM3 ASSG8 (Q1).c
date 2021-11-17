#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
char ch;
struct node *n;
};

struct stack{
struct node *s;
};

struct node* createnode(char ch){
struct node *new=(struct node*)malloc(sizeof(struct node));
new->ch=ch;
new->n=NULL;
return new;
}

void push(struct stack *st,struct node *temp){
temp->n=st->s;
st->s=temp;  }

struct node* pop(struct stack *st){
    struct node *t=st->s;
if(st->s==NULL){
return NULL; }
else{
    st->s=t->n;
    return t;
}
}

int pri(char c){
if((c=='*')||(c=='/'))
    return 2;
if((c=='+')||(c=='-'))
    return 1;
}

//works only for 4 binary operators(*,/,+,-)
char* infixtopostfix(char *s){
    char *str=(char*)malloc(100*sizeof(char));
    int i,j=0;
struct stack st;
struct node *temp,*t;
st.s=NULL;
for(i=0;s[i]!=0;i++){
    if((s[i]>='a')&&(s[i]<='z')){
        str[j]=s[i];j++;
    }
    else if(s[i]==')'){
        while(1){
            if(st.s->ch!='('){
                break;
            }
            t=pop(&st);
            if(t->ch!='('){
       str[j]=t->ch;j++;
        }
        }
       t= pop(&st);
                if(t->ch!='('){
       str[j]=t->ch;j++;
        }
        }
    else {
        while(1){
            if(st.s==NULL){
                break;
            }
            else if(st.s->ch=='('){
                 t= pop(&st);
                         if(t->ch!='('){
       str[j]=t->ch;j++;
        }
                  break;
            }
           else if(pri(st.s->ch)<pri(s[i])){
                break;
           }
       t= pop(&st);
               if(t->ch!='('){
       str[j]=t->ch;j++;
        }
        }
        temp=createnode(s[i]);
        push(&st,temp);
    }
}
while(1){
        if(st.s==NULL)
        break;
    t=pop(&st);
          if(t->ch!='('){
       str[j]=t->ch;j++;
        }
}
str[j]=0;
strcpy(s,str);
free(str);
return s;
}

void main(){
    char *s=(char *)malloc(100*sizeof(char));
scanf("%s",s);
s=infixtopostfix(s);
printf("%s",s);
}









