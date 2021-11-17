#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int key;
    struct node *l,*r,*p;
};

struct node * getnode(int k);
struct node * fn(struct node *h,char *s,int i);
int prc(char *s,int i);
int mini(struct node *h);
int maxi(struct node *h);
int checkbst(struct node *h);
int sum(struct node *h);
int count(struct node *h,int k);

void main(){
    struct node *h=NULL;
 int i=0,d=0,j=0,l,k,n;
    char s[5000],in[5000];
    scanf("%[^\n]",in);
    l=strlen(in);
    scanf("%d",&k);
   while(i<l){
     if((in[i]==')')||(in[i]=='(')){
            s[j]=in[i];
            j++;             }

       else if((in[i]>='0')&&(in[i]<='9')){
            d=(in[i]-'0');
           while((in[i+1]>='0')&&(in[i+1]<='9')){
                   d=d*10 +(in[i+1]-'0');i++;
            }
        s[j]=d;j++;
        }
        i++;}
s[j]='\0';
h=fn(h,s,0);
i=count(h,k);
if(i==0)
    printf("-1");
else
printf("%d",i);
}

struct node * fn(struct node *h,char *s,int i){
    struct node *new=NULL;
if(s[i+1]==')')
    return NULL;
else{
        new=getnode(s[i+1]);
        h=new;
 h->l= fn(h,s,i+2);

  i=prc(s,i+2);
 h->r= fn(h,s,i+1);
 return h; }
}

int prc(char *s,int i){
   int c=0;
   while(1){
    if(s[i]=='(')
        c++;
    if(s[i]==')')
        c--;
    if(c==0)
        return(i);
    i++;
   }
}

struct node * getnode(int k){
struct node *new=NULL;
new=(struct node *)malloc(sizeof(struct node));
new->key=k;
new->l=new->r=new->p=NULL;
return new;
}

int mini(struct node *h){
struct node *x=h;
while((x)&&(x->l))
    x=x->l;
return (x->key);
}
int maxi(struct node *h){
struct node *x=h;
while((x)&&(x->r))
    x=x->r;
return (x->key);
}
int checkbst(struct node *h){
 if(h==NULL)
    return 1;
 if((h->l!=NULL)&& (maxi(h->l)>=h->key) )
    return 0;
 if((h->r!=NULL)&& (mini(h->r)<=h->key))
    return 0;
 if(  (  (checkbst(h->l))   &&(checkbst(h->r) ) ) ==0)
 return 0;
 return 1;
}
int sum(struct node *h){
if(h==NULL)
    return 0;
else
    return(h->key+sum(h->l)+sum(h->r));
}
int count(struct node *h,int k){
    if(h==NULL)
        return 0;
static int cou=0;
if(     (checkbst(h))&&(sum(h)==k)    )
cou++;
count(h->l,k);
count(h->r,k);
return cou;
}

