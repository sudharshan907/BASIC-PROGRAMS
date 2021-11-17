#include<stdio.h>
#include<stdlib.h>

struct elem {
    int f;
    struct elem *lf;
    struct elem *rt;
};

struct elem* getnode(int k);
struct elem* ins(struct elem *h,struct elem *new);
int sea(struct elem *h,int k,int a[100]);
int max(int c[200],int r);

void main(){
  char s[1500],ch;
  int m,n,i=0,d=0;
  scanf("%[^\n]",s);
 scanf("%d %d",&m,&n);
  struct elem *hd=NULL;
  while(1){
    if((s[i]>47)&&(s[i]<58))
        d=d*10+(s[i]-48);
    if((   s[i]==32  )||(s[i]=='\0')){
    hd=ins(hd,getnode(d));
        if(s[i]=='\0')
        break;
    d=0;}
    i++;  }
    int a[100],b[100],na,nb,c[200];
    for(i=0;i<200;i++)
        c[i]=0;
     for(i=0;i<100;i++)
        a[i]=b[i]=-10000;
    na=sea(hd,m,a);
    nb=sea(hd,n,b);
i=0;
while(a[i]==b[i])
    i++;
    if((a[i-1]==m)||(a[i-1]==n)){
        int r=0,p=na-2;
 while(p>i-1){
    c[r]=a[p];
    r++;p--; }
 p=i;
 while(p<=nb-2){
        c[r]=b[p];
 p++;r++;
     }
 printf("%d",max(c,r));
}
else{
int r=0,p=na-2;
 while(p>i-2){
    c[r]=a[p];
    r++;p--;
 }
 p=i;
 while(p<=nb-2){
        c[r]=b[p];
 p++;r++;
 }
 printf("%d",max(c,r));
   }
}

struct elem * getnode(int k){
struct elem *new=NULL;
new=(struct elem *)malloc(sizeof(struct elem));
new->f=k;
new->lf=new->rt=NULL;
return new;
}

struct elem * ins(struct elem *h,struct elem *new){
struct elem *m=h,*n=NULL;
while(m){
    n=m;
    if(new->f<m->f)
        m=m->lf;
    else
        m=m->rt;
}
if(!n)
    h=new;
else if (new->f<n->f)
    n->lf=new;
else
    n->rt=new;
return h;
}

int sea(struct elem *h,int k,int a[100]){
int i=0;

   while((h!=NULL)&&(h->f!=k)){
    if(k<h->f){
    a[i]=h->f;i++;
        h=h->lf;  }
    else{
            a[i]=h->f;i++;
        h=h->rt;  }  }
   a[i]=k;i++;
    return i;
}

int max(int c[200],int r){
int ma=c[0];
int i=0;
for(i=1;i<r;i++){
    if(c[i]>ma)
        ma=c[i];  }
return ma;   }

