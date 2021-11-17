#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
char *w;
struct node *n;
};
struct table{
struct node *b;
};

struct node* createnode(char *s,int f,int l);
void insert(struct table T[100],int m,struct node *new);
int permit(struct table T[100],char *w,int m);

void main(){
int m,i=0,g;
char s[600];
scanf("%d\n",&m);
scanf("%[^\n]%*c",s);
struct table T[500];
for(i=0;i<m;i++)
T[i].b=NULL;
g=strlen(s);
    s[g]='\0';
struct node *new=NULL;
int f=0,l=0;


     while(1){
       if(s[l]=='\0'){
        new=createnode(s,f,l-1);
       if(permit(T,new->w,m))
       insert(T,m,new);
       break;
       }
      else if(s[l]!=32){l++;}
       else if(s[l]==32){
       new=createnode(s,f,l-1);
        if(permit(T,new->w,m))
      insert(T,m,new);
        f=++l;
       }
    }
for(i=0;i<m;i++){
        printf("%d:",i);
       if(T[i].b==NULL)
            printf("null\n");
       else{
           struct node *temp=T[i].b;
            while(1){
                 printf("%s",temp->w);
                    if(temp->n==NULL){printf("\n");  break;}
                    else{
                        printf("-");
                        temp=temp->n; }
                     } }}}
struct node* createnode(char *s,int f,int l){
char *p;
int i=0,n=l-f+1;
p=(char *)malloc((l-f+2)*sizeof(char));
while(i<n){
p[i]=s[f];
f++;i++;
}
p[i]='\0';
struct node *new=(struct node *)malloc(sizeof(struct node));
new->w=p;
new->n=NULL;
return new;
}
void insert(struct table T[100],int m,struct node *new){

int l,h;
l=strlen(new->w);
h=(l*l)%m;
if(T[h].b==NULL)
    T[h].b=new;
else{
struct node *temp=T[h].b;
while(temp->n!=NULL){
    temp=temp->n;}
    temp->n=new; }}



int permit(struct table T[100],char *wo,int m){
int i;
struct node *temp=NULL;

for(i=0;i<m;i++){
    if(T[i].b==NULL)
        continue;
        temp=T[i].b;
      while( temp!=NULL){
        if(strcmp(temp->w,wo)==0)
            return 0;
        temp=temp->n;
      }   }
return 1;
}










