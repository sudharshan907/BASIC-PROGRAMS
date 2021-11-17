#include<stdio.h>
#include<stdlib.h>

struct node {
char *s;
struct node *nx;   };

struct table{
struct node *n; };

struct arst{
char sr[55];    };

struct arstrptr{
char *sr;   };

struct node* createnode(char *st);
int specval(char *s);
int power(int l);
int strcmpar(char *s,char *t );

void main(){
int n,i,sp;
scanf("%d",&n);
struct arst sn[200];
for(i=0;i<n;i++)
scanf("%s",sn[i].sr);
struct table T[300];
for(i=0;i<300;i++)
    T[i].n=NULL;
struct node *temp=NULL,*t=NULL;
for(i=0;i<n;i++){
    temp=createnode(sn[i].sr);
    sp=specval(sn[i].sr);
    if(T[sp].n==NULL)
        T[sp].n=temp;
    else{
        t=T[sp].n;
        while(t->nx!=NULL)
            t=t->nx;
        t->nx=temp;  }}
for(i=1;i<256;i++){
        int count=0;
        if(T[i].n==NULL)
            continue;
        else{
        //counting
            t=T[i].n;
            while(t!=NULL){
                count++;
                t=t->nx;   }
            //storing in string array
            struct arstrptr strarr[200];
            int c=0;
            t=T[i].n;
            while(c<count){
                strarr[c].sr=t->s;
                t=t->nx;
                c++;   }
            //sorting
            int m;
        char *sw;
        for(m=0;m<count-1;m++){
            for(n=0;n<count-m-1;n++){

                if(strcmpar(strarr[n].sr,strarr[n+1].sr)>0){
                    sw=strarr[n].sr;
                    strarr[n].sr=strarr[n+1].sr;
                    strarr[n+1].sr=sw;   }}}
         //printing
         for(m=0;m<count;m++)
                printf("%s ",strarr[m].sr);
         printf("\n");    }}}

struct node *createnode(char *st){
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->s=st;
temp->nx=NULL;
return temp;
};

int specval(char *s){
int i,sp=0,a[8],ind;
for(i=0;i<8;i++)
    a[i]=0;
for(i=0;s[i]!='\0';i++){
     ind=s[i]-97;
if(a[ind]==0)
    sp=sp+power(ind);
a[ind]=1; }
return sp;
}

int power(int l){
    if(l==0)
  return 1;
int i=0,r=1;
for(i=0;i<l;i++)
    r=r*2;
return r;
}

int strcmpar(char *s,char *t){
for(;*s==*t;s++,t++){
    if(*s=='\0')
        return 0;
}
return (*s-*t);
}






