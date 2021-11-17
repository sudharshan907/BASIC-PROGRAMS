#include<stdio.h>
#include<stdlib.h>

struct node {
int top;
int *a;
};

int isfull(struct node *s,int maxindex){
if(s->top==maxindex)
    return -1;
return 1;

}
void push(struct node *s,int n,int maxindex){
    if(isfull(s,maxindex)==-1){
        return ;
    }
s->top+=1;
int i=s->top;
s->a[i]=n;
}

void pop(struct node *s){
s->top=s->top-1;
}

int isempty(struct node *s){
if(s->top==-1)
    return -1;
else
    return 1;
}

void main(){
int n,i,maxindex;
struct node *s=(struct node*)malloc(sizeof(struct node));
char c;
scanf("%d",&n);
maxindex=n-1;
s->top=-1;
s->a=(int *)malloc(n*sizeof(int));
for(i=0;i<n;i++){
    s->a[i]=0;
}
while(1){
    scanf("%c",&c);
    if(c=='i'){
        scanf("%d",&n);
        push(s,n,maxindex);
    }
    else if(c=='d'){
        i=s->top;
        if(i==-1)
            printf("-1\n");
        else{
                printf("%d\n",s->a[i]);
        pop(s);
    }}
    else if(c=='e'){
        printf("%d\n",isempty(s));
    }
    else if(c=='t'){
    break;
}
}
}
