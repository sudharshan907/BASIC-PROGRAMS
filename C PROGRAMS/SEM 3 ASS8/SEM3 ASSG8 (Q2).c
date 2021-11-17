#include<stdio.h>
#include<stdlib.h>

struct node {
int top;
int a[100];
};

void push(struct node *s,int n){
    if(s->top==99){
        return ; }
s->top+=1;
s->a[s->top]=n;
}

int pop(struct node *s){
    if(s->top==-1)
        return -100;
s->top=s->top-1;
return(s->a[s->top+1]);
}

//max capacity of stack is 100 numbers,only 4 binary operators (+,-,*,/),works only for positive integers
int postfixeval(char *s){
struct node st;
st.top=-1;
int i=0,o1,o2,d=0;
while(1){
       if(s[i]==0)
        break;
     if((s[i]<='9')&&(s[i]>='0')){
            while( (s[i]<='9')&&(s[i]>='0')){
                d=d*10+(s[i]-'0');
                i++;
            }
            i--;
    push(&st,d);
    d=0;}
    else if(s[i]==32){
        //dont remove this bcz if you remove space two numbers will be popped for space also in next else statement
    }
    else{
        o2=pop(&st);
        o1=pop(&st);
        if(s[i]=='+')
            push(&st,o1+o2);
           if(s[i]=='-')
            push(&st,o1-o2);
           if(s[i]=='*')
            push(&st,o1*o2);
           if(s[i]=='/')
            push(&st,o1/o2);
    }
    i++;
    }
    return pop(&st);
}
void main(){
    char s[100];
     scanf("%[^\n]",s);
    printf("%d",postfixeval(s));
}


